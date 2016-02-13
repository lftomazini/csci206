#ifndef __fileio_h_
#define __fileio_h_

#define MAXBYTES 1024
#define MAXLINES 10
#define MAXROWS 1024
#define MAXCOLS 32
#define MAXLEN 64

int read_file_bytes (char* filename, int bytes, char* buffer);
int read_file_lines (char* filename, char buffer[MAXLINES][MAXBYTES+1]);
int read_csv_row    (FILE* fd, char row_strings[MAXCOLS][MAXLEN]);
int read_csv_cols   (FILE* fd, float data[MAXROWS][MAXCOLS]);
 
#endif
