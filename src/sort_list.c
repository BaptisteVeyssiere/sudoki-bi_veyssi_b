/*
** sort_list.c for sudoki-bi in /home/VEYSSI_B/rendu/Rushs/sudoki-bi
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Sat Feb 27 17:17:35 2016 Baptiste veyssiere
** Last update Sat Feb 27 17:24:13 2016 Baptiste veyssiere
*/

#include "sudoki_bi.h"

void		sort_list(t_list **list)
{
  t_list	*tmp;
  t_list	*previous;

  tmp = *list;
  previous = NULL;
  while (tmp->next != NULL)
    {
      if (compare_size(tmp, tmp->next))
	{
	  swap_list(previous, tmp, tmp->next, list);
	  previous = NULL;
	  tmp = *list;
	}
      else
	{
	  previous = tmp;
	  tmp = tmp->next;
	}
    }
}

int		compare_size(t_list *current, t_list *next)
{
  if (current->possibilities <= next->possibilities)
    return (0);
  else
    return (1);
}

void		swap_list(t_list *previous, t_list *current, t_list *next, t_list **list)
{
  t_list	*tmp;

  if (previous == NULL)
    *list = next;
  else
    previous->next = next;
  tmp = next->next;
  next->next = current;
  current->next = tmp;
}
