/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 19:58:54 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/28 16:39:11 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.h"

void	resolve_alias(t_conversion *conv)
{
	char	*newflags;

	if (conv == NULL)
		return;
	if (ft_strchr("DOUCS", conv->conversion) != NULL)
	{
		free(conv->modifier);
		conv->modifier = ft_strdup("l");
		conv->conversion = ft_tolower(conv->conversion);
	}
	else if (conv->conversion == 'p')
	{
		newflags = ft_strjoin(conv->flags, "#");
		free(conv->flags);
		conv->flags = newflags;
		free(conv->modifier);
		conv->modifier = ft_strdup("l");
		conv->conversion = 'x';
	}
}
