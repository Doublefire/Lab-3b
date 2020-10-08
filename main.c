#include <stdio.h>
#include <stdlib.h>

struct llist {
    int data;
    struct llist *next;
    struct  llist *prev;
};

struct llist *insertEntry(struct llist *litem, int x)
{
    struct llist *new_item = malloc(sizeof(struct llist));

    new_item->data = x;
    new_item->next = NULL;

    litem->next = new_item;

    return new_item;

}

void deleteEntry(struct llist *head, int index){
    //iterate the list until you reach index
    //come out of the loop
    //re assign the pointers
    struct llist *currentItem;
    currentItem = head;
    int count = 1;
    while (currentItem != NULL && count < (index - 1)) {
        printf("%i, ", currentItem->data);
        currentItem = currentItem->next;
        count++;
    }

    struct llist *temp = currentItem->next;
    currentItem-> next = currentItem->next->next;
    free(temp);

}

void showList(struct llist *head) {
    struct llist *currentItem;
    currentItem = head;
    while (currentItem != NULL) {
        printf("%i, ", currentItem->data);
        currentItem = currentItem->next;
    }
}

int main() {

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    struct llist l1;
    l1.data = 0;
    l1.next = NULL;

    struct llist *head;
    head = &l1;

    for(int i = 0; i < 10; i++) {
        head = insertEntry(head, array[i]);
    }
    showList(&l1);
    printf("\n");
    head = &l1;
    deleteEntry(head, 4);
    printf("\n");
    showList(head);

    return 0;
}
