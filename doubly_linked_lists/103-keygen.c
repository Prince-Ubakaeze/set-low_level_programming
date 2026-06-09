#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * find_max - Locates the highest character byte value.
 * @str: The username string.
 * @len: Length of the string.
 *
 * Return: Maximum byte value found.
 */
int find_max(char *str, int len)
{
	int max = str[0];
	int i;

	for (i = 0; i < len; i++)
	{
		if (str[i] > max)
			max = str[i];
	}
	return (max);
}

/**
 * calc_rand - Computes the squared sum and random offset bytes.
 * @str: The username string.
 * @len: Length of the string.
 * @res: Results holder array.
 */
void calc_rand(char *str, int len, int *res)
{
	int i;

	res[0] = 0;
	for (i = 0; i < len; i++)
		res[0] += (str[i] * str[i]);

	res[1] = 0;
	for (i = 0; i < str[0]; i++)
		res[1] = rand();
}

/**
 * main - Keygen for crackme5.
 * @argc: Argument count.
 * @argv: Argument vector array.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *u;
	char key[7];
	int len, i, sum, max_val, r_arr[2];
	char *l = "A-Za-z0-9-ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	if (argc != 2)
		return (1);

	u = argv[1];
	len = strlen(u);

	key[0] = l[(len ^ 59) & 63];
	sum = 0;
	for (i = 0; i < len; i++)
		sum += u[i];
	key[1] = l[(sum ^ 79) & 63];
	sum = 1;
	for (i = 0; i < len; i++)
		sum *= u[i];
	key[2] = l[(sum ^ 85) & 63];

	max_val = find_max(u, len);
	srand(max_val ^ 14);
	key[3] = l[rand() & 63];

	calc_rand(u, len, r_arr);
	key[4] = l[(r_arr[0] ^ 239) & 63];
	key[5] = l[(r_arr[1] ^ 229) & 63];
	key[6] = '\0';

	printf("%s", key);
	return (0);
}
