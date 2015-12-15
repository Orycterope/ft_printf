/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:27:43 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/15 11:26:51 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list arg;
	char	*s;

	va_start(arg, format);
	s = va_arg(arg, char *);
	ft_putstr(s);
	va_end(arg);
	return (0);
}
