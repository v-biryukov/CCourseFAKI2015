#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node* left;
	struct node* right;
};
typedef struct node Node;


Node* tree_add(Node* tree, int x)
{
	if (tree == NULL)
	{
		tree = (Node*)malloc(sizeof(Node));
		tree->val = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (x < tree->val)
	{
		tree->left = tree_add(tree->left, x);
	}
	else if (x > tree->val)
	{
		tree->right = tree_add(tree->right, x);
	}
	return tree;
}


void tree_print(Node* tree)
{
	if (tree)
	{
		tree_print(tree->left);
		printf("%d ", tree->val);
		tree_print(tree->right);
	}
}

void tree_destroy(Node* tree)
{
	if (tree)
	{
		tree_destroy(tree->left);
		tree_destroy(tree->right);
		free(tree);
	}
}

int max(int x, int y)
{
	return (x > y) ? x : y;
}

int depth(Node* tree)
{
	if (tree)
		return 1 + max(depth(tree->left), depth(tree->right));
	else
		return 0;
}



int main()
{
	Node * tree = NULL;
	tree = tree_add(tree, 7);
	tree = tree_add(tree, 3);
	tree = tree_add(tree, 2);
	tree = tree_add(tree, 5);
	tree = tree_add(tree, 1);
	tree = tree_add(tree, 9);
	tree = tree_add(tree, 5);
	tree = tree_add(tree, 4);
	tree = tree_add(tree, 6);
	tree_print(tree);
	printf("\nDepth = %d\n", depth(tree));

    tree_destroy(tree);
	return 0;
}