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
# include "ft_printf.h"
# include <limits.h>

char	*get_converted_string(long long arg, t_conversion *conv);

#endif
