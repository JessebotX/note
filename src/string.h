#ifndef NOTE_STRING_H
#define NOTE_STRING_H

#include "base.h"
#include "error.h"

typedef struct String {
	size_t count_bytes;
	size_t capacity_bytes;
	char* text;
} String;

typedef struct StringResult {
	String result;
	Error error;
} String_Result;

String_Result
string_new(const char* cstr);

String_Result
string_new_with_count_bytes(size_t cstr_count_bytes, const char* cstr);

void
string_free(String* s);

String_Result
string_append_string(String* a, String b);

String_Result
string_append_cstr(String* a, const char* b);

String_Result
string_append_cstr_with_count_bytes(String* a, size_t b_count_bytes, const char* b);

Error
string_reserve(String* s, size_t n);

#endif // NOTE_STRING_H
