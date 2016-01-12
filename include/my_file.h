/*
** my_file.h for myls in /home/theis_p/my_ls/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 02:55:14 2015 THEIS Paul
** Last update Fri Nov 27 05:52:41 2015 THEIS Paul
*/

#ifndef MY_FILE_H_
# define MY_FILE_H_

typedef struct		s_max
{
  int			max_size;
  int			max_link;
}			t_max;

typedef struct		s_my_file
{
  unsigned char		type;
  char			*name;
  char			*path;
  struct s_my_file	*next;
}			t_my_file;

t_my_file	*my_add_file(t_my_file *files, char *curr, char *path,
			     unsigned char type);

#endif /* !MY_FILE_H_ */
