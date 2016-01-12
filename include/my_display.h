/*
** my_display.h for myls in /home/theis_p/my_ls/include/
**
** Made by THEIS Paul
** Login   <theis_p@epitech.eu>
**
** Started on  Fri Nov 27 02:54:53 2015 THEIS Paul
** Last update Fri Nov 27 03:25:46 2015 THEIS Paul
*/

#ifndef MY_DISPLAY_H_
# define MY_DISPLAY_H_

# define CURR_P(str) (str[0] == '.' && str[1] == '/')

void	my_putfile(char file, t_my_file *files, char *opt, char end);
void	my_puterror();
char	my_puterrno(char *str, int my_errno);

#endif /* !MY_DISPLAY_H_ */
