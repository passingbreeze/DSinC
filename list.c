
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
} list;

bool isempty(list**);
void insert(list**, int, int);
list* find(list**, int);
void erase(list**, int);
void showlist(list**);
void clear(list**);
int size(list**);
int at(list**, int);

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
            printf("\nProgram will be terminated...\n");
            clear(&root);
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
                printf("what number do you wanna delete? >> ");
                scanf("%d", &value);
                erase(&root, value);
            case PRINT:
                printf("%d elements are in list.\n In list -> ", size(&root));
                showlist(&root);
                printf("\n");
            default:
                printf("\nPlease input the number between 1 and 6\n");
                break;
        }
    }
    clear(&root);
    return EXIT_SUCCESS;
}

int size(list** root)
{
    int count=1;
    if((*root)==nullptr)
        return 0;
    else {
        while((*root)->next != nullptr){
            (*root) = (*root)->next;
            count++;
        }
    }
    return count;
}

bool isempty(list **root)
{
    return size(root)==0;
}

void clear(list **root)
{
    list *temp;
    while((*root)!=nullptr){
        temp = (*root);
        (*root) = (*root)->next;
        free(temp);
    }
    *root = nullptr;
}


int at(list** root, int i)
{
    int count=0;
    if(isempty(root) || i > size(root)){
        fputs("out of range", stderr);
        exit(1);
    }
    else {
        while(count < i){
            (*root) = (*root) -> next;
            count++;
        }
        return (*root)->data;
    }
}

list* find(list **root, int v)
{
    if(isempty(root)){
        return nullptr;
    }
    else {
        list *temp = (*root);
        while(temp->data != v){
            temp = temp->next;
        }
        return temp;
    }
}

void insert(list **root, int kth, int v)
{
    if(isempty(root)){
        (*root) = (list*)malloc(sizeof(list));
        (*root)->data = v;
        (*root)->prev = nullptr;
        (*root)->next = nullptr;
    }
    else {
        list* new = (list*)malloc(sizeof(list));
        list* temp = (*root);
        new->data = v;
        if(kth >= size(root)){
            while(temp->next != nullptr)
                temp = temp->next;
            temp->next = new;
            new->prev = temp;
            new->next = (*root);
        }
        else {
            new->next = (*root)->next;
            (*root)->next->prev = new;
            new->prev = *root;
            (*root)->next = new;
        }
    }

}

void erase(list **root, int v)
{
    if(isempty(root)){
        printf("list is empty.");
        return;
    }
    else {
        list *temp = find(root,v);

    }
}