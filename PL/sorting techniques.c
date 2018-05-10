#include<stdio.h>
#include<string.h>
void bubble(char str[10][15],int n);
void selection(char str[10][15],int n);
void main()
{
 char str[10][15];
int n,i,ch;
do
{
  printf("\n\n*******String Sorting *******");
 printf("\n1. Bubble sorting\n2. Selection sorting\n3. Exit");

 printf("\n ENTER UR CHOICE");
 scanf("%d",&ch);

 switch(ch)
{
 case 1:printf("\n\nHow many number of strings in array");
        scanf("%d",&n);
        printf("\n Enter %d strings",n);
        for(i=0;i<n;i++)
        scanf("%s",str[i]);
        bubble(str,n);
        break;
 case 2:printf("\n\nHow many number of strings in array");
        scanf("%d",&n);
        printf("\n Enter %d strings",n);
        for(i=0;i<n;i++)
        scanf("%s",str[i]);
        selection(str,n);
        break;
}
}while(ch!=3);

}


void bubble(char str[10][15],int n)
{
 int i,j,k;
 char temp[15];
 printf("\n ***Bubble sorting***: \n");
 for(k=0;k<n;k++)      
 printf("\t%s",str[k]);
 
for(i=0;i<n;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(strcmp(str[j],str[j+1])>0)
        {
          strcpy(temp,str[j]);
          strcpy(str[j],str[j+1]);
          strcpy(str[j+1],temp);
          printf("\n");
          for(k=0;k<n;k++)   
          printf("\t%s",str[k]);
        }
    }
  }

}


void selection(char str[10][15],int n)
{
 int i,j,k;
 char temp[15];
 printf("\n selection sorting : \n");
 for(k=0;k<n;k++)       
 printf("\t%s",str[k]);
 
for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(strcmp(str[i],str[j])<0)
        {
          strcpy(temp,str[i]);
          strcpy(str[i],str[j]);
          strcpy(str[j],temp);
          printf("\n");
          for(k=0;k<n;k++)  
          printf("\t%s",str[k]);
        }
    }
  }
}

