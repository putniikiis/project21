/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int n);
float mean(int *a, int n);
float dispersion(int *a, int n);
int searchnumber(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(searchnumber(data, n));
    } else
        printf("n/a");
    return 0;
}
/* ------------------------- */

int input(int *a, int *n) {
    if (scanf("%d", n) == 1 && *n <= NMAX) {
        for (int *p = a; p - a < *n; p++)
            if (scanf("%d", p) != 1 || *p != (int)*p) return 0;
        return 1;
    } else
        return 0;
}

void output(int n) { printf("%d", n); }

float mean(int *a, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum = sum + (float)*a;
        a++;
    }
    return sum / n;
}

float dispersion(int *a, int n) {
    float sum = 0.0;
    float average = mean(a, n);
    for (int i = 0; i < n; i++) {
        sum = sum + pow((*a - average), 2);
        a++;
    }
    return sum / n;
}

int searchnumber(int *a, int n) {
    float meanvalue = mean(a, n);
    float dispersionvalue = dispersion(a, n);
    float sigma1 = meanvalue + 3 * sqrt(dispersionvalue);
    float sigma2 = meanvalue - 3 * sqrt(dispersionvalue);

    for (int i = 0; i < n; i++) {
        if (*a % 2 == 0 &&      // Четность even
            *a >= meanvalue &&  // больше/равно мат ожиданию ">= mean"
            *a != 0 &&          // Не равно 0
            *a <= sigma1 &&     // Проверка на сигму 1
            *a >= sigma2        // Проверка на сигму 2
        )
            return *a;
        a++;
    }
    return 0;
} /*
     Search module for the desired value from data array.

     Returned value must be:
         - "even"
         - ">= mean"
         - "<= mean + 3 * sqrt(variance)"
         - "!= 0"

         OR

         0
 */