/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:49:49 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 07:59:15 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**	read bed file and check if only char specified are existed
**
** @param	file name
** @return	1 true / 0 false
*/

int check_char(int fd)
{
	char buffer;

	while (read(fd, &buffer, 1) > 0 && buffer != '\0')
	{
		if (!(buffer == '0' || buffer == '1' || buffer == 'C' || buffer == 'P' || buffer == 'E' || buffer == 'N' || buffer == '\n'))
			return (0);
	}
	return (1);
}

/*
**	check file ext and verifiy if its .ber
**
** @param	file name
** @return	1 true / 0 false
*/

int file_ext(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] != '.')
			i++;
		if (str[i])
		{
			if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

/*
**	check the map has all the required element
**
** @param	struct
** @return	1 true / 0 false
*/

int count_validation(t_map *map)
{
	char buffer;

	while (read(map->fd, &buffer, 1))
	{
		printf("%c", buffer);
		if (buffer == 'C')
			map->c_collect++;
		else if (buffer == 'P')
			map->c_player++;
		else if (buffer == 'E')
			map->c_exit++;
	}
	printf("%d\n", map->c_enemy);
	printf("%d\n", map->c_exit);
	printf("%d\n", map->c_player);
	if (map->c_collect > 0 && map->c_player > 0 && map->c_exit > 0)
		return (1);
	error_handling(1);
	return (0);
}


int dimension(t_map* map)
{
    int     width;
    int     hight;
    int     v_width;
    char    buff;

    width   = 0;
    hight   = 1;
    v_width = 0;
    while(read(map->fd,&buff,1)&& check_char(buff) && buff != '\n')
        width++;
    while (read(map->fd,&buff,1) && check_char(buff))
    {
        if(buff == '\n')
        {
            hight++;
            if (v_width == width)
                v_width = 0;
            else if (v_width != width)
            {
                printf("v_w : %d\n",v_width);
                printf("v_w : %d\n",width);
                // error_handling(3);
            }
        }  
        else if (buff != '\n')
            v_width++; 
    }
    hight++;
	printf("hight is : %d\n",hight);
	printf("width is :%d\n",width);
	in_dimension(map,hight, width);
    close(map->fd);
	ft_putstr_fd("Dimension are valid\n",1);
    return (1);
}




// int main(int ac, char **av)
// {
// 	t_map map;
// 	int i = 0;
// 	map.fd = open(av[1], O_RDONLY);
// 	// ft_init(&map);
// 	dimension(&map);
// 	// if (file_ext(av[1]) == 1)
// 	// 	printf("%s", "valid\n");
// 	// printf("%d", validation(&map, av[i]));
// 	// printf("%d\n", file_ext("amro.ber"));
// 	return 0;
// }