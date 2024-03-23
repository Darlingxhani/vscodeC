
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int r = 0;
char str[100];
char *reverses(char *s)
{
    if (s[0] == '-')
    {
        int l = 1, r = strlen(s) - 1;
        while (l < r)
        {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--;
        }
    }
    else
    {
        int l = 0, r = strlen(s) - 1;
        while (l < r)
        {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--;
        }
    }
    return s;
}
bool requiry(char *s)
{
    if (s[0] == '-')
    {
        if (s[1] == '0')
        {
            size_t i = 1;
            while (i < strlen(s) && s[i] == '0')
                i++;
            r = i;
            strcpy(str + 1, s + r);
            str[0] = '-';
        }
        else
        {
            strcpy(str, s);
        }
        if (strlen(str) > 11)
        {
            return false;
        }
        if (strlen(str) < 11)
        {
            return true;
        }
        else
        {
            const char *t = "2147483648";
            for (size_t i = 1; i < strlen(str); i++)
            {
                if (str[i] > t[i])
                    return false;
            }
            return true;
        }
    }
    else
    {
        if (s[0] == '0')
        {
            size_t i = 0;
            while (i < strlen(s) && s[i] == '0')
                i++;
            r = i;
        }
        strcpy(str, s + r);
        if (strlen(str) > 10)
        {
            return false;
        }
        if (strlen(str) < 10)
        {
            return true;
        }
        else
        {
            const char *t = "2147483647";
            for (size_t i = 0; i < strlen(str); i++)
            {
                if (str[i] > t[i])
                    return false;
            }
            return true;
        }
    }
}
int main()
{
    char s[100];
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';
    if (strcmp(s, "0") == 0 || strcmp(s, "-0") == 0)
    {
        printf("0");
    }
    else
    {
        char *t = reverses(s);
        if (requiry(t))
        {
            printf("%s", str);
        }
        else
        {

            printf("0");
        }
    }
    return 0;
}
