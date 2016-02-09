/* Luis Felipe Tomazini
 * T 1pm
 * lab 04 - fileio.c
 * compile with: make head
 * notes: Reads file bytes
 */

#include <fcntl.h>
#include <unistd.h>

/*
 * Reads data from a file and append a null terminator.
 * 
 *  filename: full path and filename to read from.
 *  bytes: maximum number of bytes to read.
 *  buffer: where to put the read data (note need bytes+1!).
 *  Return value: number of bytes read or -1 on error.
*/
int read_file_bytes (char* filename, int bytes, char* buffer) {
	// open file
	int file = open(filename, O_RDONLY, S_IRUSR);	

	// read up to bytes
	ssize_t bytes_read = read(file, buffer, bytes);

	//adds null terminator
	buffer[bytes_read] = '\0';
	
	// close file
	close(file);

	// return number of bytes read
	return (bytes_read >= 0) ? bytes_read : -1;
}
