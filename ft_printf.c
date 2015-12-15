/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:27:43 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/15 19:06:01 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_next_precent_position(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '%' && str[i + 1] != '%')
		i++;
	return (i);
}

static char	*process_conversion(char *str, va_list args, int *length, char **end)
{
	char	*remove_me;

	remove_me = ft_strdup("VWXYZ");
	*length += 2;
	*end += ft_strlen(remove_me);

	return (remove_me);
}


static char	*replace_conversion(const char *str, va_list args)
{
	char	*s1;
	char	*s2;
	char	*old;
	char	*insert;
	int		i;

	s1 = ft_strdup(str);
	i = get_next_precent_position(s1);
	while (s1[i] != '\0')
	{
		old = s1;
		s2 = &s1[i];
		*s2 = '\0';
		insert = process_conversion(&s1[i], args, &i, &s2);
		s1 = ft_strjoin(old, insert);
		free(insert);
		free(old);
		old = s1;
		s1 = ft_strjoin(old, s2);
		i += get_next_precent_position(&s1[i]);
		free(old);
	}
	return (s1);
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	char	*final;
	int		count;

	va_start(args, format);
	final = replace_conversion(format, args);
	count = ft_strlen(final);
	ft_putstr(final);
	free(final);
	va_end(args);
	return (count);
}
