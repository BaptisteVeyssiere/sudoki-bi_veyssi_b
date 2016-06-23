/*
** sudoki-bi.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Fri Feb 26 21:34:21 2016 Baptiste veyssiere
** Last update Sun Feb 28 18:47:04 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

int	my_strlen(char *s)
{
  int	i;

  i = -1;
  while (s[++i] != 0);
  return (i);
}

int	error_msg(char *msg, int ret)
{
  write(2, msg, my_strlen(msg));
  return (ret);
}

int		sudoki_bi()
{
  char		***tab;
  t_list	*list;
  t_present	*present;
  int		i;

  if ((tab = get_all_tab()) == NULL)
    return (-1);
  i = -1;
  while (++i < my_tablen(tab))
    {
      if ((present = get_present(tab[i])) == NULL ||
	  (list = get_list(tab[i])) == NULL)
	return (-1);
      filler(tab[i], list, present);
      if (check_valid(tab[i]) == 1)
        error_aff_tab();
      else
        aff_table(tab[i]);
      if (i < (my_tablen(tab) - 1))
        write(1, "####################\n", 21);
      free_function_bis(list, present);
    }
  free_function(tab);
  return (0);
}

int	main()
{
  if (sudoki_bi() == -1)
    return (-1);
  return (0);
}
