/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:27:27 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/19 16:18:23 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_struct(t_data *data)
{
	/* int i = 0;
	while (i < data->philoandfork_qt)
	{
		free(data->ph[i].left_fork);
		free(data->ph[i].right_fork);
		i ++;
	} */
	free(data->thr_arr);
	free(data->mtx_arr);
	free(data->ph);
}
