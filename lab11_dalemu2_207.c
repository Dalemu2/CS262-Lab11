#include<stdio.h>
#include<stdlib.h>
// struct definition
typedef struct _LinkedList
{
    int data;
    struct _LinkedList *next;
}LinkedList;

//prototypes
void insertNodeSorted(LinkedList **head, LinkedList *newNode);
void printList(LinkedList *head);
void deleteList(LinkedList **head);

/* main function read command line argument */
int main(int argc, char *argv[])
{
	LinkedList *node = NULL;
	LinkedList *head=NULL;
	int seed;
	int rNumber;
	int gnum;
	int max;
	// check number of arguments 
	if(argc!=4)
	{
		printf("Invalid argument numbers\n");
		return -1;
	}
	
	sscanf(argv[1],"%d",&seed);	// read seed from command line 
	sscanf(argv[2],"%d",&gnum);	//read number of random numbers to generated 
	sscanf(argv[3],"%d",&max);	// read the maximum possible value of the random numbers generated
	
	srandom(seed);		// seeded the random number generator 
	// 
	for(int i=0;i<gnum;i++)
	{
		rNumber=random()%max+1;	// generate random numbers with in the range
		node=malloc(sizeof(LinkedList));	// allocate memory
		if(node==NULL)
		{
		   printf(" can't allocate memory\n");
		}
		node -> data=rNumber;			// initialize the node data 
		node -> next=NULL;			// assign node next to NULL
		insertNodeSorted(&head,node);		// pass the head of the list and current node to insertNodeSorted function

	}
	printList(head);		// printlists function  pass the head of list as parameter
	
	
	deleteList(&head);		// deletelists function ( pass the head of list as parameter
	printf("\n all nodes are deleted\n");
//	printList(head);	
	return 0;
}
/*
 * insertNodeSorted function
 * this function inserts a node in assanding order 
 */
void insertNodeSorted(LinkedList **head, LinkedList *newNode)
{
	LinkedList *temp;
	int flag=0;
	if(*head==NULL)		// if the head is nulll, head will be newnode
	{
		*head=newNode;
	}
	else if(newNode -> data < (*head) -> data)	// compater the head data and newnode data
	{
		newNode -> next=*head;		// 
		*head=newNode;
		flag=0;
	}
	else if(newNode -> data == (*head) -> data)      // compater the head data and newnode data
        {
                flag=1;
        }

	else			// else compare each nodes with the new node then place it on assanding order
        {
           temp=*head;
           while((temp -> next!=NULL)&&(temp -> next -> data <= newNode -> data))
            {
		if(temp -> next -> data == newNode -> data)
		{
		  flag=1;
		   break;
		}
		else
		{
                temp=temp -> next;
		}
            }
		if(flag==0)
		{
           		newNode -> next=temp -> next;
        	   	temp -> next=newNode;
		}
       }
}

// print list function accept head as a parameter
void printList(LinkedList *head)
{
	LinkedList *temp=head;
	while(temp!=NULL)		// print all lists
	{

	  printf("%d  ",temp -> data);
	   temp=temp -> next;
	}
	printf("\n");
}

// delete function deletes all lists
void deleteList(LinkedList **head)
{
	LinkedList *temp;
	temp=*head;
	LinkedList *nextNode;
	while(temp!=NULL)
	{
	   nextNode=temp -> next;

           free(temp);
	   temp=nextNode;
	}
	*head = NULL;
}
	
