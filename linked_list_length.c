#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Length of linked list
int getLength(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// This function adds the elements from the end
void addElement(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// This function adds elements from the beginning
void push(struct Node** head_ref, int new_data)
{
    // allocate node 
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    // put in the data  
    new_node->data = new_data;
 
    // link the old list of the new node 
    new_node->next = (*head_ref);
 
    // move the head to point to the new node 
    (*head_ref) = new_node;
}



int main() {
    struct Node* head = NULL;

    addElement(&head, 5);
    addElement(&head, 10);
    addElement(&head, 15);
    addElement(&head, 20);
    push(&head, 2);
    push(&head, 2);


    printf("length of Linked list: %d\n", getLength(head));

    return 0;
}