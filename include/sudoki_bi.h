/*
** sudoki_bi.h for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Feb 26 21:36:49 2016 Baptiste veyssiere
** Last update Sun Feb 28 18:47:14 2016 Baptiste veyssiere
*/

#ifndef SUDOKI_BI_H
# define SUDOKI_BI_H

# define END 81
# define GRID_SIZE 231

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_list
{
  int		i;
  int		j;
  int		possibilities;
  struct s_list	*next;
}		t_list;

typedef struct
{
  char		line[9][9];
  char		column[9][9];
  char		block[9][9];
}		t_present;

int		my_strlen(char*);
int		error_msg(char*, int);
char		**get_tab();
void		free_function(char***);
void		aff_table(char**);
int		is_line(char**, int, int);
int		is_column(char**, int, int);
int		is_block(char**, int, int, int);
int		filler(char**, t_list*, t_present*);
int		check_valid(char**);
void		error_aff_tab();
int		my_tablen(char***);
char		***my_realloc(char***, int);
char		***get_all_tab();
int		my_strcmp(char*, char*, int*);
void		sort_list(t_list**);
int		compare_size(t_list*, t_list*);
void		swap_list(t_list*, t_list*, t_list*, t_list**);
t_list		*get_list(char**);
t_present	*get_present(char**);
void		free_function_bis(t_list*, t_present*);

#endif /* !SUDOKI_BI_H */
