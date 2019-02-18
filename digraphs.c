//Aryeh Kempler-DeLugach
//CS201 Digraphs Frequencies
#include "digraphs.h"

int main(int argc, char *argv[]) {
    char * test = argv[2];
    char * key = argv[1];
    struct digraphs digraph_chart;
    for(int i = 0; i < 51; ++i) {
        for(int k = 0; k < 51; ++k) {
            digraph_chart.counts[i][k] = 0;
        }
    }
    struct digraphs * result = &digraph_chart;
    if(key[1] == 't')
        digraphs_text(test, result);
    else if(key[1] == 'p')
        printf("not done yet\n"); 
//    struct node digraph_array[result ->unique_count]; 
    struct node * digraph_array = 
    (struct node *) malloc(result->unique_count * sizeof(struct node));
    assert(digraph_array);
    for(int i = 0; i < result->unique_count; ++i) {
        digraph_array[i].digraph[0] = 0;
        digraph_array[i].digraph[1] = 0;
        digraph_array[i].count = 0;
    }
    create_array(result, digraph_array);
    /*struct node * sorted_array =
    (struct node *) malloc(10 * sizeof(struct node));
    assert(sorted_array);
    sort_array(digraph_array, sorted_array, result->unique_count -1); */
    //display results
    printf("\nalphabetic characters: %ld\n", result -> nchars);
    printf("top digraphs:\n");
    for(int i = 0; i < 10; ++i) {
        printf("%c%c %ld\n",
        //change digraph to sorted if qsort failes
        digraph_array[i].digraph[0], digraph_array[i].digraph[1],
        digraph_array[i].count);
    } 
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


int compare(const void * p1, const void * p2) {
    const struct node * elem1 = (struct node *) p1;
    const struct node * elem2 = (struct node *) p2;
    
    if(elem1->count > elem2->count)
        return -1;
    else if(elem1->count < elem2->count)
        return 1;
    else
        return 0;

} 
int create_array(struct digraphs * result, 
struct node * digraph_array) {
    for(int i = 0; i < 51; ++i) {
        for(int k = 0; k < 51; ++k) {
            if(result->counts[i][k] > 0) {
                int x = 0;
                //loop goes to next empty index of struct array
                while(digraph_array[x].count != 0) 
                    ++x;
                if(i < 26) 
                    digraph_array[x].digraph[0] = i + 'a';
                else
                    digraph_array[x].digraph[0] = i + 'A' - 26;
                if(k < 26) 
                    digraph_array[x].digraph[1] = k + 'a';
                else
                    digraph_array[x].digraph[1] = k + 'A' - 26;
                digraph_array[x].count = result->counts[i][k];
            }
        }
    }  

    int array_size = result -> unique_count;
    printf("%d\n", array_size);


    qsort(digraph_array, 
    array_size, 
    sizeof(struct node),
    compare);   


    return 0; 
}
/*
int sort_array(struct node * digraph_array, 
struct node * sorted_array, int size) {
    int max = 0;
    int remaining = 0;
    for(int i = 0; i < size; ++i) {
        if(digraph_array[i].count > max)
            max = digraph_array[i].count;
    }
    for(int i = 0; i < 10; ++i) {   
        printf("%d\n", max);
        for(int k = 0; k < size; ++k) {
            if(digraph_array[k].count == max)
                ++remaining;
        }
        for(int x = remaining; x > 0; --x) {
            //printf("%d\n", remaining);
            for(int k = 0; k < size; ++k) {
                if(digraph_array[k].count >= max) {
                    sorted_array[i].count = digraph_array[k].count;
                    sorted_array[i].digraph[0]= 
                    digraph_array[k].digraph[0];
                    sorted_array[i].digraph[1]= 
                    digraph_array[k].digraph[1];
                    digraph_array[k].count = 0;
                    break;
                 }
            }
        }
        --max;
    }
    return 0;
}
*/

 //qsort was not working
//compare function for qsort, with help from
//stack overflow question about sorting with qsort
