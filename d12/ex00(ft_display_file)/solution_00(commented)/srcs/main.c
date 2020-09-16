/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

int		main(int argc, char **argv)	/* Принимаем количество аргументов и адресс массва строк с аргументами программы */
{
	ft_display_file(argc, argv);	/* Запускаем функцию печатающую содержимого одного файла, на который указывают аргументы
									** в массиве строк '**argv', отправляя в функцию размер массива строк и его адресс */
	return (0);						/* Завершаем главную функцию и возвращаем ноль, в знак того что все прошло успешно */
}