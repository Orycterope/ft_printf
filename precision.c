/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 18:57:09 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/29 20:10:21 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "precision.h"

char		*process_precision(char *str, t_conversion *conv)
{
	char	*out;
	char	length;

	out = str;
	length = ft_atoi(conv->precision);
	return (out);
}
