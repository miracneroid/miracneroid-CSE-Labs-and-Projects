/*
Create a double linked list and perform the following operations
1)insertion at beginning
2)insertion at some point (Except beginning and last)
3)insertion at last
4)deletion at beginning
5)deletion at some point (Except beginning and last)
6)deletion at last
7)display 
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;

void insert_at_beginning(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  new_node->prev = NULL;

  if (head != NULL) {
    head->prev = new_node;
  }

  head = new_node;
}

void insert_after(int data, int after) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;

  struct node *temp = head;
  while (temp->data != after) {
    temp = temp->next;
  }

  new_node->next = temp->next;
  if (temp->next != NULL) {
    temp->next->prev = new_node;
  }

  temp->next = new_node;
  new_node->prev = temp;
}

void insert_at_last(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;

  if (head == NULL) {
    head = new_node;
    return;
  }

  struct node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
  new_node->prev = temp;
}

void delete_at_beginning() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  struct node *temp = head;
  head = head->next;

  if (head != NULL) {
    head->prev = NULL;
  }

  free(temp);
}

void delete_after(int data) {
  struct node *temp = head;
  while (temp->data != data) {
    temp = temp->next;
  }

  if (temp->next == NULL) {
    printf("Element not found\n");
    return;
  }

  struct node *to_delete = temp->next;
  temp->next = to_delete->next;
  if (to_delete->next != NULL) {
    to_delete->next->prev = temp;
  }

  free(to_delete);
}

void delete_at_last() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  if (head->next == NULL) {
    head = NULL;
    return;
  }

  struct node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  struct node *to_delete = temp->next;
  temp->next = NULL;
  free(to_delete);
}

void display() {
  struct node *temp = head;
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

int main() {
  int choice, data, after;

  while (1) {
    printf("1. Insert at beginning\n");
    printf("2. Insert after\n");
    printf("3. Insert at last\n");
    printf("4. Delete at beginning\n");
    printf("5. Delete after\n");
    printf("6. Delete at last\n");
    printf("7. Display\n");
    printf("8. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert_at_beginning(data);
        break;
      case 2:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        printf("Enter data after which to insert: ");
        scanf("%d", &after);
        insert_after(data, after);
        break;
      case 3:
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert_at_last(data);
        break;
      case 4:
        delete_at_beginning();
        break;
      case 5:
        printf("Enter data to delete: ");
        scanf("%d", &data);
        delete_after(data);
        break;
      case 6:
        delete_at_last();
        break;
      case 7:
        display();
        break;
      case 8:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

