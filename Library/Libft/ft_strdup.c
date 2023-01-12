/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelro <miguelro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:05:37 by miguelro          #+#    #+#             */
/*   Updated: 2022/10/26 18:17:26 by miguelro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = (char *)malloc(ft_strlen(string) + 1);
	if (!newstr)
		return (NULL);
	while (string[i] != 0)
	{
		newstr[i] = string[i];
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
