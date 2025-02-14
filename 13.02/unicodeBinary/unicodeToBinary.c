#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char binary_to_char(const char *binary)
{
    char c = 0;
    for (int i = 0; i < 8; i++)
    {
        c <<= 1;
        if (binary[i] == '1')
            c |= 1;
    }
    return c;
}

void binary_to_text(const char *binaryText)
{
    char text[256] = {0};
    int text_index = 0;
    char byte[9] = {0};
    int byte_index = 0;
    
    for (int i = 0; binaryText[i] != '\0'; i++)
    {
        if (binaryText[i] == '0' || binaryText[i] == '1')
        {
            byte[byte_index++] = binaryText[i];
            if (byte_index == 8)
            {
                byte[8] = '\0';
                text[text_index++] = binary_to_char(byte);
                byte_index = 0;
            }
        }
    }
    text[text_index] = '\0';
    
    // Verificar sequência UTF-8
    printf("Text: ");
    for (int i = 0; i < text_index; i++)
    {
        unsigned char c = text[i];
        int num_bytes;

        if ((c & 0b10000000) == 0) { // 1 byte (ASCII)
            num_bytes = 1;
        } else if ((c & 0b11100000) == 0b11000000) { // 2 bytes
            num_bytes = 2;
        } else if ((c & 0b11110000) == 0b11100000) { // 3 bytes
            num_bytes = 3;
        } else if ((c & 0b11111000) == 0b11110000) { // 4 bytes
            num_bytes = 4;
        } else {
            num_bytes = 1; // Caso inválido (não deveria acontecer)
        }

        for (int j = 0; j < num_bytes; j++)
        {
            printf("%c", text[i + j]);
        }
        i += num_bytes - 1;
    }
    printf("\n");
}

int main()
{
    char binaryText[] = "01001000 01100101 01101100 01101100 01101111 00100000 11110000 10011111 10001100 10001101 00100000 11100010 10000010 10101100";
    
    printf("Binary text: %s\n", binaryText);
    binary_to_text(binaryText);
    
    return 0;
}
