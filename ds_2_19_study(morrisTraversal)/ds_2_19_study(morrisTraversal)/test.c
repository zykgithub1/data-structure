
#include<stdio.h>
#include<stdlib.h>


struct tNode
{
	int data;
	struct tNode* left;
	struct tNode* right;
};


void MorrisTraversal(struct tNode *T)
{
	struct tNode *current, *pre;
	if (!T)
		return;
	current = T;
	while (current)
	{
		if (current->left==NULL)
		{
			printf("%d ", current->data);
			current = current->right;
		}
		else
		{
			pre = current->left;
			while (pre->right&&pre->right != current)
				pre = pre->right;
			if (!pre->right)
			{
				pre->right = current;
				current = current->left;
			}
			else
			{
				pre->right = NULL;
				printf("%d ", current->data);
				current = current->right;
			}
		}
	}
}

struct tNode* newtNode(int data)
{
	struct tNode* tNode = (struct tNode*)
		malloc(sizeof(struct tNode));
	tNode->data = data;
	tNode->left = NULL;
	tNode->right = NULL;

	return(tNode);
}
void destroy(struct tNode* *T)
{
	if (!*T)
		return;
	if ((*T)->left)
		destroy(&(*T)->left);
	if ((*T)->right)
		destroy(&(*T)->right);
	free(*T);
}

int main()
{

	/* Constructed binary tree is
	1
	/   \
	2      3
	/  \
	4     5
	*/
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	MorrisTraversal(root);
	destroy(&root);
	return 0;
}