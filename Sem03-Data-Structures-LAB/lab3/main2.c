#include <stdio.h>

#define MAX_SIZE 100

int list[MAX_SIZE];
int size = 0;

void display() {
    printf("List elements:");
    for (int i = 0; i < size; i++)
        printf(" %d", list[i]);
    printf("\n");
}

void insert(int element, int position) {
    if (size >= MAX_SIZE || position < 0 || position > size) {
        printf("Invalid operation.\n");
        return;
    }
    
    for (int i = size; i > position; i--)
        list[i] = list[i - 1];
    
    list[position] = element;
    size++;
    printf("Inserted %d at position %d.\n", element, position);
}

void delete(int position) {
    if (size == 0 || position < 0 || position >= size) {
        printf("Invalid operation.\n");
        return;
    }
    
    printf("Deleted %d from position %d.\n", list[position], position);
    
    for (int i = position; i < size - 1; i++)
        list[i] = list[i + 1];
    
    size--;
}

int main() {
    int choice, element, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element and position: ");
                scanf("%d %d", &element, &position);
                insert(element, position);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                delete(position);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}


