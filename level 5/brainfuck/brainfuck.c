/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:51:54 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/14 10:09:25 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		i;
	int		loop;
	char	*pointer;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	if (!(pointer = malloc(sizeof(char *) * 2049)))
		return (0);
	while (i <= 2048)
		pointer[i++] = '\0';
	i = -1;
	while (argv[1][++i])
	{
		argv[1][i] == '>' ? pointer++ : pointer;
		argv[1][i] == '<' ? pointer-- : pointer;
		argv[1][i] == '+' ? *pointer += 1 : *pointer;
		argv[1][i] == '-' ? *pointer -= 1 : *pointer;
		argv[1][i] == '.' ? write(1, &*pointer, 1) : 0;
		if (argv[1][i] == '[' && !*pointer)
		{
			loop = 1;
			while (loop)
			{
				i++;
				argv[1][i] == '[' ? loop++ : loop;
				argv[1][i] == ']' ? loop-- : loop;
			}
		}
		if (argv[1][i] == ']' && *pointer)
		{
			loop = 1;
			while (loop)
			{
				i-= 1;
				argv[1][i] == ']' ? loop++ : loop;
				argv[1][i] == '[' ? loop-- : loop;
			}
		}
	}
	return (0);
}
