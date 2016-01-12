/*
** my_fun.c for myls in /home/theis_p/my_ls/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 04:24:23 2015 THEIS Paul
** Last update Sun Nov 29 19:14:12 2015 THEIS Paul
*/

#include "my_ls.h"

char	my_help()
{
  my_printf("Usage : ./my_ls [-aBdfFgGlorRSt] [FILES]\n\n");
  my_printf("-a: \tne pas ignorer les entrées débutant par .\n");
  my_printf("-B: \tne pas inclure les entrées se terminant par ~ "
	    "dans la liste\n");
  my_printf("-d: \tliste les dossiers eux meme non leur contenu\n");
  my_printf("-f: \tne pas trier, active -a et desactive les couleurs\n");
  my_printf("-F: \tajoute un indicateur (un de cela */=@|) aux entrées\n");
  my_printf("-g: \tidentique à -l, mais sans afficher le propriétaire\n");
  my_printf("-G: \tdans une longue liste, ne pas afficher "
	    "les noms de groupe\n");
  my_printf("-l: \tutilise le format long d'affichage\n");
  my_printf("-o: \tidentique a -l mais sans afficher "
	    "les informations de groupe\n");
  my_printf("-r: \tinverse l'ordre du tri\n");
  my_printf("-R: \taffiche recursivement les sous-repertoires\n");
  my_printf("-S: \ttri les fichiers en fonction de leur taille\n");
  my_printf("-t: \ttri les fichiers selon leur date de modification, "
	    "du plus recent au plus vieu\n");
  return (1);
}

int	my_strcmp_name(char *s1, char *s2, char reverse)
{
  int	i;
  int	j;
  char	diff;
  char	c1;
  char	c2;

  i = 0;
  j = 0;
  diff = 0;
  c1 = s1[0];
  c2 = s2[0];
  while (s1[i] && s2[j] && diff == 0)
    {
      c1 = s1[i] >= 'A' && s1[i] <= 'Z' ? s1[i] + 32 : s1[i];
      c2 = s2[j] >= 'A' && s2[j] <= 'Z' ? s2[j] + 32 : s2[j];
      if ((s1[i] < '0' || s1[i] > 'z'))
	c1 = s1[++i];
      if ((s2[j] < '0' || s2[j] > 'z'))
	c2 = s2[++j];
      diff = c1 == c2 ? 0 : 1;
      i += 1;
      j += 1;
    }
  return (reverse ? c2 - c1 : c1 - c2);
}

static int	my_strcmp_time(time_t t1, time_t t2, char reverse)
{
  if (reverse)
    {
      if (t1 < t2)
	return (-1);
      if (t1 > t2)
	return (1);
      return (0);
    }
  if (t1 < t2)
    return (1);
  if (t1 > t2)
    return (-1);
  return (0);
}

static int	my_strcmp_size(off_t s1, off_t s2, char reverse)
{
  if (reverse)
    {
      if (s1 < s2)
	return (-1);
      if (s1 > s2)
	return (1);
      return (0);
    }
  if (s1 < s2)
    return (1);
  if (s1 > s2)
    return (-1);
  return (0);
}

int		my_strcmp2(t_my_file *s1, t_my_file *s2, char reverse, char *opt)
{
  struct stat	*buf1;
  struct stat	*buf2;
  int		res;

  if (opt[NOTSORT])
    return (0);
  buf1 = my_malloc(sizeof(*buf1));
  buf2 = my_malloc(sizeof(*buf2));
  if ((lstat(my_pathfile(s1->path, s1->name, '\0'), buf1)) == -1)
    my_puterrno(my_pathfile(s1->path, s1->name, '\0'), errno);
  if ((lstat(my_pathfile(s2->path, s2->name, '\0'), buf2)) == -1)
    my_puterrno(my_pathfile(s2->path, s2->name, '\0'), errno);
  if (opt[TIME])
    res = my_strcmp_time(buf1->st_mtime, buf2->st_mtime, reverse);
  else if (opt[SIZE])
    res = my_strcmp_size(buf1->st_size, buf2->st_size, reverse);
  else
    res = my_strcmp_name(s1->name, s2->name, reverse);
  free(buf1);
  free(buf2);
  return (res);
}
