#include<stdio.h>

int solution(int n)
{
    return n/3*2 + (n % 3 != 0);
}

/* Do not edit below code */
int main(void) {
    int n;
    scanf("%d",&n);
    int answer=solution(n);
    printf("%d",answer);
    return 0;
}
