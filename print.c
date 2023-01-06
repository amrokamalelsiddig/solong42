/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:54:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 10:30:16 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char	*s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nb;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-1 * n, fd);
	}
	else if (n >= 0 && n < 10)
	{
		nb = n + 48;
		ft_putchar_fd(nb, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	check_cond(char *av)
{
	int	i;

	i = 0;
	while (av[i++])
	{
		while (av[i] != '.')
			i++;
		if (av[i] == '.')
		{
			if (av[i + 1] == 'b' && av[i + 2] == 'e' && av[i + 3] == 'r' )
				return ;
			error_handling(10);
		}	
	}
	error_handling(10);
}

void	fill_map(t_map *map)
{
	char	buff;
	int		i;
	int		fd;

	fd = open(map->file_name, O_RDONLY);
	map->map = (char *)malloc (map->size);
	map->map_2 = (char *)malloc(map->size);
	i = 0;
	while (read(map->fd, &buff, 1))
	{
		if (buff != '\n')
		{
			map->map[i] = buff;
			map->map_2[i] = buff;
			i++;
		}
	}
	map->map[i] = '\0';
	map->map_2[i] = '\0';
	close(fd);
}
