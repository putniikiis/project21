#include <stdio.h>

int main() {
    float x, y;
    float crack;
    if (scanf("%f %f", &x, &y) != 2) {
        printf("n/a");
    } else {
        crack = (x * x) + (y * y);
        if (crack < 25.0) {
            printf("GOTCHA");
        } else {
            printf("MISS");
        }
    }
    return 0;
}