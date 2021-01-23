// Implements a dictionary's functionality

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 200000;

// Hash table
node *table[N];

// Counter of words
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_of_checked_word = hash(word);
    
    node *checked_bucket = table[hash_of_checked_word];
    
    while (checked_bucket != NULL)
    {
        if (strcasecmp(word, checked_bucket->word) == 0)
        {
            return true;
        }
        checked_bucket = checked_bucket->next;
    }
    return false;
}

// Hashes word to a number https://gist.github.com/MohamedTaha98/ccdf734f13299efb73ff0b12f7ce429f
//https://github.com/hathix/cs50-section/blob/master/code/7/sample-hash-functions/good-hash-function.c
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;

    for (const char *ptr = word; *ptr != '\0'; ptr++)
    {
        hash = ((hash << 5) + hash) + tolower(*ptr);
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    
    // Return false if there is no dictionary
    if (dictionary == NULL)
    {
        return false;
    }
    
    // If there is dictionary word is put into right 'bucket'
    else
    {
        // Delclare string size of word
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
            
            // Hash loaded word to get right bucket index
            int bucket = hash(loaded_word);

            // Copy loaded word (string) into 'word' of new node 
            strcpy(n->word, loaded_word);
            
            // Insert node into hash table at that location
            n->next = table[bucket];
           
            // Add new node to the right bucket
            table[bucket] = n; 
            
            // Increment word counter
            word_count++;
        }
        fclose(file);
        
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
    
        // Create pointers to all buckets
        node *free_bucket = table[i];
        
        // Loop throgh every elemnt in 'buckets' linked list
        while (free_bucket != NULL)
        {
            // Create temporary pointer to let free_bucket pointer be able to point to next node
            node *tmp = free_bucket;
            
            // Assign free_bucket to the next node
            free_bucket = free_bucket->next;
            free(tmp); 
        }
    
        // Condition to return true when all nodes are free
        if (i == N - 1)
        {
            return true;
        }
    
    }
    return false;
}
