#include "list.h"

#include <stdlib.h>

struct node *init(struct door *door) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->door = door;
    new_node->next = NULL;
    return new_node;
}

struct node *add_door(struct node *elem, struct door *door) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->door = door;
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
}

struct node *find_door(int door_id, struct node *root) {
    struct node *current = root;
    while (current != NULL) {
        if (current->door->id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node *remove_door(struct node *elem, struct node *root) {
    struct node *current = root;
    if (elem == root) {
        root = root->next;
        free(elem->door);
        free(elem);
        return root;
    }
    while (current != NULL) {
        if (current->next == elem) {
            current->next = elem->next;
            free(elem->door);
            free(elem);
            return root;
        }
        current = current->next;
    }
    return NULL;
}

void destroy(struct node *root) {
    struct node *current = root;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->door);
        free(current);
        current = next;
    }
}
