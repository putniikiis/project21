#include <stdio.h>

int max (int a, int b);

int main (){
  int a;
  float b;
  if(scanf("%d %f", &a, &b) != 2 || (int)b!=b) {printf("n/a");}
  int m = max(a,b);
  printf("%d", m);
  return 0; }

  int max(int a, int b){
    int s;
    if(a<b) {s=b;}
    else s=a;
    return s;
  }