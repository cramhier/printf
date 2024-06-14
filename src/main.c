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

int	printf_ft(const char *string, ...)
{
	va_list	arguments;
	size_t	index;
	int		count;

	index = 0;
	count = 0;
	va_start(arguments, string);
	while (string[index])
	{
		if (string[index] == '%' && string[index + 1] == '%')
			count += outputChar(string[++index]);
		else if (string[index] == '%')
			count += formatManager(string[++index], &arguments);
		else
			count += outputChar(string[index]);
		index++;
	}
	va_end(arguments);
	return (count);
}

/* TESTING */

#include <stdio.h>
int main()
{
	//char *nbr = NULL;
	unsigned int nbr = INT_MAX;
	ft_putnbr_fd(printf_ft("This is a test Output FakePrintf: %X\nNice!\n", nbr), 1);
	ft_putstr_fd("\n\n", 1);
	ft_putnbr_fd(printf("This is a test Output FakePrintf: %X\nNice!\n", nbr), 1);
	return (0);
}

// Parse issue where the format is not the same as the variable (probably not scope of the project)