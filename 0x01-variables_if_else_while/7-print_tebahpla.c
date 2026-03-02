#include <stdio.h>

/**
 * main entry point
 *
 * Description: prints alphabets in reverse lowercase
 *
 * return always 0 success
 */

int main(void)
{
char letter;

for(letter = 'z'; letter >= 'a'; letter--)


{
	putchar(letter);
}

putchar ('\n');

return (0);
}
