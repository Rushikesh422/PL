                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
// MATRIX OPERATIONS USING POINTERS

#include<stdio.h>
#include<malloc.h>

int** create(int m ,int n);
void display(int **a,int m ,int n); 
int** addmat(int **a,int m1,int n1 ,int **b); 
int** multmat(int **a,int m1,int n1 ,int **b,int m2,int n2);
int** transpose(int **a,int m ,int n);
 
void main()
{
 int **a,**b,**c,m1,n1,m2,n2,m3,n3,ch;
 char choice;

 // Creates two matrices

 printf("\nENTER SIZE OF FIRST MATRIX");
 scanf("%d%d",&m1,&n1);
 printf("\nENTER SIZE OF SECOND MATRIX");
 scanf("%d%d",&m2,&n2);
 printf("\nENTER %d X %d FIRST MATRIX",m1,n1);
 a=create(m1,n1);
 printf("\nENTER %d X %d SECOND MATRIX",m2,n2);
 b=create(m2,n2);

 // Display choices
 do
 {

 printf("\n *** MATRIX OPERATIONS  ***");
 printf("\n1. Addition using pointers\n2. Multiplication\n3. Transpose using pointers");
 printf("\n***************************");
 printf("\n ENTER UR CHOICE\n");
 scanf("%d",&ch);

 switch(ch)
 {
  case 1:if(m1==m2 && n1==n2)
         {
           c=addmat(a,m1,n1,b);
           printf("\nA=\n");
           display(a,m1,n1);
	   printf("\nB=\n");
           display(b,m2,n2);
	   printf("\nAddition=\n");
           display(c,m1,n1);
	   break;
         }
        else
         {
          printf("\nMatrix Size should be same for addition!!!!!!!!!");
         }
  case 2:if(n1==m2)
         {
           c=multmat(a,m1,n1 ,b,m2,n2);
           printf("\nA=\n");
           display(a,m1,n1);
	   printf("\nB=\n");
           display(b,m2,n2);
	   printf("\nMultiplication=\n");
           display(c,m1,n1);
	 }
	 else
         {
          printf("\nColoumns of first Matrix should be equal to rows of Second matrix!!!!!!!!!");
         }
         break;
  case 3:  c=transpose(a,m1,n1);
           printf("\nA=\n");
           display(a,m1,n1);
	   printf("\nTranspose of A=\n");
           display(c,n1,m1);
	
         break;
  }

 printf("\n\n DO U WANT TO CONTINUE(y/n)");
//getchar();
//choice=getchar();
scanf(" %c",&choice);

}while(choice=='y');
}

// Creation of Matix
int** create(int m ,int n)
{
  
  int i,j; int **a;
  a=(int**)malloc(m*sizeof(int*));
  for(i=0;i<m;i++)
  *(a+i)=(int*)malloc(n*sizeof(int));   
  for(i=0;i<m;i++)
     for(j=0;j<n;j++)
         scanf("%d",(*(a+i)+j));  
     return(a);
}

// To display Matrix
void display(int **a,int m ,int n)
      
{ 
   int i,j;
   for(i=0;i<m;i++)
    { printf("\n");
      for(j=0;j<n;j++)
        printf("%5d",*(*(a+i)+j));
    }
 printf("\n\n");      
}

//To add two matrix

int** addmat(int **a,int m1,int n1 ,int **b)
{
  int i,j; int **c;
  c=(int**)malloc(m1*sizeof(int*));
  for(i=0;i<m1;i++)
    c[i]=(int*)malloc(n1*sizeof(int));
  for(i=0;i<m1;i++)
    for(j=0;j<n1;j++)
        *(*(c+i)+j)=*(*(a+i)+j) + *(*(b+i)+j);
     return(c);
}

//To multiply two matrices
int** multmat(int **a,int m1,int n1 ,int **b,int m2,int n2)
       
{ 
  int i,j,k,temp;     
  int **c;
  c=(int**)malloc(m1*sizeof(int*));
  for(i=0;i<m1;i++)
    *(c+i)=(int*)malloc(n2*sizeof(int));
  
    
     for(i=0;i<m1;i++)
       for(j=0;j<n2;j++)
         { 
           *(*(c+i)+j)=0;
           for(k=0;k<n1;k++)
             *(*(c+i)+j)=*(*(c+i)+j) + *(*(a+i)+k) * *(*(b+k)+j);
             
         } 
   return(c);
}

//Transpose of Matrix
int** transpose(int **a,int m ,int n)
{   
  int i,j,**c;
  c=(int**)malloc(n*sizeof(int*));
  for(i=0;i<n;i++)
  *(c+i)=(int*)malloc(m*sizeof(int));
  for(i=0;i<m;i++)
     for(j=0;j<n;j++)
       { 
        *(*(c+j)+i)=*(*(a+i)+j);
       }
 return(c);
}


