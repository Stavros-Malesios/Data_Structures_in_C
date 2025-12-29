		#include <stdlib.h>
		#include <stdbool.h>
		#include "stack.h"
		
		void stack_init(StackNode **top)
		{
			*top = NULL ;
		}
		
		bool stack_push(StackNode **top ,int value)
			{
				StackNode *n = malloc(sizeof(StackNode));
				if (!n) return false ; 
				n->data = value ;
				n->next = *top ;
				*top = n ;
				return true ;
			}

		bool stack_pop(StackNode **top , int* value)
			{
				if( top == NULL) return false ;
				StackNode *t = *top ;
				*value = t->data ;
				*top = t->next ;
				free(t);
				return true ;
			}
		
		void stack_end(StackNode **top) {
    			StackNode *current = *top;
    			StackNode *next;

    			while (current) {
        			next = current->next;
        			free(current);
        			current = next;
    			}

    			*top = NULL;
		}
		
