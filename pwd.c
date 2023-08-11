#include <stdio.h>
#include <unistd.h>

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



char *get_pwd(char **env)
{
    while(*env)
    {
        if(ft_strncmp(*env, "PWD=", 4) == 0)
            break ;
        env ++;
    }
    if(*env)
        return(*env + 4);
    return(NULL);
}

int *ft_pwd(char **env)
{
    char *pwd;

    pwd = get_pwd(env);
    if(pwd)
    {
        write(1, pwd ++, ft_strlen(pwd));
        write(1, "\n", 1);
    }
    return(0);
}

int main(int argc, char **argv, char **env)
{
    if(argc > 1)
    {
        if(ft_strncmp(argv[1], "pwd", 3) == 0 && ft_strlen(argv[1]) == 3)
            ft_pwd(env);
    }
    return (0);
}