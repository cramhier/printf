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

int outputChar(char c) // %c
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	outputString(char *string) // %s
{
	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

int	outputPointer(void *pointer) // %p
{
	unsigned long long	pointerInDecimal;
	size_t				letterCount;

	if (!pointer)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	letterCount = 0;
	pointerInDecimal = (unsigned long long)pointer;
	ft_putstr_fd("0x", 1);
	letterCount += 2 + transformToHexadecimal(pointerInDecimal, "low");
	return (letterCount);
}

int outputNumber(int number) // %d %i
{
	int	letterCount;
	long	numberCopy;		//change int to long datatype, for simplicity of changing the number into a positive value

	letterCount = 0;
	numberCopy = number;
	ft_putnbr_fd(number, 1);
	if (numberCopy == 0)
		return (1);
	else if (numberCopy < 0)
	{
		letterCount++;
		numberCopy *= -1;
	}
	while (numberCopy > 0)
	{
		numberCopy /= 10;
		letterCount++;
	}
	return (letterCount);
}

int	outputUnsignedInt(unsigned int number) //%u
{
	long		numberCopy;
	int			letterCount;

	numberCopy = number;
	letterCount = 0;
	if (numberCopy / 10)
		letterCount += outputUnsignedInt(numberCopy / 10);
	numberCopy = numberCopy % 10;
	letterCount+= outputNumber(numberCopy);
	return (letterCount);
}
