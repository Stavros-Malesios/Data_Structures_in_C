		#include <stdlib.h>
		#include <stdbool.h>
		#include "queue.h"

		void queue_init(Queue *q)
		{
    			q->front = NULL;
    			q->rear  = NULL;
		}

		bool queue_enqueue(Queue *q, int value)
		{
    			QueueNode *n = malloc(sizeof(QueueNode));
    			if (!n) return false;

    			n->data = value;
    			n->next = NULL;

    			if (q->rear == NULL) {
        			q->front = q->rear = n;
    			} else {
        			q->rear->next = n;
        			q->rear = n;
    			}

    			return true;
		}

		bool queue_dequeue(Queue *q, int *value)
		{
    			if (q->front == NULL) return false;

    				QueueNode *t = q->front;
    				*value = t->data;

    				q->front = t->next;
    			if (q->front == NULL)
        			q->rear = NULL;

    				free(t);
    				return true;
		}

		void queue_end(Queue *q)
		{
    			QueueNode *current = q->front;
    			QueueNode *next;

    			while (current) {
        			next = current->next;
        			free(current);
        			current = next;
    			}

    			q->front = q->rear = NULL;
}

