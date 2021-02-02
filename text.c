#include<stdio.h>
#include<stdlib.h>

struct book
{
	int code;
	char name[20];
	char date[20];
	int cost;
	struct book *link;

};

int seat = 60 ;

void insert_details();//for inserting movie details
void traverse(); // for view all data 
void search(); // for finding data
void book_ticket(); //for booking tickets

void main()
{

	 int ch;
 	do{
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
		/*case 4:
			book_ticket();
			break;	*/	
    		case 0:
    			exit(0);
    			break;
    		default:
    			printf("Wrong choice !");
    			break;
   	}
 }while(ch!=0);

}

struct book* head=NULL;

void insert_details() 
{
    struct book*newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node))
    printf("\nEnter movie code:");
    scanf("%d",newnode->code);
    printf("\nEnter name: ") ;
    scanf("%s",newnode->name) ;
    printf("\nEnter release date: ") ;
    scanf("%s",newnode->date) ;
    printf("\nEnter ticket price: ") ;
    scanf("%s",newnode->cost) ;
    

    newnode->link=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        newnode->link=head;
        header=newnode;
    }
    printf("\nSuccessfully inserted");
}
void Viewall()
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
	printf("/n");
        temp=temp->link;
    }
    printf("NULL\n");
}
void find()
{   
    struct book *temp;
    int code;
    int flag=-1,ele;
    printf("Enter the code to be searched:");
    scanf("%d",&ele);
    if(head==NULL)
    {
        printf("\nList is empty...\n");
        return;
    } 
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
            if(temp->code==ele)
            {
                flag=0;
                break;
            }
        }
        if(flag==-1)
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


