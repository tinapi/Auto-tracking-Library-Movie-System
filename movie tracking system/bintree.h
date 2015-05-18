//---------------------------------------------------------------------------
// BINTREE.H
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

#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"
#include "iostream"
using namespace std;

class BinTree {
	//-----------------------------  <<  ----------------------------------------
	// Overloaded output operator for class BinTree
	// Displays the whole BinTree inorder
	// Preconditions:  None
	// Postconditions:  BinTree remains unchanged.
	friend ostream & operator<<(ostream &, const BinTree &);

public:
	//-------------------------- Constructor ------------------------------------
	// Default constructor for class BinTree
	// Preconditions:  None
	// Postconditions:  root pinters to NULL object.
	BinTree();

	//---------------------------- Copy -----------------------------------------
	// Copy constructor for class BinTree
	// Preconditions:  None
	// Postconditions:    other is copied into *this.
	BinTree(const BinTree &);

	//--------------------------- Destructor ------------------------------------
	// Destructor for class BinTree
	// Preconditions:  None
	// Postconditions:  all memory has been alloacted.
	~BinTree();

	//------------------------------- = -----------------------------------------
	// Assinment operator for class BinTree
	// Preconditions:  None
	// Postconditions:  *this is assigned the same BinTree as right BinTree.
	BinTree& operator=(const BinTree &);

	//------------------------------ == -----------------------------------------
	// Equality comparison operator for class BinTree
	// Checks if two BinTree are the same. Returns true if two trees have the
	// same data and structure.
	// Preconditions:  None
	// Postconditions:  *this & right BinTree remain unchanged.
	bool operator==(const BinTree &) const;

	//------------------------------ != -----------------------------------------
	// Inequality comparison operator for class BinTree
	// Checks if two BinTree are different. Returns true if two trees have either
	// different data or structure.
	// Preconditions:  None
	// Postconditions:  *this & right BinTree remain unchanged.
	bool operator!=(const BinTree &) const;

	//---------------------------- isEmpty --------------------------------------
	// Checks if the BinTree is emptry. Returns true if it's empty; otherwise,
	// returns false.
	// Preconditions:  None
	// Postconditions:  BinTree remains unchanged.
	bool isEmpty() const;

	//--------------------------- makeEmpty -------------------------------------
	// Empty out the whole BinTree.
	// Preconditions:  None
	// Postconditions:  BinTree is empty.
	void makeEmpty();

	//--------------------------- Insert ----------------------------------------
	// Inserts a new element into BinTree if there is no duplicate and returns
	// true; otherwise, returns false.
	// Preconditions:  NodeData element is not NULL
	// Postconditions:    a new Node is added into BinTree in its proper position;
	//        count increment by 1
	bool insert(NodeData*);

	//--------------------------- Retrieve --------------------------------------
	// Retrieve a NodeData* of a given object in the tree. Returns true if found;
	// otherwise, returns false.
	// Preconditions:  the given NodeData should not be NULL
	// Postconditions:    BinTree remains unchanged. dataPtr parameter points to
	//    the actual object if found.
	bool retrieve(const NodeData&, NodeData*&) const;

	//------------------------- displaySideways ---------------------------------
	// Displays a binary tree as though you are viewing it from the side;
	// hard coded displaying to standard output.
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void displaySideways() const;

	//---------------------------- getDepth -------------------------------------
	// Get the depth of a given value in the tree from root to the value; the
	// depth of root is 1, depth of a node at the next level is 2, and so on.
	// The depth of a value not found is zero.
	// Preconditions:  data is not NULL; Tree is a binary tree.
	// Postconditions:  BinTree remains unchanged.
	int getDepth(const NodeData &) const;

private:
	struct Node {
		NodeData* data;
		Node* left;
		Node* right;
	};
	Node* root;
	int count;

	//--------------------------- CopyHelper ------------------------------------
	// Recursively copies each node of other BinTree into this BinTree in
	// postorder.
	// Preconditions:  None
	// Postconditions:  newNode is copied into this BinTree.
	Node* copyTreeHelper(const Node*) const;

	//-------------------------- destroyHelper ----------------------------------
	// Recursively delete each node of BinTree postorder.
	// Preconditions:  None
	// Postconditions:  current Node is deleted.
	void destroyHelper(Node*);

	//------------------------- equalityHelper ----------------------------------
	// Helper method for equality operator
	// Preconditions: NONE
	// Postconditions: leftSide & rightSide remains unchanged.
	bool equalityHelper(const Node*, const Node*) const;

	//------------------------ inequalityHelper ---------------------------------
	// Helper method for inequality operator
	// Preconditions: NONE
	// Postconditions: leftSide & rightSide remains unchanged.
	bool inequalityHelper(const Node*, const Node*) const;

	//----------------------- inorderPrintHelper --------------------------------
	// Helper method for printing the tree inorder
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void inorderPrintHelper(ostream &, Node*) const;

	//---------------------------- Sideways -------------------------------------
	// Helper method for displaySideways
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void sideways(Node*, int) const;

	//------------------------- getDepthHelper -----------------------------------
	// Helper method for getDepth. Recursively find the depth of a given data.
	// Preconditions:  dataPtr is not NULL; Tree is a binary tree.
	// Postconditions:  BinTree remains unchanged.
	int getDepthHelper(const NodeData&, Node*, int depth) const;
};

#endif