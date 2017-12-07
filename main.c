/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezanni <abezanni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:01:30 by abezanni          #+#    #+#             */
/*   Updated: 2017/12/07 16:20:54 by abezanni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	int test[1] = {12};
	char *mystring = "ca";

	printf("%d\n", ft_printf("test%-6s", mystring));
	printf("test%-6s", mystring);
	return (0);
}
