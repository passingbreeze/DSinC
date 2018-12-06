
// You can make header file from this line.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nullptr ((void*)0)

enum {INSERT = 1, FIND, DEL, PRINT, STOP, QUIT};

typedef struct list {
    int data;
    struct list *prev;
    struct list *next;
    bool ishead;
} list;

void insert(list**, int, int);
list* find(list**, int);
void erase(list**, int);
void showlist(list**);


// to this line.

int main(int argc, char *argv[])
{
    list *root = nullptr;

    int select=0, kth=0, value=0;
    while(true){
        printf("\nLet's make List!\n");
        printf("1. INSERT | 2. FIND SOMETHING | 3. DELETE SOMETHING | 4. SHOW LIST | 5. STOP MANIPULATE LIST | 6. QUIT PROGRAM\n");
        scanf("%d", &select);
        if(select == STOP)
            break;
        if(select == QUIT) {
            exit(0);
        }
        switch(select){
            case INSERT:
                printf("Enter input data and \'k\'th where you wanna input from head >>  ");
                scanf("%d%d", &value, &kth);
                insert(&root, kth, value);
            case FIND:
                printf("what number do you wanna find? >> ");
                scanf("%d", &value);
                if(find(&root, value))
                    printf("%d is in list!\n", find(&root,value)->data);
                else
                    printf("Not found...\n");
            case DEL:

            case PRINT:
            default:
                printf("\nPlease input the number between 1 and 6\n");
                break;
        }
    }
    return EXIT_SUCCESS;
}