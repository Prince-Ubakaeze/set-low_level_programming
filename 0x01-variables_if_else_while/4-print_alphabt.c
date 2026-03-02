#include <stdio.h>

/**
 *main entry point
 *
 * Description: Prints alphabet in lowercase except q & e
 *
 * return always 0 success
 */

int main (void) 
{
char letter;

for (letter = 'a'; letter <= 'z'; letter++)
{
if(letter != 'e' && letter != 'q')
	putchar (letter);
}

putchar('\n');
return (0);
}
