/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:35:05 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/09 21:24:32 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)
		{
			is_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*create_word(char const *start, int len)
{
	char	*word;
	char	*w;

	word = (char *)malloc((len +1) * sizeof(char));
	if (!word)
		return (NULL);
	w = word;
	while (*start && len > 0)
	{
		*word++ = *start++;
		len--;
	}
	*word = '\0';
	return (w);
}

static void	fill_words(char **words, char const *s, char c)
{
	int	word_index;
	int	start;
	int	end;

	word_index = 0;
	start = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] == c || s[end + 1] == '\0')
		{
			if (s[end] != c && s[end + 1] == '\0')
				end++;
			if (end > start && word_index < count_words(s, c))
			{
				words[word_index] = create_word(s + start, end - start);
				word_index++;
			}
			start = end + 1;
		}
		end++;
	}
	words[word_index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;

	word_count = 0;
	if (*s == '\0')
	{
		result = (char **)malloc((word_count + 1) * sizeof(char *));
		if (!result)
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	fill_words(result, s, c);
	return (result);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
/*
#include <stdio.h>
int main() {
    char *s = "hola mundo de mier";
    char c = ' ';
    char **result;
    int i;

    result = ft_split(s, c);

    if (result == NULL) 
    {
        printf("Error: no se pudo dividir la cadena.\n");
        return 1;
    }

    if (result[0] == NULL)
        printf("Palabras encontradas: %s\n", result[0]);
    else 
    {
        printf("Palabras encontradas:\n");
        i = 0;
        while (result[i] != NULL)
        {
            printf("%s\n", result[i]);
            i++;
        }
    }

    // Libera la memoria para cada palabra y luego para el arreglo result
    //i = 0;
    //while (result[i] != NULL)
    //{
    //    free(result[i]);
    //    i++;
    //}
    //free(result);
    free_split(result);

    return 0;
}
*/
