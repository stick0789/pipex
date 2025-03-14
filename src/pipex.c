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
    free_split(paths);
    /*i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);*/
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
        error_message();
    }
    if (execve(path, cmd, envp) == -1)
        error_message();
}

void    create_process(char *av, char **envp)
{
    pid_t   pid;
    int         fd[2];

    if (pipe(fd) == -1)
        error_message();
    pid = fork();
    if (pid == -1)
        error_message();
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execute(av, envp);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        waitpid(pid, NULL, 0);
    }
}

int open_file(char *av, int i)
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
        error_message();
    return (file);
}

int main(int ac, char **av, char **envp)
{
    int i;
    int infile;
    int outfile;

    if (ac >= 5)
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
            outfile = open_file(av[ac - 1], 1);
            infile = open_file(av[1], 2);
            dup2(infile, STDIN_FILENO);
        }
        while (i < ac - 2)  
            create_process(av[i++], envp);
        dup2(outfile, STDOUT_FILENO);
        execute(av[ac - 2], envp);
        
    }
    how_to_use();
}