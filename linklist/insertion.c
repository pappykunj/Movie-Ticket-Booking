struct Node
{
    int data;
    struct Node *link;
}*header=NULL;

void insertfront() 
{
    int ele;
    struct Node*newnode;
    printf("\nEnter the element to be inserted: ");
    scanf("%d",&ele);
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=ele;
    newnode->link=NULL;
    if(header==NULL)
        header=newnode;
    else
    {
        newnode->link=header;
        header=newnode;
    }
    printf("\nSuccessfully inserted");
}
void traverse()
{
    struct Node *temp;
    temp=header;
    if(header==NULL)
    {
        printf("List is empty..\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    printf("NULL\n");
}

void search()
{   
    struct Node *temp;
    int flag=-1,ele;
    printf("Enter the data to be searched:");
    scanf("%d",&ele);
    if(header==NULL)
    {
        printf("\nList is empty...The element not existing...\n");
        return;
    } 
    else
    {
        temp=header;
        while(temp->link!=NULL)
        {
            temp=temp->link;
            if(temp->data==ele)
            {
                flag=0;
                break;
            }
        }
        if(flag==-1)
            printf("The data is not existing...\n");
        else
            printf("The data has been found...\n");
    }
}

