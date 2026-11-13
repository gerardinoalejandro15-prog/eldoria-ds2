#include <nds.h>

int main(void) {
    // Enrutar el motor grafico principal a la pantalla superior.
    lcdMainOnTop();

    // Activar el modo framebuffer y asignar la memoria de video A.
    videoSetMode(MODE_FB0);
    vramSetBankA(VRAM_A_LCD);

    // Pintar todos los pixeles de la pantalla principal de azul.
    for (int i = 0; i < 256 * 192; i++) {
        VRAM_A[i] = RGB15(0, 0, 31);
    }

    while (1) {
        swiWaitForVBlank();
    }

    return 0;
}
