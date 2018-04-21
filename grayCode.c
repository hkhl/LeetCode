/*************************************************************************
	> File Name: gelei.c
	> Author: wang
	> Mail: dhkhl235@gmail.com
	> Created Time: 2018年04月21日 星期六 11时39分09秒
 ************************************************************************/

#include <stdio.h>

#define N 4

/*便于理解的garyCode简易打印代码*/
int str[100];
void reverse(int *p)
{
    if(*p == 0)
        *p = 1;
    else
    {
        *p = 0;
    }
}

void fun(int n)
{
    if(n == 0)
    {
        for(int i = N - 1; i >= 0; i--)
        {
            printf("%d", str[i]);
        }
        printf("\n");
        return ;
    }

    fun(n-1);
    reverse(&str[n-1]);
    fun(n-1);
}

int main()
{
    fun(N);
    return 0;
}
