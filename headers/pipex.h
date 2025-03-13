/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:24:13 by jaacosta          #+#    #+#             */
/*   Updated: 2025/03/12 17:05:55 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>      // open
# include <unistd.h>     // close, read, write, access, dup, dup2, execve, fork, pipe, unlink
# include <stdlib.h>     // malloc, free, exit
# include <stdio.h>      // perror
# include <string.h>     // strerror
# include <sys/wait.h>   // wait, waitpid

/*---   Funcion para el path del comando a ejecutar//Function for the path to execute ---*/
char    *find_path(char *cmd, char **envp);
/*---   Funcion para ejecutar comandos//Function to execute the commands ---*/
void    execute(char *av, char **envp);
/*---   Funcion para crear los procesos hijos//Function to create child process ---*/
void    create_process(char *av, char **envp);
/*---   Funcion para ejecutar con here_doc//Function to execute with here_doc ---*/
void    here_doc(char *limitter, int ac);
/*---   Funcion para abir archivos con respectivos permisos//Function to open files with their permissions ---*/
int open_file(char *av, int i);
/*---   Funcion para mostrar mensaje de error//Function to show the error messaage ---*/
void    error_message();
/*---   Funcion para mostrar como corren el programa//Function to show how to run the program ---*/
void	how_to_use(void);


#endif
