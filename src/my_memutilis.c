/*
** memutilis.c for myls in /home/theis_p/my_ls/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 03:37:35 2015 THEIS Paul
** Last update Sun Nov 29 18:54:06 2015 THEIS Paul
*/

#include "my_ls.h"

char	my_puterrno(char *str, int my_errno)
{
  errno = my_errno;
  my_printf("my_ls: cannot open %s: %s\n", str, strerror(my_errno));
  return (EXIT_FAILURE);
}

void	my_puterror()
{
  write(2, "Error : malloc not allocated !\n", 28);
  exit(EXIT_FAILURE);
}

void	*my_malloc(size_t const size)
{
  void	*m;

  m = malloc(size);
  if (m == NULL)
    my_puterror();
  return m;
}
