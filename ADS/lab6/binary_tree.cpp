#include <iostream>

//User-defined node for binary tree
typedef struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};

// Initialize an empty tree
void init(treeNode *newTree)
{
    newTree->data = NULL;newTree->left = newTree->right = NULL;
}

// Check if the tree is empty
bool isEmpty(treeNode *tree)
{
    return (tree != NULL);
}

//NLR
void preOrder(treeNode *tree)
{
    if(tree != NULL)
    {
        std::cout << tree->data << "-";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
//LNR
void inOrder(treeNode *tree)
{
    if(tree != NULL)
    {
        inOrder(tree->left);
        std::cout << tree->data << "-";
        inOrder(tree->right);
    }
}
//LRN
void postOrder(treeNode *tree)
{
    if(tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        std::cout << tree->data << "-";
    }
}

void addNode(treeNode *tree, int newData)
{
    if(tree == NULL)
    {
        if(newData == tree->data)
        {
            std::cout << "node already exists" << std::endl;
        }
        else
        {
            if(newData < tree->data)
            {
                addNode(tree->left, newData);
            }
            else
            {
                addNode(tree->right, newData);
            }
        }
    }
    else
    {
        tree = new treeNode();
        tree->data = newData;
        tree->left = tree->left = NULL;
    }
}

void deleteNode(treeNode *tree, int delTarget)
{
    if(tree == NULL)
    {
        std::cout << "node does not exist" << std::endl;
    }
    else
    {
        if(tree->data > delTarget)
        {
            deleteNode(tree->right, delTarget);
        }
        else if(tree->data < delTarget)
        {
            deleteNode(tree->left, delTarget);
        }
        else
        {
            treeNode *P = tree;
            if(tree->left == NULL)
            {
                tree = tree->right;
            }
            else if(tree->right == NULL)
            {
                tree = tree->left;
            }
            else
            {
                treeNode *S = tree;
                treeNode *Q = S->left;

                while(Q->right != NULL)
                {
                    S = Q;
                    Q = Q->right;
                    
                }
                P->data = Q->data;
                S->right = Q->left;
                delete Q;
            }
        }
    }
}
//Driver code
int main()
{
    treeNode *tree_one = new treeNode();
    init(tree_one);

    addNode(tree_one, 1); // root
    addNode(tree_one, 5);
    addNode(tree_one, 10);
    addNode(tree_one, 4);
    addNode(tree_one, 9);
    addNode(tree_one, 50);

    preOrder(tree_one);

    deleteNode(tree_one, 50);
    
    preOrder(tree_one);

    //free the memory
    delete tree_one;
    
    return 0;
}