#include "pipex.h"

void    error_message()
{
    perror("Error");
    exit(EXIT_FAILURE);
}

void	how_to_use(void)
{
	ft_putstr_fd("Error: Bad argument", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd("    ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 1);
	exit(EXIT_SUCCESS);
}

void    here_doc(char *limitter, int ac)
{
    pid_t   reader;
    int         fd[2];
    char    *line;

    if (ac < 6)
        how_to_use();
    if (pipe(fd) == -1)
        error_message();
    reader = fork();
    if (reader == 0)
    {
        close(fd[0]);
        //while (get_next_line(&line))
        while ((line = get_next_line(STDIN_FILENO)))
        //while (1)
        {
            //line = get_next_line(STDIN_FILENO);
            if (ft_strncmp(line, limitter, ft_strlen(limitter)) == 0)
            {
                free(line);
                exit(EXIT_SUCCESS);
            }
            write(fd[1], line, ft_strlen(line));
            free(line);
        }
        exit(EXIT_SUCCESS);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        //close(fd[0]);
        wait(NULL);
    }
}