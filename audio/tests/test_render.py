"""Renderer pacing regression with synthetic WL1 data (no game assets)."""
import pathlib
import struct
import subprocess
import sys
import tempfile
import time
import wave


def main():
    renderer = pathlib.Path(sys.argv[1]).resolve()
    with tempfile.TemporaryDirectory(prefix='wolf-render-') as directory:
        root = pathlib.Path(directory)
        chunks = [b''] * 288
        chunks[0] = struct.pack('<IH', 4, 10) + bytes([30, 60, 0, 30])
        chunks[87] = (struct.pack('<IH', 4, 10)
                      + bytes([1, 1, 0, 0, 240, 240, 119, 119, 0, 0, 0, 0, 0, 0, 0, 0])
                      + bytes([4, 64, 0, 80, 100]))
        chunks[261] = bytes([8, 0, 32, 1, 2, 0, 64, 2, 20, 0])
        offsets = [0]
        for chunk in chunks:
            offsets.append(offsets[-1] + len(chunk))
        (root / 'AUDIOHED.WL1').write_bytes(struct.pack('<289I', *offsets))
        (root / 'AUDIOT.WL1').write_bytes(b''.join(chunks))
        (root / 'VSWAP.WL1').write_bytes(
            struct.pack('<HHHIIHH', 2, 0, 0, 18, 22, 4, 4)
            + bytes([128, 255, 0, 128]) + struct.pack('<HH', 0, 4))
        for kind in ('music', 'adlib', 'pc', 'pcm'):
            outputs = []
            for paced in (False, True):
                wav = root / 'output.wav'
                trace = root / 'output.csv'
                command = [str(renderer), str(root), kind, '0', '1', str(wav),
                           '--trace', str(trace)]
                if paced:
                    command.append('--realtime')
                start = time.monotonic()
                subprocess.run(command, check=True)
                elapsed = time.monotonic() - start
                assert not paced or elapsed >= 0.99, f'{kind}: pacing ended early'
                with wave.open(str(wav), 'rb') as stream:
                    assert stream.getparams()[:4] == (2, 2, 44100, 44100)
                    samples = stream.readframes(44100)
                    assert len(samples) == 176400
                    if kind != 'music':
                        assert any(samples)
                outputs.append((samples, trace.read_bytes()))
            assert outputs[0] == outputs[1], f'{kind}: pacing changed output'
            print(f'PASS {kind}: identical offline/paced PCM and traces')


if __name__ == '__main__':
    main()
