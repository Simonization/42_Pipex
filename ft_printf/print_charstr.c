/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_charstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:17:33 by slangero          #+#    #+#             */
/*   Updated: 2024/09/20 17:56:00 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	ssize_t	result;

	result = write (1, &c, 1);
	if (result == -1)
		return (-1);
	return (1);
}

int	print_str(char *s)
{
	int		i;
	ssize_t	result;

	i = 0;
	if (!s)
	{
		result = write (1, "(null)", 6);
		if (result == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		result = write (1, &s[i], 1);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}
