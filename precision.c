/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 18:57:09 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/29 20:51:35 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precision.h"

char		*process_precision(char *str, t_conversion *conv)
{
	char	*out;
	char	*old;
	size_t	precision;

	out = str;
	if (*(conv->precision++) == '.')
	{
		precision = ft_atoi(conv->precision);
		if (ft_strchr("diouxX", conv->conversion) != NULL)
			out = zero_wrapper(out, precision);
		else if (conv->conversion == 's')
		{
			old = out;
			out = ft_strsub(out, 0, precision);
			free(old);
		}
	}
	return (out);
}
