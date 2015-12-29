/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 19:02:28 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/29 22:10:13 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

static char	*convert_decimals(long long arg, t_conversion *conv)
{
	char	op;

	op = conv->conversion;
	if (op == 'd' || op == 'i' || op == 'D')
		return (itoa(arg));
	else if (op == 'u' || op == 'U')
		return (itoa_base(arg, "0123456789"));
	else if (op == 'o' || op == 'O')
		return (itoa_base(arg, "01234567"));
	else if (op == 'x')
		return (itoa_base(arg, "0123456789abcdef"));
	else if (op == 'X')
		return (itoa_base(arg, "0123456789ABCDEF"));
	ft_putendl("erreur de conversion decimal"); //
	return (NULL);
}

static char *convert_chars(long long arg, t_conversion *conv)
{
	char	*out;
	size_t	length;

	length = 1;
	if (conv->conversion == 'C')
		length = 4; //2 ?
	out = ft_strnew(length + 1);
	ft_memcpy(out, &arg, length);
	return (out);
}

static char	*convert_strings(long long arg, t_conversion *conv)
{
	char	op;

	op = conv->conversion;
	if (op == 's')
	{
		if ((char *)arg == NULL)
			return (ft_strdup("(null)"));
		return (ft_strdup((char *)arg));
	}
	ft_putendl("erreur de conversion string"); //
	return (NULL);
}

char		*get_converted_string(long long arg, t_conversion *conv)
{
	if (ft_strchr("dDioOuUxX", conv->conversion) != NULL)
		return (convert_decimals(arg, conv));
	else if (ft_strchr("s", conv->conversion) != NULL)
		return (convert_strings(arg, conv));
	else if (ft_strchr("cC", conv->conversion) != NULL)
		return (convert_chars(arg, conv));
	ft_putendl("format non prit en charge"); //
	return (NULL);
}
