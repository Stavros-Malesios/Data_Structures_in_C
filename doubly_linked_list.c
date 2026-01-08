		#include <stdio.h>
		#include <stdlib.h>
		#include "doubly_linked_list.h"

		static Node* create_node(void *data) {
    			Node *n = malloc(sizeof(Node));
    			if (!n) return NULL;
    			n->data = data;
   	 		n->prev = n->next = NULL;
    			return n;
		}

		Node* list_insert_sorted(Node *head, void *data, CompareFunc cmp) {
    			Node *newNode = create_node(data);
    			if (!newNode) return head;

    			if (!head) return newNode;

    			Node *curr = head;
    			while (curr && cmp(curr->data, data) < 0)
        			curr = curr->next;

    				if (curr == head) {
        				newNode->next = head;
        				head->prev = newNode;
        				return newNode;
    				}

    				if (!curr) {
        				Node *tail = head;
        				while (tail->next) tail = tail->next;
        					tail->next = newNode;
        					newNode->prev = tail;
        					return head;
    				}

    				newNode->next = curr;
    				newNode->prev = curr->prev;
    				curr->prev->next = newNode;
    				curr->prev = newNode;

    				return head;
			}

		Node* list_delete(Node *head, void *key, CompareFunc cmp, FreeFunc free_data) {
    			Node *curr = head;

    			while (curr && cmp(curr->data, key) != 0)
        			curr = curr->next;

    				if (!curr) return head;

    				if (curr->prev)
        				curr->prev->next = curr->next;
    				else
        				head = curr->next;

    				if (curr->next)
        				curr->next->prev = curr->prev;

    				if (free_data)
        				free_data(curr->data);

    					free(curr);
    				return head;
		}

		Node* list_search(Node *head, void *key, CompareFunc cmp) {
    			while (head) {
        			if (cmp(head->data, key) == 0)
            				return head;
        				head = head->next;
    			}
    			return NULL;
		}

		void list_traverse(Node *head, PrintFunc print) {
    			while (head) {
        			print(head->data);
        			head = head->next;
    			}
		}

		void list_free(Node *head, FreeFunc free_data) {
    			Node *tmp;
    			while (head) {
        			tmp = head;
        			head = head->next;
        			if (free_data)
            			free_data(tmp->data);
        			free(tmp);
    			}
		}
		

