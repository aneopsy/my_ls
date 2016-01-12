/*
** my_ls.c for myls in /home/theis_p/my_ls
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 27 01:34:29 2015 Paul THEIS
** Last update Sun Nov 29 19:26:35 2015 THEIS Paul
*/

#include <stdlib.h>
#include "my_ls.h"

static char	my_is_d(char **my_tab, char *opt)
{
  return (my_tab[0] != 0 || opt[DIRC]);
}

static char	*my_strcpy2(char *my_file)
{
  int	i;
  char	*str;

  str = my_malloc(my_strlen(my_file) + 1);
  i = 0;
  while (my_file[i])
    str[i] = my_file[i++];
  str[i] = '\0';
  return (str);
}

static char	**my_nbr_words(int argc, char **argv)
{
  int		i;
  int		count;
  char		**tab;

  i = 1;
  count = 0;
  while (i < argc)
    {
      if (argv[i][0] != '-')
	count += 1;
      i += 1;
    }
  tab = my_malloc(count + 1);
  i = 0;
  while (i <= count)
    {
      tab[i] = my_malloc(1);
      tab[i] = 0;
      i += 1;
    }
  return (tab);
}

int	main(int argc, char **argv)
{
  int	i;
  int	pos;
  char	opt[8];
  char	**tb;

  i = 0;
  while (i < 8)
    opt[i++] = 0;
  if ((tb = my_nbr_words(argc, argv)) == NULL)
    my_puterror();
  i = 1;
  pos = 0;
  while (i < argc)
    {
      if (argv[i][0] == '-')
	{
	  if (my_check_opt(opt, argv[i]))
	    return (my_help());
	}
      else
	tb[pos++] = my_strcpy2(argv[i]);
      i += 1;
    }
  return (my_is_d(tb, opt) ? my_read_main(tb, opt) :
	  my_read_dir("./", opt, 0, 1));
}
