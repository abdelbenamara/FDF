/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:40:17 by abenamar          #+#    #+#             */
/*   Updated: 2023/07/21 19:40:36 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		(free(tab[i]), ++i);
	free(tab);
}
