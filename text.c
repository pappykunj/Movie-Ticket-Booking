struct book
{
    int code;
	char name[20];
	char date[20];
	int cost;
    struct book *next;
};

struct book* head=NULL;

void insertfront() 
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
void traverse()
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
void search()
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


