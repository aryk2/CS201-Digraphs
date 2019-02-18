//Aryeh Kempler-DeLugach
//CS201 Digraphs Frequencies


#ifndef _DIGRAPH_H
#define _DIGRAPH_H
#define _DEFAULT_SOURCE

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/* Digraph count information. */
struct digraphs {
    /* Number of alphabetic characters examined. */
    uint64_t nchars;
    int unique_count;
    /*
     * Digraph frequencies. The left (row) index
     * is the first character in the digraph; the right (column)
     * index is the second character. Indices 0..25 are the lowercase
     * characters in order; 26..51 are the uppercase characters.
     *
     * When you see a valid digraph, subtract 'a' or 'A' from each
     * of the characters as appropriate to get an index in the range
     * 0..51 for each position. Then increment the count at
     * the given position in the counts table.
     *
     * Example: You see "ea". 'e' - 'a' = 4. 'a' - 'a' = 0. So
     * do counts[4][0]++
     */
    uint64_t counts[52][52];
};

struct node {
    char digraph[2];
    uint64_t count;
};

//function protoypes for digraphs.c
int compare(const void * p1, const void * p2);
int create_array(struct digraphs *, struct node *);
int sort_array(struct node *, struct node *, int);
int check_input(char *);
int get_index(char);
/* text.c */

/*
 * Return a malloc-ed struct of counts
 * for the text in the file with the given name.
 * Return a null pointer on error.
 */
extern struct digraphs *
digraphs_text(char *filename, struct digraphs *);

/* fs.c */

/*
 * Return a malloc-ed struct of counts for the file and
 * directory names starting at the given path. Return a null
 * pointer on error.
 */
extern struct digraphs *
digraphs_fs(char *path);


//prototypes
#endif
