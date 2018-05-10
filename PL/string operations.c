#include<stdio.h>

// TO calculate LENGTH

void length(char *p,char *q)
{
 int l;
 l=0;
 while(*p!='\0')
{
  p++;
  l++;
 }
printf("\nLength of first string= %d",l);
 l=0;
 while(*q!='\0')
 {
  q++;
  l++;
 }
 printf("\nLength of second string= %d",l);
}

//To COPY string

void copy(char *p, char *q)
{ 
 while(*q!='\0')
  {
   *p=*q;
   p++;
   q++;
  }
 *p='\0';
}

// To COMPARE two strings

int compare(char *p,char *q)
{
 while(*p!='\0' && *q!='\0')
 {
   if(*p!=*q)
    break;
  p++;
  q++;
 }
 return(*p-*q);
}

// TO REVERSE string
void reverse(char *a)
{ 
 char *q,temp,*p;
 p=q=a;
 while(*q!='\0')
  {
     q++;
  }
  q--;
 while(p<q)
 {
  temp=*p;
  *p=*q;
  *q=temp;
  p++;
  q--;
 }
}

//TO PALINDROME string 
void palindrome(char *a)
{ 
 char *q,temp,*p;
 p=q=a;
 while(*q!='\0')
  {
     q++;
  }
  q--;
 while(p<q)
 {
   if(*p!=*q)
   {
    printf("\n String %s is not palindrome",a);
    return;
   }
  p++;
  q--;
 }
printf("\n String %s is palindrome",a);
}

//To check string is substring or not

void substring(char *p,char *q)
{
 char *a,*b;
 b=q;
 while(*p!='\0' && *q!='\0')
  {
   a=p;
   q=b;
    while(*a!='\0' && *q!='\0')
     {
      if(*a!=*q)
       break;
      a++;
      q++;
     }
    p++;
  }
  if(*q=='\0')
   printf("\n %s is substring",b);
  else
   printf("\n %s is not substring",b);
} 
 
void main()
{
 char str1[20],str2[20],str3[20],choice;
 int ch;
 
 do
  {
   printf("\n***********************");
   printf("\n1.Length\n2.copy\n3.compare\n4.reverse\n5.Check for Palindrome\n6.Check for substring");
   printf("\n***********************");
   printf("\nEnter Ur choice");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:printf("\n Enter first string");
 	   scanf("%s",str1);
	   printf("\n Enter second string");
	   scanf("%s",str2);
	   length(str1,str2);
           break;
    case 2:printf("\n Enter string to be copied");
 	   scanf("%s",str1);
           copy(str3,str1);
           printf("\nCOPIED STRING= %s",str3);
           break;
    case 3:printf("\n Enter first string");
 	   scanf("%s",str1);
	   printf("\n Enter second string");
	   scanf("%s",str2);
           if(compare(str1,str2)==0)
            printf("\nStrings are equal");
           else
            printf("\nStrings are NOT equal");
           break;
    case 4:printf("\n Enter string to reverse");
 	   scanf("%s",str1);
           reverse(str1);
           printf("\nREVERSED STRING= %s",str1);
           break;
    case 5:printf("\n Enter string to check palindrome or not");
 	   scanf("%s",str1);
           palindrome(str1);
           break;
    case 6:printf("\n Enter main string");
 	   scanf("%s",str1);
	   printf("\n Enter substring to check");
	   scanf("%s",str2);
	   substring(str1,str2);
           break;      
   }
   printf("\n Do U want to continue(y/n)");
   scanf(" %c",&choice);
  }while(choice=='y');
}
