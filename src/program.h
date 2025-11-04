#pragma once

#include "base.h"

typedef struct Program_StringOption {
	char* value;
	char* value_default;
	bool  set;
	char* name;
	char* name_alt;
} Program_StringOption;

typedef struct Program_IntOption {
	int   value;
	int   value_default;
	bool  set;
	char* name;
	char* name_alt;
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
	char* name;
	char* name_alt;
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

int
program_parse_options(int args_count, char* args[]);
