#include <stdio.h>

int main () {
     int a= 10;
     void *b = &a;
     
    printf("int a = %d\n",a);
    printf("void (int *)b =%d \n",*(int *)b);
    printf("void (double *)b =%f \n",*(double*)b);
    return 0;
}
