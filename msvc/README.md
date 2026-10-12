# Visual Studio project (shareware / WL1)

`raylib_wolf3d.sln` at the repository root opens `msvc/raylib_wolf3d.vcxproj`
(Debug/Release, x64, VS 2022 17.5+ for C11 atomics). CMake remains the primary build.

- **raylib 5.5** comes from the vcpkg manifest `vcpkg.json` (static, `x64-windows-static-md`).
  Either run `vcpkg integrate install` once, or set `VCPKG_ROOT` to a vcpkg checkout
  (a Developer prompt from VS with the vcpkg component sets it). Use a full (non-shallow)
  vcpkg clone: the manifest pins a baseline.
- **Python 3** must be on `PATH` (or pass `/p:PythonExe=py`): `scripts/obj2c.py` and
  `scripts/gen_states.py` generate `wl_objdata.c` / `wl_states.c` into `build-vs/obj/<cfg>/generated`.
- **F5** runs from `%WOLF3D_DATA%`, defaulting to `%USERPROFILE%\wolf3d-data\shareware`
  (shareware `*.WL1` data, kept outside git).
- Command line: `msbuild raylib_wolf3d.sln -p:Configuration=Release -p:Platform=x64`.
  Output: `build-vs\<Configuration>\raylib_wolf3d.exe`.

Known for the Stage 2 issues: `wl_compat.h` redeclares `itoa`/`ltoa`/`ultoa`/`filelength`
(warning C4273, dll linkage vs the UCRT); `wl_persist.c(197)` has a size_t narrowing warning.
