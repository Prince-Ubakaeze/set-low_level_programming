#include <stdio.h>

/*
 * main entry point
 *
 * Description: Prints letters in uppercase and lowercase
 *
 * return always 0 success
 */

int main(void) 
{
char letter;

/* loop 1: prints in lowercase */
for (letter = 'a'; letter <= 'z'; letter++)
	putchar(letter);

/* Loop 2: prints in uppercase */
for (letter = 'A'; letter <= 'Z'; letter++)
	putchar(letter);

/* final newline */
putchar('\n');

return(0);
}
