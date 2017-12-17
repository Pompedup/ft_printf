#include <stdio.h>
#include <limits.h>

/*
static int ft_nbr_len_base(long long n, int base)
{
	int back;

	back = 0;
	if (n == 0)
		back++;
	while (n)
	{
		n /= base;
		back++;
	}
	return (back);
}

static void	ft_rec_htoa(char *back, long long n, int i)
{
	if (n)
	{
		if (n % 16 > 9)
			back[i] = n % 16 + 87;
		else
			back[i] = n % 16 + 48;
		ft_rec_htoa(back, n / 16, --i);
	}
}

char	*ft_hmaxtoa(long long n)
{
	char *back;
	int len;

	len = ft_nbr_len_base(n, 16);
	if (!(back = (char*)malloc(len + 1)))
		return (0);
	back[len] = 0;
	ft_rec_htoa(back, n, --len);
	return (back);
}*/
/*
int	maiin()
{
	unsigned char c;

	c = 0;
	long long oui = LONG_MAX + 1;
	char r = 12;
	printf("%d\n", c);
	c += 1 << 4;
	printf("%d\n", c);
	if (c ^ 16)
	c += 1 << 4;
	printf("%d\n", c);
	printf("%lhhd", r);
	//printf("0x%s\n%p\n", ft_hmaxtoa(c), c);
	//printf("%hhhd", (long long)5);
	return (0);
}
*//*
h 1
hh 2
l 4
ll 8
j 16
z 32*/
