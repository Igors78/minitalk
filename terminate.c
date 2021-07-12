/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 19:06:22 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/12 17:41:35 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	terminate(short id)
{
	static short	i = 0;

	if (i < 8)
	{
		kill(id, SIGUSR2);
		i++;
	}
	else
		i = 0;
}
