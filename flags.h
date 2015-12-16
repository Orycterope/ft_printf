/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 19:04:25 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/16 19:15:11 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPERS_H
# define WRAPPERS_H
# include "printf.h"
# include "libft.h"
# include "get_conversion_parts.h"

char	*process_flags(char *str, t_conversion *conv);

#endif
