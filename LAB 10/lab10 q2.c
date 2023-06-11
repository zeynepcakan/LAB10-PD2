#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};

struct node* cutlastaddhead(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct node* current = head;
    struct node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;  // Son düðümü kes

    current->next = head;  // Kesilen düðümü listenin baþýna ekle

    return current;  // Listenin yeni baþýný döndür
}

void printList(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int numElements,i;
    printf("Liste boyutunu girin: ");
    scanf("%d", &numElements);

    if (numElements <= 0) {
        printf("Geçersiz liste boyutu!\n");
        return 1;
    }

    // Baðlý liste oluþturma
    struct node* head = NULL;
    struct node* tail = NULL;

    for ( i = 0; i < numElements; i++) {
        int value;
        printf("Eleman %d girin: ", i + 1);
        scanf("%d", &value);

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->number = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Kesme ve baþa ekleme iþlemini gerçekleþtirme
    struct node* newHead = cutlastaddhead(head);

    printf("Yeni Liste: ");
    printList(newHead);

    // Bellek temizleme
    struct node* current = newHead;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

