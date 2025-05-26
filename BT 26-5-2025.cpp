#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct TNODE 
{
    int key;
    struct TNODE* pLeft;
    struct TNODE* pRight
}TNODE;

typedef struct TNODE* TREE;
{
    TREE root;
}

void InsertTree(TREE &root, int x)
{
    if (root != NULL)
    {
        if (root ->key == x)
        {
            return;
        }
        else
        {
            if (root -> key > x)
            {
                InsertTree (root -> pLeft, x);
            }
            else 
            {
                InsertTree (root -> pRight, x);
            }
        }
    }
    else
    {
        root = new TNODE;
        root -> key = x;
        root -> pLeft = root -> pRight = NULL;
    }
}

void CreateTree (TREE &root)
{
    int x, n;
    printf ("\nNhap n: ");
    for (int i = 0; i <= n; i++)
    {
        scanf ("%d",&x);
        InsertTree(root, x);
    }
}
void NLR  (TREE root)
{
    if (root != NULL)
    {
        printf ("%d", root ->key);
        NLR (root -> pLeft);
        NLR (root -> pRight);
    }
}

void LNR (TREE root)
{
    if (root !=NULL)
    {
        LNR (root ->pLeft);
        printf ("%d", root -> key);
        LNR (root ->pRight);
    }
}
void LNR (TREE root)
{
    if (root != NULL)
    {
        LNR ( root -> pLeft);
        LNR (root -> pRight);
        printf ("%d", root -> key);
    }
}

TONE *searchNode(TREE root, int x)
{
    TONE *p = root;
    while (p!=NULL)
    {
        if (x == p -> key)
        {
            return;   
        }
        else 
        {
            if (x < p -> key)
            {
                p = p ->pLeft;
            }
            else
            {
                p = -> pRight;
            }
        }
    }
    return NULL;
}

void Output (TREE root, int level)
{
    for (int  i = 0; i <= level; i++)
    {
        printf ("\t");
        if (root != NULL)
        {
            printf ("%d\n", root ->key);
            Output(root -> pLeft, level +1);
            Output (root -> pRight, level +1);
        }
        else 
        {
            printf ("--\n");
        }
    }
}

void searchNode (TREE &p, TREE &q)
{
    if (q-> pRight != NULL)
    {
        searchNode (p, q-> pRight);
    }
    else
    {
        p -> key = q -> key;
        p = q;
        if ( q-> pLeft != NULL)
        {
            q = q -> pLeft;
        }
        else 
        {
            q =q -> pRight;
        }
    }
}

int delNode (TREE &root, int x)
{
    if (root ==NULL)
    {
        return 0;
    }
    if (root ->key > x)
    {
        return delNode (root ->pLeft, x);
    }
    else 
    {
        return delNode (root ->pRight, x);
    }
    TNODE* p = root;
    if (root ->pLeft == NULL)
    {
        root = root -> pRight;
    }
    else 
    {
        if (root -> pRight ==NULL)
        {
            root = root -> pLeft;
        }
        else 
        {
            searchStandFor (p, root -> pLeft);
        }
    }
    delete p;
    return 1;
}

int countLeafNodes (TREE root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root -> pLeft ==NULL && root -> pRight == NULL)
    {
        return 1;
    }
    return countLeafNodes (root ->pLeft) + countLeafNodes (root -> pRight);
}