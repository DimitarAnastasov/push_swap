/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:35:26 by dianasta          #+#    #+#             */
/*   Updated: 2026/07/30 23:01:26 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*crnt;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	crnt = *lst;
	while (crnt != NULL)
	{
		tmp = crnt->next;
		ft_lstdelone(crnt, del);
		crnt = tmp;
	}
	*lst = NULL;
}
