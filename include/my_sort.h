/*
** my_sort.h for myls in /home/theis_p/my_ls/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 02:56:00 2015 THEIS Paul
** Last update Fri Nov 27 02:56:14 2015 THEIS Paul
*/

#ifndef MY_SORT_H_
# define MY_SORT_H_

typedef struct	s_my_def_file
{
  char		*name;
  unsigned char	type;
}		t_my_def_file;

char	my_sort_list(t_my_file **begin, char reverse, char *opt);
char	**my_sort_alpha(char **arr, char reverse);

#endif /* !MY_SORT_H_ */
