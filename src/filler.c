/*
** filler.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 14:55:52 2016 Baptiste veyssiere
** Last update Sat Feb 27 19:38:15 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

int	filler(char **tab, t_list *list, t_present *present)
{
  int	i;
  int	j;
  int	k;

  if (list == NULL || (k = -1) != -1)
    return (1);
  i = list->i;
  j = list->j;
  while (++k < 9)
    if (present->line[i][k] == 0 && present->column[j][k] == 0 &&
	present->block[(3 * (i / 3)) + (j / 3)][k] == 0)
      {
	present->line[i][k] = 1;
	present->column[j][k] = 1;
	present->block[(3 * (i / 3)) + (j / 3)][k] = 1;
	if (filler(tab, list->next, present))
	  {
	    tab[i][j] = k + 1 + '0';
	    return (1);
	  }
	present->line[i][k] = 0;
	present->column[j][k] = 0;
	present->block[(3 * (i / 3)) + (j / 3)][k] = 0;
      }
  return (0);
}
