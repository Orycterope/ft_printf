/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conversion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:17:17 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/15 16:53:09 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CONVERSION_H
# define READ_CONVERSION_H
# include "ft_printf.h"

typedef struct	s_conversion
{
	char		*flags;		//	optionnel   : #0-+
	char		*width;		//	optionnel   : [0-9]*
	char		*precision;	//	optionnel   : .[0-9]*
	char		*modifier;	//	optionnel   : hh h l ll j z
	char		conversion;	//	obligatoire : sSpdDioOuUxXcC
	int			lenght;		//	longeur de la chaine du format
}				t_conversion;

t_conversion	save_conversion_format(char **str);
void			free_conversion_format(t_conversion conv);

#endif