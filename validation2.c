/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:56:00 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 08:23:02 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill_map(t_map *map)
{
    int i;
    char buff;
    
	printf("reached\n");
    map->map = (char*)malloc(map->size);
    i = 0;
	while(read(map->fd2,&buff,1) > 0  && buff != '\0')
    {
		printf("reached2\n");
        printf("%c",buff);
        if (buff != '\n')
        {
            map->map[i] = buff;
            i++;
        }
    }
    close(map->fd2);
}


