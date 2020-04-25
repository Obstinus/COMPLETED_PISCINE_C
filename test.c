/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>					/* Подкоючаем библиотеку содержащую функцию для вывода символов(write) */
#include <stdlib.h>					/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) функцию для подсчета размера переменной(sizeof) */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putchar(char c)		/* функция вывода символа */
{
	write(1, &c, 1);
}

/*#############################################################################*/

void	ft_putstr(char *str)   	/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/*#############################################################################*/

int		ft_is_space(char c)
{
	if((c == ' ' || c == '\t' || c == '\n'))
		return (1);
	return(0);
}

int		ft_wordcount(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (!(ft_is_space(str[i])))
			words++;
		while (ft_is_space(str[i + 1]) && !(ft_is_space(str[i])))
			i++;
		i++;
	}
	return (words);
}

int		ft_wordlen(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (ft_is_space(str[i]))
		i++;
	while (str[i] && !(ft_is_space(str[i++])))
		len++;
	return (len);
}

char		**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	i = 0;
	k = 0;
	if (!str || (((arr = (char **)malloc(sizeof(char*) * (ft_wordcount(str) + 1)))) == ((void *)0)))
		return ((void*)0);
	while (i < ft_wordcount(str))
	{
		if ((arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(&str[k]) + 1))) == ((void *)0))
			return ((void*)0);
		j = 0;
		while (ft_is_space(str[k]))
			k++;
		while (str[k] && !(ft_is_space(str[k])))
			arr[i][j++] = str[k++];
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = ((void*)0);
	return (arr);
}



int     main(void)				/* Основаная функция */
{
	int i;
	int j;
	char **arr_str;

	i = 0;
	if ((arr_str = ft_split_whitespaces(" sebas  sdfds s sdf sdf chapuis wuid ")) == ((void *)0)) /* Запускам функцию нахождения в строке отдельных слов и разбрасываем ихв отдельные строки */
		return (0);
	while(i < 7)				/* Печатаем каждую строку массива со строками */
	{
		j = 0;
		while(arr_str[i][j])
		{
			ft_putchar(arr_str[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);					/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}