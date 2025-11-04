#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "program.h"

int
main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("usage: %s [flags...]\n", argv[0]);
		return EXIT_FAILURE;
	}

	// char** s1 = program_add_string_option("-s", "-s2", NULL);
	// char** s2 = program_add_string_option("-s2", NULL, NULL);

	Program_StringOption s1 = (Program_StringOption){
		.name = "-s",
		.name_alt = "-s1",
	};
	Program_StringOption s2 = (Program_StringOption){
		.name = "-s2",
	};

	Program_StringOption* string_options[] = {
		&s1,
		&s2,
	};

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "-help")) {
			printf("usage: %s [flags...]\n", argv[0]);
			return EXIT_SUCCESS;
		}

		bool exists = false;
		for (int j = 0; j < 2; j++) {
			if (!strcmp(argv[i], string_options[j]->name) || (string_options[j]->name_alt != NULL && !strcmp(argv[i], string_options[j]->name_alt))) {
				if ((i + 1) >= argc) {
					printf("error: flag %s missing value\n", argv[i]);
					return EXIT_FAILURE;
				}

				string_options[j]->set = true;
				string_options[j]->value = argv[i + 1];
				i++;
				exists = true;
			}
		}

		if (!exists) {
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
