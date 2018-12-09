
// You can make header file from this line.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define nullptr ((void*)0)

enum {INSERT = 1, FIND, DEL, PRINT, STOP, QUIT};

typedef struct list {
    int data;
    struct list *prev;
    struct list *next;
    bool ishead, istail;
} list;

bool isempty(list**);
void insert(list**, int, int);
list* find(list**, int);
void erase(list**, int);
void showlist(list**);
void clear(list**);
int size(list**);
list* at(list**, int);

// to this line.

int main(int argc, char *argv[])
{
    list *root = nullptr;

    int select=0, kth=0, value=0;
    while(true){
        printf("\nLet's make List!\n");
        printf("1. INSERT | 2. FIND SOMETHING | 3. DELETE SOMETHING | 4. SHOW LIST | 5. STOP MANIPULATE LIST | 6. QUIT PROGRAM\n >> ");
        scanf("%d", &select);
        if(select == STOP)
            break;
        if(select == QUIT) {
            printf("\nProgram will be terminated...\n");
            clear(&root);
            exit(EXIT_SUCCESS);
        }
        switch(select){
            case INSERT:
                printf("Enter input data and \'k\'th where you wanna input from head >>  ");
                scanf("%d%d", &kth, &value);
                insert(&root, kth, value);
                break;
            case FIND:
                printf("what number do you wanna find? >> ");
                scanf("%d", &value);
                if(find(&root, value))
                    printf("%d is in list!\n", find(&root,value)->data);
                else
                    printf("Not found...\n");
                break;
            case DEL:
                printf("what number do you wanna delete? >> ");
                scanf("%d", &value);
                erase(&root, value);
                break;
            case PRINT:
                if(!size(&root))
                    printf("No Elements in list!\n");
                else {
                    printf("%d elements are in list.\n In list : ", size(&root));
                    showlist(&root);
                    printf("\n");
                }
                break;
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
    list *temp = (*root);
    if(temp == nullptr)
        return 0;
    else if(temp->next == temp)
        return 1;
    else {
        while(!temp->next->istail){
            temp = temp->next;
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
    while(!(*root)->istail){
        temp = (*root);
        (*root) = (*root)->next;
        free(temp);
    }
    free(*root);
}


list* at(list** root, int i)
{
    int count=0;
    if(isempty(root) || i > size(root)){
        fputs("out of range", stderr);
        exit(EXIT_FAILURE);
    }
    else {
        while(count < i){
            (*root) = (*root) -> next;
            count++;
        }
        return *root;
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
    list* new = (list*)malloc(sizeof(list));
    list* temp = *root;
    if(isempty(root)){
        printf("list begin!\n");
        (*root) = (list*)malloc(sizeof(list));
        (*root)->data = v;
        (*root)->prev = (*root)->next = *root;
        (*root)->ishead = true;
        (*root)->istail = false;
    }
    else {
        new->data = v;
        new->ishead = false;
        new->istail = true;
        if(size(root)==1){
            (*root)->prev = (*root)->next = new;
            new->prev = new->next = *root;
        }
        else if(kth < size(root)){
            temp = at(root, kth);
            new->istail = false;
            temp->next = new;
            new->prev = temp;
            new->next = temp->next;
            temp->next->prev = new;
        }
        else {
            while(!temp->istail)
                temp = temp->next;
            temp->next = new;
            new->prev = temp;
            new->next = (*root);
            (*root)->prev = new;
        }
    }
    printf("%d elements in list\n", size(root));
}

void erase(list **root, int v)
{
    if(isempty(root)){
        printf("list is empty.");
        return;
    }
    else {
        list *temp = find(root,v);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    }
}

void showlist(list** root)
{
    while(!(*root)->istail){
        printf("%d -> ", (*root)->data);
        (*root) = (*root)->next;
    }
    printf("end\n");
}