/*
** my_tablen.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 15:28:52 2016 Baptiste veyssiere
** Last update Sat Feb 27 16:10:24 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

int	my_tablen(char ***tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL);
  return (i);
}

int	my_strcmp(char *s1, char *s2, int *j)
{
  int   i;

  i = -1;
  while (s1[++i] != 0)
    if (s1[i] != s2[++(*j)])
      return (0);
  return (1);
}
