#include <stdio.h>

void main() {
    int a[5];
    int *p0, *p1, *p2, *p3, *p4;

    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    a[4] = 50;

    p0 = &a[0];
    p1 = &a[1];
    p2 = &a[2];
    p3 = &a[3];
    p4 = &a[4];

    printf("\n the values are : ");
    printf("\n the value of a[0] = %d", a[0]);
    printf("\n the value of a[1] = %d", a[1]);
    printf("\n the value of a[2] = %d", a[2]);
    printf("\n the value of a[3] = %d", a[3]);
    printf("\n the value of a[4] = %d", a[4]);
    // Note: accessing a[5] is out of bounds, but transcribed as written in notes
    printf("\n the value of a[5] = %d", a[5]);

    printf("\n the address of a[0] = %p", p0);
    printf("\n the address of a[1] = %p", p1);
    printf("\n the address of a[2] = %p", p2);
    printf("\n the address of a[3] = %p", p3);
    printf("\n the address of a[4] = %p", p4);
}

