#include<stdio.h>
void add(int a[20][20],int b[20][20],int r1,int c1,int r2,int c2);
void mul(int a[20][20],int b[20][20],int r1,int c1,int r2,int c2);
void trans(int a[20][20],int b[20][20],int r1,int c1,int r2,int c2);
void main()
{
	int m1[20][20],m2[20][20],s1,s2,s3,s4,i,j,ch,c;
	char choice;
	printf("Enter size of first matrix \n");
	scanf("%d%d",&s1,&s2);
	printf("Enter elements of matrix 1\n");
	for(i=0;i<s1;i++)
	{
		for(j=0;j<s2;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	printf("Enter size of second matrix \n");
	scanf("%d%d",&s3,&s4);
	printf("Enter elements of matrix 2\n");
	for(i=0;i<s3;i++)
	{
		for(j=0;j<s4;j++)
		{
			scanf("%d",&m2[i][j]);
		}
	}
        do
        {
	printf("Enter your choice");
	printf("1-addition\n2-multiplication\n3-transpose\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:	add(m1,m2,s1,s2,s3,s4);
			break;
		
		case 2: mul(m1,m2,s1,s2,s3,s4);
			break;
		case 3: trans(m1,m2,s1,s2,s3,s4);
                       break;
	}
         printf("\n\n DO U WANT TO CONTINUE(y/n)");
          scanf(" %c",&choice);
}while(choice=='y');
}
		//FUNCTION DEFINITION
void add(int a[20][20],int b[20][20],int r1,int c1,int r2,int c2)
{
	int c[20][20],i,j,k,l;
	if(r1==r2 && c1==c2)
	{
	for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("First matrix is\n");
	for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
	printf("Second matrix is\n");
	for (i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d \t",b[i][j]);
		}
		printf("\n");
	}
	printf("Addition of given two matrix is\n");
	for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d \t",c[i][j]);
		}
		printf("\n");
	}
	}
	else
	{
		printf("Addition cannot be done baecuse row and columns of both matrix are not same \n");
	}
}

void mul(int a[20][20],int b[20][20],int r1,int c1,int r2,int c2)
{
	int c[20][20],i,j,k;
	if(c1==r2)
	{
	for(i=0;i<r1;i++)
	{
        	for(j=0;j<c2;j++)
        	{
        		c[i][j] = 0;
        	}
	for(i=0;i<r1;i++)
	{
        	for(j=0;j<c2;j++)
		{        	
			for(k=0; k<c1; ++k)
			{
                        	c[i][j]=c[i][j]*a[i][k]*b[k][j];
			}           
		}
	}
	}
	printf("First matrix is\n");
	for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
	printf("Second matrix is\n");
	for (i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d \t",b[i][j]);
		}
		printf("\n");
	}
	printf("Multiplication of matrix is \n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d \t",c[i][j]);	
		}
		printf("\n");
	}
	}
	else
	{
		printf("Multiplication cannot be done because column of first matrix is not equal to row of second matrix");
	}
}
void trans(int a[20][20],int b[20][20],int r1,int c1,int r2,int c2)
{
	int c[20][20],d[20][20],i,j;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			c[i][j]=a[j][i];
		}
	}
		printf("First matrix is\n");
	for (i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
		printf("Transpose of First matrix is\n");
	for (i=0;i<c1;i++)
	{
		for(j=0;j<r1;j++)
		{
			printf("%d \t",c[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			d[i][j]=b[j][i];
		}
	}
		printf("Second matrix is\n");
	for (i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d \t",b[i][j]);
		}
		printf("\n");
	}
		printf("Transpose of Second matrix is\n");
	for (i=0;i<c2;i++)
	{
		for(j=0;j<r2;j++)
		{
			printf("%d \t",d[i][j]);
		}
		printf("\n");
	}
}

