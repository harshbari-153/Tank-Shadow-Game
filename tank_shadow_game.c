//Harsh Bari

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void gotoxy(int a, int b)
{
	COORD c;
	c.X = a;
	c.Y = b;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void removetank(int a,int b)
{
gotoxy(a-1,b);
printf("     ");
gotoxy(a-1,b-1);
printf("     ");
gotoxy(a-1,b+1);
printf("     ");
gotoxy(a+5,b);
printf("   ");
gotoxy(a+1,b+2);
printf(" ");
gotoxy(1+a,b+3);
printf(" ");
gotoxy(a-5,b);
printf("   ");
gotoxy(a+1,b-3);
printf(" ");
gotoxy(a+1,b-2);
printf(" ");
}
void maketank(int a,int b,int f)
{
gotoxy(a-1,b);
printf("* * *");
gotoxy(a-1,b-1);
printf("* * *");
gotoxy(a-1,b+1);
printf("* * *");
if(f==1)
{
gotoxy(a+5,b);
printf("* *");
}
else if(f==2)
{
gotoxy(a+1,b+2);
printf("*");
gotoxy(1+a,b+3);
printf("*");
}
else if(f==3)
{
gotoxy(a-5,b);
printf("* *");
}
else
{
gotoxy(a+1,b-3);
printf("*");
gotoxy(a+1,b-2);
printf("*");
}
}
void removetarget(int x,int y)
{
gotoxy(x-2,y);
printf("     ");
gotoxy(x-2,y+1);
printf("     ");
gotoxy(x-2,y-1);
printf("     ");
}
void maketarget(int x,int y)
{
gotoxy(x-2,y);
printf("# # #");
gotoxy(x-2,y+1);
printf("# # #");
gotoxy(x-2,y-1);
printf("# # #");
}
void removeshadow(int x,int y)
{
gotoxy(79-x+2,25-y);
printf("     ");
gotoxy(79-x+2,25-y-1);
printf("     ");
gotoxy(79-x+2,25-y+1);
printf("     ");
}
void makeshadow(int x,int y)
{
gotoxy(79-x+2,25-y);
printf("* * *");
gotoxy(79-x+2,25-y-1);
printf("* * *");
gotoxy(79-x+2,25-y+1);
printf("* * *");
}
int results(int a,int b,int x,int y)
{
if((b==y) && (x-3<a) && (a<x+3))
return 1;
else if((b==y+1) && (x-3<a) && (a<x+3))
return 1;
else if((b==y-1) && (x-3<a) && (a<x+3))
return 1;
else
return 0;
}
void game()
{
system("CLS");
int a,b,f,g,x,y,tt1,tt2,T1,T2,T3,nt,s,B1,B2,B3,i,result,nt2,v,d;
char e;
g=1;
T1=1;
T2=1;
T3=1;
for(a=0;a<=40;a++)
{
gotoxy(a*2,24);
printf("*");
}
gotoxy(3,1);
printf("Gear:%d",g);

for(a=0;a<=24;a++)
{
gotoxy(1,a);
printf("*");
gotoxy(80,a);
printf("*");
}
gotoxy(9,1);
printf("     ");
gotoxy(25,0);
printf("   ");
gotoxy(40,12);
a=40;
b=10;
f=2;
tt1=0;
again:
srand(time(0));
d=rand()%3;
if(d==0)
x=20;
else if(d==1)
x=40;
else
x=70;
srand(time(0));
d=rand()%3;
if(d==0)
y=6;
else if(d==1)
y=13;
else
y=19;
if(x==40 && y==13)
goto again;
maketarget(x,y);
maketank(a,b,f);
makeshadow(x,y);
nt=0;
nt2=0;
s=4000;
B3=0;
getch();
removetarget(x,y);
v=0;
while(1)
{
if(kbhit())
{
e=getch();
if(e=='0')
goto end;
else if(e=='e')
goto end;
else if(e=='l')
{
 if((g+a)>=73)
 {
 gotoxy(30,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(30,1);
 printf("                    ");
 }
 else if(f!=1)
 {
  f=1;
  removetank(a,b);
  maketank(a,b,f);
 }
 else
 {
  removetank(a,b);
  a=a+g;
  maketank(a,b,f);
 }
}
else if(e=='a')
{
 if((a-g)<=6)
 {
 gotoxy(30,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(30,1);
 printf("                    ");
 }
 else if(f!=3)
 {
  f=3;
  removetank(a,b);
  maketank(a,b,f);
 }
 else
 {
  removetank(a,b);
  a=a-g;
  maketank(a,b,f);
 }
}
else if(e=='v')
{
 if((b+g)>=21)
 {
 gotoxy(30,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(30,1);
 printf("                    ");
 }
 else if(f!=2)
 {
  f=2;
  removetank(a,b);
  maketank(a,b,f);
 }
 else
 {
  removetank(a,b);
  b=b+g;
  maketank(a,b,f);
 }
}
else if(e=='t')
{
 if((b-g)<=4)
 {
 gotoxy(30,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(30,1);
 printf("                    ");
 }
 else if(f!=4)
 {
  f=4;
  removetank(a,b);
  maketank(a,b,f);
 }
 else
 {
  removetank(a,b);
  b=b-g;
  maketank(a,b,f);
 }
}
else if(e=='j')
{
g=(g%5)+1;
gotoxy(8,1);
printf("%d",g);
}
else if(e=='d')
{
g=((g+3)%5)+1;
gotoxy(8,1);
printf("%d",g);
}
else if(e=='g')
{
B3=f;
B1=a;
B2=b;
}
else
{}
}
////User controls over
////target movement begains
//nt=1;
if(nt==0)
{
if((f==1 && x>a) || (f==3 && x<a))
{
 if((b==y) || (b==y+1) || (b==y-1))
 {
 if(tt1==0)
 {
  if(y<20)
  {
   removetarget(x,y);
   removeshadow(x,y);
   y++;
   makeshadow(x,y);
   if(v!=0)
   maketarget(x,y);
   nt=s;
  }
  else
  {
   removetarget(x,y);
   removeshadow(x,y);
   y--;
   makeshadow(x,y);
   if(v!=0)
   maketarget(x,y);
   nt=s;
  }
  if(y==20)
  tt1=(tt1+1)%2;
  }
  else
  {
    if(y>5)
  {
   removetarget(x,y);
   removeshadow(x,y);
   y--;
   makeshadow(x,y);
   if(v!=0)
   maketarget(x,y);
   nt=s;
  }
  else
  {
   removetarget(x,y);
   removeshadow(x,y);
   y++;
   makeshadow(x,y);
   if(v!=0)
   maketarget(x,y);
   nt=s;
  }
  if(y==5)
  tt1=(tt1+1)%2;
  }
 }
}
if((f==2 && y>b) || (f==4 && y<b))
{
 if((a==x) || (a==x+1) || (a==x-1) || (a==x-2) || (a==x+2) || (a==x+3) || (a==x-3))
 {
 if(tt1==0)
 {
  if(x<72)
  {
  removeshadow(x,y);
   removetarget(x,y);
   x++;
   makeshadow(x,y);
   if(v!=0)
   maketarget(x,y);
   nt=s;
  }
  else
  {
  removeshadow(x,y);
   removetarget(x,y);
   x--;
   makeshadow(x,y);
   if(v!=0)
   maketarget(x,y);
   nt=s;
  }
  if(x==72)
  tt1=(tt1+1)%2;
  }
  else
  {
    if(x>7)
  {
  removeshadow(x,y);
   removetarget(x,y);
   x--;
   makeshadow(x,y);
   if(v!=0)
   maketarget(x,y);
   nt=s;
  }
  else
  {
  removeshadow(x,y);
   removetarget(x,y);
   x++;
   makeshadow(x,y);
   if(v!=0)
   maketarget(x,y);
   nt=s;
  }
  if(x==7)
  tt1=(tt1+1)%2;
  }
 }
 }
}
if(nt>0)
nt=nt-1;
/////target movement ends
/////bullet fire starts
if(B3!=0)
{
 if(B3==1)
 {
  for(i=1;i<=5;i++)
  {
   gotoxy(B1,B2);
   printf("   ");
   B1++;
   gotoxy(B1,B2);
   printf("*>");
   delay(10);
   result=results(B1+1,B2,x,y);
   if(result==1)
   goto won;
   if(B1>=77)
   {
   gotoxy(B1,B2);
   printf("  ");
   B3=0;
   break;
   }
  }
 }
 else if(B3==2)
 {
  for(i=1;i<=5;i++)
  {
   gotoxy(B1+1,B2);
   printf(" ");
   gotoxy(B1+1,B2);
   printf(" ");
   B2++;
   gotoxy(B1+1,B2);
   printf("*");
   gotoxy(B1+1,B2+1);
   printf("v");
   delay(10);
   result=results(B1+1,B2+1,x,y);
   if(result==1)
   goto won;
   if(B2>21)
   {
   gotoxy(B1+1,B2);
   printf(" ");
   gotoxy(B1+1,B2+1);
   printf(" ");
   B3=0;
   break;
   }
  }
 }
 else if(B3==3)
 {
  for(i=1;i<=5;i++)
  {
   gotoxy(B1,B2);
   printf("  ");
   B1=B1-2;
   gotoxy(B1,B2);
   printf("<*");
   delay(10);
   result=results(B1-1,B2,x,y);
   if(result==1)
   goto won;
   if(B1<=3)
   {
   gotoxy(B1,B2);
   printf("  ");
   B3=0;
   break;
   }
  }
 }
 else
 {
  for(i=1;i<=5;i++)
  {
   gotoxy(1+B1,B2);
   printf("  ");
   gotoxy(1+B1,B2-1);
   printf("  ");
   B2--;
   gotoxy(1+B1,B2);
   printf("*");
   gotoxy(B1+1,B2-1);
   printf("^");
   delay(10);
   result=results(B1+1,B2-1,x,y);
   if(result==1)
   goto won;
   if(B2<4)
   {
   gotoxy(B1+1,B2);
   printf("  ");
   gotoxy(B1+1,B2-1);
   printf("  ");
   B3=0;
   break;
   }
  }
 }
}
/////bullet fire ends
}
won:
gotoxy(36,2);
printf("WINNER");
maketarget(x,y);
end:
gotoxy(34,1);
printf("GAME OVER");
}
void main()
{
system("CLS");
printf("       Welcome To Invisible Target Tank Game");
gotoxy(50,24);
printf("press any key to continue......");
getch();
system("CLS");
printf("Instructions:\n");
printf(" a for left\n");
printf(" l for right\n");
printf(" t for up\n");
printf(" v for down\n");
printf(" g to fire bullet\n");
printf(" j to gear up\n");
printf(" d to gear down\n");
printf(" e to exite game");
gotoxy(50,24);
printf("press any key to continue.....");
getch();
system("CLS");
gotoxy(15,3);
printf(" # # #                              * * *");
gotoxy(15,4);
printf(" # # #                              * * *");
gotoxy(15,5);
printf(" # # #                              * * *");
gotoxy(10,6);
printf("This is actual target             This is shadow of target");
gotoxy(1,10);
printf("If the shadow moves right, actual target will move left and vice-versa\n");
printf("If the shadow moves down, actual target will move up and vice-versa\n");
printf("Only first location of actual target will be shown, after starting the game only shadow will be shown\n");
printf("Hit the actual target to win the game\n");
printf("ALL THE BEST");
gotoxy(50,24);
printf("press any key to continue......");
getch();
game();
getch();
}