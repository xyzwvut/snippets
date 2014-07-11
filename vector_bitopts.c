#include <stdio.h>
#include <stdlib.h>

#define BITS 10

/*
 * 1. Read a list of numbers.
 * 2. Set the specific bits in a bitfield
 * 3. And dump the set bits.
 */


void
set_bit(char *vector, int pos)
{
  int byte = pos / 8;
	int off = pos % 8;

	vector[byte] |= 1 << off;
}

void
clear_bit(char *vector, int pos)
{
	int byte = pos / 8;
	int off = pos % 8;

	vector[byte] &= ~(1 << off);
}

int
test_bit(char *vector, int pos)
{
	int byte = pos / 8;
	int off = pos % 8;

	return !!(vector[byte] & (1 << off));
}


int
main(void)
{
	char *vector = malloc(BITS);
	int i;

	if (!vector)
		return -1;

	for (i = 0; i < BITS; i++)
		clear_bit(vector, i);

  while (scanf("%d", &i) != EOF)
		set_bit(vector, i);

	for (i = 0; i < BITS; i++) {
		if (test_bit(vector, i))
			printf("%d\n", i);
	}

	return 0;
}
