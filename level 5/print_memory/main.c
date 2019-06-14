/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:50:30 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/14 11:56:37 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_memory(const void *addr, size_t size);

int		main()
{
	int	tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};
	int tab2[10] = {10, 123, 34153, 313466, 659785, 13415, 12194, 399456};
	print_memory(tab, sizeof(tab));
	write(1, "\n\n", 2);
	print_memory(tab2, sizeof(tab2));
	return(0);
}
