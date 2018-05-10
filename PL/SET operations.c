#include<stdio.h>
void union1(int set1[20],int set2[20],int m,int n);
void intersection(int set1[20],int set2[20],int m,int n);
void difference(int set1[20],int set2[20],int m,int n);
void symm_difference(int set1[20],int set2[20],int m,int n);


void main()
{
 int s1[20],s2[20], size1,size2,i,ch;
 printf("\n How many elements in first set");
 scanf("%d",&size1);
 printf("\n Enter %d elements of first set",size1);
 for(i=0;i<size1;i++)
  {
    scanf("%d",&s1[i]);
  }
 printf("\n How many elements in Second set");
 scanf("%d",&size2);
 printf("\n Enter %d elements of second set",size2);
 for(i=0;i<size2;i++)
 {
    scanf("%d",&s2[i]);
  }

 printf("\n1.UNION\n2.INTERSECTION\n3.DIFFERENCE\n4.SYMMETRIC DIFFERENCE\n");
 printf("\n Enter ur Choice");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1: union1(s1,s2,size1,size2);
           break;
   case 2: intersection(s1,s2,size1,size2);
           break;
   case 3: difference(s1,s2,size1,size2);
           break;
   case 4: symm_difference(s1,s2,size1,size2);
           break;
 }
}

// Function for union of two sets

void union1(int set1[20],int set2[20],int m,int n)
{
 int i,j,k,flag;
 int set3[40];
 for(i=0;i<m;i++)
  {
    set3[i]=set1[i];
  }
  //size of set3 is size of set1
k=m;
for(i=0;i<n;i++)
{
    flag=0;
    for(j=0;j<k;j++)
      {
       if(set2[i]==set3[j])
         {
          flag=1;
          break;
         }
                    }
     if(flag==0)
      {
       set3[k]=set2[i];
       k++;
      }
                                                                                                                                                                               }  


printf("\n Union of two set= ");
for(i=0;i<k;i++)
 {
   printf("%d ",set3[i]);
 }
printf("\n\n");
}

// Function for interserction

void intersection(int set1[20],int set2[20],int m,int n)
{
int i,j,k,flag;
 int set3[20];
 k=0;
for(i=0;i<m;i++)
{
    flag=0;
    for(j=0;j<n;j++)
      {
       if(set1[i]==set2[j])
         {
          flag=1;
           set3[k]=set1[i];
       k++;
         }
      }
     
}  
printf("\n first set= ");
for(i=0;i<m;i++)
 {
   printf("%d ",set1[i]);
 }
printf("\n second set= ");
for(i=0;i<n;i++)
 {
   printf("%d ",set2[i]);
 }

printf("\nIntersection set= ");
for(i=0;i<k;i++)
 {
   printf("%d ",set3[i]);
 }
printf("\n\n");
}
// Function for difference
void difference(int set1[20],int set2[20],int m,int n)
{
 int i,j,k,flag;
 int set3[20];
 k=0;
for(i=0;i<m;i++)
{
    flag=0;
    for(j=0;j<n;j++)
      {
       if(set1[i]==set2[j])
         {
          flag=1;
          break;
         }
      }
     if(flag==0)
      {
       set3[k]=set1[i];
       k++;
      }
}  
printf("\n first set= ");
for(i=0;i<m;i++)
 {
   printf("%d ",set1[i]);
 }
printf("\n second set= ");
for(i=0;i<n;i++)
 {
   printf("%d ",set2[i]);
 }

printf("\nDifference of two set= ");
for(i=0;i<k;i++)
 {
   printf("%d ",set3[i]);
 }
printf("\n\n");
}

// Function for Symm-difference
void symm_difference(int set1[20],int set2[20],int m,int n)
{
 int i,j,k,flag;
 int set3[20];
 k=0; //position
for(i=0;i<m;i++) 
{
    flag=0;
    for(j=0;j<n;j++)
      {
if(set1[i]==set2[j])  //calculate set1-set2
         {
          flag=1;
          break;
         }
      }
     if(flag==0)
      {
   set3[k]=set1[i];  //insert and increment number of element..
       k++;
      }
}  
for(i=0;i<n;i++)   
{
    flag=0;
    for(j=0;j<m;j++)
      {
  if(set2[i]==set1[j]) //calculate set2-set1

         {
          flag=1;
          break;
         }
      }
     if(flag==0)
      {
  set3[k]=set2[i];  //insert and increment number of elements
       k++;
      }
}  

printf("\n first set= ");
for(i=0;i<m;i++)
 {
   printf("%d ",set1[i]);
 }
printf("\n second set= ");
for(i=0;i<n;i++)
 {
   printf("%d ",set2[i]);
 }
printf("\nDifference of two set= ");
for(i=0;i<k;i++)
 {
   printf("%d ",set3[i]);
 }
printf("\n\n");
}

