/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:18:26 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 18:21:17 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_char(char buffer)
{
	if (   buffer  == '0'    || buffer == '1'|| buffer   == 'C'   
		|| buffer   == 'P'   || buffer == 'E'|| buffer == 'N' || buffer  == '\n') // added in order to allow for the condiation to be met while reading 
		return (1);
	else
		return (0);
}

int element_validation(t_map *map)
{
	char 	buffer;
	
	map->fd = open(map->file_name,O_RDONLY);
	while (read(map->fd, &buffer,1))
	{
		if (buffer == 'C')
			map->count_c = map->count_c + 1;
		else if (buffer == 'P')
			map->count_p = map->count_p + 1 ;
		else if (buffer == 'E')
			map->count_e = map->count_e + 1 ;
	}
	close(map->fd);
	if (!(map->count_c > 0 && map->count_p > 0 && map->count_e > 0))
		error_handling(9);
	printf("c count %i\n",map->count_c);
	printf("p count	%i\n",map->count_p);
	printf("e count %i\n",map->count_e);
	return (1);
}

int validtion(t_map *map)
{
	int width;
	int hight;
	int v_width;
	char buff;

	width = 0;
	hight = 1;
	v_width = 0;
	while(read(map->fd2,&buff,1)&& check_char(buff) && buff != '\n')
	{
		width++;
		printf("%c",buff);
	}
	printf("\n");
	while (read(map->fd2,&buff,1) && check_char(buff))
	{
		printf("%c",buff);
		if(buff == '\n')
		{
			hight++;
			if(v_width == width)
				v_width = 0;
			else if (v_width != width)
				error_handling(3);
		}  
		else if (buff != '\n')
			v_width++; 
	}
	hight++;
	ft_in(map,hight,width);
	close(map->fd);
	printf("\nwidth >>  %d\n", width);
	printf("hight >>  %d\n", hight);
	return (width * hight);
}

void fill_map(t_map *map)
{
	int i;
	char buff;
	int fd;
	
	fd = open(map->file_name,O_RDONLY);
	map->map = (char*)malloc(map->size);
	i = 0;
	while(read(map->fd,&buff,1))
	{
		// printf("%c",buff);
		if (buff != '\n')
		{
			map->map[i] = buff;
			i++;
		}
	}
	close(map->fd);
}

// This funcatioon will check border of the map and ensure they are all r walls
int border_validation(t_map *map)
{
	int i;
	int z ;
	
	z = (map->width * (map->hight - 1));
	i = 0;
	while(i < map->width)
	{
		if (map->map[i] == '1' && map->map[z] == '1' )
		{
			i++;
			z++;
		}
		else
			error_handling(4);
	}
	i = 1;
	while (i <=  map->hight)
	{
		if(map->map[i - 1 ] == '1' && map->map[map->width*i-1] == '1')
			i++;
		else
			error_handling(5);
	}
	return (1);
}

void check_cond(char *av)
{
	int i;

	i = 0;
	while(av[i++])
	{
		printf("reached\n");
		while (av[i] != '.')
			i++;
		if (av[i]== '.')
		{
			if (av[i + 1] == 'b' && av[i+ 2] == 'e' && av[i+ 3] == 'r' )
				return;
			error_handling(10);
		}	
	}
	error_handling(10);
}

void vaild(char *av, t_map *map)
{
	check_cond(av);
	printf("%s\n",map->file_name);
	map->fd = open(av,O_RDONLY);
	if (!(map->fd))
		error_handling1(8,-1,NULL);
	element_validation(map);
	if (validtion(map) < 0)
		error_handling1(11,map->fd2,NULL);
	map->fd3 = map->fd;
	fill_map(map);
	if (border_validation(map) != 1)
		error_handling(3);
	check_box(map,locate_p(map));
	if (!(map->valid == 1) || map->collect_path != map->count_c)
		error_handling(8);
}