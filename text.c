//Aryeh Kempler-DeLugach
//Digraphs HW3
#include "digraphs.h"

//prototypes of functions for this file
int count_digraphs(char *, struct digraphs *);
//end of prototype section

//Function declarations 
extern struct digraphs *
digraphs_text(char *filename) {
    char letters[2];
    struct digraphs digraph_chart;
    struct digraphs * result = &digraph_chart;
    FILE * file = fopen(filename, "r");
    if(file == NULL) {
        perror("file open error");
        return NULL;
    }
    if(!feof(file)) {
        letters[1] = fgetc(file);
    }
    while(!feof(file)) {
        letters[0] = letters[1];  
        letters[1] = fgetc(file);
        int change = check_input(letters);
        if(change == 1)
            continue;
        if(change == 2) {
            letters[1] = letters[0];
            continue;
        }
        count_digraphs(letters, result);
    }
    fclose(file);
    return NULL; //make this a struct
}    

int count_digraphs
(char * letters, struct digraphs * result) {
    
    return 0; 
}
