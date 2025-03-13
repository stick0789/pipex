#include "pipex.h"

char    *find_path(char *cmd, char **envp)
{
    char    **paths;
    char    *path;
    int         i;
    char    *part_path;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0)
        i++;
    paths = ft_split(envp[i] + 5, ':');
    i  = 0;
    while (paths[i])
    {
        part_path = ft_strjoin(paths[i], "/");
        path = ft_strjoin(part_path, cmd);
        free(part_path);
        if (access(path, F_OK) == 0)
            return (path);
        free(path);
        i++;
    }
    i = -1;
    //free split
    return (0);
    
}

void    execute(char *av, char **envp)
{
    char    **cmd;
    int     i;
    char    *path;

    i = -1;
    cmd = ft_split(av, ' ');
    path = find_path(cmd[0], envp);
    if (!path)
    {
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
        ft_printf("Error Message");
    }
    if (execve(path, cmd, envp) == -1)
        ft_printf("Error Message");
}

void    create_process(char *av, char **envp)
{
    pid_t   pid;
    int         fd[2];

    if (pipe(fd) == -1)
        ft_printf("Error Message");
    pid = fork();
    if (pid == -1)
        ft_printf("Error Message");
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execute(av, envp);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDOUT_FILENO);
        waitpid(pid, NULL, 0);
    }
}

void    here_doc(char *limitter, int ac)
{
    pid_t   reader;
    int         fd[2];
    char    *line;

    if (ac < 6)
        ft_printf("Error Message");
    if (pipe(fd) == -1)
        ft_printf("Error Message");
    reader = fork();
    if (reader == 0)
    {
        close(fd[0]);
        while (get_next_line(&line))
        {
            if (ft_strncmp(line, limitter, ft_strlen(limitter)) == 0)
                exit(EXIT_SUCCESS);
            write(fd[1], line, ft_strlen(line));
        }
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        wait(NULL);
    }
}