	#include <stdio.h>
	#include <stdbool.h>
	#include "stack.h"
	#include "queue.h"

	static void print_menu(void)
	{
    		printf("\n==== DATA STRUCTURES MENU ====\n");
    		printf("1. Stack push\n");
    		printf("2. Stack pop\n");
    		printf("3. Queue enqueue\n");
    		printf("4. Queue dequeue\n");
    		printf("0. Exit\n");
    		printf("Choice: ");
	}

	int main(void)
	{
		StackNode *stack;
    		Queue queue;
    		int choice, value;

    		stack_init(&stack);
    		queue_init(&queue);

    		while (true) {
        		print_menu();

        		if (scanf("%d", &choice) != 1) {
            			printf("Invalid input. Exiting.\n");
            			break;
        		}

        	switch (choice) {
        		case 1:
            			printf("Value to push: ");
            			scanf("%d", &value);
            			if (stack_push(&stack, value))
                			printf(" Pushed %d to stack\n", value);
            			else
                			printf(" Stack push failed\n");
            			break;

        		case 2:
            			if (stack_pop(&stack, &value))
                			printf(" Popped %d from stack\n", value);
            			else
                			printf(" Stack is empty\n");
            			break;

        		case 3:
            			printf("Value to enqueue: ");
            			scanf("%d", &value);
            			if (queue_enqueue(&queue, value))
                			printf(" Enqueued %d to queue\n", value);
            			else
                			printf(" Queue enqueue failed\n");
            			break;

        		case 4:
            			if (queue_dequeue(&queue, &value))
                			printf(" Dequeued %d from queue\n", value);
            			else
                			printf(" Queue is empty\n");
            			break;

        		case 0:
            			printf("Bye Cleaning up...\n");
            			stack_end(&stack);
            			queue_end(&queue);
            			return 0;

        default:
            printf("Unknown option. Try again.\n");
        }
    }

    stack_end(&stack);
    queue_end(&queue);
    return 0;
}

