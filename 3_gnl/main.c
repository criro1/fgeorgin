#include "get_next_line.h"
#include "stdio.h"

int main()
{
    char *line;
    int fd;

    fd = open("filename", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", line);
    get_next_line(fd, &line);
    printf("%s\n", line);
    get_next_line(fd, &line);
    printf("%s\n", line);
    return 0;
}