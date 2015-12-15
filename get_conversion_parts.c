/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion_parts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 13:27:20 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/15 13:42:35 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*get_flags(char *str)
{
	int		i;

	i = 0;
	while (str[i] == '#' || str[i] == '0' || str[i] == '-' || str[i] == '+')
		i++;
	return (ft_strsub(str, str, i));
}

char			*get_width(char *str)
{
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9');
		i++;
	return (ft_strsub(str, str, i));
}

char			*get_precision(char *str)
{
	int		i;

	i = 0;
	if (*str == '.')
		i++;
	while (i > 0 && str[i] >= '0' && str[i] <= '9');
		i++;
	return (ft_strsub(str, str, i));
}

char	get_conversion(char *str)
{
	char	conversion_chars[15];

	conversion_chars = "sSpdDioOuUxXcC";
	if (ft_strchr(conversion_chars, *str) != NULL)
		return (*str);
	return (0);
}
