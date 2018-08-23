#include "inc/ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	ft_printf(  	"{%D}\n", L123456789123);
	printf(			"{%D}\n", L123456789123);
	return (0);
}
