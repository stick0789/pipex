#include "pipex.h"

int open_file(char **av, int i)
{
    int file;

    file = 0;
    if (i == 0)
        file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0777);
    else if (i == 1)
        file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    else if (i == 2)
        file = open(av, O_RDONLY, 0777);
    if (file == -1)
        ft_printf("Error Message");
    return (file);
}

int main(int ac, char **av, char **envp)
{
    int i;
    int infile;
    int outfile;

    if (av >= 5)
    {
        if (ft_strncmp(av[1], "here_doc", 8) == 0)
        {
            i = 3;
            outfile = open_file(av[ac - 1], 0);
            here_doc(av[2], ac);
        }
        else
        {
            i = 2;
            outfile = open_file(av[ac - 1], 0);
            infile = open_file(av[1], 2);
            dup2(infile, STDIN_FILENO);
        }
        while (i < ac - 2)
            create_process(av[i++], envp);
        dup2(outfile, STDOUT_FILENO);
        execute(av[ac - 2], envp);
        
    }
}