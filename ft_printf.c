/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:27:43 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/28 16:37:58 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_next_precent_position(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (str[i] != '%' ||
			(str[i] == '%' && (str[i + 1] == '%' || str[i - 1] == '%'))))
		i++;
	return (i);
}

static char	*process_conversion(char *str, va_list args, int *length, char **end)
{
	/* Dummy function */

	char			*remove_me;
	long long		argument;
	t_conversion	*conv;

	conv = save_conversion_format(str);
	if (conv == NULL)
	{
		*length += 1;
		return (NULL);
	}
	argument = get_arg(args, conv);
	remove_me = get_converted_string(argument, conv);
	resolve_alias(conv);
	remove_me = process_flags(remove_me, conv);
	**end = '\0';
	*length += ft_strlen(remove_me);
	*end += conv->length;
	return (remove_me);
}


static void replace_conversion(char **str, va_list args)
{
	char	*s2;
	char	*old1;
	char	*old2;
	char	*insert;
	int		i;

	*str = ft_strdup(*str);
	i = get_next_precent_position(*str);
	while ((*str)[i] != '\0')
	{
		old1 = *str;
		s2 = &((*str)[i]);
		insert = process_conversion(s2, args, &i, &s2);
		if (insert != NULL)
		{
			old2 = ft_strjoin(*str, insert);
			free(insert);
			*str = ft_strjoin(old2, s2);
			free(old1);
			free(old2);
			i += get_next_precent_position(&((*str)[i]));
		}
	}
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	int		count;

	va_start(args, format);
	replace_conversion((char **)&format, args);
	count = ft_strlen(format);
	ft_putstr(format);
	free((void*)format);
	va_end(args);
	return (count);
}
