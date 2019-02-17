//Aryeh Kempler-DeLugach
//Digraphs HW3
#include "digraphs.h"

//prototypes of functions for this file
int count_digraphs(char *, struct digraphs *);
int check_input(char *);
//end of prototype section

//Function declarations 
extern struct digraphs *
digraphs_text(char *filename, struct digraphs * result) {
    char letters[2];
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
    result -> counts[letters[0] - 'a'][letters[1] - 'a']++;    
    return 0; 
}
