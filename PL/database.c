#include<stdio.h>
#include<string.h>
struct student 
{
 int rno;
 char name[20];
 float p;
};

void create(struct student st[10],int n);
void display(struct student st[10],int n);
int add(struct student st[10],int n);
void search(struct student st[10],int n);
void modify(struct student st[10],int n);
int delete(struct student st[10],int n);

void main()
{
 struct student st[10];
  int n,ch;
 
 do
  {
   printf("\n\n\n*********Student database **************");
   printf("\n1.Create database\n2.Display database\n3.Add record\n4.search record\n5.Modify record\n6.delete record\n7.Exit");
   printf("\n Enter ur choice");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1: printf("\n Enter how many student records");
             scanf("%d",&n);
             create(st,n);
             break;
     case 2: display(st,n);
             break;
     case 3: if(add(st,n) ==1)
               {
                printf("\n RECORD ADDED SUCCESSFULLY........");
                n++;
                display(st,n);
               }
             break;
     case 4: search(st,n);
              break;
     case 5:modify(st,n);
            display(st,n);
            break;
     case 6: if(delete(st,n)==1)
               {
                printf("\n RECORD DELETED SUCCESSFULLY........");
                n--;
                display(st,n);
               }
;
             break;
    }
  }while(ch!=7);

}


// Creates database of student
void create(struct student st[10],int n)
{
  int i;
  float p1;
  printf("\n Enter %d students data (rno name percentage)",n);
  for(i=0;i<n;i++)
  { 
   scanf("%d%s%f",&st[i].rno,st[i].name,&p1);
   st[i].p=p1;
  }
 printf("\n DATABASE CREATED SUCESSFULLY.......");
 
}
  
void display(struct student st[10],int n)
{
 int i;
 printf("\n *******DATABASE OF STUDENT ***********");
 printf("\nRoll No.\tNAME\t  Percentage");
 for(i=0;i<n;i++)
  { 
   printf("\n%d\t%s\t%f",st[i].rno,st[i].name,st[i].p);
  }

}

int add(struct student st[10],int n)
{
  int pos,i,r;
  float p1;
  char name[20];

  printf("\n Enter position to insert");
  scanf("%d",&pos);
  if(pos<=n+1)
  {
     printf("\n Enter students data to add (Rno name percentage)");
     scanf("%d%s%f",&r,name,&p1);
     for(i=0;i<n;i++)
      {
        if(st[i].rno==r)
         {
           printf("\n Roll number of student should not be same");
           return(0);
         }
      }
   for(i=n-1;i>=pos-1;i--)
    st[i+1]=st[i]; 
   
   st[pos-1].rno=r;
   strcpy(st[pos-1].name,name);
   st[pos-1].p=p1;
   }
else
{
 printf("\n Enter Proper position!!!!!!!!!!!!!!");
  return(0);
}

return(1);
}
void search(struct student st[10],int n)
{
  int r,i;  
  printf("\n Enter students roll no. to search");
  scanf("%d",&r);
  for(i=0;i<n;i++)
   {
     if(st[i].rno==r)
       {
        printf("\n RECORD FOUND...........");
        printf("\n%d\t%s\t%f",st[i].rno,st[i].name,st[i].p); 
        return; 
       }
    }
  printf("\nRECORD NOT FOUND !!!!!!");
}

void modify(struct student st[10],int n)
{
  int r,i;  
  float p1;
  printf("\n Enter students roll no. to modify record");
  scanf("%d",&r);
  for(i=0;i<n;i++)
   {
     if(st[i].rno==r)
       {
        printf("\n Enter new name and prcentage");
         scanf("%s%f",st[i].name,&p1);
         st[i].p=p1;
        printf("\nRECORD MODIFIED SUCCESSFULLY"); 
        return; 
       }
    }
  printf("\nRECORD NOT FOUND !!!!!!");
}

int delete(struct student st[10],int n)
{
int r,i,pos;  
  
  printf("\n Enter students roll no. to delete record");
  scanf("%d",&r);
  for(i=0;i<n;i++)
   {
     if(st[i].rno==r)
       {
        pos=i;
        for(i=pos+1;i<n;i++)
          st[i-1]=st[i];
         return(1); 
       }
     }
printf("\nRECORD NOT FOUND !!!!!!");
return(0);
}

