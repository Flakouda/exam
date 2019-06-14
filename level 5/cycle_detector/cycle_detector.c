/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:10:12 by floakoud          #+#    #+#             */
/*   Updated: 2019/06/14 10:12:45 by floakoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		cycle_detector(const t_list *list)
{
	const t_list	*tortue;
	const t_list	*lapin;

	tortue = list;
	lapin = list;
	if (lapin == NULL)
		return (1);
	while (1)
	{
		tortue = tortue->next;
		if (lapin->next)
			lapin = lapin->next;
		else
			return (0);
		if (tortue == NULL || lapin == NULL)
			return (0);
		if (tortue == lapin)
			return (1);
	}
}
