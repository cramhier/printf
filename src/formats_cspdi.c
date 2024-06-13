/*                                                                 /L'-,
            ▄████▄   ██▀███   ▄▄▄       ███▄ ▄███▓. .             /  L '-,
      .     ▒██▀ ▀█  ▓██ ▒ ██▒▒████▄    ▓██▒▀█▀ ██▒`..           /       '-,
      :     ▒▓█    ▄ ▓██ ░▄█ ▒▒██  ▀█▄  ▓██    ▓██░ ,<>         /_      '-,'
      ;     ▒▓▓▄ ▄██▒▒██▀▀█▄  ░██▄▄▄▄██ ▒██    ▒██,',.;      .-'* ;     .'
      |     ▒ ▓███▀ ░░██▓ ▒██▒ ▓█   ▓██▒▒██▒   ░█< ,; `.      )`--'    /
      |     ░ ░▒ ▒  ░░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ▒░   ░  `  `. `.   /__,    ,'
      |     ░  ▒     ░▒ ░ ▒░  ▒   ▒▒ ░░  ░      ░      `. `-,_\     /
      |     ░          ░░   ░   ░   ▒   ░      ░         `./ .\----.___
      |     ░ ░         ░           ░  ░       ░           `.__) . .F. )-.
      |     ░                                               J . . . J-'-. `-.,
      |                                                     |. . . . \   `-.  F
      |                                                     F . . . . \     '`
      |     @github.com/cramhier                       __,-J . . . . . \
      |                                          __,--'    |. .__.----,'
      |     ***   ***                      __,--'          `.-;;;;;;;;;\
      |                              __,--'                 /;;;;;;;;;;;;.
      |                        __,--'                      /;;;;;;;;;;;;;;\
  \   |                  __,--'                            `--;;/     \;-'\
   \  |            __,--'                                  /  /         \  \
    \ |      __,--'                                       /  /           \  \
     \|__,--'                                         _,-;M-K,           ,;-;\
                                                     <;;;;;;;;           '-;;;;*/

#include "../headers/printf_ft.h"

int outputChar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	outputString(char *string)
{
	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

int	transformToHexadecimal(unsigned long long number)
{
	char	*hexMap;
	int		index;
	size_t	letterCount;

	hexMap = "0123456789abcdef";
	index = 0;
	letterCount = 0;
	while (number > 0)
	{
		index = number % 16;
		number /= 16;
		transformToHexadecimal(number); //recalls itself to print the digits in the right order
		outputChar(hexMap[index]);
		break ;
		letterCount++;
	}
	return (letterCount); // FIX counting mistake
}

int	outputPointer(void *pointer)
{
	unsigned long long	pointerInDecimal;
	size_t				letterCount;

	letterCount = 0;
	pointerInDecimal = (unsigned long long)pointer;
	ft_putstr_fd("0x", 1);
	letterCount += 2 + transformToHexadecimal(pointerInDecimal);
	return (letterCount);
}

// add for % di