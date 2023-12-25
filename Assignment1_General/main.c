#include <stdio.h>
#include "math.h"

int main ()
{
    check_version();
    printf ("8+10 = %d\n",sum(8,10));
    printf ("8+1 = %d\n",add(8));
    printf ("8-1 = %d\n",del(8));
    return 0;
}