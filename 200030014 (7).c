#include <stdio.h>
#include <stdlib.h>

// Stack Structure
struct StackNode {
    int data;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top; // Pointer to the top of the stack
    int size; // Current size of the stack
};

// Function to create a stack
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    stack->size = size;
    return stack;
}

// Check if the stack is full
int isStackFull(struct Stack* stack) {
    return stack->size == 0;
}

// Check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push an element onto the stack
void push(struct Stack* stack, int data, FILE* outputFile) {
    if (isStackFull(stack)) {
        fprintf(outputFile, "overflow\n");
        return;
    }

    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size--;
    fprintf(outputFile, "pushed %d\n", data);
}

// Pop an element from the stack
void pop(struct Stack* stack, FILE* outputFile) {
    if (isStackEmpty(stack)) {
        fprintf(outputFile, "underflow\n");
        return;
    }

    struct StackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size++;
    fprintf(outputFile, "popped %d\n", data);
}

// Search for an element in the stack
void search(struct Stack* stack, int key, FILE* outputFile) {
    struct StackNode* temp = stack->top;

    while (temp != NULL) {
        if (temp->data == key) {
            fprintf(outputFile, "found %d\n", key);
            return;
        }
        temp = temp->next;
    }

    fprintf(outputFile, "not found %d\n", key);
}

// Display the elements in the stack
void displayStack(struct Stack* stack, FILE* outputFile) {
    struct StackNode* temp = stack->top;

    while (temp != NULL) {
        fprintf(outputFile, "%d ", temp->data);
        temp = temp->next;
    }

    fprintf(outputFile, "\n");
}

// Free the stack memory
void freeStack(struct Stack* stack) {
    struct StackNode* temp;

    while (stack->top != NULL) {
        temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }

    free(stack);
}

// Queue Structure
struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front; // Pointer to the front of the queue
    struct QueueNode* rear; // Pointer to the rear of the queue
    int size; // Current size of the queue
};

// Function to create a queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = size;
    return queue;
}

// Check if the queue is full
int isQueueFull(struct Queue* queue) {
    return queue->size == 0;
}

// Check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Enqueue an element into the queue
void enqueue(struct Queue* queue, int data, FILE* outputFile) {
    if (isQueueFull(queue)) {
        fprintf(outputFile, "overflow\n");
        return;
    }

    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size--;
    fprintf(outputFile, "enqueued %d\n", data);
}

// Dequeue an element from the queue
void dequeue(struct Queue* queue, FILE* outputFile) {
    if (isQueueEmpty(queue)) {
        fprintf(outputFile, "underflow\n");
        return;
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    queue->size++;
    fprintf(outputFile, "dequeued %d\n", data);
}

// Search for an element in the queue
void searchQueue(struct Queue* queue, int key, FILE* outputFile) {
    struct QueueNode* temp = queue->front;

    while (temp != NULL) {
        if (temp->data == key) {
            fprintf(outputFile, "found %d\n", key);
            return;
        }
        temp = temp->next;
    }

    fprintf(outputFile, "not found %d\n", key);
}

// Display the elements in the queue
void displayQueue(struct Queue* queue, FILE* outputFile) {
    struct QueueNode* temp = queue->front;

    while (temp != NULL) {
        fprintf(outputFile, "%d ", temp->data);
        temp = temp->next;
    }

    fprintf(outputFile, "\n");
}

// Free the queue memory
void freeQueue(struct Queue* queue) {
    struct QueueNode* temp;

    while (queue->front != NULL) {
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }

    free(queue);
}

// Doubly Linked List Structure
struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

struct DLL {
    struct DLLNode* head; // Pointer to the head of the doubly linked list
};

// Function to create a doubly linked list
struct DLL* createDLL() {
    struct DLL* dll = (struct DLL*)malloc(sizeof(struct DLL));
    dll->head = NULL;
    return dll;
}

// Insert an element into the doubly linked list
void insert(struct DLL* dll, int data, FILE* outputFile) {
    struct DLLNode* newNode = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dll->head;

    if (dll->head != NULL) {
        dll->head->prev = newNode;
    }

    dll->head = newNode;
    fprintf(outputFile, "inserted %d\n", data);
}

// Delete an element from the doubly linked list
void delete(struct DLL* dll, int key, FILE* outputFile) {
    struct DLLNode* temp = dll->head;

    while (temp != NULL) {
        if (temp->data == key) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                dll->head = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            free(temp);
            fprintf(outputFile, "deleted %d\n", key);
            return;
        }

        temp = temp->next;
    }

    fprintf(outputFile, "cannot delete %d\n", key);
}

// Search for an element in the doubly linked list
void searchDLL(struct DLL* dll, int key, FILE* outputFile) {
    struct DLLNode* temp = dll->head;

    while (temp != NULL) {
        if (temp->data == key) {
            fprintf(outputFile, "found %d\n", key);
            return;
        }

        temp = temp->next;
    }

    fprintf(outputFile, "not found %d\n", key);
}

// Display the elements in the doubly linked list
void displayDLL(struct DLL* dll, FILE* outputFile) {
    struct DLLNode* temp = dll->head;

    while (temp != NULL) {
        fprintf(outputFile, "%d ", temp->data);
        temp = temp->next;
    }

    fprintf(outputFile, "\n");
}

// Free the doubly linked list memory
void freeDLL(struct DLL* dll) {
    struct DLLNode* temp;

    while (dll->head != NULL) {
        temp = dll->head;
        dll->head = dll->head->next;
        free(temp);
    }

    free(dll);
}

// Main function
int main(int argc, char* argv[]) {
    // Check the number of command-line arguments
    if (argc < 3) {
        printf("Insufficient command-line arguments.\n");
        return 1;
    }

    char* filename = argv[1]; // Input filename
    int stackSize = atoi(argv[2]); // Stack size

    // Open the input file, stack output file, queue output file, and doubly linked list output file
    FILE* input = fopen(filename, "r");
    FILE* stackOutput = fopen("stack.txt", "w");
    FILE* queueOutput = fopen("queue.txt", "w");
    FILE* dllOutput = fopen("dll.txt", "w");

    // Create stack, queue, and doubly linked list
    struct Stack* stack = createStack(stackSize);
    struct Queue* queue = createQueue(stackSize);
    struct DLL* dll = createDLL();

    char line[100];

    // Read lines from the input file
    while (fgets(line, sizeof(line), input)) {
        if (line[0] == '!') {
            displayStack(stack, stackOutput);
            displayQueue(queue, queueOutput);
            displayDLL(dll, dllOutput);
        } else if (line[0] == '+') {
            int value;
            sscanf(line, "+ %d", &value);
            push(stack, value, stackOutput);
            enqueue(queue, value, queueOutput);
            insert(dll, value, dllOutput);
        } else if (line[0] == '-') {
            int value;
            sscanf(line, "- %d", &value);
            pop(stack, stackOutput);
            dequeue(queue, queueOutput);
            delete(dll, value, dllOutput);
        } else if (line[0] == '?') {
            int value;
            sscanf(line, "? %d", &value);
            search(stack, value, stackOutput);
            searchQueue(queue, value, queueOutput);
            searchDLL(dll, value, dllOutput);
        }
    }

    // Close the files
    fclose(input);
    fclose(stackOutput);
    fclose(queueOutput);
    fclose(dllOutput);

    // Free the stack, queue, and doubly linked list memory
    freeStack(stack);
    freeQueue(queue);
    freeDLL(dll);

    return 0;
}
