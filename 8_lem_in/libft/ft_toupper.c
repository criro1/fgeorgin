/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:09:45 by fgeorgin          #+#    #+#             */
/*   Updated: 2019/07/08 17:41:53 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int b)
{
	if (b >= 97 && b <= 122)
		return (b - 32);
	else
		return (b);
}