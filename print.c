/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:54:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 11:44:15 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_map *m)
{
    int j;
    int i;

    i = 0; // width counter 
    j = 1; // hight counter 
    
    while(i < m->size)
    {
        if(m->width * j == i) // loop untill it reach the last char on the line 
        {
            printf("\n");  // start new line 
            //color(m->map[i]);
            printf("%c",m->map[i]); // start printing 
            j++;
        }
        else
            printf("%c",m->map[i]);
        i++;
    }
}

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
