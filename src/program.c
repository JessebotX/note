#include "program.h"

#define INT_BASE 10

Program_StringOption*
program_add_string_option(char* name, char* name_alt, char* value_default)
{
	uint8_t i = program__string_options_count;
	program__string_options[i] = (Program_StringOption){
		.name          = name,
		.name_alt      = name_alt,
		.value         = value_default,
		.value_default = value_default,
	};
	program__string_options_count++;

	return &program__string_options[i];
}

Program_IntOption*
program_add_int_option(char* name, char* name_alt, int value_default)
{
	uint8_t i = program__int_options_count;
	program__int_options[i] = (Program_IntOption){
		.name          = name,
		.name_alt      = name_alt,
		.value         = value_default,
		.value_default = value_default,
	};
	program__int_options_count++;

	return &program__int_options[i];
}

Program_FloatOption*
program_add_float_option(char* name, char* name_alt, double value_default)
{
	uint8_t i = program__float_options_count;
	program__float_options[i] = (Program_FloatOption){
		.name          = name,
		.name_alt      = name_alt,
		.value         = value_default,
		.value_default = value_default,
	};
	program__float_options_count++;

	return &program__float_options[i];
}

Program_BoolOption*
program_add_bool_option(char* name, char* name_alt, bool value_default)
{
	uint8_t i = program__bool_options_count;
	program__bool_options[i] = (Program_BoolOption){
		.name          = name,
		.name_alt      = name_alt,
		.value         = value_default,
		.value_default = value_default,
	};
	program__bool_options_count++;

	return &program__bool_options[i];
}

int
program_parse_options(int args_count, char* args[])
{
	for (int i = 0; i < args_count; i++) {
		bool exists = false;

		for (int j = 0; j < program__string_options_count; j++) {
			Program_StringOption* string_opt = &program__string_options[j];
			if (!strcmp(args[i], string_opt->name) || (string_opt->name_alt != NULL && !strcmp(args[i], string_opt->name_alt))) {
				if ((i + 1) >= args_count) {
					return 1;
				}

				string_opt->set = true;
				string_opt->value = args[i + 1];
				i++;
				exists = true;
				break;
			}
		}

		for (int j = 0; j < program__bool_options_count; j++) {
			Program_BoolOption* bool_opt = &program__bool_options[j];
			if (!strcmp(args[i], bool_opt->name) || (bool_opt->name_alt != NULL && !strcmp(args[i], bool_opt->name_alt))) {
				bool_opt->set = true;
				bool_opt->value = true;
				exists = true;
				break;
			}
		}

		for (int j = 0; j < program__int_options_count; j++) {
			Program_IntOption* int_opt = &program__int_options[j];
			if (!strcmp(args[i], int_opt->name) || (int_opt->name_alt != NULL && !strcmp(args[i], int_opt->name_alt))) {
				if ((i + 1) >= args_count) {
					return 1;
				}

				char* endptr;
				long int num = strtol(args[i + 1], &endptr, INT_BASE);
				if (*endptr != '\0') {
					return 1;
				}

				int_opt->set = true;
				int_opt->value = (int)(num);
				i++;
				exists = true;
				break;
			}
		}

		for (int j = 0; j < program__float_options_count; j++) {
			Program_FloatOption* float_opt = &program__float_options[j];
			if (!strcmp(args[i], float_opt->name) || (float_opt->name_alt != NULL && !strcmp(args[i], float_opt->name_alt))) {
				if ((i + 1) >= args_count) {
					return 1;
				}

				char* endptr;
				double num = strtod(args[i + 1], &endptr);
				if (*endptr != '\0') {
					return 1;
				}

				float_opt->set = true;
				float_opt->value = num;
				i++;
				exists = true;
				break;
			}
		}

		if (!exists) {
			return 2;
		}
	}

	return 0;
}
