
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>


char	*before_new_line(char *s1)
{
	char	*s1_copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	printf("%d",i);
	s1_copy = (char *)malloc(sizeof(char) * (i + 1));
	if (s1_copy == NULL)
		return (NULL);
	while (s1[j] && j < i)
	{
		s1_copy[j] = s1[j];
		j++;
	}
	s1_copy[j] = '\0';
	return (s1_copy);
}

int	main(void)
{
	char	*test;

	test = before_new_line("hola\nme\n");
	printf("%s",test);
}