#include <stdio.h>

void	print_binary(unsigned char c)
{
	int	i;
	i = 7;

	while (i >= 0)
	{
		printf("%d", (c >> i) & 1);
		i--;
	}
	printf(" ");
}

int	main()
{
	char text[] = "Hello 🌍 🐒 €";
	int i = 0;

	printf("Text: %s \n", text);
	printf("Binary: ");

	while (text[i] != '\0')
	{
		unsigned char	c;.
		c = text[i];

		int	num_bytes;

		  if ((c & 0b10000000) == 0) { // 0xxxxxxx → 1 byte (ASCII)
            num_bytes = 1;
        } else if ((c & 0b11100000) == 0b11000000) { // 110xxxxx → 2 bytes
            num_bytes = 2;
        } else if ((c & 0b11110000) == 0b11100000) { // 1110xxxx → 3 bytes
            num_bytes = 3;
        } else if ((c & 0b11111000) == 0b11110000) { // 11110xxx → 4 bytes
            num_bytes = 4;
        } else { //(ASCII) Caso inválido (não deveria acontecer)
            num_bytes = 1;
        }

		int	j = 0;

		while (j < num_bytes)
		{
			print_binary(text[i]);
			j++;
			i++;
		}
	}

	printf("\n");
	return 0;
}
