extern "C" {
    // Add the header files required to run your main 
#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>

#include "C:\Users\NIels\OneDrive - Aarhus Universitet\Dokumenter\prog 1. sem/assignment-10-Voggo/include/linked_list.h"
}


/* functions to create lists */
node* make_node(int v, node* q)
{
    node* p = (node*)malloc(sizeof(node));
    p->value = v;

    if (q == NULL)
        p->next = NULL;
    else
        p->next = q;
    return p;
}

/* free all nodes in the list p */
void free_list(node* p)
{
	node* q;
	while (p->next != NULL)
	{
		q = p;
		p = p->next;
		free(q);
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

int sum_squares(node* p)
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

node* map(node* p, int (*f) (int))
{
    // Add your code for excercise 3
    if (p == NULL) {
        return NULL;
    }
    else {
        return make_node((*f)(p->value), map(p->next, (*f)));
    }
}


int square(int x)
{
    return x * x;
}


// File for sandboxing and trying out code
int main(int argc, char** argv)
{
    node* ns = NULL;
    ns = NULL;
    ns = make_node(1,
        make_node(2,
            make_node(3,
                make_node(4,
                    make_node(5,
                        NULL)))));
    print_list(ns);
    printf("%d\n", sum_squares(ns));
    free(ns);
    ns = NULL;
    print_list(ns);
    printf("%d\n", sum_squares(ns));

    // node* p = NULL;
    // p = map(p, square);
    // print_list(p);
    return 0;
}