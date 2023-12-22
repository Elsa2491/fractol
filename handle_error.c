#include "fractol.h"

void	ft_handle_malloc_error(void)
{
	printf("malloc problem\n");
	exit(1);
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
