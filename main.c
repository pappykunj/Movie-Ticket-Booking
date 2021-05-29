#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct person		
{
    char name[50];
    struct person *next;
};

struct ticket
{
    char number[50];
    struct ticket *next;
};

struct book			
{
	int code;
	char name[20];
	char date[20];
	int cost;
	struct book *link;

};

struct person* create_person(char *);
struct ticket* create_ticket(char *);

void insert_person();		// for inserting details
void insert_ticket();		// To book tickets
void display_persons();		// for entering peron
void display_tickets();		// for entering ticket details
void insert_details();		// for inserting movie details
void viewAll();			// for view the movies
void find(); 			// for searching the moive
void book_ticket(); 		// Menu to book tickets

struct person *newperson;
struct person *ptrPerson;
struct ticket *newticket;
struct ticket *ptrTicket;

struct person * firstPerson = NULL;
struct person * lastPerson = NULL;
struct ticket * firstTicket = NULL;
struct ticket * lastTicket = NULL; 
struct book * head = NULL;

int seat = 60 ;

void main()
{
    int ch;
    do
    {
 	printf("\n\n\n");	    
 	printf("\t ***MOVIE TICKETING SYSTEM***");
	printf("\n\n");
	printf("\n*Enter <1> Insert Movie");
   	printf("\n*Enter <2> View All Movie");
	printf("\n*Enter <3> Find Movie ");
	printf("\n*Enter <4> Book Ticket");
   	printf("\n*Enter <0> Exit ");
	printf("\nEnter your Choice ::");
   	scanf("%d",&ch); 	

   	switch (ch)
   	{
    		case 1 :
    			insert_details();
   			break;
		case 2:
    			viewAll();
   			break;
		case 3:
    			find();
   			break;
		case 4:
			book_ticket();
			break;	
    		case 0:
    			exit(0);
    			break;
    		default:
    			printf("Wrong choice !");
    			break;
   	}
    }while(ch!=0);
}

void insert_details() 
{
    struct book*newnode;
    newnode=(struct book*)malloc(sizeof(struct book));
    newnode->link=NULL;
    printf("\nEnter movie code:");
    scanf("%d",&newnode->code);
    printf("\nEnter name: ") ;
    scanf("%s",newnode->name) ;
    printf("\nEnter release date: ") ;
    scanf("%s",newnode->date) ;
    printf("\nEnter ticket price: ") ;
    scanf("%d",&newnode->cost) ;
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->link=head;
        head=newnode;
    }
    printf("\nSuccessfully inserted");
}

void viewAll()
{
    struct book *temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is empty..\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ->" ,temp->code);
	printf("%s ->" ,temp->name);
	printf("%s ->" ,temp->date);
	printf("%d " ,temp->cost);
	printf("\n");
        temp=temp->link;
    }
    printf("\n");
}

void find()
{   
    struct book *temp;
    int code;
    int flag=0,item;
    printf("Enter the code to be searched:");
    scanf("%d",&item);
    if(head==NULL)
    {
        printf("\nList is empty...\n");
        return;
    } 
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            
            if(temp->code==item)
            {
                flag=1;
                break;
            }
            temp=temp->link;
        }
        if(flag==0)
            printf("The record not existing...\n");
        else
	{
	    printf("\n Record Found\n");
	    printf("\n\t\tCode ::%d",temp->code);
	    printf("\n\t\tmovie name ::%s",temp->name);
	    printf("\n\t\tmovie date ::%s",temp->date);
	    printf("\n\t\tprice of ticket ::%d",temp->cost);
	    printf("\n");
	}
            
    }
}

void book_ticket()
{
    int ch;
    char ans = 'Y';

    while (ans == 'Y'||ans == 'y')
    {
        printf("\n---------------------------------\n");
        printf("\nOperations on Ticket & Queue\n");
        printf("\n---------------------------------\n");
        printf("\n1. Add Person in Q");
        printf("\n2. Add ticket");
        printf("\n3. Display All Persons in Q:");
	printf("\n4. Display All Tickets");
        printf("\n0. Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: 
            printf("\n...Adding Person in Q...\n");
            insert_person();
            break;

            case 2: 
            printf("\n...Adding Ticket...\n");
            insert_ticket();
            break;	
            
            case 3: 
            printf("\n...Displaying Persons in Q From Beginning to End : \n");
            display_persons();
            break;
            
            case 4: 
            printf("\n...Displaying Tickets From Beginning to End :\n");
            display_tickets();
            break;
		
            case 0: 
            printf("\n...Exiting...\n");
            break;
            
            default: 
            printf("\n...Invalid Choice...\n");
            break;
        };
        printf("\n\n You want to continue (Y/N)");
        scanf(" %c", &ans);
    }
}
 
struct person* create_person(char *ptrName)
{
    newperson = (struct person *)malloc(sizeof(struct person));
    if (newperson == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        strcpy(newperson->name, ptrName);
        newperson->next = NULL;
        return newperson;
    }
}
 
struct ticket* create_ticket(char *tktNumber)
{
    newticket = (struct ticket *)malloc(sizeof(struct ticket));
    if (newticket == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        strcpy(newticket->number, tktNumber);
        newticket->next = NULL;
        return newticket;
    }
}

 
void insert_person()
{
    char val[50];
    Try:	
    printf("\nEnter the name of person : ");    
    scanf("%s", val);
    if(atoi(val))
    {
	 printf("\nYou have enter integer....Try Again:");
	 goto Try; 	
    }
    else
    {
	 newperson = create_person(val);   
    }	    
    if (firstPerson == lastPerson && lastPerson == NULL)
    {
        firstPerson = lastPerson = newperson;
        firstPerson->next = NULL;
        lastPerson->next = NULL;
    }
    else
    {
        lastPerson->next = newperson;
        lastPerson = newperson;
        lastPerson->next = NULL;
    }
    printf("\n----INSERTED----");
}    

void insert_ticket()
{
    char val[50];

    printf("\nEnter the number of ticket : ");    
    scanf("%s", val);
    newticket = create_ticket(val);
    if (firstTicket == lastTicket && lastTicket == NULL)
    {
        firstTicket = lastTicket = newticket;
        firstTicket->next = NULL;
        lastTicket->next = NULL;
    }
    else
    {
        lastTicket->next = newticket;
        lastTicket = newticket;
        lastTicket->next = NULL;
    }
    printf("\n----INSERTED----");
} 

void display_persons()
{
    if (firstPerson == NULL)
    {
        printf(":No Person in the list to display\n");
    }
    else
    {
        for (ptrPerson = firstPerson; ptrPerson != NULL;ptrPerson = ptrPerson->next)
        {    
            printf("%s\t", ptrPerson->name);
        }
    }
}

void display_tickets()
{
    if (firstTicket == NULL)
    {
        printf(":No Ticket in the list to display\n");
    }
    else
    {
        for (ptrTicket = firstTicket; ptrTicket != NULL;ptrTicket = ptrTicket->next)
        {    
            printf("%s\t", ptrTicket->number);
        }
    }
} 
