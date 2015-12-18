/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conversion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:17:17 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/18 15:53:38 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_CONVERSION_H
# define READ_CONVERSION_H

typedef struct	s_conversion
{
	char		*flags;		//	optionnel   : #0-+
	char		*width;		//	optionnel   : [0-9]*
	char		*precision;	//	optionnel   : .[0-9]*
	char		*modifier;	//	optionnel   : hh h l ll j z
	char		conversion;	//	obligatoire : sSpdDioOuUxXcC
	int			length;		//	longeur de la chaine du format
}				t_conversion;

t_conversion	*save_conversion_format(char *str);
void			free_conversion_format(t_conversion *conv);

# include "get_conversion_parts.h"
#endif
