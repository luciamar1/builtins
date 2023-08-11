#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
    {
        void			*content;
        struct s_list	*next;
    }	t_list;
    t_list envi;
t_list *envi;
int ft_crear_env(char **env)
{
    while(*env)
    {
        
    }
}

/////crear una lista global llamada env

int main(int argc, char **argv, char **env)
{
    ft_crear_env(env);
}