	#ifndef DOUBLY_LINKED_LIST
	#define DOUBLY_LINKED_LIST

	typedef struct Node {
    		void *data;
    		struct Node *prev;
    		struct Node *next;
	} Node;

	typedef int  (*CompareFunc)(void *, void *);
	typedef void (*PrintFunc)(void *);
	typedef void (*FreeFunc)(void *);

	Node* list_insert_sorted(Node *head, void *data, CompareFunc cmp);
	Node* list_delete(Node *head, void *key, CompareFunc cmp, FreeFunc free_data);
	Node* list_search(Node *head, void *key, CompareFunc cmp);
	void  list_traverse(Node *head, PrintFunc print);
	void  list_free(Node *head, FreeFunc free_data);

#endif

