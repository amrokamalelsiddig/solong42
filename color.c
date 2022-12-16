/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:51:29 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/09/11 18:55:22 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void yellow()
{
  printf("\033[1;33m");
}

void red()
{
    printf("\033[1;31m");
}

void reset()
{
    printf("\033[0m");
}

void Green()
{
    printf("\033[0;32m");
}

void Black()
{    
    printf("\033[0;30m");
}
void Cyan()
{
    printf("\033[0;36m");
}
    