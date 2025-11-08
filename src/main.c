#include "program.h"
#include "string.h"

int
main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("usage: %s [flags...]\n", argv[0]);
		return EXIT_FAILURE;
	}

	Program_StringOption* s1 = program_add_string_option("-s", "-s1", NULL);
	Program_StringOption* s2 = program_add_string_option("-s2", NULL, NULL);
	Program_IntOption* i1 = program_add_int_option("-i", "-i1", 0);
	Program_BoolOption* b1 = program_add_bool_option("-b", "-b1", "-no-b", "-no-b1", true);
	Program_FloatOption* f1 = program_add_float_option("-f", "-f1", 1.05);

	String hello = string_new("Hello").result;
	String world = string_new(", world!!!!!!!!!!").result;

	string_append_string(&hello, world);
	string_append_cstr(&hello, " It's me!");

	printf("%s (%zu/%zu)\n", hello.text, hello.count_bytes, hello.capacity_bytes);

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

	printf("-i1 = %ld\n", i1->value);
	printf("-b1 = %d\n", b1->value);
	printf("-f1 = %lf\n", f1->value);

	return EXIT_SUCCESS;
}
