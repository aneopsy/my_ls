/*
** my_color.c for myls in /home/theis_p/my_ls
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 27 01:46:18 2015 Paul THEIS
** Last update Fri Nov 27 01:49:37 2015 Paul THEIS
*/

#include "my_ls.h"

static char	**my_create_tab_color(char **my_col)
{
  char		*color[8];

  color[0] = "\033[1;34m";
  color[1] = "\033[1;33m";
  color[2] = "\033[1;33m";
  color[3] = "\033[21;33m";
  color[4] = "\033[1;31m";
  color[5] = "\033[1;36m";
  color[6] = "\033[1;33m";
  color[7] = 0;
  my_col = color;
  return (my_col);
}

static char	*my_create_tab_opt_col(char *my_opt, struct stat *buf)
{
  char		my_opt_col[8];

  my_opt_col[0] = S_ISDIR(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[1] = S_ISCHR(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[2] = S_ISBLK(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[3] = S_ISFIFO(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[4] = S_ISSOCK(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[5] = S_ISLNK(buf->st_mode) == 1 ? 1 : 0;
  my_opt_col[6] = ((buf->st_mode & S_IXGRP) || (buf->st_mode & S_IXUSR) ||
		   (buf->st_mode & S_IXOTH));
  my_opt_col[7] = S_ISREG(buf->st_mode) == 1 ? 1 : 0;
  my_opt = my_opt_col;
  return (my_opt);
}

char	my_check_color(char *file, char *link, struct stat *buf, char *opt)
{
  int	i;
  char	*my_opt_col;
  char	**color;

  color = my_create_tab_color(color);
  my_opt_col = my_create_tab_opt_col(my_opt_col, buf);
  i = 0;
  while (my_opt_col[i] != 1 && i < 8)
    i += 1;
  if (i == 7 || opt[NOTSORT])
    my_printf("%s", file);
  else if (i == 6)
    my_printf("\033[1;32m%s\033[0m", file);
  else if (i != 5)
    my_printf("%s%s\033[0m", color[i], file);
  else
    {
      if (!link)
  	my_printf("%s%s\033[0m", color[i], file);
      else
  	return (1);
    }
  if (opt[INDICATOR])
    my_option_F(i);
  return (0);
}
