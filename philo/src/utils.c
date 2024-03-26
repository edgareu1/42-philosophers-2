#include "../include/philo.h"

int	ft_atoi(char *str)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] == '\r' || str[count] == '\t' || str[count] == ' '
		|| str[count] == '\f' || str[count] == '\v' || str[count] == '\n')
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	if (!(str[count] >= '0' && str[count] <= '9'))
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
		result = result * 10 + (str[count++] - '0');
	return (result * sign);
}

bool	has_nb_meals(t_data *data)
{
	return (data->nb_meals > 0);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mutex_state);
		pthread_mutex_destroy(&data->philos[i].mutex_nb_meals_had);
		pthread_mutex_destroy(&data->philos[i].mutex_last_eat_time);
	}
	pthread_mutex_destroy(&data->mutex_die_t);
	pthread_mutex_destroy(&data->mutex_eat_t);
	pthread_mutex_destroy(&data->mutex_sleep_t);
	pthread_mutex_destroy(&data->mutex_nb_philos);
	pthread_mutex_destroy(&data->mutex_print);
	pthread_mutex_destroy(&data->mutex_keep_iter);
	pthread_mutex_destroy(&data->mutex_start_time);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}

void	print_message(t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time() - get_time_start(data);
	pthread_mutex_lock(&data->mutex_print);
	if (get_keep_iter(data))
		printf("%llu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mutex_print);
}
