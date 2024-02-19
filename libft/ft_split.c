/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younghoc <younghoc@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:08:36 by younghoc          #+#    #+#             */
/*   Updated: 2023/10/27 19:58:31 by younghoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_split_word(char const *s, char c)
{
	const size_t	slen = ft_strlen(s);
	size_t			i;
	size_t			count;

	count = 0;
	i = 1;
	while (i < slen)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] != '\0' && s[i - 1] != c)
		count++;
	return (count);
}

static size_t	strlen_delimiter(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	return (len);
}

static char	**free_split(char **strs, size_t i)
{
	while (i > 0)
	{
		free(strs[i]);
		i--;
	}
	free(strs[0]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	const size_t	count_word = count_split_word(s, c);
	char			**result;
	size_t			i;
	size_t			j;
	size_t			wordlen;

	result = ft_calloc((count_word + 1), sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_word)
	{
		while (s[j] == c)
			j++;
		wordlen = strlen_delimiter(&s[j], c);
		result[i] = ft_substr(s, j, wordlen);
		if (result[i] == NULL)
			return (free_split(result, i));
		j += wordlen;
		i++;
	}
	return (result);
}
