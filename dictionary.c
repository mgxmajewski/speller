// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

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
    FILE *file = fopen(*dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    else
    {
        char *tmp;
        // Read strings from file one at the time
        while (fscanf(file, "s%", tmp) != EOF)
        {
            // Create a new node for each word
            node *n = malloc(sizeof(node));
            if (node == NULL)
            {
                return false;
            }
            else
            {
                // Hash word to obtain a hash value
                int bucket = hash(*tmp);
                if (table[bucket] != NULL)
                {
                    // Insert node into hash table at that location
                }
                else
                {
                    //Add node as last node
                    strcpy(n->word, tmp);
                    n->next = NULL; // here need to point to first node in bucket
                }
            }
           
        }
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
