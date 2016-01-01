/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 19:02:38 by tvermeil          #+#    #+#             */
/*   Updated: 2015/12/18 19:02:46 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECIMALS_H
# define DECIMALS_H
# include "libft.h"
# include "utf.h"
# include "ft_printf.h"

char	*get_converted_string(long long arg, t_conversion *conv);
char	*process_conversion(char *str, va_list args, int *length, char **end);

#endif
