/*
** my_date.c for myls in /home/theis_p/my_ls
**
** Made by Paul THEIS
** Login   <theis_p@epitech.net>
**
** Started on  Fri Nov 27 02:38:12 2015 Paul THEIS
** Last update Sun Nov 29 19:27:40 2015 THEIS Paul
*/

#include <stdlib.h>
#include <time.h>
#include "my_ls.h"

char		*curr_year(char *my_date)
{
  char		*curr_y;
  int		i;
  int		j;
  time_t	curr_t;
  char		*my_year;

  if (my_date == NULL)
    {
      if ((curr_t = time(NULL)) == -1)
	my_puterror();
    }
  curr_y = my_date == NULL ? ctime(&curr_t) : my_date;
  i = my_strlen(curr_y) - 2;
  while (curr_y[i - 1] != ' ')
    i -= 1;
  j = 0;
  my_year = my_malloc(my_strlen(curr_y) - i);
  while (curr_y[i] && curr_y[i] != '\n')
    my_year[j++] = curr_y[i++];
  my_year[j] = '\0';
  return (my_year);
}

static void	my_standard_year(char *str, char *my_year)
{
  int		i;

  i = 4;
  while (str[i + 2] && str[i + 3] != ':')
    my_putchar(str[i++]);
  my_putstr(my_year);
}

static char	my_format_date(char *file_y, char *curr_y)
{
  int	i;

  i = 0;
  while (file_y[i] && curr_y[i] && file_y[i] == curr_y[i])
    i += 1;
  return (curr_y[i] - file_y[i]);
}

static void	my_standard_date(char *str)
{
  int		i;
  int		end;

  i = 4;
  end = my_strlen(str) - 2;
  while (str[end] != ':')
    end -= 1;
  while (i < end)
    {
      my_putchar(str[i]);
      i += 1;
    }
  my_putchar(' ');
}

char	my_putdate(char *str, char *current_year)
{
  int	i;
  char	point;
  char	*my_year;

  if ((my_year = curr_year(str)) == NULL)
    my_puterror();
  if (my_format_date(my_year, current_year) != 0)
    my_standard_year(str, my_year);
  else
    my_standard_date(str);
  free(my_year);
  free(current_year);
  return (0);
}
