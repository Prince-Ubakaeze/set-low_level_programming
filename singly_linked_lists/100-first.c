#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - Prints a poem before the main function is executed.
 *
 * Description: Uses the GCC constructor attribute to force execution
 * prior to the invocation of the program's entry point (main).
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
