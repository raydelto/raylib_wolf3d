/*
 * Link stubs for wolf_render_test on Windows.  PE ld keeps the game code in
 * WL_DRAW.C/WL_STATE.C that ELF --gc-sections discards, so the symbols it
 * references must exist.  The test never executes them; resolution is by
 * name only, so the types here are placeholders.
 */
#define FN(name) void name(void) {}
#define DATA(name) char name[512];

FN(A_DeathScream) FN(FizzleFade) FN(GetBonus) FN(GetNewActor) FN(GivePoints)
FN(PM_NextFrame) FN(PlaceItemType) FN(PlaySoundLocGlobal) FN(SD_PlaySound)
FN(TakeDamage) FN(VL_Hlin) FN(VL_Refresh) FN(VL_ScreenToScreen) FN(VL_SetCRTC)
FN(VL_SetScreen) FN(WL_NotPorted)

DATA(TimeCount) DATA(areabyplayer) DATA(bufferofs) DATA(demoplayback)
DATA(demorecord) DATA(demotest) DATA(dirangle) DATA(displayofs) DATA(fizzlein)
DATA(focallength) DATA(gamestate) DATA(laststatobj) DATA(madenoise)
DATA(mapon) DATA(new) DATA(player) DATA(plux) DATA(pluy) DATA(screenofs)
DATA(statobjlist) DATA(tics)

DATA(s_blinkychase1) DATA(s_bosschase1) DATA(s_bossdie1) DATA(s_deathcam)
DATA(s_dogchase1) DATA(s_dogdie1) DATA(s_fakechase1) DATA(s_fakedie1)
DATA(s_fatchase1) DATA(s_fatdie1) DATA(s_giftchase1) DATA(s_giftdie1)
DATA(s_grdchase1) DATA(s_grddie1) DATA(s_grdpain) DATA(s_grdpain1)
DATA(s_gretelchase1) DATA(s_greteldie1) DATA(s_hitlerchase1) DATA(s_hitlerdie1)
DATA(s_mechachase1) DATA(s_mechadie1) DATA(s_mutchase1) DATA(s_mutdie1)
DATA(s_mutpain) DATA(s_mutpain1) DATA(s_ofcchase1) DATA(s_ofcdie1)
DATA(s_ofcpain) DATA(s_ofcpain1) DATA(s_schabbchase1) DATA(s_schabbdie1)
DATA(s_sschase1) DATA(s_ssdie1) DATA(s_sspain) DATA(s_sspain1)
