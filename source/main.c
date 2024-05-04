/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:30:47 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/04 15:42:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Main for the philosophers project. Set all values to 0,
 * check if the arguments are valid, initialize the data, attribute
 * the forks and start the threads. After, clean to prevent leaks.
*/
int	main(int argc, char **argv)
{
	t_data		d;

	memset(&d, 0, sizeof(t_data));
	if (argument_isvalid(argc, argv) != 0)
		return (errormsg_and_exit("Error\nInvalid Arguments", EXIT_FAILURE));
	init_data(argc, argv, &d);
	if (attribute_forks(&d) != 0)
	{
		free_struct(&d);
		return (errormsg_and_exit("Error\nInvalid Mutex", EXIT_FAILURE));
	}
	if (start_threads(&d) != 0)
	{
		free_struct(&d);
		return (errormsg_and_exit("Error\nInvalid Thread", EXIT_FAILURE));
	}
	free_struct(&d);
}
