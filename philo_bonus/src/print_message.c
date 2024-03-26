#include "../include/philo_bonus.h"

int	print_message(t_data *data, char *msg)
{
	sem_wait(data->sem_print);
	if (did_someone_die())
	{
		sem_post(data->sem_print);
		return (1);
	}
	printf("%llu %d %s\n", get_time() - get_time_start(data),
		data->philo.id, msg);
	sem_post(data->sem_print);
	return (0);
}

void	print_sem(t_data *data, char *str)
{
	sem_wait(data->sem_print);
	printf("%s\n", str);
	sem_post(data->sem_print);
}
