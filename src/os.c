#include "os.h"

OS_File_Result
os_file_open(String path, String mode)
{
	FILE* f = fopen(path->text, mode->text);
	if (f == NULL) {
		return (OS_File_Result){ .error = FILE_STREAM_OPEN_FAIL };
	}

	return (OS_File_Result){ .result = f };
}

Error
os_file_close(FILE* stream)
{
	int err = fclose(stream);
	if (err) {
		return FILE_STREAM_CLOSE_FAIL;
	}

	return OK;
}

Error
os_dir_new(String path, int permissions)
{
	int err = mkdir(path->text, permissions);
	if (err) {
		return DIR_NEW_FAIL;
	}

	return OK;
}
