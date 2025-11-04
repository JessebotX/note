#include "program.h"

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

int*
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

	return &program__int_options[i].value;
}

double*
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

	return &program__float_options[i].value;
}

bool*
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

	return &program__bool_options[i].value;
}

int
program_parse_options(int args_count, char* args[])
{
	for (int i = 0; i < args_count; i++) {
		bool exists = false;

		for (int j = 0; j < program__string_options_count; j++) {
			if (!strcmp(args[i], program__string_options[j].name) || (program__string_options[j].name_alt != NULL && !strcmp(args[i], program__string_options[j].name_alt))) {
				if ((i + 1) >= args_count) {
					return 1;
				}

				program__string_options[j].set = true;
				program__string_options[j].value = args[i + 1];
				i++;
				exists = true;
			}
		}

		if (!exists) {
			return 2;
		}
	}

	return 0;
}
