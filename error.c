/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:16:22 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 00:09:03 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_handling(int i)
{
	if (i == 1)
		ft_putstr_fd("Map is invalid : Missing one of the required element \n", 1);
	else if (i == 2)
		ft_putstr_fd("Map invalid\n", 1);
	else if (i == 3)
		ft_putstr_fd("Map is invalid : dimension\n",1);
	else if (i == 4)
		ft_putstr_fd("Map is invalid :issue with FD\n",1);
	exit(0);
}