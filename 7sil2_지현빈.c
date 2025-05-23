#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    int t = gcd(b, a % b);
    return t;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}
