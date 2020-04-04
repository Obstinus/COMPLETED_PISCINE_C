/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
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

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Функция проверки массива с нужной на системой счисления на корректность */
static int	check_base(char *base)		/* функция принимает адресс массива с основанием числа */
{
	int	i;								/* обьявляем счетчик */
	int	z;								/* обьявляем счетчик */

	i = 0;								/* инициализируем счетчик нулем чтобы начать с начала массива */
	z = 0;								/* инициализируем счетчик нулем чтобы начать с начала массива */
	if (!base || !base[1])				/* если массив пуст */
		return (0);						/* то возвращаем 0 и завершаем цикл и функцию */
	while (base[i])						/* до тех пор пока выбранная ячейка массива не пуста запускаем цикл */
	{
		z = i + 1;						/* сохраняем в переменную z число указывающее на сл ячейку после i */
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z'))) /* провеяем массив, чтобы там были только символы чисел и букв алфавита */
			return (0);					/* если в массиве есть что то не нужное нам то возвращаем 0 и завершаем цикл и функцию */
		while (base[z])					/* запускаем цикл, который проверит все ячеки которые следуют за теми на которые указывает переменная i */
			if (base[i] == base[z++])	/* если символ в ячейке на которую указывает i  такой же что и в след ячейке */ 
				return (0);				/* то возвращаем 0 и завершаем цикл и функцию */ /* если нет то продолжаем цикл пробегаясь по остальным ячейка и сравнивая их с i */
		i++;					/* если дошли до сюда значит символ этой ячейки соответсвует условиям и идентичных ему в массиве нет */ /* переходим к проверке сл ячейки */
	}
	return (1);					/* если дошли до сюда, значит массив соответсвует условиям */ /* возвращаем 0 и завершаем функцию */
}


void		ft_putstr_non_printable(char *str)	/* принимаем адресс нужной нам для печати строки */
{
	int		i;									/* обьявляем счетчик для перемечения по массиву символов(строке) */
	char	*hex;								/* обьявляем массив для хранения данных о шестнадцатиричной системе счисления */

	hex = "0123456789abcdef";					/* инициализируем массив заполняя его */
	i = 0;										/* инициализируем счетчик нулем чтобы начать с нулевой ячейки массива символо(строки) */
	if(check_base(hex))							/* Проверяем систему счисления на корректность, и продолжаем дальше если все корректно */
	{
		while (str[i])							/* запускаем цикл по печати строки и печати не отображаемых символов в шестнадцатиричном формате(hex) */ 
		{
			if ((str[i] < 32 && str[i] >= 0) || str[i] == 127)	/* если символ являеться не отображаемым то */
			{
				ft_putchar('\\');								/* печатаем сивол экранирования как знак того что дальше будет разбит на состовляющие по 4 бита и 
																 * напечатан в шестнадцатиричном формате */
				if (str[i] < 16)								/* если значение символа находится в пределах 16-ти */
				{
					ft_putchar('0');							/* то печатаем ноль */ 
					ft_putchar(hex[(int)str[i]]);				/* и используем его значение символа чтобы найти его эквивалент в желаемой системе счисления т.к он в пределах числа 16 */
				}
				else											/* Если значение символа выходит за пределы 16-ти то разбиваем его значение на части по 16. 
																 * Результатом будут две, по 4 бита, половинки нашего символа длинна которого один байт.
																 * т.е мы получим два шестнадцатиричных значение одного символа, которые и напечатаем */
				{
					ft_putchar(hex[(int)str[i]/16]);
					ft_putchar(hex[(int)str[i]%16]);
				}
				
			}
			else								/* Если символ является печатаемым */
				ft_putchar(str[i]);				/* То отправляем его на печать */
			i++;
		}
	}
}


int     main(void)
{
    ft_putstr_non_printable("ytu\t_sdf");		/* Отправляем нужную нам строку в функцию для печати и проверки отображения нечитаемых символов */
    return (0);									/* Завершаем функцию и возвращаем ноль */
}