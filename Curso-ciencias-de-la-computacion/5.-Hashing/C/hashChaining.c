//Hash tables in C. Collisions solved with chaining
//by JCPC -> Based on JacobSorber code

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

//Defining constants
#define MAX_NAME 256
#define TABLE_SIZE 10

//Struct person
typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person* next;
} person;

person* hash_table[TABLE_SIZE];

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
}

unsigned int hash(char* name){
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value = hash_value * name[i] % TABLE_SIZE;
    }
    return hash_value;
}

void print_table(){
    printf("START\n");
    for (int i = 0; i < TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        }else{
            person* tmp = hash_table[i];
            printf("\t%i\t", i);
            while(tmp != NULL){
                printf("%s -> ", tmp->name);  
                tmp = tmp->next;
            }  
            printf("\n");        
        }
    }
    printf("END\n");
}

bool hash_table_insert(person* p){
    if (p == NULL) return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
}

person* hash_table_lookup(char* name){
    int index = hash(name);
    person* tmp = hash_table[index];
    if(tmp != NULL && strncmp(name, tmp->name, MAX_NAME)){	//strncmp returns 0 in case name == tmp->name in the first MAX_NAME characters
        tmp = tmp->next;
    }
    return tmp;
}

person* hash_table_delete(char* name){
    int index = hash(name);

    person* prev = NULL;
    person* tmp = hash_table[index];
    if(tmp != NULL && strncmp(name, tmp->name, MAX_NAME)){
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL){
        hash_table[index] = tmp->next;
    }else{
        prev->next = tmp->next;
    }
    return tmp;
}

//main
int main(){

    init_hash_table();
    print_table();

    person jacob = {.name = "Jacob", .age = 25};
    person kate = {.name = "Kate", .age = 27};
    person mpho = {.name = "Mpho", .age = 14};
    person sarah = {.name = "Sarah", .age = 54};
    person edna = {.name = "Edna", .age = 15};
    person maren = {.name = "Maren", .age = 25};
    person eliza = {.name = "Eliza", .age = 34};
    person robert = {.name = "Robert", .age = 1};
    person jane = {.name = "Jane", .age = 75};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane);

    print_table();

    person* tmp = hash_table_lookup("Jacob");

    if (tmp == NULL){
        printf("Not found\n");
    } else {
        printf("Found: %s\n", tmp->name);
    }

    tmp = hash_table_delete("Jacob");

    print_table();
}