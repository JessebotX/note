#include "string.h"

String_Result
string_new(const char* cstr)
{
	assert(cstr != NULL);

	return string_new_with_count_bytes(strlen(cstr), cstr);
}

String_Result
string_new_with_count_bytes(size_t cstr_count_bytes, const char* cstr)
{
	assert(cstr != NULL);

	String s = (String){
		.count_bytes = cstr_count_bytes,
		.capacity = (s.count_bytes + 1) * 2,
		.text = malloc(sizeof(*s.text) * s.capacity),
	};
	if (s.text == NULL) {
		return (String_Result){ .error = ALLOC_FAIL };
	}

	for (size_t i = 0; i < s.count_bytes; i++) {
		s.text[i] = cstr[i];
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

String_Result
string_append(String* a, String b)
{
	assert(a != NULL);

	size_t new_count_bytes = a->count_bytes + b.count_bytes;

	if (new_count_bytes >= a->capacity) {
		size_t new_capacity = sizeof(a->text) * ((new_count_bytes + 1) * 2);
		char* old_text = a->text;

		a->text = realloc(a->text, new_capacity);
		if (!a->text) {
			a->text = old_text;
			return (String_Result){ .error = ALLOC_FAIL };
		}

		a->capacity = new_capacity;
	}

	for (size_t i = 0; i < b.count_bytes; i++) {
		a->text[a->count_bytes + i] = b.text[i];
	}
	a->count_bytes = new_count_bytes;
	a->text[a->count_bytes] = '\0';

	return (String_Result){ .result = *a };
}

