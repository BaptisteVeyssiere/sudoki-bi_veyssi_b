/*
** free_function.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 00:09:28 2016 Baptiste veyssiere
** Last update Sat Feb 27 19:31:44 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

void		free_function_bis(t_list *list, t_present *present)
{
  t_list        *tmp;

  free(present);
  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void	free_function(char ***tab)
{
  int	i;
  int	j;

  i = -1;
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j] != NULL)
	free(tab[i][j]);
      free(tab[i]);
    }
  free(tab);
}
