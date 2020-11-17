#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;


void push(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}


Node* getNth(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}


void insert(Node *head, unsigned n, int val) {
    unsigned i = 0;
    Node *tmp = NULL;

    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (Node*) malloc(sizeof(Node));
    tmp->value = val;

    if (head->next) {
        tmp->next = head->next;

    } else {
        tmp->next = NULL;
    }
    head->next = tmp;
}
int deleteNth(Node **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;
    }
}

void printLinkedList(const Node *head) {
    while (head!=0) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
void Menu(Node **head){
     printf("1 - добавить узел \n2 - удалить \n3 - весь список\n");
    int i;
    scanf("%d",&i);
switch(i) {
        case 1:
            printf("Введите номер узла\n");
            int j,k;
            scanf("%d",&j);
            printf("Введите значение\n");
            scanf("%d",&k);
            if (head==NULL)
                push(&head, k);
            else
            insert(head,j,k);
            Menu(head);
        case 2:
            printf("Введите номер элемента\n");
            int l;
            scanf("%d",&l);
            deleteNth(&head, l-1);
            Menu(head);

        case 3:
            printLinkedList(head);
            Menu(head);

        default:
                printf("Вы открыли секретный уровень\n");

                Menu(head);
}
}
int main(void) {
    setlocale(LC_ALL, "Rus");
    Node *head = NULL;
    Menu(head);
    return 0;
}

