/*
** get_present.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 18:43:01 2016 Baptiste veyssiere
** Last update Sat Feb 27 19:19:20 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

void	init_present(t_present *present)
{
  int	i;
  int	j;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	{
	  present->line[i][j] = 0;
	  present->column[i][j] = 0;
	  present->block[i][j] = 0;
	}
    }
}

void	fill_present_values(t_present *present, char **tab)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	if ((k = tab[i][j]) != ' ')
	  {
	    k -= '0';
	    present->line[i][k - 1] = 1;
	    present->column[j][k - 1] = 1;
	    present->block[(3 * (i / 3)) + (j / 3)][k - 1] = 1;
	  }
    }
}

t_present	*get_present(char **tab)
{
  t_present	*present;

  if ((present = malloc(sizeof(t_present))) == NULL)
    return (NULL);
  init_present(present);
  fill_present_values(present, tab);
  return (present);
}
