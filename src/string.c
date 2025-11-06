#include "string.h"

String_Result
string_new(const char* c_str)
{
	assert(c_str != NULL);

	return string_new_with_count_bytes(strlen(c_str), c_str);
}

String_Result
string_new_with_count_bytes(size_t c_str_count_bytes, const char* c_str)
{
	assert(c_str != NULL);

	String s = (String){
		.count_bytes = c_str_count_bytes,
		.capacity = (s.count_bytes + 1) * 2,
		.text = malloc(sizeof(*s.text) * s.capacity),
	};
	if (s.text == NULL) {
		return (String_Result){ .error = ALLOC_FAIL };
	}

	for (size_t i = 0; i < s.count_bytes; i++) {
		s.text[i] = c_str[i];
	}
	s.text[s.count_bytes] = '\0';

	return (String_Result){ .result = s };
}

void
string_free(String* s)
{
	assert(s != NULL);

	free(s->text);
	s->text = NULL;
	s->count_bytes = 0;
	s->capacity = 0;
}
