#include <stdio.h>
#include <time.h>

#define JOPA		1

char    tab[] = { 0, 1, 2, 4, 8};

int		test_arry(char code)
{
	char	res;

	res = tab[code >> 6] |
		tab[0x03 & (code >> 4)] |
		tab[0x03 & (code >> 2)];

	return (res);
}

int		test_calc(char code)
{
	char tab2[6];
	char res;


	tab2 = (char[]){ 0, 1, 2, 4, 8};
	/*res = tab2[code >> 6] |
		tab2[0x03 & (code >> 4)] |
		tab2[0x03 & (code >> 2)];*/
	res = (8 >> (code >> 6)) | (8 >> (0x03 & (code >> 4))) |
		(8 >> (0x03 & (code >> 4)));
	return (res);
}

int		main(void)
{
	char    tab[5];
	char    types_flag;
	char	arg_type;
	register  long	counter = 0;
	clock_t start;
	clock_t	end;

	start = clock();
	while (counter++ < 1000000000)
	{
		test_arry(0x70);
	}
	end = clock();
	printf("test_arry %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	counter = 0;
	start = clock();
	while (counter++ < 1000000000)
	{
		test_calc(0x70);
	}
	end = clock();
	printf("test_calc %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	return (0);
}
