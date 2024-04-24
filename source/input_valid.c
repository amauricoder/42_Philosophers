/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:57:13 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/24 15:25:20 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
/**
 * @brief Checks if the arguments from the 
 * input are valid using other functions
 * @param argv
 * @return Boolean. 1 for yes, 0 for no.
*/
int	 argument_isvalid(int argc, char **argv)
{
	//here I need to check for int max too.
	//timestamp needs to be bigger than 60ms
	if (!is_digit(argv) || !is_null(argv) || argc < 5 || argc > 6
	|| ft_atoi(argv[5]) == 0)
		return (EXIT_FAILURE);	
	else
		return (EXIT_SUCCESS);
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
