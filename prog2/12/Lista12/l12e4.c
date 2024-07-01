#define LED_BASE_ADDR 0x1000
#define PRIM_BIT 0x80
#define LEDS_POR_COL 8
#define N_COL 128

int main()
{
    int desloc;
    unsigned char* ptr;
    for(desloc=0; desloc<N_COL; desloc++)
    {
        *ptr = LED_BASE_ADDR + desloc;
        *ptr = PRIM_BIT >> (desloc%LEDS_POR_COL);
    }
    return 0;
}
