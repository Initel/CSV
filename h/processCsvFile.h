//processCsvFile.h
#ifndef processCsvFile_H
#define processCsvFile_H

#include <stdio.h>

#define MAX_ROWS 256
#define MAX_COLS 256

typedef struct {
  char **data;
  int num_rows, num_cols;
} CSV;

CSV* csv_read(const char *csvFilePath); //Leitura do CSV
void csv_free(CSV *csv); //Liberar memoria
void csv_selectedColumns(CSV *csv, const char *selectedColumns);
void csv_rowFilter(CSV *csv, const char *rowFilterDefinitions); 
void csv_print(CSV *csv);


#endif
/*processCsvFile
    csvFilePath
    selectedColumns
    rowFilterDefinitions
    
  
  processCsv
    csv
    selectedColumns
    rowFilterDefinitions
*/