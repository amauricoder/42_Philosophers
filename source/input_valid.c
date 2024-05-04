/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:13 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/04 16:22:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static long	ft_atol(char *char_nbr);

/**
 * @brief Checks if the arguments from the 
 * input are valid using other functions
 * @return Boolean. 1 for yes, 0 for no.
*/
int	argument_isvalid(int argc, char **argv)
{
	if (!is_digit(argv) || !is_null(argv) || argc < 5 || argc > 6
		|| ft_atoi(argv[5]) == 0 || is_intvalid(argv))
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

/**
 * @brief Checks all the arguments in argv are number only
 * @attention This function will consider a "-" as a non digit.
 * For this reason, will block negative numbers too.
 * @return Boolean. 1 for yes, 0 for no.
*/
int	is_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

/**
 * @brief Checks if the argv is null
 * @return Boolean. 1 for yes, 0 for no.
*/
int	is_null(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], ""))
			return (0);
		i ++;
	}
	return (1);
}

/**
 * @brief Checks if the int is valid into the scope of INT_MAX
*/
int	is_intvalid(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > 2147483647)
			return (EXIT_FAILURE);
		i ++;
	}
	return (EXIT_SUCCESS);
}

static long	ft_atol(char *char_nbr)
{
	long	res;
	long	signal;
	long	i;

	signal = 0;
	res = 0;
	i = 0;
	if (!char_nbr)
		return (EXIT_FAILURE);
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
		res = res + char_nbr[i ++] - 48;
	}
	if (signal == -1)
		res = res * signal;
	return (res);
}
