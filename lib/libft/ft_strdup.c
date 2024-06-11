/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/11/01 14:36:34 by agaougao          #+#    #+#             */
/*   Updated: 2024/04/23 18:01:11 by agaougao         ###   ########.fr       */
=======
/*   Created: 2023/10/31 18:32:19 by hmouhib           #+#    #+#             */
/*   Updated: 2024/05/23 01:47:27 by hmouhib          ###   ########.fr       */
>>>>>>> parse
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	copy = (char *)malloc(ft_strlen(s1) + 1);
	ft_bzero((void *)copy, (ft_strlen(s1) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
