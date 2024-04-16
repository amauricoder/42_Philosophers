/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:27:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/15 16:05:54 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_struct(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philoandfork_qt)
		free(data->threads_arr[i ++]);
	free(data->threads_arr);
	free(data);
}
