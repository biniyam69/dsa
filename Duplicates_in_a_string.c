// print loop for duplicates in a string


#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, len, count;
    printf("Enter the string: ");
    scanf("%s", str);
    len = strlen(str);
    for(i=0; i<len; i++)
    {
        count = 1;
        if(str[i])
        {
            for(j=i+1; j<len; j++)
            {
                if(str[i] == str[j])
                {
                    count++;
                    str[j] = '\0';
                }
            }
            if(count > 1)
            {
                printf("%c is repeated %d times\n", str[i], count);
            }
        }
    }
    return 0;
}