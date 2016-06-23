/*
** my_realloc.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 15:55:50 2016 Baptiste veyssiere
** Last update Sat Feb 27 19:27:57 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

char	***my_realloc(char ***tab, int length)
{
  int	i;
  char	***tmp;

  if ((tmp = malloc(sizeof(char**) * (length + 1))) == NULL)
    return (NULL);
  tmp[length] = NULL;
  i = -1;
  while (++i < (length))
    tmp[i] = tab[i];
  free(tab);
  tab = tmp;
  return (tab);
}
