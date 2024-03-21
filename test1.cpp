#include <stdio.h>
int main()
{
    int x = 8, y = 0, z = 0;
    y = !x && (++z);

    printf("%d %d %d", x, y, z);
    return 0;
}
