
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void readData_8106(struct person **arr, int *n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    fscanf(file, "%d", n);
    *arr = (struct person *)malloc(*n * sizeof(struct person));

    for (int i = 0; i < *n; i++) {
        (*arr)[i].name = (char *)malloc(100 * sizeof(char)); 
        fscanf(file, "%d %s %d %d %d", &(*arr)[i].id, (*arr)[i].name, &(*arr)[i].age, &(*arr)[i].height, &(*arr)[i].weight);
    }

    fclose(file);
}

void minHeapify_8106(struct person *arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        struct person temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify_8106(arr, n, smallest);
    }
}

void maxHeapify_8106(struct person *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        struct person temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify_8106(arr, n, largest);
    }
}

void buildMinHeap_8106(struct person *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify_8106(arr, n, i);
}

void buildMaxHeap_8106(struct person *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify_8106(arr, n, i);
}

void displayWeightOfYoungest_8106(struct person *arr) {
    if (arr != NULL) {
        printf("Weight of youngest person: %.2f kg\n", arr[0].weight / 2.205);
    } else {
        printf("Heap is empty.\n");
    }
}

void insertMinHeap_8106(struct person *arr, int *n, struct person newPerson) {
    (*n)++;
    arr = realloc(arr, (*n) * sizeof(struct person));
    int i = *n - 1;
    arr[i] = newPerson;

    while (i != 0 && arr[(i - 1) / 2].age > arr[i].age) {
        struct person temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void deleteOldest_8106(struct person *arr, int *n) {
    if (*n == 0) {
        printf("Heap is empty.\n");
        return;
    }

    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify_8106(arr, *n, 0);
}

int main() {
    struct person *arr = NULL;
    int n = 0, choice;

    while (1) {
        printf("MAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readData_8106(&arr, &n, "data.txt");
                break;
            case 2:
                buildMinHeap_8106(arr, n);
                break;
            case 3:
                buildMaxHeap_8106(arr, n);
                break;
            case 4:
                displayWeightOfYoungest_8106(arr);
                break;
            case 5: {
                struct person newPerson;
                newPerson.name = (char *)malloc(50 * sizeof(char));
                printf("Enter id, name, age, height, and weight: ");
                scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                insertMinHeap_8106(arr, &n, newPerson);
                break;
            }
            case 6:
                deleteOldest_8106(arr, &n);
                break;
            case 7:
                free(arr);
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
