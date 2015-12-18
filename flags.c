/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 19:04:36 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/18 19:22:25 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

static char *get_left_part(char *str)
{
	char	*left_part;
	int		i;

	left_part = ft_strdup(str);
	i = 0;
	while (str[i] == '0' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == '+' || str[i] == '-' || str[i] == ' ')
		i++;
	left_part[i] = '\0';
	return (left_part);
}

static char	*sign_wrapper(char *str, t_conversion *conv)
{
	char	*out;

	out = str;
	if (*str != '-')
	{
		if (ft_strchr(conv->flags, '+') != NULL)
			out = ft_strjoin("+", str);
		else if (ft_strchr(conv->flags, ' ') != NULL)
			out = ft_strjoin(" ", str);
		free(str);
	}
	return (out);
}

static char	*minus_wrapper(char	*str, t_conversion *conv)
{
	size_t	length;
	char	*out;
	char	*old;

	out = str;
	length = ft_atoi(conv->width);
	if (length > 0)
		while (ft_strlen(out) < length)
		{
			old = out;
			out = ft_strjoin(old, " ");
			free(old);
		}
	return (out);
}

static char	*zero_wrapper(char *str, t_conversion *conv)
{
	size_t	length;
	char	*out;
	char	*old;
	char	*left_part;

	left_part = get_left_part(str);
	out = ft_strdup(str + ft_strlen(left_part));
	free(str);
	length = ft_atoi(conv->width);
	while (ft_strlen(out) + ft_strlen(left_part) < length && *(conv->precision) == 0)
	{
			old = out;
			out = ft_strjoin("0", old);
			free(old);
	}
	old = out;
	out = ft_strjoin(left_part, old);
	free(old);
	free(left_part);
	return (out);
}

static char	*hash_wrapper(char *str, t_conversion *conv)
{
	char	*out;

	out = str;
	if (conv->conversion == 'o')
	{
		out = ft_strjoin("0", str);
		free(str);
	}
	else if (conv->conversion == 'x')
	{
		out = ft_strjoin("0x", str);
		free(str);
	}
	else if (conv->conversion == 'X')
	{
		out = ft_strjoin("0X", str);
		free(str);
	}
	return (out);
}

char		*process_flags(char *str, t_conversion *conv)
{
	char	*out;

	out = str;
	if (ft_strchr(conv->flags, '+') != NULL
			|| ft_strchr(conv->flags, ' ') != NULL)
		out = sign_wrapper(out, conv);
	if (ft_strchr(conv->flags, '-') != NULL)
		out = minus_wrapper(out, conv);
	else if (ft_strchr(conv->flags, '0') != NULL)
		out = zero_wrapper(out, conv);
	if (ft_strchr(conv->flags, '#') != NULL
			&& ft_strchr(conv->flags, '0') != NULL)
		out = hash_wrapper(out, conv);
	return (out);
}
