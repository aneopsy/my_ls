/*
** my_path.c for myls in /home/theis_p/my_ls
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 27 01:49:54 2015 Paul THEIS
** Last update Sun Nov 29 18:11:27 2015 THEIS Paul
*/

#include "my_ls.h"

char	*my_separpath(char **str)
{
  char	*path;
  char	*file;
  int	i;
  int	j;
  int	limit;

  i = my_strlen((*str)) - 1;
  while ((*str)[i] && (*str)[i] != '/')
    i -= 1;
  i += 1;
  file = my_malloc(my_strlen((*str)) - i + 1);
  path = my_malloc(i + 1);
  limit = i;
  j = 0;
  while ((*str)[i])
    file[j++] = (*str)[i++];
  file[j] = '\0';
  i = 0;
  while (i < limit)
    path[i] = (*str)[i++];
  path[i] = '\0';
  (*str) = path;
  return (file);
}

char	*my_separpathD(char **str)
{
  char	*path;
  char	*file;
  int	i;
  int	j;
  int	limit;

  i = (*str)[my_strlen(*str) - 1] == '/' ?
    my_strlen((*str)) - 2 : my_strlen((*str)) - 1;
  while ((*str)[i] && (*str)[i] != '/')
    i -= 1;
  i += 1;
  file = my_malloc(my_strlen((*str)) - i + 1);
  path = my_malloc(i + 1);
  limit = i;
  j = 0;
  while ((*str)[i])
    file[j++] = (*str)[i++];
  file[j] = '\0';
  i = 0;
  while (i < limit)
    path[i] = (*str)[i++];
  path[i] = '\0';
  (*str) = path;
  return (file);
}

char	*my_pathfile(char *path, char *file, char c)
{
  char	*str;
  int	i;
  int	j;

  if ((str = my_malloc(my_strlen(path) + my_strlen(file) + 2)) == NULL)
    return (NULL);
  i = 0;
  while (path[i])
    str[i] = path[i++];
  j = 0;
  while (file[j])
    str[i++] = file[j++];
  if (c != '\0')
    str[i++] = c;
  str[i] = '\0';
  return (str);
}
