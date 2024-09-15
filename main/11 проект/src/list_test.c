#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAIL -1

struct node *init(struct door *door);
struct node *add_door(struct node *elem, struct door *door);
struct node *find_door(int door_id, struct node *root);
struct node *remove_door(struct node *elem, struct node *root);
void destroy(struct node *root);

int main() {
    struct door *door1 = (struct door *)malloc(sizeof(struct door));
    door1->id = 1;
    struct node *list = init(door1);
    struct door *door2 = (struct door *)malloc(sizeof(struct door));
    door2->id = 2;
    add_door(list, door2);
    if (find_door(2, list) == NULL) {
        printf("add_door test failed\n");
        return FAIL;
    }
    struct node *node_to_remove = find_door(2, list);
    remove_door(node_to_remove, list);
    if (find_door(2, list) != NULL) {
        printf("FAIL\n");
        return FAIL;
    }
    destroy(list);
    printf("SUCCESS\n");
    return SUCCESS;
}