#include <stdio.h>

int main ()
{
    int foo = 10, bar = 5;

    printf ("%d\n", foo + 10);
    printf ("%d\n", foo + 10);
    printf ("%d\n", foo + 10);

    bar = foo + 1;

    printf ("%d\n", foo);
    printf ("%d\n", bar);
    printf ("%d\n", foo+bar);

    foo = foo + 2;
    printf ("%d\n", foo);

    return 0;
}
