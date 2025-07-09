#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Node *creatNode(int value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Stack *createStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, int value) {
    Node *node = creatNode(value);
    node->next = s->top;
    if (s->top != NULL) {
        s->top->prev = node;
    }
    s->top = node;
}

int pop(Stack *s) {
    if (s->top == NULL) {
        printf("Stack trong");
        return 0;
    }
    Node *temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}

void printStack(Stack *s) {
    if (s->top == NULL) {
        printf("Stack trong");
        return;
    }
    Node *current = s->top;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current!=s->top) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("%d\n",s->top->data);
}

int main() {
    Stack *s = createStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    printf("%d\n", pop(s));
    printStack(s);
    return 0;
}
