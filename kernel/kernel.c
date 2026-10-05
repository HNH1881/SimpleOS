#include <stdint.h>

#define VGA_ADDRESS 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static volatile uint16_t *video = (volatile uint16_t *)VGA_ADDRESS;

static void clear_screen(void)
{
    for (int y = 0; y < VGA_HEIGHT; ++y) {
        for (int x = 0; x < VGA_WIDTH; ++x) {
            video[y * VGA_WIDTH + x] = (uint16_t)(' ' | 0x0700);
        }
    }
}

static void print_string(const char *str)
{
    int x = 0;
    int y = 0;
    while (*str) {
        if (*str == '\n') {
            x = 0;
            ++y;
        } else {
            if (x >= VGA_WIDTH) {
                x = 0;
                ++y;
            }
            if (y >= VGA_HEIGHT) {
                y = 0;
            }
            video[y * VGA_WIDTH + x] = (uint16_t)((unsigned char)(*str) | 0x0700);
            ++x;
        }
        ++str;
    }
}

void kmain(void)
{
    clear_screen();
    print_string("Hello from the C kernel!\n");
    print_string("This is the beginning of SimpleOS.\n");
    for (;;) {
        __asm__ volatile ("hlt");
    }
}
