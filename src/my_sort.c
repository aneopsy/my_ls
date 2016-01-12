/*
** my_sort.c for myls in /home/theis_p/my_ls/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 03:34:25 2015 THEIS Paul
** Last update Fri Nov 27 03:49:54 2015 THEIS Paul
*/

#include "my_ls.h"

static t_my_def_file	*crt_def(char *name, unsigned char type)
{
  t_my_def_file		*tmp;

  tmp = my_malloc(sizeof(*tmp));
  tmp->name = name;
  tmp->type = type;
  return (tmp);
}

char		my_sort_list(t_my_file **begin, char reverse, char *opt)
{
  t_my_file	*head;
  char		done;
  t_my_def_file	*tmp;

  done = 1;
  while (done)
    {
      head = (*begin);
      done = 0;
      while (head != NULL && head->next != NULL)
	{
	  if (my_strcmp2(head, head->next, reverse, opt) > 0)
	    {
	      tmp = crt_def(head->name, head->type);
	      head->name = (head->next)->name;
	      head->type = (head->next)->type;
	      (head->next)->name = tmp->name;
	      (head->next)->type = tmp->type;
	      free(tmp);
	      done = 1;
	    }
	  head = head->next;
	}
    }
  return (0);
}

char	**my_sort_alpha(char **arr, char reverse)
{
  int	i;
  int	done;
  char	*tmp;

  done = 1;
  while (done)
    {
      done = 0;
      i = 0;
      while (arr[i] != 0 && arr[i + 1] != 0)
	{
	  if (my_strcmp_name(arr[i], arr[i + 1], reverse) > 0)
	    {
	      tmp = arr[i];
	      arr[i] = arr[i + 1];
	      arr[i + 1] = tmp;
	      done = 1;
	    }
	  i += 1;
	}
    }
  return (arr);
}
