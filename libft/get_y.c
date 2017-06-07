#include "libft.h"

unsigned int				get_y(const char *s, char c)
{
	int				curseur;
	unsigned int	y;

	y = 0;
	if (s != NULL)
	{
		curseur = DEHORS;
		while (*s == c && *s != '\0')
			s++;
		while (*s != '\0')
		{
			if (*s == c)
				if (curseur == DEDANS)
					y++;
			curseur = (*s++ == c) ? DEHORS : DEDANS;
		}
		if (curseur == DEDANS)
			y++;
	}
	return (y);
}
