/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:34:17 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/15 14:34:30 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
* @brief Counts the quantity of characters in a string.
* @param String to be counted.
* @return Quantity of chars counted.
*/
int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i ++;
	return (i);
}

/**
* @brief Compare the difference between 2 strings.
* @return The difference of value between
* the last equal(or last in str) char of str1 and str2.
*/
int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] == str2[i]) && (str1[i] != '\0' || str2[i] != '\0'))
		i ++;
	return (str1[i] - str2[i]);
}

/**
 * @brief Convert char to integer.
 * @param char_nbr Char to be converted.
 * @return The equivalent of the char_nbr, but INT.
*/
int	ft_atoi(char *char_nbr)
{
	int	res;
	int	signal;
	int	i;

	signal = 0;
	res = 0;
	i = 0;
	while (char_nbr[i] == 32 || (char_nbr[i] >= 9 && char_nbr[i] <= 13))
		i ++;
	if (char_nbr[i] == '+' || char_nbr[i] == '-')
	{
		if (char_nbr[i] == '-')
			signal = -1;
		i ++;
	}
	while (char_nbr[i] >= '0' && char_nbr[i] <= '9')
	{
		res = res * 10;
		res = res + char_nbr[i] - 48;
		i ++;
	}
	if (signal == -1)
		res = res * signal;
	return (res);
}

/**
 * @brief Init struct with initial data
 * @return A struct with data filled.
*/
t_data	*init_struct(int argc, char **argv)
{
	t_data	*values;

	values = malloc(sizeof(t_data));
	if (!values)
		return (NULL);
	values->argc_qt = argc;
	values->philoandfork_qt = ft_atoi(argv[1]);
	values->die_timeto = ft_atoi(argv[2]);
	values->eat_timeto = ft_atoi(argv[3]);
	values->sleep_timeto = ft_atoi(argv[4]);
	if (argc > 5)
		values->musteat_times = ft_atoi(argv[5]);
	else
		values->musteat_times = 0;
	return (values);
}
