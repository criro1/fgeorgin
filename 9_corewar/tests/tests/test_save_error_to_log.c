/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:05:42 by wmaykit           #+#    #+#             */
/*   Updated: 2020/01/12 14:51:34 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(void)
{
	errno = 10;
	save_error_to_log("Test1", "Test1");
	save_error_to_log(NULL, "Test2");
	save_error_to_log("Test3", NULL);
	save_error_to_log(NULL, NULL);
	return (0);
}
