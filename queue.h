		#ifndef QUEUE_H
		#define QUEUE_H

		#include <stdbool.h>

		typedef struct QueueNode {
    			int data;
    			struct QueueNode *next;
		} QueueNode;

		typedef struct {
    			QueueNode *front;
    			QueueNode *rear;
		} Queue;

		void queue_init(Queue *q);
		bool queue_enqueue(Queue *q, int value);
		bool queue_dequeue(Queue *q, int *value);
		void queue_end(Queue *q);

		#endif

