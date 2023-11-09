#include <stdio.h>

int main()
{
    char str[4];
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t ;i++)
    {
        scanf("%s", str);
        int count = 0;
        if(str[0] == 'a') count += 1;
        if(str[1] == 'b') count += 1;
        if(str[2] == 'c') count += 1;
        if(count == 3 || count == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}