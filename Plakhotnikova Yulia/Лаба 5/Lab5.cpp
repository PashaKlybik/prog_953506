#include "pch.h"
#include <iostream>
#include <malloc.h>

struct queue {
	int qu[100];
	int rear, frnt;
};

void init(struct queue *q) {
	q->frnt = 1;
	q->rear = 0;
} 

void insert(struct queue *q, int x) {
	if (q->rear < 99) {
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		printf("Queue is full!\n");
}

int isempty(struct queue *q) {
	if (q->rear < q->frnt)    return 1;
	else  return 0;
}

void print(struct queue *q) {
	int h;
	if (isempty(q) == 1) {
		printf("Queue is empty!\n");
		return;
	}
	for (h = q->frnt; h <= q->rear; h++)
		printf("%d ", q->qu[h]);
	return;
}

void revurse(struct queue *q) {
	int rev;
	for (int i = q->frnt; i < (q->rear + 2) / 2; i++) {
	    rev = q->qu[i];
		q->qu[i] = q->qu[q->rear - i + 1];
		q->qu[q->rear - i + 1] = rev;
	}
	printf("\n");
	print(q);
}

void Free(struct queue *q) {
	int x, h;
	if (isempty(q) == 1) {
		printf("Очередь пуста!\n");
	}
	x = q->qu[q->frnt];
	for (h = q->frnt; h < q->rear; h++) {
		q->qu[h] = q->qu[h + 1];
	}
	q->rear--;
}


int main()
{
	struct queue *q;
	int a, n;
	q = (queue*)malloc(sizeof(queue));
	init(q);
	print(q);
	printf("Enter the number of queue items: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter queue item: ");
		scanf_s("%d", &a);
		insert(q, a);
	}
	print(q);
	revurse(q);
	while (q->frnt <= q->rear) {
		Free(q);
		free(q);
	}

	getchar(); getchar();
	return 0;
}