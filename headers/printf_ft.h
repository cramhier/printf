#ifndef PRINTF_H
# define PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>  
#include <limits.h>

//Format Manager
int	formatManager(char format, va_list *arguments);
//Output Functions
int outputChar(char c);
int	outputString(char *string);
int	outputPointer(void *pointer);
int outputNumber(int number);
int	outputUnsignedInt(unsigned int number);
int	transformToHexadecimal(unsigned long long number, char *type);

#endif