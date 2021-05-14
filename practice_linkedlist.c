#include<stdio.h>
#include<stdlib.h>

struct linkedlist{
    int data;
    struct linkedlist *next;
};
struct linkedlist *start;

void insert();
void display();
void count_nodes();

void  insert_AtBeg();
void  insert_AtEnd();
void  insert_Before();
void  insert_After();
void  insert_AtPos();

int main(){

   
    int ch;
    char choice = 'y';
    start = NULL;

    do
    {
        printf("\n\n 1. Insert");
        printf("\n 2. Display");
        printf("\n 6. Count Nodes");
        printf("\n 8. Exit");

        printf("\n\nEnter Choice : ");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            display();
            break;

        case 6:
            count_nodes();
            break;
        case 8:
            choice = 'n';
            break;
        
        default:
            printf("\n Invalid Input....");
        }
    } while (choice == 'y');
    return 0;
}

void display(){
    struct linkedlist *temp;
    temp = start;
    while(temp != NULL){
        printf("%d ---> ", temp->data);
        temp = temp->next;
    }
}

void insert()
{
    int ch2;
    char choice2;

    do
    {
        printf("\n\n 1. At Beginning");
        printf("\n 2. At End");
        printf("\n 3. Before");
        printf("\n 4. After");
        printf("\n 5. At Position");
        printf("\n 6. Exit");

        printf("\n\nEnter Choice : ");
        scanf("%d", &ch2);

        switch (ch2)
        {
        case 1:
           insert_AtBeg();
            break;
        case 2:
            insert_AtEnd();
            break;

        case 3:
            insert_Before();
            break;

        case 4:
            insert_After();
            break;

        case 5:
            insert_AtPos();
            break;
        case 6:
            choice2 = 'n';
            break;
        default:
            printf("\nInvalid choice");
        }
    } while(choice2 == 'y');
    
}

/*
Algorithm to ADD a node at Beg. of LinkList
===========================================

step 1 - Create a node/LinkedList
step 2 - if START = NULL then
	START = node
	exit
             end if
step 3 - TEMP = START
step 4 - START = node
step 5 - next[node] = TEMP
step 6 - EXIT

*/
void  insert_AtBeg(){
    struct linkedlist *node, *temp;
    node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    printf("\n\nEnter Value : ");
    scanf("%d", &node->data);
    node->next = NULL;

    if (start == NULL){
        start = node;
        return ;
    }
    else{
        temp = start;
        start = node;
        node->next = temp;
    }
}

/*
Algorithm to ADD a node at end of LinkList
=============================

step 1. Create a node
step 2. if start == NULL then
	start = node
	exit
            endif
step 3. temp = start
step 4. Repeat While next[temp] != NULL
step 5-    temp = next[temp]
step 6-   end of While
step 7-  next[temp] = node
step 8 - exit

*/

void  insert_AtEnd(){
    struct linkedlist *node, *temp;
    node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    printf("\n\nEnter Value : ");
    scanf("%d", &node->data);
    node->next = NULL;

    if (start == NULL){
        start = node;
        return;
    }
    else{
        temp = start;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
    }
}


/*
Algorithm to ADD a node before a specified node in LinkList :
========================================
step 1 - Start
step 2 - Accept the value into val , before we want to add Node.
step 3 - Create a Node.
step 4 - temp = start
step 5 - repeat while ( temp -> num != val )
	temp1 = temp
	temp = next [ temp ]
step 6 - end of while
step 7 - next[temp1] = node
step 8 - next[node ] = temp
step 9 - Stop
*/

void  insert_Before(){
    int val;
    struct linkedlist *node, *temp, *temp1;
    printf("\nEnter Value Before Which you want to Insert : ");
    scanf("%d", &val);
    node = (struct linkedlist *)malloc(sizeof(struct linkedlist));

    printf("\nEnter Value to Insert : ");
    scanf("%d", &node->data);
    node->next = NULL;

    temp = start;
    temp1 = start;
    while (temp->data != val)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = node;
    node->next = temp;
    
}

/*
Algorithm to ADD a node after a specified node in LinkList :
============================================================
step 1 - Start
step 2 - Accept the value into val , after which we want to add Node.
step 3 - Create a Node.
step 4 - temp = start
step 5 - repeat while ( temp -> num != val )
	temp = next [ temp ]
step 6 - end of while
step 7 - next[node ] = next[temp]
step 8 - next[temp] = node
step 9 - Stop

*/

void  insert_After(){
    int val;
    printf("\nEnter Value After which you want to Insert  : ");
    scanf("%d", &val);

    struct linkedlist *node, *temp;
    node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    printf("\nEnter Value : ");
    scanf("%d", &node->data);
    node->next = NULL;

    temp = start;
    while (temp->data != val)
    {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    

}

/*
Algorithm to ADD a node  at specified position in LinkList :
========================================
step 1 - Start
step 2 - Accept the position no. in n where we want to insert a node.
step 3 - Create a new Node
step 4 - temp = start
step 5- repeat while(temp != NULL)
	counter = counter + 1
	temp = next[temp]
step 6 - end of while
step 7- if n > counter display "Invalid" and Return
step 8- temp = start and i = 1
step 9 - repeat while(i < n)
	i = i + 1
	temp1 = temp
	temp = next[temp]
step 10- end of while
step 11 next[temp1] = node
step 12 next[node ] = temp
step 13 Stop

*/

void  insert_AtPos(){
    int pos, counter = 0;
    printf("Enter Position : \n");
    scanf("%d", &pos);

    struct linkedlist *node, *temp, *temp1;
    node = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    temp = start;

    while (temp != NULL){
        counter = counter + 1;
        temp = temp->next;
    }

    if (pos > counter){
        printf("\nInvalid Position....\n");
        return;
    }
   

    int i = 1;
    printf("\nEnter Value to be Inserted : ");
    scanf("%d", &node->data);
    node->next = NULL;
    temp = start;

    while (i < pos){
        i += 1;
        temp1 = temp;
        temp = temp->next;
    }

    temp1->next = node;
    node->next = temp;
}


void count_nodes(){
    int counter = 0;
    struct linkedlist *temp;
    temp = start;
    
    while(temp != NULL){
        counter = counter + 1;
        temp = temp->next;
    }

    printf("\nTotal Nodes = %d\n", counter);
}