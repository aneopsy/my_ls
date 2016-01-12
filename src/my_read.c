/*
** my_read.c for myls in /home/theis_p/my_ls
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 27 01:43:47 2015 Paul THEIS
** Last update Sun Nov 29 19:06:04 2015 THEIS Paul
*/

#include "my_ls.h"

static char	my_read_optD(char *str, char *opt)
{
  t_my_file	*my_file;
  char		*file;

  my_file = NULL;
  file = my_separpathD(&str);
  if (file[0] == '\0')
    {
      write(2, "Error : unvalid file name\n", 26);
      exit(EXIT_FAILURE);
    }
  my_file = my_add_file(my_file, file, str, DT_REG);
  my_putfile(1, my_file, opt, 1);
  free(file);
  return (0);
}

static char	my_read_file(char *str, char *opt, char multiple)
{
  t_my_file	*my_file;
  char		*file;

  my_file = NULL;
  file = my_separpath(&str);
  if (!opt[DIRC] && errno != ENOTDIR)
    return (my_puterrno(str, errno));
  else if (file[0] == '\0')
    {
      write(2, "Error : unvalid file name\n", 26);
      exit(EXIT_FAILURE);
    }
  my_file = my_add_file(my_file, file, str, DT_REG);
  my_putfile(1, my_file, opt, 1);
  free(file);
  return (0);
}

char		my_read_dir(char *str, char *opt, char multiple, char end)
{
  DIR		*rep;
  t_my_file	*my_files;
  struct dirent	*my_file;
  int		count;

  count = 0;
  my_files = NULL;
  if  ((opt[DIRC] && multiple) ||
       !(rep = opendir(str)) && !(rep = opendir(my_pathfile(str, "\0", '/'))))
    return (my_read_file(str, opt, multiple));
  str = str[my_strlen(str) - 1] != '/' ? my_pathfile(str, "\0", '/') : str;
  while (my_file = readdir(rep))
    {
      if (opt[LONG])
	my_putall_l(my_file->d_name, str, &count);
      my_files = my_add_file(my_files, my_file->d_name, str, my_file->d_type);
    }

  my_printf((opt[RECURSIVE] || multiple ? "%s:\n" : "\0"), str);
  my_printf((opt[LONG] ? "total %d\n" : "\0"), count);
  my_putfile(my_sort_list(&my_files, opt[REVERSE], opt), my_files, opt, end);
  if (closedir(rep) == -1)
    return (my_puterrno(str, errno));
  return (0);
}

char	my_read_main(char **str, char *opt)
{
  int	i;

  i = 0;
  str = my_sort_alpha(str, opt[REVERSE]);
  if (opt[DIRC])
    {
      if (str[0] == 0)
	return (my_read_optD("./", opt));
      while (str[i] != 0)
	{
	  errno = 0;
	  (void)my_read_optD(str[i], opt);
	  i += 1;
	}
      return (0);
    }
  while (str[i] != 0)
    {
      errno = 0;
      (void)my_read_dir(str[i], opt, str[1] != 0 ? 1 : 0,
			str[i + 1] != 0 ? 0 : 1);
      i += 1;
    }
  return (0);
}
