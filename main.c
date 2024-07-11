#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h/csv.c"

int main(){
    CSV* csv = csv_read("/dataCsv/data.csv");
    if (csv){
        csv_print(csv);
        csv_free(csv);
    }
    return 0;
}