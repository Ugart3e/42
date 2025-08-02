#include "philo.h"

void ft_error(char *error)
{
    printf("%s\n", error);
    exit(EXIT_FAILURE);
}

long	ft_atol(const char *str)
{
	long		result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
    while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

long gettime(t_time_code time_code)
{
	struct timeval tv;
	if (gettimeofday(&tv, NULL))
		ft_error("Gettimeofday failed");
	if (time_code == SECOND)
		return tv.tv_sec + (tv.tv_usec / 1e6);
	else if (time_code == MILISECOND)
		return (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
	else if (time_code == MICROSECOND)
		return (tv.tv_sec * 1000000L) + tv.tv_usec;
	else
		ft_error("Wrong input to gettime");
	return -1;
}

//more precise than usleep bc 1ms is relevant in this project
void ft_usleep(long usec, t_table *table)
{
	long start;
	long elapsed;
	long rem;

	start = gettime(MICROSECOND);
	while(gettime(MICROSECOND) - start < usec)
	{
		if(simulation_finished(table))
			break;
		elapsed = gettime(MICROSECOND);
		rem = usec - (elapsed - start);
		if(rem > 1e3)
			usleep(rem / 2);
		else
		{
			//SPINLOCK
			while (gettime(MICROSECOND) - start < usec)
				;
		}
	}
}

void clean_data(t_table *table)
{
	t_philo *philo;
	int i;

	i = 0;
	while(i < table->philo_nbr)
	{
		philo = table->philos + i;
		safe_mutex_handle(&philo->philo_mutex, DESTROY);
		i++;
	}
	safe_mutex_handle(&table->write_mutex, DESTROY);
	safe_mutex_handle(&table->table_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}