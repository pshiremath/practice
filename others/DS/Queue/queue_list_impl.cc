#include <bits/stdc++.h>

typedef struct _QNode {
  int data;
  _QNode *next;
} QNode;

typedef struct _Queue {
  QNode *front;
  QNode *rear;
} Queue;

Queue *createQueue() {
  Queue *q = new Queue();
  q->front = nullptr;
  q->rear = nullptr;

  return q;
}

void enQueue(Queue *queue, int data) {
  QNode *node = new QNode();
  node->data = data;
  node->next = nullptr;

  if (queue->rear == nullptr) {
    queue->front = queue->rear = node;
    return;
  }

  queue->rear->next = node;
  queue->rear = queue->rear->next;
}

QNode *deQueue(Queue *q) {
  if (q->front == nullptr) {
    return nullptr;
  }

  QNode *temp = q->front;
  q->front = q->front->next;

  if (q->front == nullptr) {
    q->rear = nullptr;
  }

  return temp;
}

int main(int argc, char const *argv[]) {
  Queue *q = createQueue();
  enQueue(q, 10);
  enQueue(q, 20);
  deQueue(q);
  deQueue(q);
  enQueue(q, 30);
  enQueue(q, 40);
  enQueue(q, 50);
  QNode *n = deQueue(q);
  if (n != nullptr) {
    printf("Dequeued item is %d", n->data);
  }
  return 0;
}