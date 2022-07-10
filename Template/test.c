#include <stdio.h>
#include <string.h>

int main()
{
    Record value, *ptr;

    ptr = &value;

    value.x = 1;
    strcpy(value.s, "XYZ");

    f(ptr);
    printf("\nValue of x %d", ptr -> x);
    printf("\nValue of s %s", ptr->s);


    return 0;
}

void f(Record *r)
{
    r->x *= 10;
    (*r).s[0] = 'A';
}

void g(Record r)
{
    r.x *= 100;
    r.s[0] = 'B';
}

void h(const Record r)
{
    r.x *= 1000;
    r.s[0] = 'C';
}
