#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* head = NULL;

// Insert node at the beginning
void insertNodeInBeg(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;  // Points to itself in circular list
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;  // Update last node's next to new head
    }
    printf("Node Inserted !!!!!!\n");
}

// Insert node at the end
void insertNodeAtEnd(int ele) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node Inserted !!!!!!\n");
}

// Insert at any position
void insertAtAnyPos(int ele, int pos) {
    if (head == NULL && pos != 1) {
        printf("List is empty, can only insert at position 1\n");
        return;
    }
    if (pos == 1) {
        insertNodeInBeg(ele);
        return;
    }
    
    Node* temp = head;
    int i = 1;
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next != head || i == pos - 1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = ele;
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node Inserted !!!!!!\n");
    } else {
        printf("Invalid Position !!!!\n");
    }
}

// Delete node from beginning
void deleteNodeFromBeg() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    if (head->next == head) {  // Only one node
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Node Deleted !!!!!\n");
}

// Delete node from end
void deleteNodeFromEnd() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    if (head->next == head) {  // Only one node
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Node Deleted !!!!!\n");
}

// Delete node from any position
void deleteNodeFromAnyPos(int pos) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    if (pos == 1) {
        deleteNodeFromBeg();
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    int i = 1;
    
    while (i < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    
    if (i == pos) {
        prev->next = temp->next;
        free(temp);
        printf("Node Deleted !!!!!\n");
    } else {
        printf("Invalid Position!!!\n");
    }
}

void search(int target) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        Node* temp = head;
        do {
            if (temp->data == target) {
                printf("Element Found!!!\n");
                return;
            }
            temp = temp->next;
        } while (temp != head);
        printf("Not Found!!!\n");
    }
}

// Display circular linked list elements
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node* temp = head;
    printf("Elements are: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function with menu-driven implementation
int main() {
    while (1) {
        printf("\n.......Circular Singly Linked List.......\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position\n");
        printf("7. Search Element in List\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        
        int choice, value, pos, target;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertNodeInBeg(value);
                display();
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertNodeAtEnd(value);
                display();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtAnyPos(value, pos);
                display();
                break;
            case 4:
                deleteNodeFromBeg();
                display();
                break;
            case 5:
                deleteNodeFromEnd();
                display();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteNodeFromAnyPos(pos);
                display();
                break;
            case 7:
                printf("Enter target: ");
                scanf("%d", &target);
                search(target);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
