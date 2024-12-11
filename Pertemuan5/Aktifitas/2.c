#include <stdio.h>
#include <string.h>

int main()
{
    int length, i, s_len, rand_num = 0;
    char password;
    const char search[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=,.<>?";

    srand(time(NULL));
    s_len = strlen(search);
    printf("Enter the length of password : ");
    scanf("%d", &length);

    if (length < 8 || length > 32)
    {
        printf("Password length should be be 8 and 32 char: ");
    }
    else
    {
        printf("Your password is: \n");
        for (int i = 0; i < length; i++)
        {
            rand_num = rand() % s_len;
            password = search[rand_num];
            printf("%c", password);
        }
    }
    return 0;
}
