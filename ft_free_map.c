/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:00:11 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/07 02:09:46 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		(free(tab[i]), ++i);
	free(tab);
}

void	ft_free_map(char ***map)
{
	size_t	i;

	i = 0;
	while (map[i])
		(ft_free_tab(map[i]), ++i);
	free(map);
}
