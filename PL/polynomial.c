
#include<stdio.h>
#include<malloc.h>

typedef struct polynode
{
  int coeff,exp;
  struct polynode *next;
}node;

node * create();
void display(node *head);
node * attach(node *head,node *p3);
void add(node *p1head,node *p2head);
void mult(node *p1head,node *p2head);
void evaluate(node *p1head);
int power(int x,int e);
int main()
 { 
   int ch;
   char choice;
   node *p1head, *p2head;
   
   do
     { printf("\n\n\n1)Create\n2)Display\n3)Add\n4)Multiply\n5)Evaluate");
       printf("\nEnter Your Choice:");
       scanf("%d",&ch);
       switch(ch)
         {  
            case 1: printf("\n creating first polynomial");
			p1head=create();
		    printf("\n creating second polynomial");
			p2head=create();
			break;
    	    case 2: printf("\n first polynomial is");
			display(p1head);
		    printf("\n second polynomial is");
			display(p2head);
			break;
            case 3: add(p1head,p2head);
			break;
            case 4: mult(p1head,p2head);
			break;
            case 7: evaluate(p1head);
			break;
         }
	printf("Do u want to continue(y/n)");
	scanf(" %c",&choice);
       }while(choice=='y');
	return(0);
 }
node *create()
   {
       int n,i;
       node *p,*last,*head;
       printf("\nEnter No. of Terms in polynomial:");
       scanf("%d",&n);
       head=NULL;       
       for(i=0;i<n;i++)
          {   	
		p=(node*)malloc(sizeof(node));
		p->next=NULL;
		printf("Enter coef & exp=%d term",i+1);
		scanf("%d%d",&p->coeff,&p->exp);

		if(head==NULL)
		{
			head=(node*)malloc(sizeof(node));
			head->coeff=head->exp=-999;
			head->next=p;
			p->next=head;
		}
		else
		{
			last->next=p;
			p->next=head;
		}
		last=p;
     	  }
	printf("\n polynomial created");
       return(head);
  }

 void display( node *head)
 {  
	node *p;
	if(head==NULL)
		printf("\n polynmial not created");
	else
		{
			p=head->next;
			while(p!=head)
			{
				printf("%d x^ %d +",p->coeff,p->exp);
				p=p->next;
			}
		}
  }
 

node * attach(node *head,node *p3)
{
  node *temp;
  if(head==NULL)
    {
      head=(node*)malloc(sizeof(node));
      head->coeff=head->exp=-999;
      head->next=p3;
      p3->next=head;
    }
  else
    {
      temp=head->next;
      while(temp->next!=head)
	temp=temp->next;
      temp->next=p3;
      p3->next=head;
    }
  return(head);
}

 void add(node *p1head,node *p2head)
  {  
	node *p3head,*p1,*p2,*p3;
	if(p1head==NULL && p2head==NULL)
		printf("\n Empty plynomial");
	else
	{
		p1=p1head->next;
		p2=p2head->next;
		p3head=NULL;
		while(p1!=p1head && p2!=p2head)
		{
			p3=(node*)malloc(sizeof(node));
			p3->next=NULL;
			if(p1->exp==p2->exp)
			{
				p3->exp=p1->exp;
				p3->coeff=p1->coeff + p2->coeff;
				p1=p1->next;
				p2=p2->next;
			}
			else if(p1->exp>p2->exp)
			{
				p3->exp=p1->exp;
				p3->coeff=p1->coeff;
				p1=p1->next;
			}
			else if(p1->exp<p2->exp)
			{
				p3->exp=p1->exp;
				p3->coeff=p2->coeff;
				p2=p2->next;
			}
			p3head=attach(p3head,p3);
		} 

		while(p1!=p1head)
		{
			p3=(node*)malloc(sizeof(node));
			p3->next=NULL;
			p3->exp=p1->exp;
			p3->coeff=p1->coeff;
			p1=p1->next;
			p3head=attach(p3head,p3);
		}

		while(p2!=p2head)
		{
			p3=(node*)malloc(sizeof(node));
			p3->next=NULL;
			p3->exp=p2->exp;
			p3->coeff=p2->coeff;
			p2=p2->next;
			p3head=attach(p3head,p3);
		}
                printf("\n First polynomial is");
		display(p1head);
		printf("\n second polynomial is");
		display(p2head);
		printf("\n resultant polynomial is");
		display(p3head);	
	}

     
  }

void mult(node *p1head,node *p2head)
{
  node *p3head,*p1,*p2,*p3,*last,*temp;
  int c,e,found=0;

  if((p1head==NULL)||(p2head==NULL))
    printf("\n\nEmpty polynomial");
  else
    {
      p3head=(node*)malloc(sizeof(node));
      p3head->coeff=p3head->exp=-999;
      p3head->next=p3head;
      p1=p1head->next;
      while(p1!=p1head)
	{
	  p2=p2head->next;
	  while(p2!=p2head)
	    {
	      c=p1->coeff * p2->coeff;
	      e=p1->exp + p2->exp;
	      found=0;
	      temp=p3head->next;
	      while(temp!=p3head)
		{
		  if(temp->exp==0)
		    {
		      found=1;
		      break;
		    }
		  else
		    temp=temp->next;
		}
	      if(found==1)
		temp->coeff=temp->coeff + c;
	      else
		{
		  p3=(node*)malloc(sizeof(node));
		  p3->coeff=c;
		  p3->exp=e;
		  if(p3head->next==p3head)
		    {
		      p3head->next=p3;
		      p3->next=p3head;
		      last = p3;
		    }
		  else
		    {
		      last->next=p3;
		      p3->next=p3head;
		      last = p3;
		    }
		}
	      p2 = p2->next;
	    }
	    p1 = p1->next;
	}
      printf("\n\nfirst polynomial=");
      display(p1head);
      printf("\n\n second polynomial=");
      display(p2head);
      printf("\n\nResultant  polynomial multiplication =");
      display(p3head);
    }
}

void evaluate(node *p1head)
{
  node *p;
  int total,x;
  printf("\n Enter x value");
  scanf("%d",&x);
  total=0;
  p=p1head->next;
  while(p!=p1head)
    {
      total+=(p->coeff * power(x,p->exp));
      p=p->next;
    }
  printf("\n\nEvaluation=%d",total);
}




int power(int x,int e)
 {
   int i,p=1;
   for(i=1;i<=e;i++)
     p*=x;
   return(p);
   
 }



