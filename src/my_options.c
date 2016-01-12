/*
** my_options.c for myls in /home/theis_p/my_ls
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 27 01:53:05 2015 Paul THEIS
** Last update Sun Nov 29 18:59:43 2015 THEIS Paul
*/

#include "my_ls.h"

char		*my_opt_l(char *str, char *opt, t_max *max)
{
  struct stat	*buf;
  int		len;
  char		*link;

  buf = my_malloc(sizeof(*buf));
  link = my_malloc(256 * sizeof(char));
  if ((lstat(str, buf) == -1))
    my_puterrno(str, errno);
  my_putopt_l(buf, ctime(&buf->st_atime), opt, max);
  if (S_ISLNK(buf->st_mode))
    {
      if ((len = readlink(str, link, 256 * sizeof(char))) < 0)
        my_puterrno(str, errno);
      else
	link[len] = '\0';
      free(buf);
      return (link);
    }
  free(buf);
  return (NULL);
}

void		my_opt_R(t_my_file *files, char *opt)
{
  t_my_file	*tmp;

  tmp = files;
  while (tmp != NULL)
    {
      if ((opt[ALL] && !my_check_dir(tmp->name) || tmp->name[0] != '.')
	  && tmp->type == DT_DIR)
	{
	  my_printf("\n");
	  my_read_dir(my_pathfile(tmp->path, tmp->name, '/'), opt, 0, 1);
	}
      tmp = tmp->next;
    }
  free(tmp);
}

void	my_option_F(int i)
{
  char	optF[8];

  optF[0] = '/';
  optF[1] = '\0';
  optF[2] = '\0';
  optF[3] = '|';
  optF[4] = '=';
  optF[5] = '@';
  optF[6] = '*';
  if (i < 7)
    my_putchar(optF[i]);
}
