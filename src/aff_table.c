/*
** aff_table.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Feb 26 21:43:33 2016 Baptiste veyssiere
** Last update Sat Feb 27 15:23:46 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

void	aff_table(char **tab)
{
  int	i;
  int	j;
  char	aff;

  i = -1;
  write(1, "|------------------|\n", 22);
  while (++i < 9)
    {
      j = -1;
      write(1, "|", 1);
      while (++j < 9)
	{
	  write(1, " ", 1);
	  aff = tab[i][j];
	  write(1, &aff, 1);
	}
      write(1, "|\n", 2);
    }
  write(1, "|------------------|\n", 21);
}

void	error_aff_tab()
{
  int	i;
  int	j;
  char	aff;

  i = -1;
  write(1, "|------------------|\n", 22);
  while (++i < 9)
    {
      j = -1;
      write(1, "|", 1);
      while (++j < 9)
        {
          write(1, " ", 1);
          aff = 'X';
          write(1, &aff, 1);
        }
      write(1, "|\n", 2);
    }
  write(1, "|------------------|\n", 21);
}
