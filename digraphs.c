//Aryeh Kempler-DeLugach
//CS201 Digraphs Frequencies
#include "digraphs.h"

int main(int argc, char *argv[]) {
    char * test = argv[2];
    char * key = argv[1];
    if(key[1] == 't')
        digraphs_text(test);
    else if(key[1] == 'p')
        printf("not done yet\n"); 
    return 1;
}

//general purpose function to check if 
//inputed letters are valid, used in both cases    
int check_input(char * letters) {
    char l1 = letters[0];
    char l2 = letters[1];
    if(l1 > 122) //ascii value above 'z'
        return 1;
    if(90 < l1 && l1 < 97) //ascii value between 'Z' and 'a'
        return 1;
    if(l1 < 65) //ascii value less than 'A'
        return 1;
   if(l2 > 122) //ascii value above 'z'
        return 2;
    if(90 < l2 && l2 < 97) //ascii value between 'Z' and 'a'
        return 2;
    if(l2 < 65) //ascii value less than 'A'
        return 2;
    return 0;
}   
