/*
** my_display.c for myls in /home/theis_p/my_ls
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 27 01:50:25 2015 Paul THEIS
** Last update Sun Nov 29 19:23:06 2015 THEIS Paul
*/

#include "my_ls.h"

static char	my_putcolor(char *file, char *path, char *link, char *opt)
{
  struct stat	*buf;

  buf = my_malloc(sizeof(*buf));
  if ((lstat(my_pathfile(path, file, '\0'), buf)) == -1)
    return (my_puterrno(my_pathfile(path, file, '\0'), errno));
  my_printf(opt[QUOTE] ? "\"" : "\0");
  file = opt[DIRC] && !CURR_P(path) ? my_pathfile(path, file, '\0') : file;
  if (my_check_color(file, link, buf, opt) == 1)
    {
      my_printf("\033[1m\033[36m%s\033[0m", file);
      my_printf(opt[QUOTE] ? "\" -> " : " -> ");
      my_putcolor(link, link[0] == '/' ? "\0" : path, NULL, opt);
    }
  else
    my_printf(opt[QUOTE] ? "\"\n" : "\n");
  free(buf);
  return (0);
}

void		my_putfile(char file, t_my_file *files, char *opt, char end)
{
  char		*link;
  t_my_file	*tmp;
  t_max		*max;

  link = NULL;
  tmp = files;
  max =  my_find_digit(files);
  while (files != NULL)
    {
      if (!(opt[BACKUP] && files->name[my_strlen(files->name) - 1] == '~') &&
	  (file || opt[ALL] || !(files->name[0] == '.')))
	{
	  if (opt[LONG])
	    link = my_opt_l(my_pathfile(files->path, files->name, '\0'), opt, max);
	  (void)my_putcolor(files->name, files->path, link, opt);
	}
      files = files->next;
    }
  if (!file && !end)
    my_putchar('\n');
  if (opt[RECURSIVE] && !opt[DIRC])
    my_opt_R(tmp, opt);
  free(link);
  free(tmp);
}
