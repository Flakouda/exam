/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:18:18 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/14 11:12:25 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		octet[26];
	int		i;
	int		n;
	int		j;
	int		l;

	if (argc < 2)
	{
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
		return (0);
	}
	j = 0;
	l = 6;
	i = -1;
	while (++i != 26)
		octet[i] = 0;
	while (argv[++j])
	{
		i = 0;
		if (argv[j][i] == '-')
		{
			n = 0;
			if (argv[j][0] == '-' && argv[j][1] == 'h')
			{
				ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
				return (0);
			}
			while (argv[j][++n])
				if (argv[j][n] < 97 || argv[j][n] > 122)
				{
					ft_putstr("Invalid Option\n");
					return (0);
				}
			while (argv[j][++i])
				octet[122 - argv[j][i]] = 1;
		}
		i = -1;
		write(1, "000000", 6);
		while (++i < 26)
		{
			if (l == 8)
			{
				ft_putchar(' ');
				l = 1;
			}
			else
				l++;
			ft_putchar(octet[i] + 48);
		}
	}
	ft_putchar('\n');
	return (0);
}
