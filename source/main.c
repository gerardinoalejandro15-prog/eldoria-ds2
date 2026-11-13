#include <nds.h>
#include <stdio.h>

static volatile int frame = 0;

static void Vblank(void) {
    frame++;
}

int main(void) {
    irqSet(IRQ_VBLANK, Vblank);

    // Inicializacion de pantalla siguiendo el ejemplo oficial de devkitPro.
    consoleDemoInit();

    iprintf("        ELDORIA\n");
    iprintf("   RPG - MUNDO DE FANTASIA\n\n");
    iprintf(" Un nuevo mundo te espera...\n\n");
    iprintf(" Pulsa START para comenzar\n");

    while (pmMainLoop()) {
        swiWaitForVBlank();
        scanKeys();

        if (keysDown() & KEY_START) {
            iprintf("\n\n La aventura comienza!\n");
        }

        iprintf("\x1b[20;0HPrueba de pantalla: %d   ", frame);
    }

    return 0;
}
