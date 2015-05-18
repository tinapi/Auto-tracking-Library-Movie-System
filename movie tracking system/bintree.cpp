//---------------------------------------------------------------------------
// BINTREE.CPP
// class BinTree
// Author: Jingjing Dong
// Date: 04/18/2014
// Version: 1.1
//---------------------------------------------------------------------------
// BinTree class:  a binary search tree class includes additional features:
//   -- read in lines from a data file to build binary trees
//   -- allows for comparison of 2 BinTrees, node by node and structure
//   -- allows for assignment of 2 BinTrees
//     -- allows for retrieving data of a given object if exists in the tree
//     -- allows for getting the depth of a given value in the tree
//     -- allows for filling an array with all values in the tree
//     -- allows for building a balanced BinTree from a sorted array
//     -- allows for displaying the whole BinTree in sideways
//
// Assumptions:
//   -- a tree Node has 3 pointer
//     -- a tree Node which holds a NodeData* for the data, holds a Node* for
//        its left child, and holds a Node* for its right child
//   -- BinTree is initially created as an empty tree
//---------------------------------------------------------------------------

#include "bintree.h"

//-------------------------- Constructor ------------------------------------
// Default constructor for class BinTree
// Preconditions:  None
// Postconditions:  root points to NULL object.
BinTree::BinTree() {
	root = NULL;
}

//---------------------------- Copy -----------------------------------------
// Copy constructor for class BinTree
// Preconditions:  None
// Postconditions:    other is copied into *this.
BinTree::BinTree(const BinTree & other) {
	root = copyTreeHelper(other.root);
}

//------------------------- CopyHelper -----------------------------------
// Recursively copies each node of other BinTree into this BinTree in
// postorder.
// Preconditions:  None
// Postconditions:  newNode is copied into this BinTree.
BinTree::Node* BinTree::copyTreeHelper(const Node* current) const{
	Node* newNode = NULL;

	if (current != NULL) {
		newNode = new Node;
		newNode->data = current->data;
		newNode->left = newNode->right = NULL;

		newNode->left = copyTreeHelper(current->left);
		newNode->right = copyTreeHelper(current->right);
	}

	return newNode;
}

//--------------------------- Destructor ------------------------------------
// Destructor for class BinTree
// Preconditions:  None
// Postconditions:  all memory is alloacted.
BinTree::~BinTree() {
	makeEmpty();
}

//------------------------------- = -----------------------------------------
// Assinment operator for class BinTree
// Preconditions:  None
// Postconditions:  *this is assigned the same BinTree as right BinTree.
BinTree& BinTree::operator=(const BinTree & right) {
	if (*this != right) {
		makeEmpty();
		root = copyTreeHelper(right.root);
	}
	return *this;
}

//------------------------------ == -----------------------------------------
// Equality comparison operator for class BinTree
// Checks if two BinTree are the same. Returns true if two trees have the
// same data and structure.
// Preconditions:  None
// Postconditions:  *this & right BinTree remain unchanged.
bool BinTree::operator==(const BinTree & right) const {
	return equalityHelper(root, right.root);
}

//------------------------- equalityHelper ----------------------------------
// Helper method for equality operator
// Preconditions: NONE
// Postconditions: leftSide & rightSide remains unchanged.
bool BinTree::equalityHelper(const Node* leftSide, const Node* rightSide)
const {
	if (leftSide != NULL && rightSide != NULL) {
		inequalityHelper(leftSide->left, rightSide->right);
		if (*leftSide->data != *rightSide->data) {
			return false;
		}
		inequalityHelper(leftSide->right, rightSide->right);
	}
	else {
		return false;
	}

	return true;
}

//------------------------------ != -----------------------------------------
// Inequality comparison operator for class BinTree
// Checks if two BinTree are different. Returns true if two trees have either
// different data or structure.
// Preconditions:  None
// Postconditions:  *this & right BinTree remain unchanged
bool BinTree::operator!=(const BinTree & right) const {
	return inequalityHelper(root, right.root);
}

//------------------------ inequalityHelper ---------------------------------
// Helper method for inequality operator
// Preconditions: NONE
// Postconditions: leftSide & rightSide remains unchanged.
bool BinTree::inequalityHelper(const Node* leftSide, const Node* rightSide)
const {
	if (leftSide != NULL && rightSide != NULL) {
		inequalityHelper(leftSide->left, rightSide->right);
		if (*leftSide->data == *rightSide->data) {
			return false;
		}
		inequalityHelper(leftSide->right, rightSide->right);
	}

	return true;
}

