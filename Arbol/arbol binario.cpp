#include <iostream>
using namespace std;

struct Tree
{
	char data;
	Tree *left;
	Tree *right;  
	Tree *parent;  
};

struct Tree *newTreeNode(int data) 
{
	Tree *node = new Tree;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node-> parent = NULL;
	return node;
}

struct Tree* insertTreeNode(struct Tree *node, int data)
{
	static Tree *p;
	Tree *retNode;

	if(node == NULL)  {
	    retNode = newTreeNode(data);
	    retNode->parent = p;
	    return retNode;
	}
	if(data <= node->data ) { 
	    p = node;
	    node->left = insertTreeNode(node->left,data);
	} 
	else {
	    p = node;
	    node->right = insertTreeNode(node->right,data);
	} 
	return node;
}

void clear(struct Tree *node)
{
	if(node != NULL) {
	    clear(node->left);
	    clear(node->right);
	    delete node;
	}
}

void printTreeInOrder(struct Tree *node) // 4
{
	if(node == NULL) return;

	printTreeInOrder(node->left);
	cout << node->data << " ";
	printTreeInOrder(node->right);
}

void printTreePostOrder(struct Tree *node) // 3
{
	if(node == NULL) return;

	printTreePostOrder(node->left);
	printTreePostOrder(node->right);
	cout << node->data << " ";
}

void printTreePreOrder(struct Tree *node) // 2
{
	if(node == NULL) return;

	cout << node->data << " ";
	printTreePreOrder(node->left);
	printTreePreOrder(node->right);
}

void printTreeReverseOrder(struct Tree *node) //1
{
	if(node == NULL) return;
	if(node->left == NULL && node->right == NULL) {
	    cout << node->data << " ";
	    return;
	}
	
	printTreeReverseOrder(node->right);
	cout << node->data << " ";
	printTreeReverseOrder(node->left);
}

int main(int argc, char **argv)
{
	Tree *root = newTreeNode('F');
	insertTreeNode(root,'B');
	insertTreeNode(root,'A');
	insertTreeNode(root,'D');
	insertTreeNode(root,'C');  
	insertTreeNode(root,'E');
	insertTreeNode(root,'G');
	insertTreeNode(root,'I');
	insertTreeNode(root,'H');

	/* print tree in order */
	cout << "increasing sort order\n";
	printTreeInOrder(root);
	cout << endl;

	/* print tree in postorder*/
	cout << "post order \n";
	printTreePostOrder(root);
	cout << endl;

	/* print tree in preorder*/
	cout << "pre order \n";
	printTreePreOrder(root);
	cout << endl;

	/* print tree in reverse order*/
	cout << "reverse order \n";
	printTreeReverseOrder(root);
	cout << endl;
	
	clear(root);

	return 0;
}
