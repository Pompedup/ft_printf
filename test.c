#include <stdio.h>
#include <stdarg.h>

/* print all args one at a time until a negative argument is seen;
   all args are assumed to be of int type */
void printargs(int arg1, ...)
{
	va_list ap;
	char *test;
	int i;

	va_start(ap, arg1);
	for (i = arg1; i >= 0; i = va_arg(ap, int))
		printf("%d ", i);
	test = va_arg(ap, char*);
	printf("%s", test);
	va_end(ap);
	putchar('\n');
}

int main(void)
{
	int test[4] = {12, 12 , 12, 42};
	printf("%-+--6d", 192);
  // printargs(5, 2, 14, 84, 97, 15, -1, "test", 48, -1);
 //  printargs(84, 51, -1);
   //printargs(-1);
   //printargs(1, -1);
   return 0;
}
