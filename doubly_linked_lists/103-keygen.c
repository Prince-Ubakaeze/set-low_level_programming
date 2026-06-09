#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a valid key based on a username for crackme5.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *username;
	char key[7];
	int len, i, sum;
	char *lookup = "A-Za-z0-9-ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);

	/* Character 1 */
	key[0] = lookup[(len ^ 59) & 63];

	/* Character 2 */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += username[i];
	key[1] = lookup[(sum ^ 79) & 63];

	/* Character 3 */
	sum = 1;
	for (i = 0; i < len; i++)
		sum *= username[i];
	key[2] = lookup[(sum ^ 85) & 63];

	/* Character 4 */
	sum = username[0];
	for (i = 0; i < len; i++)
	{
		if (username[i] > sum)
			sum = username[i];
	}
	srand(sum ^ 14);
	key[3] = lookup[rand() & 63];

	/* Character 5 */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += (username[i] * username[i]);
	key[4] = lookup[(sum ^ 239) & 63];

	/* Character 6 */
	sum = 0;
	for (i = 0; i < username[0]; i++)
		sum = rand();
	key[5] = lookup[(sum ^ 229) & 63];

	key[6] = '\0';

	/* Print the final generated 6-character key string */
	printf("%s", key);

	return (0);
}
