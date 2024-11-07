#include <stdio.h>

//defining constant
#define MAX_SIZE 1000

//list
int list[MAX_SIZE];
int size = 0;

//display logic
void display() {
    printf("List elements: ");
    for (int i = 0; i < size; i++) { //
        printf("%d ", list[i]);
    }
    printf("\n");
}

//insertatLast logic
void insertAtLast(int element) {
    if (size < MAX_SIZE) {
        list[size++] = element;
        printf("Element %d inserted at last.\n", element);
    } else {
        printf("List is full. Cannot insert.\n");
    }
}

//insertatPosition logic
void insertAtPosition(int element, int position) {
    if (size < MAX_SIZE && position >= 0 && position <= size) {
        for (int i = size; i > position; i--) {
            list[i] = list[i - 1];
        }
        list[position] = element;
        size++;
        printf("Element %d inserted at position %d.\n", element, position);
    } else {
        printf("Invalid position or list is full. Cannot insert.\n");
    }
}

//insertatBeginning logic
void insertAtBeginning(int element) {
    insertAtPosition(element, 0);
}

//deletefromlast logic
void deleteFromLast() {
    if (size > 0) {
        printf("Element %d deleted from last.\n", list[--size]);
    } else {
        printf("List is empty. Cannot delete.\n");
    }
}

//deletefromPosition logic
void deleteFromPosition(int position) {
    if (size > 0 && position >= 0 && position < size) {
        printf("Element %d deleted from position %d.\n", list[position], position);
        for (int i = position; i < size - 1; i++) {
            list[i] = list[i + 1];
        }
        size--;
    } else {
        printf("Invalid position or list is empty. Cannot delete.\n");
    }
}

//deletefromBeginning logic
void deleteFromBeginning() {
    deleteFromPosition(0);
}

//menu logic
int main() {
    int choice, element, position;
    do {	
        printf("\nMenu:\n");
        printf("1. Insertion at last\n");
        printf("2. Insertion at position\n");
        printf("3. Insertion at beginning\n");
        printf("4. Deletion from last\n");
        printf("5. Deletion from position\n");
        printf("6. Deletion from beginning\n");
        printf("7. Display the elements\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

	switch (choice) {
		case 1:
			printf("Enter element to insert: ");
		        scanf("%d", &element);
		        insertAtLast(element);
		        break;
		  case 2:
		        printf("Enter element to insert: ");
		        scanf("%d", &element);
		        printf("Enter position: ");
		        scanf("%d", &position);
		        insertAtPosition(element, position);
		        break;
		    case 3:
		        printf("Enter element to insert: ");
		        scanf("%d", &element);
		        insertAtBeginning(element);
		        break;
		    case 4:
		        deleteFromLast();
		        break;
		    case 5:
		        printf("Enter position: ");
		        scanf("%d", &position);
		        deleteFromPosition(position);
		        break;
		    case 6:
		        deleteFromBeginning();
		        break;
		    case 7:
		        display();
		        break;
		    case 8:
		        printf("Exiting.\n");
		        break;
		    default:
		        printf("Invalid choice.\n");
		}
    	} while (choice != 8);

    return 0;
}
