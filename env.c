 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	char				aux;
	unsigned long		counter;

	aux = 1;
	counter = 0;
	while (aux != 0)
	{
		aux = *(str + counter);
		counter++;
	}
	return (--counter);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	while ((*s1 != 0 || *s2 != 0) && n > 0)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int ft_env(char **env)
{
    while(*env)
    {
        write(2, (*env) ++, ft_strlen(*env));
        write(2, "\n", 1);
        env ++;
    }
    return (0);
}

int main(int argc, char **argv, char **env)
{
    if(argc == 2)
    {
        if(ft_strncmp(argv[1], "env", 3) == 0 && ft_strlen(argv[1]) == 3)
        {
            printf("hoal\n");
            ft_env(env);
        }
    }
    return(0);
}