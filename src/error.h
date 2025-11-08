#ifndef ERROR_H
#define ERROR_H

typedef enum Error {
	OK = 0,
	ALLOC_FAIL,
	FILE_STREAM_OPEN_FAIL,
	FILE_STREAM_CLOSE_FAIL,
	DIR_NEW_FAIL,
} Error;

#endif // ERROR_H
