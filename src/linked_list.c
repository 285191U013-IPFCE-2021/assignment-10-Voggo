#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

 /* functions to create lists */
node* make_node(int v, node* q)
{
	node* p = malloc(sizeof(node));
	p->value = v;

	if (q == NULL)
		p->next = NULL;
	else
		p->next = q;
	return p;
}

void free_list (node * p)
{
  node *q = p;
  while (q != NULL)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list(node* p)
{
	// Add your code for exercise 1
	// There is NO testcode for this

	if (p != NULL) { 
		printf("|%d|\n", p->value);
		print_list(p->next);
		return;
	}
	if (p == NULL) {
		return;
	}
}

int sum_squares(node * p)
{
	// Add your code for excercise 2
	// You can find the tests in tests.cpp
 
    if (p == NULL) {
        return 0;
    }
    else if (p->next == NULL) {
        return square(p->value);
    }
    else {
        return square(p->value) + (sum_squares(p->next));
    }
}

node* map(node * p, int (*f) (int))
{
	// Add your code for excercise 3
	if (p == NULL){
		return NULL;
	} else {
		return make_node((*f)(p->value), map(p->next, (*f)));
	}
}


int square(int x)
{
	return x * x;
}
