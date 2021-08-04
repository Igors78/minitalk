/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:32:39 by ioleinik          #+#    #+#             */
/*   Updated: 2021/08/04 16:51:52 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	check_handles(char *new, short *mask, short *i, short pid)
{
	if (new[(*i)])
	{
		if (*mask < 1)
		{
			(*i)++;
			*mask = 128;
		}
		if (*mask >= 1)
		{
			if (*mask & new[(*i)])
			{
				if (kill(pid, SIGUSR1) == -1)
					error("Signal error client to server. Restart server\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					error("Signal error client to server. Restart server\n");
			}
			*mask = *mask >> 1;
		}
	}
}

static void	telegram(short id, char *msg)
{
	static short	mask = 128;
	static short	pid = 0;
	static short	i = 0;
	static char		new[10000];

	if (id)
		pid = id;
	if (msg)
		ft_strlcpy(new, msg, 10000);
	check_handles(new, &mask, &i, pid);
	if (!(new[i]))
		terminate(pid);
}

static void	sig_handl(int signum, siginfo_t *info, void *unused)
{
	(void)unused;
	(void)info;
	if (signum == SIGUSR1)
	{
		telegram(0, 0);
	}
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd(GREEN "Delivered\n" RESET, 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_sig;

	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = sig_handl;
	if (argc != 3 || ft_atoi(argv[1]) < 1 || !(argv[2]))
	{
		write(1, "Incorrect arguments\n", 20);
		return (1);
	}
	if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
		error("SIGACTION ERROR\nRestart server\n");
	if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
		error("SIGACTION ERROR\nRestart server\n");
	write(1, "PID : ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	telegram(ft_atoi(argv[1]), argv[2]);
	while (1)
		sleep(1);
	return (0);
}
