#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef struct Program_StringOption {
	bool set;
	char* value;
	char* value_default;
	size_t names_count;
	const char* names[];
} Program_StringOption;

typedef struct Program_IntOption {
	bool set;
	int value;
	int value_default;
	size_t names_count;
	const char* names[];
} Program_IntOption;

typedef struct Program_FloatOption {
	bool set;
	double value;
	double value_default;
	size_t names_count;
	const char* names[];
} Program_FloatOption;

void
program_cli_parse(void);
