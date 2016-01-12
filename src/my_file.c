/*
** my_file.c for myls in /home/theis_p/my_ls/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sun Nov 29 18:07:30 2015 THEIS Paul
** Last update Sun Nov 29 18:20:59 2015 THEIS Paul
*/

#include "my_ls.h"

t_my_file	*my_add_file(t_my_file *files, char *curr,
			     char *path, unsigned char type)
{
  t_my_file	*tmp;
  t_my_file	*head;

  tmp = my_malloc(sizeof(*tmp));
  tmp->type = type;
  tmp->name = curr;
  tmp->path = path;
  tmp->next = NULL;
  if (files == NULL)
    return (tmp);
  head = files;
  while (head->next != NULL)
    head = head->next;
  head->next = tmp;
  return (files);
}
