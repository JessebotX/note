#include "program.h"

int
main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("usage: %s [flags...]\n", argv[0]);
		return EXIT_FAILURE;
	}

	Program_StringOption* s1 = program_add_string_option("-s", "-s1", NULL);
	Program_StringOption* s2 = program_add_string_option("-s2", NULL, NULL);

	int err;
	if ((err = program_parse_options(argc - 1, argv + 1))) {
		printf("%d\n", err);
		return EXIT_FAILURE;
	}

	if (s1->set) {
		printf("-s1 = %s\n", s1->value);
	}

	if (s2->set) {
		printf("-s2 = %s\n", s2->value);
	}

	return EXIT_SUCCESS;
}
