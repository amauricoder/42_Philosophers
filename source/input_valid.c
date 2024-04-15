/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:13 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/15 14:36:19 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
/**
 * @brief Checks if the arguments from the 
 * input are valid using other functions
 * @param argv
 * @return Boolean. 1 for yes, 0 for no.
*/
int	argument_isvalid(int argc, char **argv)
{
	if (!is_digit(argv) || !is_null(argv) || argc < 5 || argc >= 7)
		return (0);
	else
		return (1);
}

/**
 * @brief Checks all the arguments in argv are number only
 * @attention This function will consider a - as a non digit. For this reason,
 * will block negative numbers too.
 * @param argv
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
 * @param argv Argvs
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
