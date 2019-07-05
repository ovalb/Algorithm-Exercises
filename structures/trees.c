#include <stdio.h>
#include <stdlib.h>
#include "llqueue.h"
#include "llstack.h"

typedef struct tree_t {
	int value;
	struct tree_t *kid1;
	struct tree_t *kid2;
	struct tree_t *kid3;
} tree_t;

typedef enum TraverseStrategy {BFS, DFS} TraverseStrategy;

tree_t *generate_sample_tree();
tree_t *create_tree_node(int value);

void traverse_tree(tree_t *root, void (*print_node)(void *), TraverseStrategy);
void print_node(void *node);

int main() {
	void (*print_n)(void *) = &print_node;
	tree_t* albero = generate_sample_tree(&albero);
	traverse_tree(albero, print_n, BFS);
	traverse_tree(albero, print_n, DFS);

	return 0;
}

void traverse_tree(tree_t *root, void (*print_node)(void *), TraverseStrategy strat) {
	linked_list *list = NULL;
	int empty_queue = 0;

	void (*add)(linked_list **, void *) = (strat == BFS) ? &enqueue : &push;
	void *(*remove)(linked_list **) = (strat == BFS) ? &dequeue : &pop;

	add(&list, root);

	tree_t *current;
	printf("Tree: ");
	
	while((current = remove(&list)) != NULL) {
		(*print_node)(current);
		
		if (current->kid1 != NULL) add(&list, current->kid1);
		if (current->kid2 != NULL) add(&list, current->kid2);
		if (current->kid3 != NULL) add(&list, current->kid3);
	}

	printf("\n");
}

tree_t *create_tree_node(int value) {
	tree_t *tree = malloc(sizeof(tree_t));
	tree->value = value;
	tree->kid1 = NULL;
	tree->kid2 = NULL;
	tree->kid3 = NULL;

	return tree;
}

tree_t *generate_sample_tree() {
	tree_t *tree = create_tree_node(1);
	tree->kid1 = create_tree_node(2);
	tree->kid2 = create_tree_node(3);
	tree->kid3 = create_tree_node(4);
	
	tree->kid1->kid1 = create_tree_node(5);
	tree->kid1->kid2 = create_tree_node(6);

	tree->kid3->kid1 = create_tree_node(7);
	tree->kid3->kid2 = create_tree_node(8);

	return tree;
}

void print_node(void *node) {
	if (((tree_t *)node) != NULL) {
		printf("-> %d ", ((tree_t*)node)->value);
	}
}