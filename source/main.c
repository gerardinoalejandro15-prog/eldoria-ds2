#include <nds.h>
#include <stdio.h>

static volatile int frame = 0;

static void Vblank(void) {
    frame++;
}

int main(void) {
    irqSet(IRQ_VBLANK, Vblank);
    consoleDemoInit();

    iprintf("       E L D O R I A\n");
    iprintf("  RPG - MUNDO DE FANTASIA\n\n");
    iprintf("  Si puedes leer esto,\n");
    iprintf("  el juego ha arrancado.\n\n");
    iprintf("  Pulsa START para salir.\n");

    while (pmMainLoop()) {
        swiWaitForVBlank();
        scanKeys();

        if (keysDown() & KEY_START) {
            iprintf("\n  Inicio detectado.");
        }

        iprintf("\x1b[20;0HFrames: %d   ", frame);
    }

    return 0;
}
