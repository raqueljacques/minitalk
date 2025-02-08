#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	binary_to_char(const char *binary)
{
	char	result = 0;
	int	i = 0;
	while (i < 8)
	{
		// Desloca para a esquerda e adiciona o bit atual
		result = (result << 1) | (binary[i] - '0');   
		i++;
	}
	return(result);
}

void	decode_binary_to_text(const char *binary_string)
{
	//8 bits + '\0'
	char	buffer[9];

	while (*binary_string)
	{
		//ignore space between bytes
		if (*binary_string == ' ')
		{
			binary_string++;
			continue;
		}
		//copy 8 char (bits)
		strncpy(buffer, binary_string, 8);
		buffer[8] = '\0';

		char character = binary_to_char(buffer);
		printf("%c", character);

		binary_string += 8;
	}
	printf("\n");
}

int	main()
{
	char	binary_string[] = "01001000 01100101 01101100 01101100 01101111 00100000 01110111 01101111 01110010 01100100 00100000 00110001 00110010 00110011 00110100 00100000 00111001 00101000 00101000 00101001 00101001";
	printf("Binary: %s\n", binary_string);
	printf("Decoded Text: ");
	decode_binary_to_text(binary_string);
	return 0;
}
