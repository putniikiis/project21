#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void sort_doors(struct door *doors);
void print_doors(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort_doors(doors);
    print_doors(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
        for (int y = 0; y < DOORS_COUNT - 1; y++)
            if (doors[y].id > doors[y + 1].id) {
                struct door tmp = doors[y];
                doors[y] = doors[y + 1];
                doors[y + 1] = tmp;
            }
    }
}

void print_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) printf("%d, %d\n", doors[i].id, doors[i].status);
}