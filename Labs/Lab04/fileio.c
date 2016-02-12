/* Luis Felipe Tomazini
 * T 1pm
 * lab 04 - fileio.c
 * compile with: make head
 * notes: Reads file bytes
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

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

/*
 * Reads data from a file and append a null terminator.
 *
 *  filename: full path and filename to read from.
 *  lines: maximum number of lines to read.
 *  buffer: where to put the read data (note need bytes+1!).
 *  Return value: number of lines read or -1 on error.
 */
int read_file_lines (char* filename, int lines, int bytes, char* buffer) {
    // open file
    FILE *file;
    file = fopen(filename, "r");
    
    //repeat for lines
    int i = 0;
    for (i = 0; i < lines; i++){
        // read up to bytes
        fgets (buffer, bytes, file);
        
        // move to next line
        fseek (file, bytes, SEEK_CUR);
    }
    
    //close file
    fclose(file);
    
    // return number of lines read
    return (lines >= 0) ? lines : -1;
}

int read_csv_row (FILE* fd, char row_strings[][]) {
    int i = 0;
    
    if (row = fgets(row_strings[][i], MAXLEN, fd) != NULL) {
        data = strtok(row,",");
        while (data != NULL) {
            row_strings[i][j++] = atof(data);
            data = strtok(row, ",");
        }
    }
    
    int columns_read = j;

    
    return (columns_read >= 0) ? columns_read : -1;
}

int read_csv_cols (FILE* fd, float data[][]) {
    char tmp_row[MAXCOLS][MAXLEN];
    row = 0;
    do {
        int columns = read_csv_row (fd, tmp_row)
        if (columns == -1) {
            break;
        } else {
            
        }
    } while (row++);
}































