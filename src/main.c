#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program.h"

int
main(int argc, char* argv[])
{
	Program_StringOption s1;
	Program_StringOption s2;

	if (argc < 2) {
		printf("usage: %s [flags...]\n", argv[0]);
		return EXIT_FAILURE;
	}

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "-help")) {
			printf("usage: %s [flags...]\n", argv[0]);
			return EXIT_SUCCESS;
		}

		if (!strcmp(argv[i], "-s1")) {
			if ((i + 1) >= argc) {
				printf("error: flag %s missing value\n", argv[i]);
				return EXIT_FAILURE;
			}

			s1.set = true;
			s1.value = argv[i + 1];
			i++;
		} else if (!strcmp(argv[i], "-s2")) {
			if ((i + 1) >= argc) {
				printf("error: flag %s missing value\n", argv[i]);
				return EXIT_FAILURE;
			}

			s2.set = true;
			s2.value = argv[i + 1];
			i++;
		} else {
			printf("error: unrecognized flag %s\n", argv[i]);
			return EXIT_FAILURE;
		}
	}

	printf("Hello world\n");

	if (s1.set) {
		printf("-s1 = %s\n", s1.value);
	}

	if (s2.set) {
		printf("-s2 = %s\n", s2.value);
	}

	return EXIT_SUCCESS;
}
