/*
** is_present.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 00:28:07 2016 Baptiste veyssiere
** Last update Sat Feb 27 16:09:55 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

int	is_line(char **tab, int i, int nbr)
{
  int	j;

  j = -1;
  while (++j < 9)
    if (tab[i][j] == nbr)
      return (1);
  return (0);
}

int	is_column(char **tab, int i, int nbr)
{
  int	j;

  j = -1;
  while (++j < 9)
    if (tab[j][i] == nbr)
      return (1);
  return (0);
}

int	is_block(char **tab, int i, int j, int nbr)
{
  int	k;
  int	l;

  k = i - i % 3;
  l = j - j % 3;
  i = k - 1;
  while (++i < (k + 3))
    {
      j = l - 1;
      while (++j < (l + 3))
	if (tab[i][j] == nbr)
	  return (1);
    }
  return (0);
}
