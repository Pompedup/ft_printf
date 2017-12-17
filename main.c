/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:22:28 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/16 18:22:59 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	char c;
	char *s = "TRTRTR";
	char *b;

	i = 12785;
	c = 'j';
	b = malloc(1);
	/*ft_putnbr(ft_printf("%s", "coucou\ntest\n"));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("%s", "coucou\ntest\n"));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%d\n", 192));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%d\n", 192));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%i\n", 192));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%i\n", 192));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%u\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%u\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%o\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%o\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%x\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%x\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%X\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%X\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%c\n", c));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%c\n", c));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%p\n", b));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%p\n", b));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%+25 p\n", b));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%+25 p\n", b));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%-+25 p\n", b));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%-+25 p\n", b));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%-+25 d\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%-+25 d\n", i));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(ft_printf("\n%sj\n", s));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%sj\n", s));
	ft_putendl("");
	ft_putendl("");*/
	short int test = 429496729656414564;
	ft_putnbr(ft_printf("\n%jx\n", -4294967296));
	ft_putendl("");
	ft_putendl("");
	ft_putnbr(printf("\n%jx\n", -4294967296));
	ft_putendl("");
	ft_putendl("");
	return (0);
}
