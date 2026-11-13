#include <nds.h>
#include <stdio.h>

static PrintConsole topScreen;
static PrintConsole bottomScreen;
static volatile int frame = 0;

static void Vblank(void) {
    frame++;
}

int main(void) {
    irqSet(IRQ_VBLANK, Vblank);

    // Configurar por separado las dos pantallas de Nintendo DS.
    lcdMainOnTop();
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    consoleInit(&topScreen, 0, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
    consoleInit(&bottomScreen, 0, BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);

    consoleSelect(&topScreen);
    consoleClear();
    iprintf("\n\n       E L D O R I A\n");
    iprintf("  RPG - MUNDO DE FANTASIA\n\n");
    iprintf("  Si puedes leer esto,\n");
    iprintf("  la pantalla superior funciona.\n");

    consoleSelect(&bottomScreen);
    consoleClear();
    iprintf("\n\n     PRUEBA DE PANTALLA\n\n");
    iprintf("  Si puedes leer esto,\n");
    iprintf("  la pantalla tactil funciona.\n\n");
    iprintf("  Pulsa START para probar.");

    while (pmMainLoop()) {
        swiWaitForVBlank();
        scanKeys();

        if (keysDown() & KEY_START) {
            consoleSelect(&bottomScreen);
            iprintf("\n\n  START detectado correctamente.");
        }

        consoleSelect(&topScreen);
        iprintf("\x1b[20;0HContador: %d     ", frame);
    }

    return 0;
}
