#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int ac, char **av)
{
	int	i;
	int	n;

	n = 0;
	while (n < (ac - 1))
	{
		if (ft_strcmp(av[n], av[n + 1]) > 0)
		{
			ft_swap(&av[n], &av[n + 1]);
			n = 0;
		}
		n++;
		i = 1;
		while (i < ac)
		{
			printf("<%s>",av[i]);
			i++;
		}
		if(i == ac)
			printf("\n");
	}
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]); //wtf hhh you're just printing the same word av[n] hhh put the i instead not n it's working with  i
		ft_putchar('\n');
		i++;
	}
}
