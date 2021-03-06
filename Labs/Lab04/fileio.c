/* Luis Felipe Tomazini
 * T 1pm
 * lab 04 - fileio.c
 * compile with: make
 * notes: Reads file bytes
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileio.h"

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
int read_file_lines (char* filename, char buffer[MAXLINES][MAXBYTES+1]) {
    // open file
    FILE *file;
    file = fopen(filename, "r");
    
    //fseek( file, 0, SEEK_SET );
    
    //repeat for lines
    int i = 0;
    for (i = 0; i < MAXLINES; i++){
        // read up to bytes
        fgets (buffer[i], MAXBYTES, file);
    }
    
    //close file
    fclose(file);
    
    // return number of lines read
    return (i >= 0) ? i : -1;
}

int read_csv_row(FILE* fd, char row_strings[MAXCOLS][MAXLEN]) {
    char line[MAXLEN];
    if ((fgets(line, MAXLEN, fd)) != NULL) {
        // strip trailing newline from line
        line[strlen(line)-1] = '\0';
        
        char* data;

        // tokenize line upto MAXCOLS
        data = strtok(line,",");

        // remove " "
        while (data[0] == ' ') {
            data++;
        }

        // store in original
        strcpy(row_strings[0], data);
        
        int i = 0;
        while(((data = strtok(NULL, ",")) != NULL) && (i < MAXCOLS)) {
            // remove " "
            while (data[0] == ' ') {
                    data++;
            }
            // store in original
            strcpy(row_strings[++i], data);
        }
    
        // return number of tokens [0...MAXCOLS] read, -1 if fgets failed (EOF).
        return (i > 0) ? i : -1;
	}
}

int read_csv_cols (FILE* fd, float data[MAXROWS][MAXCOLS]) {
    char tmp_row[MAXCOLS][MAXLEN];
    int row = 0;
    do {
        int n = read_csv_row (fd, tmp_row); // returns number of cols
        if (n == -1) {
            break;
        } else {
            //iterate over columns in tmp_row
            int col = 0;
            for (col = 0; col < MAXCOLS; col++){
                data[row][col] = atof(tmp_row[col]);
            }
        }
    } while(1);
    return row; // number of rows read.
}































