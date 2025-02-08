#include <stdio.h>
#include <string.h>

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
	char word[] = "Hello word 1234 9(())";
	printf("Word: %s\n", word);
	printf("Binary: ");

	unsigned long i;
	i = 0;
	while (i < strlen(word))
	{
		print_binary(word[i]);
		i++;
	}
	printf("\n");
	return 0;
}
