#include <nds.h>

int main(void) {
    // Prueba minima: usar la VRAM como framebuffer, sin consola ni texto.
    videoSetMode(MODE_FB0);
    vramSetBankA(VRAM_A_LCD);

    u16 *framebuffer = (u16 *)VRAM_A;
    for (int i = 0; i < 256 * 192; i++) {
        framebuffer[i] = RGB15(0, 0, 31) | BIT(15);
    }

    // Mantener la imagen visible sin depender de la consola ni de IRQ propias.
    while (1) {
        swiWaitForVBlank();
    }

    return 0;
}
