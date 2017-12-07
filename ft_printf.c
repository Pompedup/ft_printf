/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:35:43 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/07 16:19:58 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//write malloc free exit

#include "ft_printf.h"

void	ft_strjoinf(t_printf *dt, const char *s2)
{
	int	i;

	if (!s2)
		return ;
	i = -1;
	while (s2[++i])
		dt->buf[dt->pos_b++] = s2[i];
}

int		ft_printf(char *str, ...)
{
	t_printf	dt;

	dt.str = str;
	dt.pos_s = 0;
	dt.tot = 0;
	dt.pos_b = 0;
	va_start(dt.ap, str);
	while (str[dt.pos_s])
	{

		if (dt.str[dt.pos_s] != '%')
			dt.buf[dt.pos_b++] = dt.str[dt.pos_s++];
		else
		{
			dt.pos_s++;
			ft_nbr_percent(&dt);
		}
	}
	ft_putstr(dt.buf);
	va_end(dt.ap);
	return (dt.tot);
}

void	ft_nbr_percent(t_printf *dt)
{
	int aff;
	char *tmp;

	printf("test:%c\n",dt->str[dt->pos_s]);
	if (dt->str[dt->pos_s++] == '-')
	{
		while (dt->str[dt->pos_s] == '+' || dt->str[dt->pos_s] == '-')
			dt->pos_s++;
		aff = ft_atoif(dt);
		printf("%d\n", aff);
		tmp = ft_apply_percent(dt);
		ft_strjoinf(dt, tmp);
		printf("%s\n", tmp);
		aff -= ft_strlen(tmp);
		while (aff > 0 && aff--)
			dt->buf[dt->pos_b++] = ' ';
	}
	else if (ft_isdigit(dt->str[dt->pos_s++]))
	{
		aff = ft_atoif(dt);
		while (aff--)
			ft_putchar(' ');
	}
	else
		ft_apply_percent(dt);
}

char	*ft_apply_percent(t_printf *dt)
{
	if (dt->str[dt->pos_s++]== 's')
		return(va_arg(dt->ap, char*));
	else if (dt->str[dt->pos_s++] == 'S')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'p')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'd')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'D')
		ft_putnbr(*(va_arg(dt->ap, int*)));
	else if (dt->str[dt->pos_s++] == 'i')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'o')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'O')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'u')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'U')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'x')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'X')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'c')
		ft_putchar(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == 'C')
		ft_putnbr(va_arg(dt->ap, int));
	else if (dt->str[dt->pos_s++] == '%')
		ft_putchar('%');
	return 0;
}




void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putnbr(-(n / 10));
			ft_putchar('8');
		}
		else
			ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putstr(char const *s)
{
	int i;

	i = -1;
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoif(t_printf *dt)
{
	int deb;
	int signe;
	int back;

	signe = 1;
	back = 0;
	while (ft_isspace(dt->str[dt->pos_s]))
		dt->pos_s++;
	if (dt->str[dt->pos_s] == '+')
		dt->pos_s++;
	else if (dt->str[dt->pos_s] == '-')
	{
		signe = -1;
		dt->pos_s++;
	}
	deb = dt->pos_s;
	while (48 <= dt->str[dt->pos_s] && dt->str[dt->pos_s] <= 57)
		back = back * 10 + dt->str[dt->pos_s++] - 48;
	if (dt->pos_s - deb > 18)
		return (signe == 1 ? -1 : 0);
	return (back * signe);
}

int	ft_isspace(int c)
{
	return (c == 32 || (8 < c && c < 14));
}

int	ft_nbr_len(int n)
{
	int back;

	back = 0;
	if (n < 0)
		back++;
	while (n)
	{
		n /= 10;
		back++;
	}
	return (back);
}
