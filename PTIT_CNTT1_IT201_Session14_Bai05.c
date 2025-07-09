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
Node* creatNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}
void push(Stack *s, int value) {
    Node* node = creatNode(value);
    node->next = s->top;
    if (s->top!=NULL) {
        s->top->prev = node;
    }
    s->top = node;
}
int pop(Stack *s) {
    if (s->top==NULL) {
        printf("Stack trong");
        return 0;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}
void printStack(Stack *s) {
    if (s->top==NULL) {
        printf("Stack trong");
        return;
    }
    Node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current=current->next;
    }
    printf("\n");
}
void delete(Stack *s,int value) {
    if (s->top==NULL) {
        printf("Stack trong");
        return;
    }
    while (s->top != NULL&&s->top->data==value) {
        pop(s);
    }
    Node* current =s->top;
    while (current != NULL) {
        if (current->data==value) {
            Node* temp= current->next;
            if (current->prev!=NULL) {
                current->prev->next = current->next;
            }
            if (current->next!=NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            current=temp;
            continue;
        }
        current=current->next;
    }
}
void checkFirst(Stack *s) {
    if (s->top==NULL) {
        printf("Stack trong");
        return;
    }
    printf("%d",s->top->data);
}
int main() {
    Stack* s = createStack();
    int n,value;
    printf("Nhap vao so luong phan tu: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        printf("Nhap vao gia tri phan tu: ");
        scanf("%d",&value);
        push(s,value);
    }
    printf("Nhap vao gia tri can xoa: ");
    scanf("%d",&value);
    delete(s,value);
    printStack(s);
    return 0;
}
