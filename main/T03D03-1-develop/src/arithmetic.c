#include <stdio.h>

int del(int input, int input_1);
int plus(int input, int input_1);
int minus(int input, int input_1);
int umnoj(int input, int input_1);

int main() {
    float input, input_1;
    if (scanf("%f %f", &input, &input_1) != 2 || (int)input != input || (int)input_1 != input_1) {
        printf("n/a");
    }

    if (input_1 != 0) {
        printf("%d %d %d %d", plus(input, input_1), minus(input, input_1), umnoj(input, input_1),
               del(input, input_1));
    } else {
        printf("%d %d %d n/a", plus(input, input_1), minus(input, input_1), umnoj(input, input_1));
    }
};
int plus(int input, int input_1) { return input + input_1; }

int minus(int input, int input_1) { return input - input_1; }

int umnoj(int input, int input_1) { return input * input_1; }

int del(int input, int input_1) { return input / input_1; }