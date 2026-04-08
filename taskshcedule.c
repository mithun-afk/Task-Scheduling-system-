#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// Task structure
typedef struct {
    char name[50];
    int duration;
} Task;

// Queue variables
Task queue[MAX];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Enqueue (Add Task)
void enqueue() {
    if (isFull()) {
        printf("\nQueue is FULL!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;

    printf("\nEnter Task Name: ");
    scanf("%s", queue[rear].name);

    printf("Enter Duration (seconds): ");
    scanf("%d", &queue[rear].duration);

    printf("Task added successfully!\n");
}

// Dequeue (Execute Task)
void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY!\n");
        return;
    }

    printf("\nExecuting Task: %s\n", queue[front].name);

    for (int i = 1; i <= queue[front].duration; i++) {
        printf("Processing... %d/%d sec\n", i, queue[front].duration);
    }

    printf("Task Completed!\n");

    front++;
}

// Display Queue
void display() {
    if (isEmpty()) {
        printf("\nNo tasks in queue.\n");
        return;
    }

    printf("\n--- Task Queue ---\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s (%d sec)\n",
               i - front + 1,
               queue[i].name,
               queue[i].duration);
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n===== TASK SCHEDULER (QUEUE) =====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Execute Task\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}