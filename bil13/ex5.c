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

void	push_back(t_poly **poly, t_poly *monom)
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

	if (!monom)
		return ;
	if (!(*poly))
	{
		*poly = monom;
		return ;
	}
	if (monom->coeff == 0)
	{
		free(monom);
		return ;

	}
	if (monom->pow > (*poly)->pow) //[x3]->[]->[]->[]
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
	if (tmp->next && tmp->next->pow == monom->pow)
	{
		tmp->next->coeff += monom->coeff;
		free(monom);
	}
	else
	{
		monom->next = tmp->next;
		tmp->next = monom;
	}
}

void	print(t_poly *poly)
{
	printf("<");
	printf("%d", poly->coeff);
	if (poly->pow != 0)
	{
		printf("x");
		if (poly->pow > 1)
			printf("^%zu", poly->pow);
	}
		poly = poly->next;
	while (poly)
	{
		if (poly->coeff > 0)
		{
			printf("+");
		}
		printf("%d", poly->coeff);
		if (poly->pow != 0)
		{
			printf("x");
			if (poly->pow > 1)
				printf("^%zu", poly->pow);
		}
		poly = poly->next;
	}
	printf(">");
}



void	free_list(t_poly *list)
{
	t_poly	*tmp;

	while (list)
	{
		tmp = list;
		list = (list)->next;
		free(tmp);
	}
}

// t_poly	*parse_monom(FILE *file)
// {
// 	if ()
// }

// t_poly	*parse_poly(const char *pathname)
// {
// 	FILE	*file;
// 	char	c;
// 	if (file = fopen(pathname, "r") == NULL)
// 	{
// 		return NULL;
// 	}
// 	if (c = getc(file) != )
// 	while (/* condition */)
// 	{
// 		/* code */
// 	}
	
// }

int main()
{
	t_poly *list = NULL;
	sorted_insert(&list, new_node(-9, 3));
	sorted_insert(&list, new_node(-2, 2));
	sorted_insert(&list, new_node(5, 1));
	sorted_insert(&list, new_node(6, 4));
	sorted_insert(&list, new_node(7, 3));
	sorted_insert(&list, new_node(3, 0));
	sorted_insert(&list, new_node(-3, 9));
	print(list);
	free_list(list);
}

