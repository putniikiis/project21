#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void sort(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else
        printf("n/a");
    return 0;
}

/* Функции */
int input(int *a, int *n) {
    if (scanf("%d", n) == 1 && *n <= NMAX) {
        for (int *p = a; p - a < *n; p++)
            if (scanf("%d", p) != 1 || *p != (int)*p) return 0;
        return 1;
    } else
        return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *a);
        a++;
    }
    printf("\n");
}

void sort(int *a, int n) {
    int temp;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int max(int *a, int n) {
    int p[n];
    for (int i = 0; i < n; i++) p[i] = a[i];  // копируем массив
    sort(p, n);
    return p[n - 1];
}

int min(int *a, int n) {
    int p[n];
    for (int i = 0; i < n; i++) p[i] = a[i];  // копируем массив
    sort(p, n);
    return p[0];
}

double mean(int *a, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum = sum + (float)*a;
        a++;
    }
    return sum / n;
}
double variance(int *a, int n) {
    float sum = 0.0;
    float average = mean(a, n);
    for (int i = 0; i < n; i++) {
        sum = sum + pow((*a - average), 2);
        a++;
    }
    return sum / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}