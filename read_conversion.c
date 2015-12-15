/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:41:44 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/15 15:21:33 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_conversion.h"
/*
** Fonction qui prend un pointeur sur une chaine de caracteres
** Retourn une structure conversion qui contient les parties
** du format de conversion
*/

t_conversion	save_conversion_format(char *str)
{
	t_conversion	conv;
	int				i;

	i = 0;
	if (str[i++] != '%')
		return (NULL);
	conv.flags = get_flags(&str[i]);
	i += ft_strlen(conv.flags);
	conv.width = get_width(&str[i]);
	i += ft_strlen(conv.width);
	conv.precision = get_precision(&str[i]);
	i += ft_strlen(conv.precision);
	conv.modifier = get_modifier(&str[i]);
	i += ft_strlen(conv.modifier);
	conv.conversion = get_conversion(&str[i]);
	if (conv.conversion == NULL)
	{
		free_conversion_format(conv);
		return (NULL);
	}
	i++;
	conv.length = i;
	return (conv);
}

void			free_conversion_format(t_conversion conv)
{
	free(conv.flags);
	free(conv.width);
	free(conv.precision);
	free(conversion.modifier);
}