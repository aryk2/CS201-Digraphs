//Aryeh Kempler-DeLugach
//Digraphs HW3
#include "digraphs.h"

//prototypes of functions for this file
int count_digraphs_x(char *, struct digraphs *);
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
    int xcount = 0;
    if(!feof(file)) {
        letters[1] = fgetc(file);
        ++xcount;
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
        ++xcount;
        result->unique_count += count_digraphs_x(letters, result);
    }
    result -> nchars = xcount;
    fclose(file);
    return result; //make this a struct
}    

//gets passed the struct and an array of the 2 letters that
//will make up the digraph, add the digraph to the count in 
//the struct and return 1 if this is the first time this
//digraph has appeard in this text entry
int count_digraphs_x
(char * letters, struct digraphs * result) {
    int index1 = get_index(letters[0]);
    int index2 = get_index(letters[1]);
    result -> counts[index1][index2]++;    
    if(result->counts[index1][index2] == 1)
        return 1;
    return 0; 
}

int get_index(char letter) {
    if(letter == 'a')
        return 0;
    if(letter == 'A')
        return 26;
    if(letter > 97)
        return letter - 'a';
    else 
        return (letter - 'A') + 26;
}

