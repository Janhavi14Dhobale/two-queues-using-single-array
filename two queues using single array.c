#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE];
int front1 = -1, rear1 = -1;
int front2 = SIZE, rear2 = SIZE;


void enqueue1(int x) {
    if (rear1 + 1 == rear2) {
        printf("\nQueue 1 Overflow! No space.\n");
        return;
    }

    if (front1 == -1)
        front1 = 0;

    arr[++rear1] = x;
    printf("%d enqueued to Queue 1.\n", x);
}


void enqueue2(int x) {
    if (rear2 - 1 == rear1) {
        printf("\nQueue 2 Overflow! No space.\n");
        return;
    }

    if (front2 == SIZE)
        front2 = SIZE - 1;

    arr[--rear2] = x;
    printf("%d enqueued to Queue 2.\n", x);
}


int dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("\nQueue 1 Underflow!\n");
        return -1;
    }
    int val = arr[front1++];
    if (front1 > rear1)
        front1 = rear1 = -1;

    return val;
}


int dequeue2() {
    if (front2 == SIZE || front2 < rear2) {
        printf("\nQueue 2 Underflow!\n");
        return -1;
    }
    int val = arr[front2--];
    if (front2 < rear2)
        front2 = rear2 = SIZE;

    return val;
}


void display1() {
    if (front1 == -1) {
        printf("\nQueue 1 is empty.\n");
        return;
    }
    printf("\nQueue 1 elements: ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void display2() {
    if (front2 == SIZE) {
        printf("\nQueue 2 is empty.\n");
        return;
    }
    printf("\nQueue 2 elements: ");
    for (int i = front2; i >= rear2; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n     Two Queues Using One Array    ");
        printf("\n1. Enqueue to Queue 1");
        printf("\n2. Enqueue to Queue 2");
        printf("\n3. Dequeue from Queue 1");
        printf("\n4. Dequeue from Queue 2");
        printf("\n5. Display Queue 1");
        printf("\n6. Display Queue 2");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue in Queue 1: ");
                scanf("%d", &value);
                enqueue1(value);
                break;

            case 2:
                printf("Enter value to enqueue in Queue 2: ");
                scanf("%d", &value);
                enqueue2(value);
                break;

            case 3: {
                int d = dequeue1();
                if (d != -1)
                    printf("Dequeued from Queue 1: %d\n", d);
                break;
            }

            case 4: {
                int d = dequeue2();
                if (d != -1)
                    printf("Dequeued from Queue 2: %d\n", d);
                break;
            }

            case 5:
                display1();
                break;

            case 6:
                display2();
                break;

            case 7:
                printf("\nExiting program. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

