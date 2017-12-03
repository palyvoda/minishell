/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalyvod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 19:58:40 by vpalyvod          #+#    #+#             */
/*   Updated: 2017/07/06 19:58:43 by vpalyvod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFF_SIZE 8
# define TABA(x)(x != ' ' && x != '\t' && x != '\n')

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <termios.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

struct
{
	char	*tmp_var;
	char	*tmp_val;
}			set_env;

struct
{
	int		slash;
}			without_path;

struct
{
	int		i;
	int		j;
	char	*p;
	char	*path;
	char	*pars_str;
	int		not_found;
	int		count;
	char	*copy;
	int		correct;
	char	**spl_words;
	char	**mass;
	char	*word;
	char	*tmp;
}			comm;

int			check_space_tabs(char *line);
void		print_env(char **env);
int			check_command(char *line, char *command);
void		var_without_dol(char *line);
char		**get_env(char **env);
void		siginthandler(int k);
int			check_errors_cd(DIR **dp, char *dir);
int			comm_if();
void		comm_free();
int			check_correct_comm(char *line, char **env);
void		check_correct_comm_cont(char **env);
void		check_correct_comm_2(char **env);
void		check_comm_cycle_else();
void		check_for_pars(char *line, char **env);
void		check_with_slash(char *line);
void		path_pars_exec(char *line, char **env);
void		my_set_env(char **env);
int			ft_setenv(char *line);
int			env_strcmp(const char *s1, const char *s2);
char		*my_strndup(char *str, int len);
void		ft_strdel_mass(char **mass);
void		print_newpwd(char **env);
void		print_oldpwd(char **env);
int			ft_unsetenv(char **env, char *line);
void		ft_unsetenv_cycle(char **env);
void		just_parse_it(pid_t pid, char *line, char **env);
void		comm_3(void);
void		comms_2(void);
void		comms(char *line, char **env);
char		*words_first(char *line);
char		*words(char *line);
void		print_echo_cycle(char **first);
void		print_echo_else(char *line, char **env);
void		print_echo_else_cycle(char **env);
void		print_echo(char *line, char **env);
void		print_echo_quote(char *line, char **first);
int			print_echo_check_quote(char *line);
void		print_echo_do(char **env, char *line);
char		**ft_split_quotes(char *str);
int			count_word(char *str);
char		**ft_split(char *str);
char		*ft_strndup(const char *s, size_t n);
int			count_words(char *str);
void		cd_if_mass_1_null(char **env);
void		cd_errors(char *temp);
void		cd_minus_sign(char **env);
void		cd_tilde_sign(char **env, char **mass);
void		cd_simple_input(char **env, char **mass);
void		cd_command(char **env, char *line);
void		cd_with_variable(char **env, char *line, char **mass);
void		cd_with_var_cycle(char **env, int check);
void		check_error_var(int check);
void		cd_with_var_cycle2(int i, int j, char **env);
int			get_next_line(int const fd, char **line);
int			count_setenv(char **mass);

#endif
