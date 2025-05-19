#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct TNODE{
	int key;
	TNODE* pLeft;
	TNODE* pRight;
} TNODE;
typedef struct TNODE *TREE;
//ham
void InsertTree(TREE &root , int x)
{
	if(root != NULL)
	{
		if(root->key==x) return;
		if(root-> key >x)
			InsertTree(root->pLeft,x);
		else
			InsertTree(root->pRight,x);
	}
	else
	{
		root= new TNODE;
		root->key=x;
		root->pLeft=root->pRight=NULL;
	}
}
void CreateTree(TREE &root)
{
	int x,n;
	printf("Nhap n = "); scanf("%d",&n);
	for(int i=1; i<=n;i++)
	{
		scanf("%d",&x);
		InsertTree(root,x);
	}
}
void NLR(TREE root){
	if (root != NULL)
	{
		printf("%d ",root->key);
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}
void LNR(TREE root)
{
	if (root != NULL)
	{
		LNR(root->pLeft);
		printf("%d ",root->key);
		LNR(root->pRight);
	}
}
void LRN(TREE root)
{
	if (root != NULL)
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		printf("%d ",root->key);
	}
}

TNODE* searchNode(TREE root, int x)
{
	if(root!=NULL)
	{
		if(root-> key == x)
		return root;
		if(root-> key > x)
			searchNode(root->pLeft, x);
		else
			searchNode(root->pRight, x);
	}
	return NULL;
}
int main()
{
	TREE root=NULL;
	CreateTree(root);
	printf("Duyet Node-Left-Right: ");NLR(root);printf("\n");
	printf("Duyet Left-Node-Right: ");LNR(root);printf("\n");
	printf("Duyet Left-Right-Node: ");LRN(root);printf("\n");
	searchNode(root,x);
	return 0;
}
//Xuat cay dang folder
void Output(TREE Root,int level) {
	for(int i=1;i<=level;i++)
		printf("\t");
	if (Root != NULL) {
		printf("%d\n", Root->key);
		Output(Root->pLeft,level+1);
		Output(Root->pRight,level+1);
	}
	else
		printf("--\n");
}
