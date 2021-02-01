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
