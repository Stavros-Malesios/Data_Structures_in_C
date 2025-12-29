		#include <stdbool.h>
		
		#ifndef STACK_H
		#define STACK_H
			typedef struct StackNode {
				int data ; 
				struct StackNode *next ; 
			}StackNode;

			void stack_init(StackNode **top);
			bool stack_push(StackNode **top , int value);
			void stack_end(StackNode **top);
			bool stack_pop(StackNode **top , int *value);
				
		#endif 
