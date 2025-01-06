#include "FileAccess.h"

#include <stdio.h>
#include <stdlib.h>


const char * FA_AccessMode_ToString( const FA_AccessMode mode )
{
	switch (mode)
	{
		case FA_AM_READ:
			return "rb";
		case FA_AM_WRITE:
			return "wb";
		case FA_AM_RW:
			return "rb+";
		case FA_AM_WR:
			return "wb+";
	}
	return "";
}


void FileAccess_Close( FA_FileAccess * file )
{
	if (file == NULL)
	{
		return;
	}

	if (file->_handle == NULL)
	{
		return;
	}

	fclose( file->_handle );
	free( file );
}

void FA_FileAccess_Seek( const FA_FileAccess * this,
                         const FA_NUMBER position )
{
	fseek( this->_handle, position, SEEK_SET );
}

void FA_FileAccess_SeekEnd( const FA_FileAccess * this, FA_NUMBER position )
{
	fseek( this->_handle, position, SEEK_END );
}

FA_NUMBER FA_FileAccess_Position( const FA_FileAccess * this )
{
	return ftell( this->_handle );
}

void * FA_FileAccess_Read( const FA_FileAccess * this, FA_NUMBER size )
{
	void * buffer = malloc( size );

#ifndef _WIN32
	fread( buffer, size, 1, this->_handle );
#else
	fread_s( buffer, size, size, 1, this->_handle );
#endif

	return buffer;
}

char FA_FileAccess_ReadByte( const FA_FileAccess * this )
{
	void * buffer = FA_FileAccess_Read( this, sizeof( char ) );
	const char value = *( char * )buffer;
	free( buffer );
	return value;
}

short FA_FileAccess_ReadShort( const FA_FileAccess * this )
{
	void * buffer = FA_FileAccess_Read( this, sizeof( short ) );
	const short value = *( short * )buffer;
	free( buffer );
	return value;
}


int FA_FileAccess_ReadInt( const FA_FileAccess * this )
{
	void * buffer = FA_FileAccess_Read( this, sizeof( int ) );
	const int value = *( short * )buffer;
	free( buffer );
	return value;
}

long FA_FileAccess_ReadLong( const FA_FileAccess * this )
{
	void * buffer = FA_FileAccess_Read( this, sizeof( long ) );
	const long value = *( short * )buffer;
	free( buffer );
	return value;
}

char * FA_FileAccess_ReadAsString( const FA_FileAccess * this )
{
	return FA_FileAccess_Read( this, this->size );
}

FA_FileAccess * FA_FileAccess_open( const char * path,
                                    FA_AccessMode mode )
{
	FA_FileAccess * file = calloc( 1, sizeof( FA_FileAccess ) );
	if (file == NULL)
		return NULL;

#ifndef _WIN32
	this->_handle = fopen( path, FA_AccessMode_ToString( mode ) );
#else
	fopen_s( &file->_handle, path, FA_AccessMode_ToString( mode ) );
#endif

	if (file->_handle == NULL)
		return FA_FAILURE;

	fseek( file->_handle, 0L, SEEK_END );
	FA_NUMBER * _ = ( FA_NUMBER * )&file->size;
	*_ = ftell( file->_handle );
	rewind( file->_handle );

	file->close = &FileAccess_Close;
	file->seek = &FA_FileAccess_Seek;
	file->seek_end = &FA_FileAccess_SeekEnd;
	file->position = &FA_FileAccess_Position;
	file->get_buffer = &FA_FileAccess_Read;
	file->get_byte = &FA_FileAccess_ReadByte;
	file->get_short = &FA_FileAccess_ReadShort;
	file->get_int = &FA_FileAccess_ReadInt;
	file->get_long = &FA_FileAccess_ReadLong;

	return file;
}

