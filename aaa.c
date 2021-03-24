#include <stdio.h>

int main()
{
    FILE *fp = fopen("zz.txt", "w");
    for (int i = 0; i < 10000; i++)
    {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);

    return 0;
}