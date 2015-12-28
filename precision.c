/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 18:57:09 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/28 19:00:46 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precision.h"

char	*space_wrapper(char	*str, size_t length)
{
	char	*out;
	char	*old;

	out = str;
	if (length > 0)
		while (ft_strlen(out) < length)
		{
			old = out;
			out = ft_strjoin(" ", old);
			free(old);
		}
	return (out);
}
