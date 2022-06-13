#include <stdio.h>
int tower(int n, char from, char aux, char to);
int count = 0;
int main(void)
{
    int n;
    char from, to, aux;
    scanf("%d", &n);
    from = 'A', to = 'C', aux = 'B';
    int c = tower(n, from, aux, to);
    printf("%d\n", c);
    return 0;
}

int tower(int n, char from, char aux, char to)
{
    count++;
    if (n == 1)
    {
        printf("move disk 1 from %c to %c\n", from, to);
        return 1;
    }
    tower(n - 1, from, to, aux);
    printf("move disk %d from %c to %c\n", n - 1, from, to);
    tower(n - 1, aux, from, to);
    //count += 2;
    return count;
}