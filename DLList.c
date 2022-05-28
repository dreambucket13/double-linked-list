//Chris Carmine
//Double Linked list for CS503
//list always inserts nodes in ascending order

#include <stdio.h> 
#include <stdlib.h> 

//setting up basic structure of a node with a pointer to next and previous nodes
struct node
 {
  int info;
  struct node* next;
  struct node* prev;
 };

//declare head and tail pointers
struct node* head_p;
struct node* tail_p;

//insert a node in ascending order
 int insertNode(int v){

    struct node * newNode = malloc (sizeof (struct node) ) ; 

    //initialize newNode
    newNode->info = v;
    newNode->next = NULL;
    newNode->prev = NULL;


    //if head is null we know it is the first element
    if (head_p==NULL){
        head_p = newNode;
        tail_p = newNode;
        return(1);
    } 

    struct node * n = tail_p;
    //otherwise, need to find the spot to insert
    while (n!=NULL){
        if (v==n->info){
            //element already exists if passed value value equals current info
            free(newNode); //no need for this anymore
            return(0); 
        } else if (v>n->info){

            if (n==tail_p){
                tail_p = newNode;
                newNode->prev = n;
                n->next = newNode;  
                return(1);              
            } else {
                newNode->next = n->next;
                newNode->next->prev = newNode;
                newNode->prev = n;
                n->next = newNode;
                return(1);
            }
        } else if (n==head_p){
                head_p=newNode;
                newNode->next = n;
                n->prev = newNode;
                return(1);
        }

        n=n->prev; //iterate through list
    }
     return(-1);
}

//remove a node
int removeNode(int v){

struct node * n = tail_p;
    
    //iterate through list to find element
    while (n != NULL){

        if (n->info == v){

            if (n==tail_p && n==head_p){
                tail_p = NULL;
                head_p = NULL;
            }
            else if (n==tail_p){
                tail_p = n->prev;
                n->prev->next = NULL;            
            } else if (n==head_p){
                head_p = n->next; 
                n->next->prev = NULL;
            } else {
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }

            free(n);//free the memory at n
            return(1); //return 1 if n is found
        }
        n=n->prev; //iterate through list
    }
    return(0); //return 0 if element not found
}

void printList(){

    struct node * n = head_p;

    if (head_p == NULL){
        printf("List is empty.\n");
        return;
    }

    while (n!=NULL){

        printf("value: %d, ",n->info);

        if (n->prev == NULL) {
            printf("previous: NULL, ");
        } else {
            printf("previous: %d, ", n->prev->info);
        }

        if (n->next == NULL) {
            printf("next: NULL, ");
        } else {
            printf("next: %d, ", n->next->info);
        }

        if (n==head_p) {
            printf("Head = TRUE, ");
        } else {
            printf("Head = FALSE, ");
        }

        if (n==tail_p) {
            printf("Tail = TRUE\n");
        } else {
            printf("Tail = FALSE\n");
        }

        n = n->next;
    }

}

int main (int argc, char* argv[]){

int node;
char input;

#ifdef DEBUG
insertNode(-1);
insertNode(5);
insertNode(10);
insertNode(7);
printList();
#endif


while (1){

    printf("Enter (a)dd or (r)emove node then the value.\n");
    scanf(" %c %d", &input, &node);

    // printf("Value of node\n");
    // scanf(" %d", &node);

    if (input == 'a'){
        insertNode(node);
        printList();
    } else if (input == 'r'){
        removeNode(node);
        printList();
    }

    printf("Enter (c) to continue, or any other key to exit...\n");
    scanf(" %c", &input);

    if (input != 'c'){
        return(1);
    }

}


return(0);
}






