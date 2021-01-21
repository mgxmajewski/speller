// Implements a dictionary's functionality

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number https://gist.github.com/MohamedTaha98/ccdf734f13299efb73ff0b12f7ce429f
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
        int c;
        while ((c = *word++))
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (dictionary == NULL)
    {
        return false;
    }
    else
    {
        char loaded_word[LENGTH + 1];
        // Read strings from file one at the time
        while (fscanf(file, "%s", loaded_word) != EOF)
        {
            // Create a new node for each word
            node *n = malloc(sizeof(node));
            if (n == NULL)
            {
                return false;
            }
            // else
            // {
                // Hash word to obtain a hash value
                int bucket = hash(loaded_word);
                //if (table[bucket] != NULL)
                //{
                    strcpy(n->word, loaded_word);// Insert node into hash table at that location
                    n->next = table[bucket];
                   
                    table[bucket] = n;
                // }
                // else
                // {
                //     //Add node as first/last node
                //     table[bucket] = n;
                //     strcpy(n->word, loaded_word);
                //     n->next = NULL; // here need to point to first node in bucket
                // }
            // }
        }
        fclose(file);
        return true;
    }
    
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
