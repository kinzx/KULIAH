#include <stdio.h>

int main()
{
    int alpukat, jambu;

    for (alpukat = 5; alpukat >= 1; alpukat--)
    {

        for (jambu = 5; jambu >= alpukat; jambu--)
        {
            printf("%d ", jambu);
        }
        printf("\n");
    }

    return 0;
}
