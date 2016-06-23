/*
** get_tab.c for get_tab in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Feb 26 21:52:42 2016 Baptiste veyssiere
** Last update Sun Feb 28 18:42:27 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

int	check_line(char *str, int *i)
{
  int	j;

  j = 0;
  while (j < 17)
    {
      if (str[++(*i)] != ' ')
        return (1);
      if (((str[++(*i)] < '0' || str[*i] > '9') && str[*i] != ' '))
	return (-1);
      j += 2;
    }
  return (0);
}

char	**str_to_tab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  if ((tab = malloc(sizeof(char*) * 10)) == NULL)
    return (NULL);
  i = -1;
  tab[9] = NULL;
  while (++i < 9)
    if ((tab[i] = malloc(sizeof(char) * 10)) == NULL)
      return (NULL);
  i = -1;
  k = 22;
  while (++i < 9 && (j = -1) == -1)
    {
      while (++j < 9)
	{
	  tab[i][j] = str[++k];
	  ++k;
	}
      k += 3;
      tab[i][j] = 0;
    }
  return (tab);
}

int	check_integrity(char *str)
{
  char	*s;
  int	i;
  int	j;

  s = "|------------------|\n";
  i = -1;
  j = -1;
  if (my_strcmp(s, str, &j) == 0)
    return (error_msg("MAP_ERROR\n", 1));
  while (++i < 9)
    {
      if (str[++j] != '|' || check_line(str, &j) == 1 ||
	  str[++j] != '|' || str[++j] != '\n')
	return (error_msg("MAP_ERROR\n", 1));
    }
  s =  "|------------------|";
  if (my_strcmp(s, str, &j) == 0)
    return (error_msg("MAP_ERROR\n", 1));
  return (0);
}

char	**get_tab()
{
  char	str[GRID_SIZE + 1];
  char	**tab;
  int	read_size;
  int	i;

  i = -1;
  while (++i <= GRID_SIZE)
    str[i] = 0;
  read_size = read(0, str, GRID_SIZE);
  if (read_size < GRID_SIZE && str[0] != 0)
    exit(error_msg("MAP ERROR\n", -1));
  else if (read_size < GRID_SIZE && str[0] == 0)
    return (NULL);
  if (check_integrity(str))
    return (NULL);
  if ((tab = str_to_tab(str)) == NULL)
    return (NULL);
  return (tab);
}

char	***get_all_tab()
{
  char	***tab;
  int	i;

  if ((tab = malloc(sizeof(char**) * 2)) == NULL)
    return (NULL);
  tab[1] = NULL;
  i = -1;
  while ((tab[++i] = get_tab()) != NULL)
    if ((tab = my_realloc(tab, (my_tablen(tab) + 1))) == NULL)
      return (NULL);
  return (tab);
}
