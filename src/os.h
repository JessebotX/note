#ifndef OS_H
#define OS_H

#include "base.h"
#include "error.h"
#include "string.h"

typedef struct OS_File_Result {
	FILE* result;
	Error error;
} OS_File_Result;

OS_File_Result
os_file_open(String path, String mode);

Error
os_file_close(FILE* f);

Error
os_dir_new(String path, int permissions);

#endif // OS_H
