#include "fractol.h"

void	ft_handle_malloc_error(void)
{
	printf("malloc problem\n");
	exit(1);
}

double	ft_atoi(char *str)
{
	double		j;
	double		before_comma;
	double		after_comma;
	int	sign;

	before_comma = 0;
	after_comma = 0;
	j = 1;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str += 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str += 1;
	}
	while (*str >= 48 && *str <= 57)
		before_comma = before_comma * 10 + *str++ - 48;
	if (*str == '.')
		str += 1;
	while (*str >= 48 && *str <= 57)
	{
		j /= 10;
		after_comma = after_comma + (*str++ - 48) * j;
	}	
	return (sign * (before_comma + after_comma));
}

void	ft_to_lower(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i += 1;
	}
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2 || n <= 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i += 1;
	return (s1[i] - s2[i]);
}
