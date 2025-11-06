#pragma once

#include "base.h"
#include "error.h"

typedef struct String {
	size_t count_bytes;
	size_t capacity;
	char* text;
} String;

typedef struct StringResult {
	String result;
	Error error;
} String_Result;

String_Result
string_new(const char* c_str);

String_Result
string_new_with_count_bytes(size_t c_str_count_bytes, const char* c_str);

void
string_free(String* s);
