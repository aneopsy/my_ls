/*
** my_digit_manager.c for myls in /home/theis_p/my_ls/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 04:30:01 2015 THEIS Paul
** Last update Sun Nov 29 19:39:39 2015 THEIS Paul
*/

#include "my_ls.h"

int	nbrDigit(int n)
{
    if (n < 0) return nbrDigit((n == MININT) ? MAXINT : -n);
    if (n < 10) return 1;
    return 1 + nbrDigit(n / 10);
}

t_max		*my_find_digit(t_my_file *files)
{
  struct stat	*buf;
  t_my_file	*tmp;
  t_max		*max;

  tmp = files;
  buf = my_malloc(sizeof(*buf));
  max = my_malloc(sizeof(*max));
  max->max_size = 0;
  max->max_link = 0;
  while (tmp != NULL)
    {
      stat(my_pathfile(tmp->path, tmp->name, '\0'), buf);
      if (buf->st_size > max->max_size)
	max->max_size = buf->st_size;
      if (buf->st_nlink > max->max_link)
	max->max_link = buf->st_nlink;
      tmp = tmp->next;
    }
  free(buf);
  free(tmp);
  return (max);
}
