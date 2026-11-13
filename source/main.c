#include <nds.h>
#include <stdio.h>

int main(void) {
    consoleDemoInit();

    iprintf("\x1b[2J");
    iprintf("\x1b[3;8HELDORIA");
    iprintf("\x1b[5;3HRPG - MUNDO DE FANTASIA");
    iprintf("\x1b[9;2HUn nuevo mundo te espera...");
    iprintf("\x1b[14;3HPulsa START para comenzar");

    // libnds 2.x necesita que el bucle principal atienda el sistema de energía.
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
