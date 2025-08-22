#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct SLL {
    int info;
    struct SLL *next;
};

// Menu function
void menu() {
    printf("\n1. Insert at first");
    printf("\n2. Insert at last");
    printf("\n3. Delete at first");
    printf("\n4. Delete at last");
    printf("\n5. Search");
    printf("\n6. Count");
    printf("\n7. Display");
    printf("\n8. Exit");
}

// Create a node
struct SLL *createNode(int x) {
    struct SLL *temp;
    temp = (struct SLL *)malloc(sizeof(struct SLL));
    temp->info = x;
    temp->next = NULL;
    return temp;
}

// Insert at first
struct SLL *InsertAtfirst(struct SLL *first, int x) {
    struct SLL *temp = createNode(x);
    if (first == NULL) {
        first = temp;
    } else {
        temp->next = first;
        first = temp;
    }
    return first;
}

// Insert at last
struct SLL *InsertAtLast(struct SLL *first, int x) {
    struct SLL *temp = createNode(x);
    if (first == NULL) {
        first = temp;
    } else {
        struct SLL *p = first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    return first;
}

// Delete at first
struct SLL *DeleteAtFirst(struct SLL *first) {
    if (first == NULL) {
        printf("\nList is empty!");
    } else {
        struct SLL *temp = first;
        first = first->next;
        printf("\nDeleted: %d", temp->info);
        free(temp);
    }
    return first;
}

// Delete at last
struct SLL *DeleteAtLast(struct SLL *first) {
    if (first == NULL) {
        printf("\nList is empty!");
    } else if (first->next == NULL) {
        printf("\nDeleted: %d", first->info);
        free(first);
        first = NULL;
    } else {
        struct SLL *p = first, *q = NULL;
        while (p->next != NULL) {
            q = p;
            p = p->next;
        }
        printf("\nDeleted: %d", p->info);
        free(p);
        q->next = NULL;
    }
    return first;
}

// Search
void Search(struct SLL *first, int key) {
    struct SLL *p = first;
    int pos = 1;
    while (p != NULL) {
        if (p->info == key) {
            printf("\nElement %d found at position %d", key, pos);
            return;
        }
        p = p->next;
        pos++;
    }
    printf("\nElement %d not found!", key);
}

// Count
void Count(struct SLL *first) {
    int count = 0;
    struct SLL *p = first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    printf("\nTotal nodes: %d", count);
}

// Display
void Display(struct SLL *first) {
    struct SLL *p;
    if (first == NULL) {
        printf("\nList is empty!");
    } else {
        p = first;
        printf("\nList: ");
        while (p != NULL) {
            printf("%d -> ", p->info);
            p = p->next;
        }
        printf("NULL");
    }
}

// Main function
void main() {
    struct SLL *first = NULL;
    int x, choice;
    clrscr();
    while (1) {
        menu();
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                first = InsertAtfirst(first, x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                first = InsertAtLast(first, x);
                break;
            case 3:
                first = DeleteAtFirst(first);
                break;
            case 4:
                first = DeleteAtLast(first);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &x);
                Search(first, x);
                break;
            case 6:
                Count(first);
                break;
            case 7:
                Display(first);
                break;
            case 8:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
        getch();
        clrscr();
    }
}
