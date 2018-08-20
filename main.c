#include "inc/ft_printf.h"
#include <stdio.h>

int main()
{
	ft_printf(	"{test%1.d}\n", 0);
	printf(		"{test%1.d}\n", 0);
	return (0);
}
