/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
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



#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		ft_putchar(char c)
{
	write(1, &c, 1);

	return (0);
}

void	ft_putstr(char *str)		
{
	int	i;						

	i = 0;						
	while (str[i] != '\0')		
	{
		ft_putchar(str[i]);		
		i++;					
	}
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}


int 	main(void)
{
   // Сравниваемые строки
   char str1[] = {"1234567890"};
   char str2[] = {"1234467890"};
  
   // Сравниваем первые пять символов двух строк
   if (ft_strncmp(str1, str2, 5) == 0)
      ft_putstr("Первые пять символов строк идентичны");
   else
      ft_putstr("Первые пять символов строк отличаются");

   return (0);
}

