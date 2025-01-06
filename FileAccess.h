#ifndef FILEACCESS_H
#define FILEACCESS_H

#include <stdio.h>

#ifndef FA_NUMBER
#define FA_NUMBER long
#endif

typedef enum
{
	FA_FAILURE,
	FA_SUCCESS,
	FA_INVALID_HANDLE
} FA_Result;

typedef enum
{
	FA_AM_READ,
	FA_AM_WRITE,
	FA_AM_RW,
	FA_AM_WR,
} FA_AccessMode;

typedef struct File FA_FileAccess;

struct File
{
	/**
	 * The underlying file handle.
	 * @private
	 */
	FILE * _handle;

	/**
	 * The size of the file in bytes.
	 * @public
	 */
	const long size;

	void ( *close )( FA_FileAccess * this );

	void ( *seek )( const FA_FileAccess * this, FA_NUMBER position );

	void ( *seek_end )( const FA_FileAccess * this, FA_NUMBER position );

	FA_NUMBER ( *position )( const FA_FileAccess * this );

	void * ( *get_buffer )( const FA_FileAccess * this, FA_NUMBER size );

	char ( *get_byte )( const FA_FileAccess * this );

	short ( *get_short )( const FA_FileAccess * this );

	int ( *get_int )( const FA_FileAccess * this );

	long ( *get_long )( const FA_FileAccess * this );

	float ( *get_float )( const FA_FileAccess * this );

	double ( *get_double )( const FA_FileAccess * this );

};


extern FA_FileAccess * FA_FileAccess_open( const char * path,
                                           FA_AccessMode mode );
extern void FA_FileAccess_close( FA_FileAccess * file );

#endif //FILEACCESS_H
