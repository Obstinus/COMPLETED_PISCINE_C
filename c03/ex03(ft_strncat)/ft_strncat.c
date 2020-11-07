/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/08 18:04:06 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**
**  - Воспроизведите поведение функции strncat (man strncat).
**
**
**  - Вот как это должно быть обьявлено:
**
**       char	*ft_strncat(char *dest, char *src, int nb);
**
**
** ************************************************************************** **
**
**
**  Аргументы:
**
**  dest – указатель на массив в который будет добавлена строка.
**  src – указатель на массив из которого будет скопирована строка.
**  nb – максимальная длина добавляемой строки.
**
**  Возвращаемое значение:
**
**  Функция возвращает указатель на массив, в который добавлена строка (dest).
**
**  Положительное число – если в первых n символах сравниваемых строк есть отличия и 
** код первого отличающегося символа в строке 's1' больше кода символа на той же позиции 
**  в строке 's2'.
** 
**  Отрицательное число – в первых n символах сравниваемых строк есть отличия и код первого
**  отличающегося символа в строке 's1' меньше кода символа на той же позиции в строке 's2'.
** 
**  Описание:
** 
**  Функция 'strncat' добавляет в строку, на которую указывает аргумент 'dest', строку,
**  на которую указывает аргумент 'src', пока не встретится символ конца строки или
**  пока не будет добавлено 'n' символов.
**
**  Символ конца строки помещается в конце объединенных строк.
**  
**  Если строки перекрываются, результат объединения будет не определен.
**
** 
** 
** ************************************************************************** **
**
**
** Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
**
** ************************************************************************** */
/* ************************************************************************** */



char	*ft_strncat(char *dest, char *src, int nb)
{
	int	i;
	int	dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	while (i < nb && src[i] != '\0')
	{
		dest[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}



/* ************************************************************************** */
/* ************************************************************************** */



char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int lenght;

	i = 0;
	lenght = 0;
	while (dest[lenght] != '\0')
		lenght++;
	while (i < nb && src[i] != '\0')
	{
		dest[lenght] = src[i];
		lenght++;
		i++;
	}
	dest[lenght] = '\0';
	return (dest);
}


/* ************************************************************************** */
/* ************************************************************************** */


char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (dest[i] != '\0')
		i++;
	while (src[x] != '\0' && x < nb)
	{
		dest[i] = src[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}


/* ************************************************************************** */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while ((j < nb) && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/* ************************************************************************** */
/* ************************************************************************** */