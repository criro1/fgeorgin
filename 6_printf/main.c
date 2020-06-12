#include "include/ft_printf.h"
#include "stdio.h"

int main()
{
    ft_printf("%d - %s, %f, %Xo\n", 777, "testing prog", 55.432, 66);
    printf("%d - %s, %f, %Xo\n", 777, "testing prog", 55.432, 66);
    return 0;
}