#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<ctype.h>
FILE *fp;
struct student
{
 char snum[13];
 char fname[20];
 char sname[20];
 char mi;
 char ccode;
 }record;
 void Temp1(void);
 void two_line_box(int x1,int y1,int x2,int y2)
 {
 int x,y;
 gotoxy(x1,y1);
 printf("E");
 gotoxy(x2,y2);
 printf(">>");
 for(y=y1+1;y<y2;y++)
   {
     gotoxy(x,y1);
     printf("I");
     gotoxy(x,y2);
     printf("I");
   }
 gotoxy(x1,y2);
 printf("E");
 gotoxy(x2,y2);
 printf("1/4");
 for(x=x1+1;x<x2;x++)
   {
     gotoxy(x,y1);
     printf("I");
     gotoxy(x,y2);
     printf("I");
   }
 gotoxy(x1+1,y1+1);

}
 void printxy(int x,int y,char string[])
 {
 gotoxy(x,y);
 printf("%s",string);

 }
  void centre (int y,char string[])
  {
   int x=(80-strlen(string)+1)/2;
   gotoxy(x,y);
   printf("%s",string);
  }
  void Create()
  {
  char opt;
  centre(21,"WARNING!!!");
  centre(22,"You are about to create a new file");
  centre(23,"This will erase all records in the file .....");
  centre(24,"Are you sure you want to proceed?[Y/N]");
  opt=getch();
  opt=toupper(opt);
  if(opt =="Y")
   {

    fp=fopen("group4.txt","w");
    centre(24,"File successfully created!");
   }
  getch();
  fclose(fp);
  }
  void Add(void)
  {
   char opt;
  fp=fopen("group4.txt","a");
  clrsrn();
  Temp1();
  gotoxy(19,8);
  scanf("");gets(record.snum);
  gotoxy(19,10);
  scanf("");gets(record.fname);
  gotoxy(19,12);
  scanf("");gets(record.sname);
  gotoxy(19,14);
  record.mi=getche();
  record.mi=toupper(record.mi);

  gotoxy(19,16);
  record.ccode=getch();
  gotoxy(5,22);
  clreol();printxy(79,22,"0");
  fprintf(fp,"%s             %s            %s           %c             %c",record.snum,record.fname,record.sname,record.mi,record.ccode,fclose());
  gotoxy(5,21);clreol();center(21,"Record successfully added!");
  printf(79,21,"0"); gotoxy(53,22); delay(1000);
  center(22,"Press any  key to go to main menu....");
  getch();
  fclose(fp);
  }
   void Temp1(void)
   {
    two_line_box(2,6,79,20);
    two_line_box(2,20,79,24);
    two_line_box(2,2,79,24);
    center(4,"ADD RECORD");
    printxy(6,8,"Student no.");
    printxy(6,10,"First name");
    printxy(6,12,"Last name");
    printxy(6,14,"Middle init.");
    printxy(6,16,"Course code");
    center(22,"Course code:[A]-ComputerSci,[B]-for Info tech ,[any key]-Services");
   gotoxy(19,7);
   }
   void List(void)
   {
    int count =0,i,x=0,page=1,CS=0,IT=0,Serv=0;
    fp=fopen("group4.txt","r");
    clrscr();
    center(2,"DELHI TECHNOLICAL UNIVERSITY");
    center(3,"SHAHBAD DAULATPUR BAWANA NEW DELHI-42");
    center(2,"COMPUTER SCIENCE DEPARTEMENT");
    printxy(10,7,"REcord    Student#    NameCourse");
    for(i=0;i<80;i++)
    {
     gotoxy(i,8);
     puts("I");
    }
   while(fscanf(fp,"%s %s %s %c %c",&record.snum,&record.fname,&record.sname,&record.mi,&record.ccode,fclose())!=EOF)
   {
    if(count!=0&&count%5==0)
    {
     printxy(5,23,"Press any key to continue...");
    }
     getch();
     x=0;
     for(i=10;i<24;i++)
    {
     gotoxy(1,i);clreol();
    }
    page++;

   }
    gotoxy(70,4);
    printf("page%d",page);
    gotoxy(13,10+x);
    printf("%d",count+1);
    gotoxy(19,10+x);
    printf("%s",record.snum);
    gotoxy(37,10+x);
    printf("%s,%s %c",record.sname,record.fname,record.mi);
    gotoxy(62,10+x);
    switch(record.ccode)
    {
     case'A':("CompSci"); CS++;
             break;
     case'B':("InfoTech");IT++;
             break;
     default:printf("Services");Serv++;
    }
    x++;
    count++;

    printxy(25,17,"TOTAL");
    gotoxy(15,18);printf("CompSci:%d",CS);
    gotoxy(15,19); printf("InfoTech:%d",IT);
    gotoxy(15,20);printf("Services:%d",Serv);
    printxy(5,23,"Press any key to go to main menu....");
    getch();
    fclose(fp);
   }

    void Quit(void)
    {
     clrscr();
     two_line_box(2, 2,79,24);
     center(8,"PROGRAMMED ");
     center(9,"BY ");
     center(11,"PRIYANKA KUMARI");
     center(13," ROLL NO. 2K21/B9/01");
     center(14,"SANGEETA MONDAL ");
     center(15,"ROLL NO.-2K21/B9/30 ");
     delay(5000);
     exit(1);
     fclose(fp);
    }
     void Err_mess(void)
     {
      Beep(1000,1000);
      center(22,"Invalid Input!");
      Sleep(1000);

     }

    void main()
    {
     char choice;
     do
     {
      clrscr();
      two_line_box(29,6,51,8);
      two_line_box(20,5,60,8);
      two_line_box(2,20,79,25);
      two_line_box(2,2,79,25);
      center(7,"MAIN MENU");
      printxy(30,11,"[A]-Create File");
      printxy(30,12,"[B]-Add Record");
      printxy(30,13,"[C]-List Record");
      printxy(30,14,"[D]-Quit Program ");
      printxy(30,16,"Enter your choice... ");
      gotoxy(50,16);
      choice=getch();choice=toupper(choice);
      switch(choice)
      {
       case'A':Create();
               break;
       case'B': Add();
               break;
       case'C':List();
               break;
       case'D':Quit();
               break;
       default:Err_mess();
      }
     }while(choice!='D');


    }
