#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node* Insert(int x, struct tree_node* t)
{
	// Insert item x into the tree t
	if (t == NULL) {
		t = malloc(sizeof(struct tree_node));
		t->item = x;
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	if (x <= t->item) {
		t->left = Insert(x, t->left);
		return t;
	}

	if (x > t->item) {
		t->right = Insert(x, t->right);
		return t;
	}
}

// struct tree_node* Remove(int x, struct tree_node* t)
// {
// 	// Remove one item from the tree t
// 	if (!Contains(x, t)) {
// 		return t;
// 	}
// 	while (t->item != x) {
// 		if (t->item < x) {
// 			t = t->right;
// 		}
// 		else {
// 			t = t->left;
// 		}
// 	}

// 	struct tree_node* p = malloc(sizeof(struct tree_node));
// 	p = t->right;
// 	while (p->left != NULL && p->left->left != NULL) {
// 		p = p->left;
// 	}
// 	if (p->left = NULL) {
// 		t->item = p->item;
// 		t->right = p->right;
// 		return p;
// 	}
// 	else {
// 		t->item = p->left->item;
// 		struct tree_node* q = p;
// 		p->left = NULL;
// 		return q->left;
// 	}
// }

struct tree_node* Remove(int x, struct tree_node* t) {
	// tjekker om x findes i træet før den starter
	if (!Contains(x, t) || t == NULL) {
		return t;
	}
	//finder den node med x værdi
	else if (x < t->item) {
		t->left = Remove(x, t->left);
		return t;
	}
	if (x > t->item)
	{
		t->right = Remove(x, t->right);
		return t;
	}

	// håndtere fjernelsen af en node med et eller ingen børn.

	if (t->left == NULL) {
		struct tree_node* tmp = t->right; // hvis left er null skal node have værdien af den til hæjre. ligemeget om den er null eller har en værdi.
		free(t);
		return tmp; // rykker træet op en tak eller sætter det lig med leaf.
	}
	else if (t->right == NULL) {
		struct tree_node* tmp = t->left;
		free(t);
		return tmp;
	}
	else {
		// node har 2 børn så finder man den med den laveste værdi i det højre barn
		struct tree_node* temp = t;
		while (temp->left != NULL && temp != NULL) {
			temp = temp->left;
		}
		t->item = temp->item; // sætter værdien på x plads lig med den mindst større værdi i træet
		t->right = Remove(temp->item, t->right); // fjerner den flyttede node
	}
	return t;
}


int Contains(int x, struct tree_node* t)
{

	// Return true if the tree t contains item x. Return false otherwise.
	if (t == NULL) {
		return 0;
	}
	if (t->item == x) {
		return 1;
	}
	if (x <= t->item) {
		return Contains(x, t->left);
	}
	else if (x > t->item) {
		return Contains(x, t->right);
	}
}


struct tree_node* Initialize(struct tree_node* t)
{
	t = NULL;
	return t;
	// Create an empty tree
}

int Empty(struct tree_node* t)
{
	// Test if empty
	return (t == NULL);
}

int Full(struct tree_node* t)
{
	// Test if full
	// ??? 
	return 0;
}
