/*
** check_valid.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 15:18:46 2016 Baptiste veyssiere
** Last update Sat Feb 27 15:20:15 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

int	check_valid(char **tab)
{
  int	i;
  int	j;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	if (tab[i][j] == ' ')
	  return (1);
    }
  return (0);
}
