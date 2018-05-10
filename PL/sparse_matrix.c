#include<stdio.h>
struct sparse
{
	int row;
	int col;
	int val;
	};
void create(int m[10][10],int r,int c,struct sparse s[10]);
void display(struct sparse s[20]);
void add(struct sparse s1[10],struct sparse s2[20]);
void transpose(struct sparse s[20]);
void ftranspose(struct sparse s[20]);
int main()
{
	int m1[10][10],m2[10][10],r1,c1,r2,c2;
	struct sparse s1[10],s2[20];
	int ch,i,j;
	char choice;
	do
	{
	   printf("\n1.create\n2.display\n3.addition\n4.transpose\n5.ftranspose");
	   printf("\n Enter your choice");
	   scanf("%d", &ch);
	switch(ch)
    {
	case 1:printf("\n Enter size of first matrix");
	       scanf("%d%d",&r1,&c1);
	       printf("\n Enter %d * %d matrix",r1,c1);
	       for(i=0;i<r1;i++)
	       for(j=0;j<c1;j++)
	       scanf("%d",&m1[i][j]);
	       create(m1,r1,c1,s1);
	       printf("\n Enter size of second matrix");
	       scanf("%d%d",&r2,&c2);
	       printf("\n Enter %d * %d matrix",r2,c2);
	       for(i=0;i<r2;i++)
	       for(j=0;j<c2;j++)
	       scanf("%d",&m2[i][j]);
	       create(m2,r2,c2,s2);
		break;
	case 2:printf("\n first sparse matrix \n");
	       display(s1);
	       printf("\n second sparse matrix \n");
	       display(s2);
	       break;
	case 3:add(s1,s2);
	       break;
	case 4:transpose(s1);
	       break;
	case 5:ftranspose(s1);
	       break;
	    }
	printf("\n Do you want to continue(y/n)");
	scanf(" %c",&choice);
	} while(choice=='y');
    return(0);
   }
void create(int m[10][10],int r,int c,struct sparse s[10])
{
   int i,j,k,nz=0;
   s[0].row=r;
   s[0].col=c;
   k=1; 
   for(i=0;i<r;i++)
   for(j=0;j<c;j++)
   {
	if(m[i][j]!=0)
	{
		s[k].row=i;
		s[k].col=j;
		s[k].val=m[i][j];
		k++;
		nz++;
		}
	     }
	s[0].val=nz;
     }
void display(struct sparse s[20])
{
	int nz,i;
	nz=s[0].val;
	printf("\n row\tcol\tval");
	for(i=0;i<=nz;i++)
	printf("\n %d\t%d\t%d",s[i].row,s[i].col,s[i].val);
	}
void add(struct sparse s1[10],struct sparse s2[20])
{
	struct sparse s3[20];
	int nz=0;
	int i,j,k;
	s3[0].row=s1[0].row;
	s3[0].col=s1[0].col;
	i=1;
	k=1;
	j=1;
	while(i<=s1[0].val && j<=s2[0].val)
	{
	   if(s1[i].row==s2[j].row && s1[i].col==s2[j].col) //row number and col number both matrix are same
	    {
		s3[k].row=s1[i].row;
	    	s3[k].col=s1[i].col;
		s3[k].val=s1[i].val+s2[j].val;
		k++;
		j++;
		i++;
		nz++;
		}
	     if(s1[i].row==s2[j].row && s1[i].col<s2[j].col) 
	      {
		s3[k].row=s1[i].row;
	    	s3[k].col=s1[i].col;
		s3[k].val=s1[i].val;
		k++;
		i++;
		nz++;
		}  
	     if(s1[i].row==s2[j].row && s1[i].col>s2[j].col) 
	       {
		s3[k].row=s2[j].row;
	    	s3[k].col=s2[j].col;
		s3[k].val=s2[j].val;
		k++;
		j++;
		nz++;
		}
       if(s1[i].row<s2[j].row)
	{
	        s3[k].row=s1[i].row;
	    	s3[k].col=s1[i].col;
		s3[k].val=s1[i].val;
		k++;
		i++;
		nz++;
		}   
       if(s1[i].row>s2[j].row)
	{
		s3[k].row=s2[j].row;
	    	s3[k].col=s2[j].col;
		s3[k].val=s2[j].val;
		k++;
		j++;
		nz++;
		}
	       }
	while(i<=s1[0].val)
	{
	s3[k].row=s1[i].row;
	s3[k].col=s1[i].col;
	s3[k].val=s1[i].val;
	k++;
	i++;
	nz++;
	} 
    while(j<=s2[0].val)
     {
	        s3[k].row=s2[j].row;
	    	s3[k].col=s2[j].col;
		s3[k].val=s2[j].val;
		k++;
		j++;
		nz++;
		} 
	s3[0].val=nz;
	printf("\n first sparse matrix \n");
	display(s1);
	printf("\n second sparse matrix \n");
	display(s2);
	printf("\n addition= \n");
	display(s3);
	}
 void transpose(struct sparse s[20])
{
	struct sparse T[20];
	int c,i,k;
	T[0].row=s[0].col;
	T[0].col=s[0].row;
	T[0].val=s[0].val;
	k=1;
	for(c=0;c<s[0].col;c++)
	{
	  for(i=1;i<=s[0].val;i++)
	   {
		if(c==s[i].col)
		{
		   T[k].row=s[i].col;
		   T[k].col=s[i].row;
		   T[k].val=s[i].val;
		   k++;
		}
	      }
	   }
	printf("\n original matrix \n");
	display(s);
	printf("\n transpose matrix \n");
	display(T);
	}
void ftranspose(struct sparse s[20])
{
	int i,j,r,c,nz,rpos[10],rterm[10];
	struct sparse T[20];
	r=s[0].row;
	c=s[0].col;
	nz=s[0].val;
	T[0].row=r;
	T[0].col=c;
	T[0].val=nz;
	for(i=0;i<c;i++)
	rterm[i]=0;
	for(i=1;i<=nz;i++)
	rterm[s[i].col]++;
	rpos[0]=1;
	for(i=1;i<c;i++)
	rpos[i]=rpos[i-1]+rterm[i-1];
	for(i=1;i<nz;i++)
	{
	   j=rpos[s[i].col];
	   T[j].row=s[i].col;
	   T[j].col=s[i].row;
	   T[j].val=s[i].val;
	   rpos[s[i].col]++;
	  }
	printf("\n sparse matrix \n");
	display(s);
	printf("\n ftranspose \n");
	display(T);
}


