#include <iostream>
#include <cstdlib>

typedef int ElementType;
typedef struct tagNode {
    ElementType data;
    struct tagNode* nextNode;
} Node;

const int BUCKET_COUNT = 10;

void appendNode(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* tail = *head;
        while (tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        tail->nextNode = newNode;
    }
}

Node* createNode(ElementType newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->nextNode = NULL;
    return newNode;
}

void insertAfter(Node* current, Node* newNode) {
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

void orderInsertNoDuple(Node* buckets[], int data) {
    int bucketIndex = data % BUCKET_COUNT;

    
    Node* current = buckets[bucketIndex];
    while (current != NULL) {
        if (current->data == data) {
            return; 
        }
        current = current->nextNode;
    }


    Node* newNode = createNode(data);
    Node* prev = NULL;
    current = buckets[bucketIndex];

    
    while (current != NULL && current->data < data) {
        prev = current;
        current = current->nextNode;
    }


    if (prev == NULL) {
        
        newNode->nextNode = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    } else {
        
        insertAfter(prev, newNode);
    }
}

void printList(Node* buckets[]) {
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        std::cout << "[" << i << "]: ";
        Node* current = buckets[i];
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->nextNode;
        }
        std::cout << std::endl;
    }
}

void deleteList(Node* buckets[]) {
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        Node* current = buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->nextNode;
            free(temp);
        }
        buckets[i] = NULL;
    }
}

void deleteValue(Node* buckets[], int data) {
    int bucketIndex = data % BUCKET_COUNT;

    
    Node* current = buckets[bucketIndex];
    Node* prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->nextNode;
    }

    
    if (current == NULL) {
        std::cout << "No delete" << std::endl;
        return;
    }

    
    if (prev == NULL) {
        buckets[bucketIndex] = current->nextNode;
    } else {
        prev->nextNode = current->nextNode;
    }
    free(current);
}

int main() {
    
    Node* buckets[BUCKET_COUNT];
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        buckets[i] = NULL;
    }

    bool shouldExit = false;

    while (!shouldExit) {
        int input;
        std::cin >> input;

        if (input == 0) {
            shouldExit = true;
        } else if (input > 0) {
            orderInsertNoDuple(buckets, input);
        } else { 
            deleteValue(buckets, -input);
        }
    }

    printList(buckets);
    deleteList(buckets);

    return 0;
}
