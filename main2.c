# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int main()
{
	if (write(14, "", 0) != -1)
		printf("c nul\n");
	return (0);
}
