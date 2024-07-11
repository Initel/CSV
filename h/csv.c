#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processCsvFile.h"

CSV* csv_read(const char *csvFilePath){
    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROWS * sizeof(char*));
    csv->num_rows = 0;
    csv->num_cols = 0;

    //Abrindo o CSV
    FILE *file = fopen(csvFilePath, "r");
    if (!file){
        printf("Erro ao abrir");
        free(csv->data);
        free(csv);
        return NULL;
    }
    
    char line[1024];
    while (fgets(line, 1024, file)){
        line[strcspn(line, "\n")] = 0;

        //Conta o número de colunas
        int cols = 0;
        char * token = strtok(line, ",");
        while (token){
            cols++;
            token = strtok(NULL, ",");
        }

        //Alocando Memoria para a linha
        csv->data[csv->num_rows] = malloc(cols * sizeof(char*));
        token = strtok(line, ",");
        for (int i = 0; i < cols; i++){
            csv->data[csv->num_rows][i] = malloc(strlen(token) + 1);
            strcpy(csv->data[csv->num_rows][i], token);
            token = strtok(NULL, ",");
        }

        csv->num_rows++;
        if(csv->num_cols < cols){
            csv->num_cols = cols;
        }

        if (csv->num_rows >= MAX_ROWS){
            break;
        }    
    }
    fclose(file);
    return csv;
}

void csv_free(CSV *csv){
    for (int i = 0; i < csv->num_rows; i++){
        for (int j = 0; j < csv->num_cols; j++){
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}


void csv_print(CSV *csv){
    for (int i = 0; i < csv->num_rows; i++){
        for (int j = 0; j < csv->num_cols; j++){
            printf("%s", csv->data[i][j]);
            if (j < csv->num_cols - 1){
                printf(",");
            } 
        }        
    }    
}

/*processCsvFile
    csvFilePath
    selectedColumns
    rowFilterDefinitions
    
  
  processCsv
    csv
    selectedColumns
    rowFilterDefinitions
*/