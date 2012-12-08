/*
 * $Id: keynames.c 2 2004-02-23 03:20:42Z kal $
 */

#include <test.priv.h>

int main(int argc GCC_UNUSED, char *argv[] GCC_UNUSED)
{
	int n;
	for (n = -1; n < 512; n++) {
		printf("%d(%5o):%s\n", n, n, keyname(n));
	}
	return EXIT_SUCCESS;
}
