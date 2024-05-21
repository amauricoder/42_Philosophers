/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:33:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/05/03 14:41:48 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/**
 * @brief Send error message to output 2 (error std) and return exit_code.
 * @param msg Message to be sended.
*/
int	errormsg_and_exit(char *msg, int exit_code)
{
	write(2, msg, ft_strlen(msg));
	return (exit_code);
}
