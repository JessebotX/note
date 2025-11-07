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

PRIVATE uint8_t program__string_options_count = 0;
PRIVATE Program_StringOption program__string_options[PROGRAM__MAX_ARGS];

PRIVATE uint8_t program__int_options_count = 0;
PRIVATE Program_IntOption program__int_options[PROGRAM__MAX_ARGS];

PRIVATE uint8_t program__float_options_count = 0;
PRIVATE Program_FloatOption program__float_options[PROGRAM__MAX_ARGS];

PRIVATE uint8_t program__bool_options_count = 0;
PRIVATE Program_BoolOption program__bool_options[PROGRAM__MAX_ARGS];

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
