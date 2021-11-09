#include <stdio.h>
#include <stdlib.h>

typedef struct Polynom
{
	int				coeff;
	size_t			pow;
	struct Polynom	*next;
}	t_poly;

t_poly	*new_node(int coeff, size_t pow)
{
	t_poly	*new;

	new = (t_poly *)malloc(sizeof(t_poly));
	if (!new)
	{
		perror("malloc failed\n");
		return (NULL);
	}
	new->coeff = coeff;
	new->pow = pow;
	new->next = NULL;
	return (new);
}

void	*push_back(t_poly **poly, t_poly *monom)
{
	t_poly	*tmp;

	if (!(*poly))
	{
		*poly = monom;
		return ;
	}
	tmp = *poly;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = monom;
}

void	sorted_insert(t_poly **poly, t_poly *monom)
{
	t_poly	*tmp;

	if (!(*poly))
	{
		*poly = monom;
		return ;
	}
	if (monom->pow > (*poly)->pow)
	{
		monom->next = (*poly);
		*poly = monom;
		return ;
	}
	tmp = (*poly);
	while (tmp->next && tmp->next->pow > monom->pow)
	{
		tmp = tmp->next;
	}
	if (tmp->next->pow == monom->pow)
	{
		tmp->next->coeff += monom->coeff;
	}
	else
	{
		monom->next = tmp->next;
		tmp->next = monom;
	}
}

void sort()

t_poly	*parse(char *pathname)
{

}



