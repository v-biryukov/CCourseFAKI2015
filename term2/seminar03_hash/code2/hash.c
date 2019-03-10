#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define INITIAL_SIZE (1024)
#define GROWTH_FACTOR (2)
#define MAX_LOAD_FACTOR (1)


struct node 
{
    struct node* next;
    char* key;
    char* value;
};
typedef struct node Node;

struct hashtable 
{
    int size;           /* size of the pointer table */
    int n;              /* number of elements stored */
    struct node** table;
};
typedef struct hashtable Hashtable;



Hashtable* hashtable_create(int size)
{
    int i;
    Hashtable* ht = malloc(sizeof(Hashtable));

    ht->size = size;
    ht->n = 0;
    ht->table = malloc(sizeof(struct node *) * ht->size);

    for(i = 0; i < ht->size; i++) 
        ht->table[i] = 0;

    return ht;
}


void hashtable_destroy(Hashtable* ht)
{
    int i;
    struct node *e;
    struct node *next;

    for(i = 0; i < ht->size; i++) 
    {
        for(e = ht->table[i]; e != 0; e = next) 
        {
            next = e->next;

            free(e->key);
            free(e->value);
            free(e);
        }
    }

    free(ht->table);
    free(ht);
}

unsigned long hash_function(char *s)
{
    unsigned long h = 0;

    for(unsigned char* p = s; *p; p++)
        h = h * 97 + *p;

    return h;
}


/* insert a new key-value pair into an existing dictionary */
void hashtable_insert(Hashtable* ht, const char* key, const char* value)
{
    // Выделить память под node

    
    // Выделить память под pn->kkey и pn->kvalue и скопировать в них key и value


    // Найти позицию нового элемента в хеш-таблице


    // Добавить его в хеш-таблицу


    // Увеличить ht->n


    // (в следущей задаче) Если количество элементов в хеш-таблице слишком много (n > size * MAX_LOAD_FACTOR), 
    // то нужно увеличить таблицу в GROWTH_FACTOR раз

}



int main()
{
    Hashtable* p;

    p = hashtable_create(10);

    //hashtable_insert(p, "Dolgoprudny", "is a town in Moscow Oblast, Russia, located about 20 kilometers (12 mi) north of Moscow city center.");



    hashtable_destroy(p);

    return 0;
}