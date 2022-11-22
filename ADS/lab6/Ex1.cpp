#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
 
/*
A binary tree can be used to sort n elements of an array data. First, create a
complete binary tree, a tree with all leaves at one level, whose height h = (lg n) +
1, and store all elements of the array in the first n leaves. In each empty leaf, store
an element E greater than any element in the array.

Figure (a) shows an example for data = 8, 20, 41, 7, 2, h = ceil(lg(5)) + 1 = 4,
and E = 42. Then, starting from the bottom of the tree, assign to each node the
minimum of its two children values, as in Figure (b), so that the smallest element
emin in the tree is assigned to the root.

If a leaf node is to be removed, this node is replaced by a new node with the
same value of its parent node.

If a node is added into the tree, it will be a leaf node. Normally a node with
value E is replaced with new value. It’s necessary to verify recursively all values of
its parent and make any possible modification if necessary so that the tree rules are
respected.

Implement this tree structure in C/C++ with the necessary functions.

- write a function to initialize an array with n random values (done)
- write a function to build this binary tree with the above definition with any
data structure learnt in lectures
- write a function to display the tree information (done)
- write a function to search an input value using recursion. If found, display all 
the subtree with the found node as the root of this subtree’ or else return -1. (done)
- write a function to insert new nodes into the tree and another one to remove nodes from the tree  (done)
*/

struct node
{
    int value;
    node *left;
    node *right;
};
typedef struct node TreeNode;


//Initialize a new array with n random variables
int *createArray(int n)
{
    //Since normal array can only have fixed size, we use dynamic array for this
    //Allocate some memory for the new array with size of n
    int *array = new int[n];
    
    //Set the seed for rand() in order to return different sequence every executions
    srand(time(NULL)); 
     
    for(int i = 0; i < n; i++)
    { 
        //Generate a new integer value between 1 - 100 in element i of array
        array[i] = (rand() % 100) + 1; 
    }

    //Return the new array
    return array;
}
// Return minimum value in the array
int findMin(int arr[], int size)
{
    int min = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
// Return the E number, a number that is bigger than all elements, in the array
int returnE(int arr[], int size)
{
    int max = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }

    // the number E just needs to be bigger than all elements in the array,
    // so we simply add 1 to the max element
    return max + 1;
}

//Insert a new node into the tree
// TreeNode *tree in this function refers to the current node in the tree, in this case it starts from root
//This one is from the slide
int insertNode(TreeNode *tree, int x)
{
    // if the current node is not null
    if(tree != NULL)
    {
        // if the node is already in the tree, simply do nothing
        if(x == tree->value)
        {
            cout << "Node already in the tree." << endl;
            return 0;
        }
        else
        {
            // traverse either left or right depend on x and node->value
            if(x < tree->value)
            {
                insertNode(tree->left, x);
            }
            else
            {
                insertNode(tree->right, x);
            }
        }
    }
    else //insert a new node if the node is not found already
    {
        tree = new TreeNode();
        tree->value = x;
        tree->left = NULL;
        tree->right = NULL;

        cout << "Node successfully added" << endl;
        return 1;
    }
}

// Delete a node that has the value x (this is from the slide)
int deleteNode(TreeNode *tree, int x)
{
    if(tree == NULL) //If node =/= exist
        return 0;
    else if(x < tree->value) // Traverse to left node 
        return deleteNode(tree->left, x);
    else if(x > tree->value) // Traverse to right node
        return deleteNode(tree->right, x);
    else if(x == tree->value) //If the target node is found for deletion
    {
        // From here we consider the target node as a root of a subtree
        TreeNode *P = tree;

        //Traverse to right child if the left one does not exist
        if(tree->left == NULL)
        {
            tree = tree->right;
        }
        //Traverse to left child if the right one does not exist
        else if(tree->right == NULL)
        {
            tree = tree->left;
        }
        else // If the node has 2 children
        {
            TreeNode *S = tree;
            TreeNode *Q = S->left;

            while(Q->right != NULL)
            {
                S = Q;
                Q = Q->right;
            }

            P->value = Q->value;
            S->right = Q->left;

            //Finally, you delete the target node
            delete Q;
        }
    }
    return 1;
}

//Calculate height of the tree
int height(int arraySize)
{
    //Round up log2(arraySize) and then + 1
    return ceil(log2(arraySize)) + 1;
}

// Pre-order (NLR)
void printBT(TreeNode* node)
{
    if(node != NULL)
    {
        cout << node->value << " ";
        printBT(node->left);
        printBT(node->right);
    }
}

// Search for a node with given value
int searchNode(TreeNode *node, int target)
{
    if(node != NULL)
    {
        // If the target node is found, display all subtree with the target node as the root, and return the root's value
        if(node->value == target)
        {
            printBT(node);
            cout << "Node does exist: ";
            return 0;
        }
        else // Keep traversing to next level, right and left until you found the target
        {
            searchNode(node->right, target);
            searchNode(node->left, target);
        }
    }
    else // If the node is not in the tree, returns -1
    {
        return -1;
    }
}

int SearchNode(TreeNode *node, int target)
{
    if(node != NULL)
    {
        // If the target node is found, display all subtree with the target node as the root, and return the root's value
        if(node->value == target)
        {
            printBT(node);
            cout << "Node does exist: ";
            return node->value;
        }
        else // Keep traversing to next level, right and left until you found the target
        {
            return SearchNode(node->right, target);
            return SearchNode(node->left, target);
        }
    }
    else // If the node is not in the tree, returns -1
    {
        return -1;
    }
}

void createBST(int array[], int arraySize)
{
    cout << "Array: " << endl;
    for(int i = 0; i < arraySize; i++)
    {
        cout << array[i] << endl;
    }

    //Create a new tree
    TreeNode *root = new TreeNode();
    root->value = findMin(array, arraySize);
    root->left = NULL;
    root->right = NULL;

    //Insert all elements in the array into the tree
    for(int i = 1; i < arraySize; i++)
    {
        insertNode(root, array[i]);
    }

    //Print the tree
    printBT(root);

    //Search for a node with value 10
    searchNode(root, 10);

    //Delete a node with value 10
    deleteNode(root, 10);

    //Print the tree again
    printBT(root);
}

int main()
{
    // Initialize a dynamic array with a specific size
    int *arr;
    int size = 6;
    arr = createArray(size);

    createBST(arr, size);

    delete arr;
    return 0;
}