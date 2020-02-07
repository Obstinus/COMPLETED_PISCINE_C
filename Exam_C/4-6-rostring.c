/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <jaleman@student.42.us.org>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:06:43 by exam              #+#    #+#             */
/*   Updated: 2016/12/06 10:41:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.
Напишите программу, которая берет строку и отображает эту строку после поворота ее на одно слово влево.

Thus, the first word becomes the last, and others stay in the same order.
Таким образом, первое слово становится последним, а остальные остаются в том же порядке.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
«Слово» определяется как часть строки, разделенная пробелами / табуляцией или началом / концом строки.

Words will be separated by only one space in the output.
Слова будут разделены только одним пробелом в выводе.

If there's less than one argument, the program displays \n.
Если аргументов меньше одного, программа отображает \ n.

Example:
Пример:


$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring | cat -e
$
$>


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		k;

	if (argc > 1)
	{
		i = 0;
		j = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i += 1;
		k = i;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			i += 1;
		while (argv[1][i])
		{
			if (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t') \
				&& (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t'))
			{
				while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
					write(1, &argv[1][i++], 1);
				write(1, " ", 1);
			}
			i += 1;
		}
		while (argv[1][k] && (argv[1][k] != ' ' && argv[1][k] != '\t'))
			write(1, &argv[1][k++], 1);
	}
	write(1, "\n", 1);
	return (0);
}