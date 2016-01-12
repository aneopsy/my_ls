/*
** my_display_l.c for myls in /home/theis_p/my_ls
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 27 01:50:59 2015 Paul THEIS
** Last update Sun Nov 29 18:57:47 2015 THEIS Paul
*/

#include "my_ls.h"

static void	my_putuid_grp(struct passwd *my_uid,
			      struct group *my_gid, char *opt)
{
  if (!opt[OWNER])
    my_printf("%s ", my_uid->pw_name);
  if (!opt[GROUP] && !opt[INFGRP])
    my_printf("%s ", my_gid->gr_name);
}

static void	my_putpermission(struct stat *buf)
{
  if (S_ISDIR(buf->st_mode))
    my_putchar('d');
  else if (S_ISLNK(buf->st_mode))
    my_putchar('l');
  else if (S_ISCHR(buf->st_mode))
    my_putchar('c');
  else if (S_ISBLK(buf->st_mode))
    my_putchar('b');
  else if (S_ISFIFO(buf->st_mode))
    my_putchar('p');
  else if (S_ISSOCK(buf->st_mode))
    my_putchar('s');
  else
    my_putchar('-');
  my_printf((buf->st_mode & S_IRUSR) ? "r" : "-");
  my_printf((buf->st_mode & S_IWUSR) ? "w" : "-");
  my_printf((buf->st_mode & S_IXUSR) ? "x" : "-");
  my_printf((buf->st_mode & S_IRGRP) ? "r" : "-");
  my_printf((buf->st_mode & S_IWGRP) ? "w" : "-");
  my_printf((buf->st_mode & S_IXGRP) ? "x" : "-");
  my_printf((buf->st_mode & S_IROTH) ? "r" : "-");
  my_printf((buf->st_mode & S_IWOTH) ? "w" : "-");
  my_printf((buf->st_mode & S_IXOTH) ? "x " : "- ");
}

void	my_putopt_l(struct stat *buf, char *date, char *opt, t_max *max)
{
  my_putpermission(buf);
  my_printf("%*d ", nbrDigit(max->max_link), buf->st_nlink);
  my_putuid_grp(getpwuid(buf->st_uid), getgrgid(buf->st_gid), opt);
  if (S_ISCHR(buf->st_mode) || S_ISBLK(buf->st_mode))
    my_printf("%u, %u ", major(buf->st_rdev), minor(buf->st_rdev));
  else
    my_printf("%*ld ", nbrDigit(max->max_size), buf->st_size);
  if (my_putdate(ctime(&buf->st_mtime), curr_year(NULL)))
    my_puterror();
}

void		my_putall_l(char *str, char *path, int *count)
{
  struct stat	*buf;

  if (str[0] != '.')
    {
      buf = my_malloc(sizeof(*buf));
      if ((lstat(my_pathfile(path, str, '\0'), buf)) == -1)
	(void)my_puterrno(my_pathfile(path, str, '\0'), errno);
      else
	*count += (buf->st_blocks / 2);
      free(buf);
    }
}
