/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 10:30:55 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/28 16:37:15 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"
# include "read_conversion.h"
# include "flags.h"
# include "itoa_base.h"
# include "itoa.h"
# include "converter.h"
# include "cast.h"
# include "alias.h"

int		ft_printf(const char *format, ...);

#endif
