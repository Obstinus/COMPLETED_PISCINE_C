/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:03:30 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 10:06:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : hello
Expected files   : hello.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays "Hello World!" followed by a \n.
Напишите программу, которая отображает «Hello World!» сопровождаемый \ n.

Example:
Пример:

$>./hello
Hello World!
$>./hello | cat -e
Hello World!$
$>


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

int		main(void)
{
	write(1, "Hello World!\n", 13);
	return (0);
}
