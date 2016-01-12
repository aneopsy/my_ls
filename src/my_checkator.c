/*
** my_check.c for myls in /home/theis_p/my_ls/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Sun Nov 29 18:07:11 2015 THEIS Paul
** Last update Sun Nov 29 19:27:18 2015 THEIS Paul
*/

#include "my_ls.h"

static char	my_create_tab_opt(char c)
{
  char		tab[14];
  char		i;

  tab[ALL] = 'a';
  tab[BACKUP] = 'B';
  tab[DIRC] = 'd';
  tab[GROUP] = 'G';
  tab[INDICATOR] = 'F';
  tab[INFGRP] = 'o';
  tab[LONG] = 'l';
  tab[NOTSORT] = 'f';
  tab[OWNER] = 'g';
  tab[QUOTE] = 'Q';
  tab[RECURSIVE] = 'R';
  tab[REVERSE] = 'r';
  tab[SIZE] = 'S';
  tab[TIME] = 't';
  i = 0;
  while (tab[i] && tab[i] != c)
    i += 1;
  return (i);
}

char	my_check_dir(char *file)
{
  if (file[0] == '.' && (file[1] == '\0' ||
			 (file[1] == '.' && file[2] == '\0')))
    return (1);
  return (0);
}

char	my_check_opt(char *opt, char *str)
{
  int	i;
  char	c;

  i = 1;
  while (str[i])
    {
      if ((c = my_create_tab_opt(str[i])) < 14)
	opt[c] = 1;
      else
	return (1);
      i += 1;
    }
  opt[LONG] = opt[INFGRP] || opt[OWNER] ? 1 : opt[LONG];
  opt[ALL] = opt[NOTSORT] ? 1 : opt[ALL];
  return (0);
}
