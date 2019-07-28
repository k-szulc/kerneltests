/*
 *  kernel.c
 *  /
 */

void kmain(void)
{
    const char *str = "dupa 1 2 3";
    char *vidptr = (char*)0xb8000;
    unsigned int i = 0;
    unsigned int j = 0;

    /* this loops clears the screen
     * there are 25 lines each of 80 columns; each elemnt takes 2 bytes */
    while(j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07;
        j = j + 2;
    }

    j = 0;

    /* This loop writes the string to video memory */
    while(str[j] != '\0') {
        /*the character's ascii */
        vidptr[i] = str[j];
        /* attribute-byte: give character black bh and light grey fg */
        vidptr[i+1] = 0x07;
        ++j;
        i = i +2;
    }
    return;
}
