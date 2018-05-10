#include<stdio.h>
#include<malloc.h>

typedef struct node
{
   int data;
   struct node *next;
}node;

node* create();
void display(node*);
node* insert_beg(node*,int);
node* insert_end(node*,int);
void insert_bet(node*,int);
node* delete_any(node*);
void print_reverse(node *p);
node* reverse(node *head);


void main()
{
  int ch,ch1,d;
  node *head;
  head=NULL;
  do
  {
    printf("\n********SINGLY LINKED LIST *************");
    printf("\n1.create SLL\n2.Display SLL\n3.Insert elemnt\n4.Delete element\n5.print Reverse SLL\n6.Reverse \n7.Exit");
    printf("\nENTER UR CHOICE");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1: head=create();
             break;
     case 2:display(head);
             break;
     case 3:printf("\n1.Insert at begining\n2.Inset at End\n3.Insert in between");
            printf("\nEnter your choice");
            scanf("%d",&ch1);
            printf("\nEnter data to insert");
            scanf("%d",&d);
            switch(ch1)
            {
             case 1:head=insert_beg(head,d);
                    break;
             case 2:head=insert_end(head,d);
                    break;
             case 3:insert_bet(head,d);
                    break;
             }
            break;
     case 4:head=delete_any(head);
             break;
     case 5:printf("\n REVERSED LIST IS");
            print_reverse(head);
            break;
     case 6:head=reverse(head);
            break;




    }
  }while(ch!=7);

}

//***** CREATE SLL*************
 node* create()
{
  node *head,*p,*last;
  int n,i;
  head=NULL;
  printf("\n ENTER NO.OF NODES in SLL");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    p=(node*) malloc(sizeof(node));
    p->next=NULL;
    printf("\n ENTER DATA");
    scanf("%d",&p->data);
   if(head==NULL)
      {     
	   head=p;
        last=p;
      }
   else
      {
       last->next=p;
       last=p;
      }
  }
    
  return(head);
 }


//*****DISPLAY LIST ***************

void display(node *head)
{
  node *p;
  if(head==NULL)
   printf("\n SLL IS EMPTY !!!!!!!!!!!!");
  else
  {
   printf("\n SLL is  :");
   p=head;
   while(p!=NULL)
   {
    printf(" %d->",p->data);
    p=p->next;
   }
  }
}

//*****Insert at begining of List *********

node* insert_beg(node *head,int d)
{
 node *p;
p=(node*) malloc(sizeof(node));
p->data=d;
if(head==NULL)
 head=p;
else
{
  p->next=head; 
  head=p;
}
printf("\nNode added successfully................");
display(head);
return(head);
}

//*****Insert at end of List *********

node* insert_end(node *head,int d)
{
 node *p,*q;
p=(node*) malloc(sizeof(node));
p->data=d;
p->next=NULL;

if(head==NULL)
{
 head=p;
}
else
{
q=head;
while(q->next!=NULL)
 q=q->next;
q->next=p;
}

printf("\nNode added successfully................");
display(head);
return(head);
}

//*****Insert in between of List *********

void insert_bet(node *head,int d)
{
 node *p,*q, *r;
int sd;
printf("\n Enter data after which u want to insert new node");
scanf("%d",&sd);
p=(node*) malloc(sizeof(node));
p->data=d;
p->next=NULL;
q=head;
while(q!=NULL)
{
 if(q->data==sd)
  {
   r=q->next;
   q->next=p;
   p->next=r;
   printf("\nNode added successfully................");
   display(head);
   return;
  }
  else
    q=q->next;

 }

printf("\nData after which node inserted not found................");

}

// Delete any node**********************************
node* delete_any(node *head)
{
  node *p,*prev;
   int sd;
  if(head==NULL)
   printf("\n NOT DELETED... BCOZ EMPTY SLL.........");
  else
   {
     printf("\nEnter data to delete");
      scanf("%d",&sd);
     p=prev=head;
    while(p!=NULL)
    {
       if(p->data==sd)
        {
         if(head==p)
          head=head->next;
         else
         prev->next=p->next;
         free(p);
         printf("\n Node deleted Successfully.................");
         display(head);
         return(head);
        }
        else
        {
          prev=p;
          p=p->next;
        }
           
     }
printf("\n Node not found.................");
  return(head);
}
}

void print_reverse(node *p)
{
 if(p->next!=NULL)
  print_reverse(p->next);

 printf("%d -> ",p->data);
}


node* reverse(node *head)
{
 node *p,*q,*r;
if(head==NULL)
 {
  printf("\n SLL IS EMPTY!!!!!!!!!!");
  return(head);
 }
 p=NULL;
 q=head;
 r=q->next;
 while(q!=NULL)
 {
  q->next=p;
  p=q;
  q=r;
 if(q!=NULL)
  r=q->next;
}
head=p;
display(head);
return(head);
}


