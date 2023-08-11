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

void	ft_bzero(void *s, size_t n)
{
	char	*point;

	point = s;
	while (n > 0)
	{
		*point = 0;
		point++;
		n--;
	}
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*ret_cpy;

	if (!s1 || !s2)
		return (NULL);
	ret = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	ret_cpy = ret;
	if (ret == NULL)
		return (NULL);
	while (*s1 != 0)
		*(ret++) = *(s1++);
	while (*s2 != 0)
		*(ret++) = *(s2++);
	return (ret_cpy);
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

/*char *choose_path(char *str)
{
    while(*str)
}*/

int    ft_cd(int argc, char **argv, char **env)
{
    char    *pwd;
    int     value;
	int		counter;

	counter = 0;
    if (argc > 3)
        write(2, "bash: cd: too many arguments\n", 29);
    pwd = get_pwd(env);
    if(pwd)
	{
        value = chdir(argv[2]);  

		if (value == -1)
		{
			write(2, "bash: cd: ", 11); 
			write(2, &argv[2][counter++], ft_strlen(argv[2]));
			write(2, ": ", 2);
			perror("");
			return(1);
		}
	}
	return(0);
}

int main(int argc, char ** argv, char **env)
{
    if( argc >= 2 && ft_strncmp(argv[1], "cd", 2) == 0 && ft_strlen(argv[1]) == 2)
        ft_cd(argc, argv, env);
    return(0);

}