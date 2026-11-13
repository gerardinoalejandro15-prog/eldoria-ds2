#include <nds.h>
#include <stdio.h>

int main(void) {
    // Inicializar explícitamente la pantalla superior como pantalla principal.
    videoSetMode(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_BG);

    // Crear la consola de texto en la pantalla superior.
    consoleInit(NULL, 0, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);

    consoleClear();
    iprintf("\x1b[3;8HELDORIA");
    iprintf("\x1b[5;3HRPG - MUNDO DE FANTASIA");
    iprintf("\x1b[9;2HUn nuevo mundo te espera...");
    iprintf("\x1b[14;3HPulsa START para comenzar");

    while (pmMainLoop()) {
        scanKeys();
        int keys = keysDown();

        if (keys & KEY_START) {
            iprintf("\x1b[18;5HLa aventura comienza!");
        }

        swiWaitForVBlank();
    }

    return 0;
}
