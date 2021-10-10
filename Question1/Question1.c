#include<stdio.h>


int solution(int n)
{
    int both = n / 3;
    int rest = n - 3 * both;
    return 2 * both + (rest != 0);
}

/* Do not edit below code */
int main(void) {
    int n;
    scanf("%d",&n);
    int answer=solution(n);
    printf("%d",answer);
    return 0;
}
