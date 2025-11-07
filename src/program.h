#ifndef NOTE_PROGRAM_H
#define NOTE_PROGRAM_H

#include "base.h"

typedef struct Program_StringOption {
	char* value;
	char* value_default;
	bool  set;
	char* name;
	char* name_alt;
} Program_StringOption;

typedef struct Program_IntOption {
	long long value;
	long long value_default;
	bool      set;
	char*     name;
	char*     name_alt;
} Program_IntOption;

typedef struct Program_FloatOption {
	double value;
	double value_default;
	bool   set;
	char*  name;
	char*  name_alt;
} Program_FloatOption;

typedef struct Program_BoolOption {
	bool  value;
	bool  value_default;
	bool  set;
	char* name_true;
	char* name_true_alt;
	char* name_false;
	char* name_false_alt;
} Program_BoolOption;

#define PROGRAM__MAX_ARGS 64

Program_StringOption*
program_add_string_option(char* name, char* name_alt, char* value_default);

Program_IntOption*
program_add_int_option(char* name, char* name_alt, int value_default);

Program_FloatOption*
program_add_float_option(char* name, char* name_alt, double value_default);

Program_BoolOption*
program_add_bool_option(char* name_true, char* name_true_alt, char* name_false, char* name_false_alt, bool value_default);

int
program_parse_options(int args_count, char* args[]);

#endif // NOTE_PROGRAM_H
