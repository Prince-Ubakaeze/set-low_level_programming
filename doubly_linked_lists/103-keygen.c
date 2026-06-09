#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * validate_key - Generates a verifiable hash based on a given username
 * @username: The input username string
 * @provided_key: The user-supplied key to compare against
 *
 * Return: 1 if the key matches the calculated criteria, 0 otherwise
 */
int validate_key(const char *username, const char *provided_key)
{
	size_t len = strlen(username);
	size_t i;
	char expected_key[256];

	if (len == 0 || len > 100)
		return (0);

	/* Simple deterministic transformation mapping for demonstration */
	for (i = 0; i < len && i < 255; i++)
	{
		/* Example logic: static XOR mask altering input characters */
		expected_key[i] = username[i] ^ 0x5A;
	}
	expected_key[i] = '\0';

	/* Compare the generated criterion with the user's supplied argument */
	if (strcmp(expected_key, provided_key) == 0)
		return (1);

	return (0);
}

/**
 * main - Secure command line interface wrapper
 * @argc: Argument count
 * @argv: Argument vector containing program name, username, and key
 *
 * Return: Always 0 (Success) or 1 (Failure/Invalid arguments)
 */
int main(int argc, char **argv)
{
	/* 
	 * CRITICAL: Check that all parameters exist before scanning memory. 
	 * Accessing argv[1] or argv[2] when argc < 3 causes a Segmentation Fault.
	 */
	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s <username> <key>\n", argv[0]);
		return (1);
	}

	if (validate_key(argv[1], argv[2]))
	{
		printf("Validation Succeeded!\n");
	}
	else
	{
		printf("Validation Failed.\n");
	}

	return (0);
}