//---------------------------- isEmpty --------------------------------------
// Checks if the BinTree is emptry. Returns true if it's empty; otherwise,
// returns false.
// Preconditions:  None
// Postconditions:  BinTree remained unchanged.
bool BinTree::isEmpty() const {
	return root == NULL;
}


//--------------------------- makeEmpty -------------------------------------
// Empty out the whole BinTree.
// Preconditions:  None
// Postconditions:  BinTree is empty.
void BinTree::makeEmpty() {
	destroyHelper(root);
	root = NULL;
}

//------------------------- destroyHelper -----------------------------------
// Recursively delete each node of BinTree postorder.
// Preconditions:  None
// Postconditions:  current Node is deleted.
void BinTree::destroyHelper(Node* current) {
	if (current != NULL) {
		destroyHelper(current->left);
		destroyHelper(current->right);
		delete current->data;
		current->data = NULL;
		delete current;
		current = NULL;
	}
}

//--------------------------- Insert ----------------------------------------
// Insert a new element into BinTree if there is no duplicate and returns
// true; otherwise, returns false.
// Preconditions:  NodeData element is not NULL
// Postconditions:    a new Node is added into BinTree in its proper position;
//        count increment by 1
bool BinTree::insert(NodeData* dataPtr) {
	Node* ptr = new Node;
	if (ptr == NULL) return false;            // out of memory
	ptr->data = dataPtr;
	ptr->left = ptr->right = NULL;

	if (isEmpty()) {
		root = ptr;
	}
	else {
		Node* current = root;
		bool inserted = false;

		while (!inserted) {
			if (*ptr->data < *current->data) {
				if (current->left == NULL) {
					current->left = ptr;
					inserted = true;
				}
				else {
					current = current->left;
				}
			}
			else if (*ptr->data > *current->data) {
				if (current->right == NULL) {
					current->right = ptr;
					inserted = true;
				}
				else {
					current = current->right;
				}
			}
			else {
				delete ptr;
				return false;
			}
		}
	}

	return true;
}

//--------------------------- Retrieve --------------------------------------
// Retrieve a NodeData* of a given object in the tree. Returns true if found;
// otherwise, returns false.
// Preconditions:  the given NodeData should not be NULL
// Postconditions:    BinTree remains unchanged. dataPtr parameter points to
//    the actual object if found.
bool BinTree::retrieve(const NodeData& data, NodeData*& dataPtr) const {
	Node* current = root;
	while (current != NULL) {
		if (data < *current->data) {
			current = current->left;
		}
		else if (data > *current->data) {
			current = current->right;
		}
		else {
			dataPtr = current->data;
			current = NULL;
			return true;
		}
	}
	current = NULL;
	return false;
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;     // display information of object
		sideways(current->left, level);
	}
}

//---------------------------- getDepth -------------------------------------
// Get the depth of a given value in the tree from root to the value; the
// depth of root is 1, depth of a node at the next level is 2, and so on.
// The depth of a value not found is zero.
// Preconditions:  data is not NULL; Tree is a binary tree.
// Postconditions:  BinTree remains unchanged.
int BinTree::getDepth(const NodeData & dataPtr) const {
	return getDepthHelper(dataPtr, root, 1);
}

//------------------------- getDepthHelper -----------------------------------
// Helper method for getDepth. Recursively find the depth of a given data.
// Preconditions:  dataPtr is not NULL; Tree is a binary tree.
// Postconditions:  BinTree remains unchanged.
int BinTree::getDepthHelper(const NodeData& dataPtr, Node* current, int depth)
const {
	if (current == NULL) {
		return 0;
	}

	if (dataPtr == *current->data) {
		return depth;
	}

	int downDepth = getDepthHelper(dataPtr, current->left, depth + 1);
	if (downDepth != 0) {
		return downDepth;
	}

	return getDepthHelper(dataPtr, current->right, depth + 1);
}

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class BinTree
// Displays the whole BinTree inorder
// Preconditions:  None
// Postconditions:  BinTree remains unchanged
ostream& operator<<(ostream & output, const BinTree & other) {
	other.inorderPrintHelper(output, other.root);
	output << endl;
	return output;
}

//-------------------------- inorderHelper ----------------------------------
// Helper method for inorder traversal
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::inorderPrintHelper(ostream & output, Node* current) const {
	if (current != NULL) {
		inorderPrintHelper(output, current->left);
		output << *current->data;
		inorderPrintHelper(output, current->right);
	}
}