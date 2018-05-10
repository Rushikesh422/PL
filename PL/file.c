#include<stdio.h> 
struct student{ 
int roll; 
char name[20]; 
float marks; 
}s[30]; 
void disp(int n) 
{ 
char ch3; 
int i; 
FILE *fp=fopen("main.txt","r"); 
if(fp==NULL) 
{ 
printf("There is an error while opening the file\n"); 
} 
ch3=getc(fp); 
while(ch3!=EOF) 
{ 
 printf("%c", ch3); 
    ch3 = getc(fp); 
} 
} 
void delete(int n) 
{ 
int i,r,p; 
char c,ch5; 
FILE *fp1; 
FILE *fp2; 
fp1=fopen("main.txt","r"); 
fp2=fopen("temp.txt","w+"); 
printf("Enter the roll no. to delete the record:\t"); 
scanf("%d",&r); 
fprintf(fp2,"\nRoll No.\t\tName\t\tMarks\n"); 
for(i=1;i<=n;i++) 
{ 
p=s[i].roll; 
if(p!=r) 
{ 
fscanf(fp1,"%d\t\t%s\t\t%f\n",&s[i].roll,s[i].name,&s[i].marks); 
fprintf(fp2,"%d\t\t%s\t\t%f\n",s[i].roll,s[i].name,s[i].marks); 
} 
} 
fclose(fp1); 
fclose(fp2); 
fp1=fopen("main.txt","w+"); 
fp2=fopen("temp.txt","r"); 

 c = fgetc(fp2); 
    while (c != EOF) 
    { 
        fputc(c, fp1); 
        c = fgetc(fp2); 
    } 
fclose(fp1); 
fclose(fp2); 


} 
void search(int n) 
{ 
int p,r,i; 
FILE *fp2; 
printf("Enter roll no to search the information:\t"); 
scanf("%d",&r); 
fp2 = fopen("main.txt", "r"); 
for(i=1;i<=n;i++) 
{ 
p = s[i].roll; 
if (p==r) 
{ 
printf("\nRoll no = %d",s[i].roll); 
printf("\nName    = %s",s[i].name); 
printf("\nMark    = %.2f\n",s[i].marks); 
} 
} 
fclose(fp2); 
} 

void update(int n) 
{ 
int i,p,r,up,d; 
char c; 
FILE *fp1; 
FILE *fp2; 
fp1=fopen("main.txt","r"); 
fp2=fopen("temp.txt","w+"); 

printf("Enter the roll no. to update the information:\t"); 
scanf("%d",&r); 
for(i=1;i<=n;i++) 
{ 
d=s[i].roll; 
if(d!=r) 
{ 
fscanf(fp1,"%d\t\t%s\t\t%f\n",&s[i].roll,s[i].name,&s[i].marks); 
fprintf(fp2,"%d\t\t%s\t\t%f\n",s[i].roll,s[i].name,s[i].marks); 
} 
} 
 
for(i=1;i<=n;i++) 
{ 
p=s[i].roll; 
if(p==r) 
{ 
printf("Select what you want to update:\n"); 
printf("1.name of student\n2.marks of student\n3.Both name and marks of student\n"); 
scanf("%d",&up); 
switch(up) 
{ 
case 1 :printf("Enter name of student:\t"); 
        scanf("%s",s[i].name); 
        break; 
case 2 :printf("Enter marks of student:\t"); 
        scanf("%f",&s[i].marks); 
        break; 
case 3 :printf("Enter name of student:\t"); 
        scanf("%s",s[i].name); 
        printf("Enter marks of student:\t"); 
        scanf("%f",&s[i].marks); 
        break; 
default: printf("\nsorry wrong selection\n"); 
         break; 
} 
fprintf(fp2,"%d\t\t%s\t\t%f\n",s[i].roll,s[i].name,s[i].marks); 
} 
} 
fclose(fp1); 
fclose(fp2); 

fp1=fopen("main.txt","w+"); 
fp2=fopen("temp.txt","r"); 

 c = fgetc(fp2); 
    while (c != EOF) 
    { 
        fputc(c, fp1); 
        c = fgetc(fp2); 
    } 
fclose(fp1); 
fclose(fp2); 

} 

void add(int n) 
{ 
int i,r,count=1; 
char c; 
FILE *fp1; 
FILE *fp2; 
fp1=fopen("main.txt","r"); 
fp2=fopen("temp.txt","w+"); 
for(i=1;i<=n;i++) 
{ 
fscanf(fp1,"%d\t\t%s\t\t%f\n",&s[i].roll,s[i].name,&s[i].marks); 
fprintf(fp2,"%d\t\t%s\t\t%f\n",s[i].roll,s[i].name,s[i].marks); 
count=count+1; 
} 
printf("Enter roll no :.\t"); 
scanf("%d",&s[count].roll); 
printf("Enter name :.\t"); 
scanf("%s",s[count].name); 
printf("Enter marks :.\t"); 
scanf("%f",&s[count].marks); 
fprintf(fp2,"%d\t\t%s\t\t%f\n",s[count].roll,s[count].name,s[count].marks); 
fclose(fp1); 
fclose(fp2); 
fp1=fopen("main.txt","w+"); 
fp2=fopen("temp.txt","r"); 
 c = fgetc(fp2); 
    while (c != EOF) 
    { 
        fputc(c, fp1); 
        c = fgetc(fp2); 
    } 
fclose(fp1); 
fclose(fp2); 

} 


void main() 
{ 
int i,ch1,ch2,n; 
char ch; 
FILE *fp=fopen("main.txt","w+"); 
printf("For how many students you are going to store the data:\t"); 
scanf("%d",&n); 
fprintf(fp,"\nRoll No.\t\tName\t\tMarks\n"); 
for(i=1;i<=n;i++) 
{ 
printf("Enter students roll number:\t"); 
scanf("%d",&s[i].roll); 
printf("Enter students name:\t"); 
scanf("%s",s[i].name); 
printf("Enter students marks:\t"); 
scanf("%f",&s[i].marks); 
fprintf(fp,"%d\t\t%s\t\t%f\n",s[i].roll,s[i].name,s[i].marks); 
} 
printf("\nYour file is created successfully.....\n"); 
fclose(fp); 
printf("Which operation do you want to do on your file:\n"); 
do{ 
printf("1.display \n2.delete\n3.search\n4.update\n5.Add\n"); 
scanf("%d",&ch1); 
switch(ch1) 
{ 
case 1: disp(n); 
         break; 
case 2: delete(n); 
          break; 
case 3: search(n); 
          break; 
case 4: update(n); 
         break; 
case 5: add(n); 
         break; 
default:printf("\nSorry......wrong choice\n"); 
} 
printf("Do you want to perform more:(1.yes/2.no)\t"); 
scanf("%d",&ch2); 
}while(ch2==1); 
}


