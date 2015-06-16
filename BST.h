#ifndef _BINARY_SEARCH_TREE_INCLUDE_H_
#define _BINARY_SEARCH_TREE_INCLUDE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) ((a)>(b) ? (a):(b))

typedef struct _data{
	char* name;
	char* semester;
	int is_like;
} Data;

typedef struct _node{
	struct _node* right;
	struct _node* left;
	Data val;
} *Node, NodeImpl;

typedef struct _bst{
	Node root;
} *BinTree, BinTreeImpl;

int search(Node root, const Data data, Data* tmp);
int add_BST(Node* root, Data data);
void print_data(Data data);

int has_left(Node node);
int has_right(Node node);
int is_leaf(Node node);
BinTree init_bin_tree();
Node make_node(Data data);
int is_empty(BinTree tree);
Node empty_tree(BinTree tree, Node node);
BinTree destroy_tree(BinTree tree);
int node_count(Node node);
int leaf_count(Node node);
int tree_height(Node node);

void print_inorder(Node root);

#endif

