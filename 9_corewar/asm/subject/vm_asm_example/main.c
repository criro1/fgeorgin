#include <unistd.h>
#include <fcntl.h>

int			main(void)
{
	int		i;
	int		cnt = 0;
	int		res;
	int		fd;
	char	*a;
	char	*b;

	i = 0x258;
	a = (char*)&i;
	b = ((char*)&res) + 3;
	while (cnt++ < 4)
		*b-- = *a++;
	fd = open("test.cor", O_TRUNC | O_CREAT | O_WRONLY, 511);
	write(fd, &res, 4);
	close(fd);
	return (0);
}
