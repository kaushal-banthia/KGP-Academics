#include <stdio.h>
#include <stdlib.h>

void main()
{
    int p[9] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int v[9];
    v[0] = p[0];
    v[1] = p[1];
    int more = 0;
    int max_cut[9];
    max_cut[0] = 0;
    max_cut[1] = 0;

    for (int i = 2; i <= 9; i++)
    {
        more = 0;
        for (int j = 1; j <= i; j++)
        {
            if (more < p[j] + v[i-j])
            {
                more = p[j] + v[i-j];
                max_cut[i] = j;
            }
        }
        v[i] = more;
    }
    printf("%d\n", v[8]);

    for (int i = 0; i < 9; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    int i = 8;
    printf("Cut Sizes are ");
    while(i>0)
    {
        printf("%d ", max_cut[i]);
        i-=max_cut[i];
    }
}
