#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char data;
	struct node *left;
	struct node *right;
	struct node *next;
};

struct node *head = NULL;

struct node* createnode(char data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> next = NULL;

	return temp;
	
}

void push(struct node *ptr)
{
	if(head == NULL)
		head = ptr;
	else
	{
		ptr -> next = head;
		head = ptr;
	}
}

struct node* pop()
{
	struct node *ptr = head;
	if(head != NULL)
	head = head -> next;
	return ptr;
}


void inorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		inorder(ptr -> left);
		printf("%c", ptr->data);
		inorder(ptr -> right);
	}
}


void preorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		printf("%c", ptr -> data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		postorder(ptr -> left);
		postorder(ptr -> right);
		printf("%c", ptr -> data);
	}
}


int main()
{

	struct node *a, *b, *exp;
	char s[100];
	printf("\nEnter the postfix expression : ");
	scanf("%s", s);
	//printf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < l; i++)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^')
		{
			exp = createnode(s[i]);
			a = pop();
			b = pop();
			exp -> left = b;
			exp -> right =a;
			push(exp);
		}
		else
		{
			exp = createnode(s[i]);
			push(exp);
		}
	}

	exp = pop();
	printf("\nInorder Traversal : ");
	inorder(exp);
	printf("\nPreorder Traversal : ");
	preorder(exp);
	printf("\nPostorder Traversal gives : ");
	postorder(exp);
	return 0;
}