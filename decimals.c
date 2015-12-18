/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:50:36 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/18 18:11:38 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decimals.h"

char	*convert_decimals(long long arg, t_conversion *conv)
{
	if (conv->conversion == 'd')
		return (itoa(arg));
	else if (conv->conversion == 'o')
		return (itoa_base(arg, "01234567"));
	else if (conv->conversion == 'x')
		return (itoa_base(arg, "0123456789abcdef"));
	else if (conv->conversion == 'X')
		return (itoa_base(arg, "0123456789ABCDEF"));
	ft_putendl("erreur de conversion decimal");
	return (NULL);
}
