/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:42:50 by jaacosta          #+#    #+#             */
/*   Updated: 2025/02/28 19:02:25 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

/*	Funciones Autorizadas // Autorized Functions	*/
/*	open - close - read - write - malloc - free 	*/
/*	perror - strerror - access - dup - dup2 	*/
/*	execve - exit - fork - pipe - unlink - wait	*/
/*	waitpid	- Also all my libftFunctions, ft_printf	*/
/*
 * 	int access(const char *pathname, int mode);
 * 	me dice si un archivo es accesible, si lo es devuelve 0
 * 	si no, retorna -1
 * 	ex: if (access("rwfile", R_OK|W_OK) == 0) - IMPORTANTE -
 *
 * 	int dup2(int oldfd, int newfd);
 * 	es una llamada al sistema que me permite duplicar un
 * 	fileDescriptor(oldfd) en un nuevo fileDescriptor(newfd)
 * 	es util para redirigir la entrada o salidad
 * 	estandar en programas que manejan archivos o
 * 	procesos - IMPORTANTE -
 * 	en caso de exito retorna newfd y si falla -1
 *	
 *	int pipe(int pipefd[2]);
 *	crea una pipe, un canal unidireccional para usarlo
 *	en los procesos internos de comunicacion, el array
 *	pipefd[2] devuelve 2 fileDescriptors referentes a los
 *	extremos de la tuberia, pipe[0] es el de lectura y 
 *	pipe[1] al extremo de escritura, los datos de pipe[1] 
 *	son almacenados por el kernel hasta que se leen desde
 *	el extremo de lectura, en exito retorna 0, si falla -1
 *
 *	pid_t fork(void); FORK()
 *	crea un nuevo proceso duplicando el proceso de llamada,
 *	el nuevo proceso (llamado hijo) es un duplicado exacto 
 *	del proceso de llamada (llamado padre)
 *
 *	pid_t waitpid(pid_t pid, int *status, int options);
 *	es una llamada al sistema para suspender la ejecucion
 *	de la llamada de un proceso hasta que un hijo
 *	especifico (especificado por pid) haya cambiado de 
 *	estado, por defecto espera solo por hijos acabados
 *
 *	pid_t wait(int *status);
 *	es una llamada al sistema para suspender la ejecucion
 *	de la llamada de un proceos hasta que uno de sus hijos
 *	termine
 *	
 *	int execve(const char *filename, char *const argv[], char *const envp[]);
 *	ejecuta el programa apuntado por filename, en caso de 
 *	exito no retorna por que el proceso que lo invoco es 
 *	remplazado por el programa ejecutado
 *
 *	int unlink(const char *pathname);
 *	elimina un nombre de los archivos del sistema, si el
 *	nombre fue el ultimo link a un archivo y no hay
 *	procesos que tengan abierto el archivo es eliminado y
 *	el espacio disponible puede ser reutilizado
 *	so el nombre fue el ultimo link de un archivo pero 
 *	ningun proceso, este mantiene el archivo abierto
 *	en espera hasta que el ultimo fileDescriptor referente
 *	se cierre, si todo va bien retorna 0 si no -1
 * 	
 */
static int	verify_files(int ac, char **av)
{
	int	fd;

	if (access(av[1], F_OK) != 0)
	{
		ft_printf("Error: No existe archivo de entrada\n");
		return (1);
	}
	if (access(av[1], R_OK) != 0)
	{
		ft_printf("Error: El archivo no tiene suficientes permisos");
		return (1);
	}
	if (access(av[ac - 1], W_OK) != 0)
	{
		ft_printf("Error: No se puede escrbir en %s, intentando crearlo", av[ac - 1]);
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			ft_printf("Error al crear el archivo");
			return (1);
		}
	}
	return (0);
}
/*
void	create_pipe_and_fork()
{
	char	buffer[100];
	int	fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("Error al crear el pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error en fork");
		exit(1);
	}
	if (pid == 0)//proceso hijo
	{
		close(fd[0]);
		write(fd[1], "hijo envia", 10);
		close(fd[1]);
		exit(0);
	}
	else//proceso padre
	{
		close(fd[1]);
		read(fd[0], buffer, sizeof(buffer));
		write(1, "padre recibio: ", 15);
		write(1, buffer, 22);
		close(fd[0]);

		wait(NULL);
	}
}
*/
int	create_pipe()
{
	int	pipe_fd[2];

	if(pipe(pipe_fd) == -1)
	{
		perror("Error creando pipe");
		exit(1);
	}
	return (pipe_fd[1]);
}

void	setup_io(int i, int pipe_fd, int ac, char **av)
{
	int	infile = 0;
	int	outfile = 0;

	if (i == 0)
	{
		infile = open(av[1], O_RDONLY);
		if (infile == -1)
		{
			perror("Error abriendo infile");
			exit(1);
		}
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	else
		dup2(pipe_fd, STDIN_FILENO);
	if (i == ac - 4)
	{
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	       if (outfile == -1)
	       {
		       perror("Error abriendo outfile");
		       exit(1);
	       }
	       dup2(outfile, STDOUT_FILENO);
	       close(outfile);
	}
}

void	execute_child_command(int i, char **av, char **envp)
{
	char	*args[] = {av[i + 2], NULL}; // argumentos para execve
	
	execve(av[i + 2], args, envp);
	perror("Error ejecutando comando");
	exit(1);
}

void	wait_for_children(int ac)
{
	int	i;

	i = 0;
	while (i < ac -3)
	{
		wait(NULL);
		i++;
	}
}

void	create_processes(int ac, char **av, char **envp)
{
	int	pipe_fd[2]; //se crea un ppipe por cada comando
	int	i;
	pid_t	pid;

	i = 0;
	while(i < ac- 3)
	{
		if (i != 0)
			pipe_fd[1] = create_pipe();//crear un pipe por cada comando
		pid = fork();
		if (pid == -1)
		{
			perror("Error en fork");
			exit(1);
		}
		if (pid == 0)
		{
			setup_io(i, pipe_fd[1], ac, av);
			execute_child_command(i, av, envp);
		}
		i++;
	}
	wait_for_children(ac);
}

int	main(int ac, char **av, char **envp)
{
	(void)	av;
	(void)	envp;
	if (ac >= 5)
	{
		if (verify_files(ac, av) == 0)
			ft_printf("hola");
		create_processes(ac, av, envp);
	}
	else
		ft_printf("Error en la cantidad de argumentos\n");
	return (0);
}
