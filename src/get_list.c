/*
** get_list.c for sudoki-bi.h in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 16:35:19 2016 Baptiste veyssiere
** Last update Sat Feb 27 19:48:17 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

int		add_to_list(t_list **list, int i, int j, char **tab)
{
  t_list	*elem;
  int		nbr;
  int		pos;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (-1);
  elem->i = i;
  elem->j = j;
  nbr = 0;
  pos = 0;
  while (++nbr < 10)
    if (is_line(tab, i, (nbr + '0')) == 0 &&
	is_column(tab, j, (nbr + '0')) == 0 &&
	is_block(tab, i, j, (nbr + '0')) == 0)
      ++pos;
  elem->possibilities = pos;
  elem->next = *list;
  *list = elem;
  return (0);
}

t_list		*get_list(char **tab)
{
  t_list	*list;
  int		i;
  int		j;

  list = NULL;
  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	if (tab[i][j] == ' ' &&
	    add_to_list(&list, i, j, tab) == -1)
	  return (NULL);
    }
  sort_list(&list);
  return (list);
}
