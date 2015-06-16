#include "BinarySearchTree.h"

BinTree init_bin_tree(){
	BinTree tree = (BinTree)malloc(sizeof(BinTreeImpl));
	if(!tree){
		printf("failed to allocate memory for tree\n");
		return 0;
	}

	tree->root = NULL;
	return tree;
}

int search(Node root, const Data data, Data* tmp){
	if(root == NULL){
		printf("%s not found in tree.\n", data.name);
		return 0;
	}
	else{
		int result = strcmp(data.name, root->val.name);
		if(result == 0){
			*tmp = root->val;
			return 1;
		} 
		else if(result < 0)
			return search(root->left, data, tmp);
		else
			return search(root->right, data, tmp);
	}
}

int add_BST(Node* root, Data data){ // pass in reference to root to change it @ the address
	Node newNode = make_node(data);
	if(!(*root)){
		*root = newNode;
		return 0;
	}
	else{
		int result = strcmp(data.name, (*root)->val.name);
		if(result < 0)
			return add_BST(&(*root)->left, data);
		else if(result > 0)
			return add_BST(&(*root)->right, data);
		else{
			//data already in tree
			free(newNode->val.name);
			free(newNode->val.semester);
			free(newNode);
		}
	}

	return 1;

}

int is_leaf(Node node){
	if(!node){
		printf("Node is null\n");
		return 0;
	}

	if((node->left == NULL) && (node->right == NULL))
		return 1;
	else 
		return 0;
}

int has_left(Node node){
	if(!node){
		printf("Node is null\n");
		return 0;
	}

	if(node->left)
		return 1;
	else 
		return 0;
}

int has_right(Node node){
	if(!node){
		printf("Node is null\n");
		return 0;
	}

	if(node->right)
		return 1;
	else 
		return 0;
}

Node make_node(Data data){
	Node elem = (Node)malloc(sizeof(NodeImpl));
	if(!elem){
		printf("failed to allocate memory for node\n");
		return 0;
	}

	elem->val.name = (char*)malloc(strlen(data.name) + 1);
	elem->val.semester = (char*)malloc(strlen(data.semester) + 1);
	elem->val.is_like = data.is_like;
	strcpy(elem->val.name, data.name);
	strcpy(elem->val.semester, data.semester);
	elem->right = NULL;
	elem->left = NULL;
	return elem;
}

int is_empty(BinTree tree){
	return !tree->root;
}

Node empty_tree(BinTree tree, Node node){
	if(node == NULL){
		free(tree->root);
		return (tree->root) = NULL;
	}
	if(node->left != NULL)
		empty_tree(tree, node->left);
	if(node->right != NULL)
		empty_tree(tree, node->right);
	free(node->val.name);
	free(node->val.semester);
	free(node);
	return node = NULL;
}

BinTree destroy_tree(BinTree tree){
	tree->root = NULL;
	if(!is_empty(tree)){
		printf("tree is not empty\n");
		empty_tree(tree, tree->root);
	}
	free(tree);
	return (tree = NULL);
}

int node_count(Node node){
	if(!node)
		return 0;
	else if(is_leaf(node))
		return 1;
	else return(1 + node_count(node->left) + node_count(node->right));
}

int leaf_count(Node node){
	if(!node)
		return 0;
	else if(is_leaf(node))
		return 1;
	else return(leaf_count(node->left) + leaf_count(node->right));
}

int tree_height(Node node){
	if(!node)
		return 0;
	return 1 + max(tree_height(node->left), tree_height(node->right));
}

void print_data(Data data){
	printf("Course name: %s", data.name);
	if(data.is_like)
		printf("You liked the course\n");
	else
		printf("You did not like the course\n");
	printf("Course was taken during the %s \n", data.semester);
}


void print_inorder(Node node){
	if(node){
		print_inorder(node->left);
		print_data(node->val);
		print_inorder(node->right);
	}
}


