// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "dictionary.h"
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Creating head of table and a new node
node *n = NULL;
bool load_work = false;

// Counter of numbers
unsigned int num_counter;

// Number of buckets in hash table
const unsigned int N = 60;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int aux = hash(word);
    node *cursor = table[aux];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Hashes word to a number
    // Source: SocratesSatisfied (https://www.reddit.com/r/cs50/
    // comments/eo4zro/good_hash_function_for_speller/)

    unsigned long hash = 5381;
    int c = *word;
    c = tolower(c);

    while (*word != 0)
    {
        hash = ((hash << 5) + hash) + c;
        c = *word++;
        c = tolower(c);
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Open Dictionary File
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Initializing the table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Create word char
    char word[LENGTH + 1];

    // Initalizing counter number of words
    num_counter = 0;

    while (fscanf(file, "%s", word) != EOF)
    {
        // Counter o number of words
        num_counter = num_counter + 1;

        //Create a New Node
        n = malloc(sizeof(node));

        strcpy(n->word, word);
        n->next = NULL;

        //Hash Word
        int index = hash(word);

        // Insert the new node infront the list
        n->next = table[index];
        table[index] = n;
    }

    fclose(file);
    load_work = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (load_work == true)
    {
        return num_counter;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (load_work == false)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *cursor = table[i];
            do
            {
                node *tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
            while (cursor != NULL);
        }
    }
    return true;
}
