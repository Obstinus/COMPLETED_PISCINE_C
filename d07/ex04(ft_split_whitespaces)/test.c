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
#include <stdlib.h>					/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для подсчета размера переменной(sizeof) */


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


int		ft_isspace(char c)		/* Функция узнает является ли наш символ разделителем между словами */
{
	return (c == ' ' || c == '\t' || c == '\n');/* Если наш символ это пробел или табуляция, или концом строки */
												 /* То завершаем функцию и возвращаем '1' */ 
												 /* Если это какой то др символ то завершаем функцию и возвращаем '0' */
}

int		ft_wordcount(char *str) /* Функция считает количество слов в строке */
{
	int		words;				/* Обьявляем переменную для хранения количества найденых слов */

	words = 0;					/* Инициализируем переменную хранящую количество найденых слов нулем */
	while (*str)				/* Запускаем цикл который пройдеться по строке и посчитает слова пока не дойдет до конца строки */
	{
		if (!(words) && !(ft_isspace(*str)))/* Если нам не встречались символы слова и эта ячейка содержит не пустой символ */ 
			words++;			/* Значит мы встретили первое слово. Прибавляем к переменной один */
		else if (ft_isspace(*(str - 1)) && !(ft_isspace(*str)))/* Если в этой ячейке ячейке храниться первая буква слова */
			words++;			/* Значит мы встретили еще одно слово. Прибавляем к переменной один */
		str++;					/* Проходимся по всему массиву символо(строке) пока не дойдем до последней */
	}
	return (words);				/* Завершаем функцию и возвращаем количество слов в строке */
}


int		ft_wordlen(char *str)	/* Функция вычисляет размер первого слова найденого в строке */
{
	int		len;				/* Обьявляем переменную для хранения размера слова */

	len = 0;					/* Инициализируем переменную хранящую размер слова нулем */
	while (ft_isspace(*str))	/* Цикл пропустит символы в начале массива, которые не являются словом */
		str++;
	while (*str && !(ft_isspace(*str)))/* Цикл который будет считать каждый символ пока не закончится слово */
	{
		str++;
		len++;
	}
	return (len);				/* Завершаем функцию и возвращаем размер слова */
}


char		**ft_split_whitespaces(char *str)/* функция разбирает строку на отдельные слова создавая для них массивы символов, 
											  * записывает адреса созданных массивов в массив указателлей на указатели и 
											  * возвращает адресс массива указателей на указатели */
{
	int		i;					/* Обьявляем переменную для счетчика чтоб перемечаться по созданным строкам */
	int		j;					/* Обьявляем переменную для счетчика чтоб перемечаться по созданному массиву символов */
	char	**arr;				/* Обьявляем указатель на указатель в который мы сохраним адресс выдленой памяти с адресами массивов */
	int		words;				/* Обьявим переменную для хранения вычесленного количества строк */

	words = ft_wordcount(str);	/* Вызываем функцию по вычислению количества слов в строке и записываем результат в переменную */
	i = 0;						/* Инициализируем счетчик 'i' нулем чтобы начать работу с нулевого массива */
	if (!str || (((arr = (char **)malloc(sizeof(char*) * (words + 1)))) == ((void *)0)))/* Выделяем память нужного размера
								 * под указатели на адреса массивов которые будут содержать строки со словами.
								 * И проверяем прошло ли выделение памяти без ошибок. */ 
		return ((void*)0);		/* Если были проблемы то завершаем функцию и возвращаем нулевой указатель */
	/* Если выше всё прошло удачно то мы переходим к созданию памяти для каждого слова */
	while (i < words)			/* Этот цикл будет создавать память под слова и записывать символы этих слов в выделеную память  */
	{
		if ((arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(str) + 1))) == ((void *)0))/* Выделяем память под указатели(их будет
								 * столько же сколько слов нашла функция ft_wordcount в строке, плюс один указатель под завершающий
								 * - нулевой указатель). В эти указатели мы поместим адреса каждого добытого слова помещеных в строку
								 * (массивов символов). И проверяем прошло ли выделение памяти без ошибок. */ 
			return ((void*)0);	/* Если что то пошло не так то завершаем функцию и возвращаем нулевой указатель */
		j = 0;					/* Инициализируем счетчик 'j' нулем чтобы начать работу с нулевой ячейки выбранного массива */
		while (ft_isspace(*str))/* Пропускаем ячейки с символами которые не являються частью слова */
			str++;				/* чтобы добраться до ячейки массива где начинается слова */
		while (*str && !(ft_isspace(*str)))/* Пока мы не дошли символа конца строки или не встретили пустой символ */
			arr[i][j++] = *str++;/* Копируем символы найденого текущего слова в новый массив */
		arr[i][j] = '\0';		/* После слова в конце массива добавляем символ конца массива */
		i++;					/* Переходим к след строке чтобы скопировать туда след слово, которое мы найдем с помощью
								 * str, в котором сохранилась информация о позиции ячейки после прошлого слова. 
								 * Эту позицию мы и используем как точку отсчета для поиска нового(последующего) слова */
	}
	arr[i] = ((void*)0);		/* В конце массива указателей на указатели, хранящего адреса строк, добавляем нулевой адрес как 
								 * символ конца этого массива указателей на указатели */
	return (arr);				/* Заавершаем функцию и возвращаем адресс массива с указателями на указатели(адреса массивов со
								 * словами) */
}


int     main(void)				/* Основаная функция */
{
	char	**arr_str;			/* Обьявляем указатель на указатель, в который мы сохраним адресс массива с адресами строк */
	
	if ((arr_str = ft_split_whitespaces(" param pam pam  muther fucker ")) == ((void *)0)) /* Запускам функцию нахождения в строке отдельных слов и разбрасываем ихв отдельные строки */
		return (0);
	while (*arr_str != ((void *)0))/* Проверяем есть ли по этому адресу строка. Если есть то спускаемся ниже и печатаем ее символы */
	{
		ft_putstr(*arr_str);	/* Печатаем текущую строку */
		ft_putchar('\n');		/* После, печатаем символ перехода на новую строку */
		arr_str++;				/* Переходим к след ячейке хранящей адрес другой строки */
	}
	return (0);					/* Если дошли до сюда значит основная функция завершается, возвращается ноль и программа завершается */ 
}