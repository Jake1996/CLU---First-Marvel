//Welcome to chess game done by Arjun and Jatin from class XI
//The computer project for the year 2012-13

//The coordinates must be entered in following way
// (number,character) for ex.. 1a (or) 5f

//If u want to quit the game in between, be pressing 'q'..

//If u want to do castling, give the coordinates of two spaces away
//from the king...

//ENJOY THE GAME PEOPLE!!! :)

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <iostream.h>
#include <process.h>
#define color 8
void cleardevice1();

int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);
int n[8][8],count=1,i=0,color1=2,color2=3,color3=15,color4=0,w=0,b=0,castling_value;
char n1[10],n2[10];
int between(int,int,int,int,int,int);
char selection(void);
char selection1(void);
int start (void);
int win (void);
void option (void);
void wish(int,int);
void name(void);
void end(void);
void instructions(void);
int valid_move (int,int,int,int);
int valid_path (int,int,int,int);
int valid (int,int,int,int);
int castling(int,int,int,int);
void move_castling (int,int,int,int);
void move (int,int,int,int);
void disp_cordinate (void);
void disp_board (void);
void disp_board_char (void);
void in_board (void);
void board (void);

int chess()
{
clrscr();     //clears the screen

   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");
   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)
   /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
   /* terminate with an error code */
      exit(1);
   }

 int x,y,cl;
 int k,l;
  callmouse();
  settextstyle(GOTHIC_FONT, HORIZ_DIR, 6);
  setcolor(3);
    mousehide();
    outtextxy(100,100,"C");
    outtextxy(200,150,"H");
    outtextxy(300,100,"E");
    outtextxy(400,150,"S");
    outtextxy(500,100,"S");
    callmouse();
    getch();
    cleardevice1();
    float c,d;
    for (c=100,d=150;c<=400;d+=1.25,c+=1.5)
     {
      cleardevice1();
      delay(2);
      mousehide();
      outtextxy(100,c,"C");
      delay(2);
      outtextxy(200,d,"H");
      delay(2);
      outtextxy(300,c,"E");
      delay(2);
      outtextxy(400,d,"S");
      delay(1);
      outtextxy(500,c,"S");
     callmouse();
     }

     for (c=400;c>=100;c--)
     {
      cleardevice1();
      mousehide();
      delay(2);
      outtextxy(100,c,"C");
      delay(2);
      outtextxy(200,c,"H");
      delay(2);
      outtextxy(300,c,"E");
      delay(2);
      outtextxy(400,c,"S");
      delay(1);
      outtextxy(500,c,"S");
     callmouse();
     }

     settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
     setcolor(14);
     mousehide();
     outtextxy(300,170,"-- JATIN AND ARJUN");
     outtextxy(300,200,"-- XI 'A'     SVEC");
     callmouse();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);

    setcolor(15);
    l = getmaxy() - 10;
    k = getmaxx() - 10;

    int fill_color = 1;

    for (;l>0;l-=10)
    { mousehide();
      delay(2);
    setfillstyle (SOLID_FILL,fill_color);
    circle (7,l,7);
    floodfill (5,l,15);
	delay(2);
    setfillstyle (SOLID_FILL,fill_color);
    circle (k,l,7);
    floodfill (k,l,15);
    callmouse();
    }

    l = getmaxy() - 10;

    for (;k>0;k-=10)
    {mousehide();
     delay(2);
    setfillstyle (SOLID_FILL,fill_color);
    circle (k,7,7);
    floodfill (k,5,15);
	delay(2);
    setfillstyle (SOLID_FILL,fill_color);
    circle (k,l,7);
    floodfill (k,l,15);
    callmouse();
    }
  getch();

 name();            //to accept the names of the players
 int ext=start();
 if(ext==0)
 return 0;
 cleardevice1();     //clears the screen
 setcolor(color);   //sets text color to grey
 setbkcolor(0);     //sets background color to black
 in_board();        //to initialise values to the characters
 board();           //the display board, characters and coordinates

 int x1,x2,y1,y2;
 char b[3],a[3],q;

 count++;  //count is incremented so that delay works only for the
	   //first time the board, characters & coordinates
	   //are displayed

 while(win())
 { callmouse();
  mouseposi(x,y,cl);
  a[0]=' ';
  a[1]=' ';
  a[2]='\0';

  b[0]=' ';
  b[1]=' ';
  b[2]='\0';

  cleardevice1();     //clears the screen
  board();           //to display board, cahracters and coordinates

  if(i%2==0)
  {
  //player 1's turn :
  //accepts coordinates of the character to be moved
  //to put mouse and change function
   outtextxy(480,40,n1);
   outtextxy(480,50,"x1,y1:-");
   mouseposi(x,y,cl);
   while(cl==0)
   {mouseposi(x,y,cl);}
   if(between(470,400,570,450,x,y)&&cl==1)
   return 0;

   //if(cl==1)
   a[0]=selection();
   outtextxy(480,60,a);
   a[1]=selection1();
   outtextxy(480,60,a);
   //first set of coordinates is accepted

   q=getch();
   if(q=='q')    //if 'q' is entered, the program is terminated
    return 0;

   cleardevice1();     //clears the screen
   board();           //to display board, cahracters and coordinates

  //player 1's turn :
  //accepts coordinates to where the character should be moved
   outtextxy(480,40,n1);
   outtextxy(480,50,"x2,y2:-");
  // if(cl==1);
   mouseposi(x,y,cl);
   while(cl==0)
   {mouseposi(x,y,cl);}
   if(between(470,400,570,450,x,y)&&cl==1)
   return 0;

   b[0]=selection();
   outtextxy(480,60,b);
   b[1]=selection1();
   outtextxy(480,60,b);
   //second set of coordinates is accepted

   q=getch();
   if(q=='q')    //if 'q' is entered, the program is terminated
    return 0;

   //converting characters to integers so the calculations can be made
   x1=a[0]-49;
   y1=a[1]-97;
   x2=b[0]-49;
   y2=b[1]-97;

   if (castling(x1,x2,y1,y2))
    move_castling(x1,x2,y1,y2);
   else if(valid(x1,x2,y1,y2))
    move(x1,x2,y1,y2); //the character is moved using the two sets of
		       //coordinates if the coordinates are valid for
		       //the character that is being moved
   else
   {
    outtextxy(480,70,"INVLAID MOVE");

    q=getch();
    if(q=='q')   //if 'q' is entered, the program is terminated
     return 0;

    continue;
   }
  }
  else
  {
  //player 2's turn :
  //accepts coordinates of the character to be moved
   outtextxy(480,40,n2);
   outtextxy(480,50,"x1,y1:-");
   mouseposi(x,y,cl);
   while(cl==0)
   {mouseposi(x,y,cl);}
   if(between(470,400,570,450,x,y)&&cl==1)
   return 0;

  // if(cl==1)
   a[0]=selection();
   outtextxy(480,60,a);
   a[1]=selection1();
   outtextxy(480,60,a);
   //first set of coordinates is accepted

   q=getch();
   if(q=='q')    //if 'q' is entered, the program is terminated
    return 0;

   cleardevice1();     //clears the screen
   board();           //to display board, cahracters and coordinates

  //player 2's turn :
  //accepts coordinates to where the character should be moved
   outtextxy(480,40,n2);
   outtextxy(480,50,"x2,y2:-");
   mouseposi(x,y,cl);
   while(cl==0)
   {mouseposi(x,y,cl);}
  // if(cl==1);
   if(between(470,400,570,450,x,y)&&cl==1)
   return 0;
   b[0]=selection();
   outtextxy(480,60,b);
   b[1]=selection1();
   outtextxy(480,60,b);
   //second set of coordinates is accepted

   q=getch();
   if(q=='q')    //if 'q' is entered, the program is terminated
    return 0;

   //converting characters to integers so the calculations can be made
   x1=a[0]-49;
   y1=a[1]-97;
   x2=b[0]-49;
   y2=b[1]-97;

   if (castling(x1,x2,y1,y2))
    move_castling(x1,x2,y1,y2);
   else if(valid(x1,x2,y1,y2))
    move(x1,x2,y1,y2); //the character is moved using the two sets of
		       //coordinates if the coordinates are valid for
		       //the character that is being moved
   else
   {
    outtextxy(480,70,"INVLAID MOVE");

    q=getch();
    if(q=='q')   //if 'q' is entered, the program is terminated
     return 0;

    continue;
   }
  }

 i++;
 } //while loop ends
 mousehide();
 end();      //to display which player wins the game
 getch();

   /* clean up */
//   closegraph();
return 0;
}//main program ends

//this functions gives the basic rules on how to play and about the chess game
void instructions()
{
cleardevice1();
    mousehide();
    setfillstyle (SOLID_FILL,0);     //fills the background color
    floodfill(11,71,15);             //with black color

settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);

outtextxy(200,25,"INSTRUCTIONS");

settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);

outtextxy(30,100,"1.");
outtextxy(50,100,"Enter the coordinates in the form of number first and then");
outtextxy(50,120,"digit .. for example '1a'..");
outtextxy(30,140,"2.");
outtextxy(50,140,"For castling, just move the king two spaces away..");
outtextxy(30,160,"3.");
outtextxy(50,160,"The game ends when the king of either side is killed");
outtextxy(50,180,"by the opponent..");
outtextxy(30,200,"4.");
outtextxy(50,200,"To quit the game in the middle, keep pressing 'q'..");
outtextxy(50,250,"Thank You for playing our game!!");

settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);

outtextxy(30,300,"ENJOY THE GAME..!! :)");

settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
callmouse();
getch();
}//function ends


//this function displays which player wins...
void end(void)
{
 cleardevice1();     //clears the screen
  mousehide();
  setcolor(15);
  int  l = getmaxy() - 10;
  int  k = getmaxx() - 10;

    int fill_color = 6;

    for (;l>0;l-=10)
    {  delay(2);
    setfillstyle (SOLID_FILL,fill_color);
    circle (7,l,7);
    floodfill (5,l,15);
	delay(2);
    setfillstyle (SOLID_FILL,fill_color);
    circle (k,l,7);
    floodfill (k,l,15);
    }//for loop ends

    l = getmaxy() - 10;

    for (;k>0;k-=10)
    {  delay(2);
    setfillstyle (SOLID_FILL,fill_color);
    circle (k,7,7);
    floodfill (k,5,15);
	delay(2);
    setfillstyle (SOLID_FILL,fill_color);
    circle (k,l,7);
    floodfill (k,l,15);
    }//for loop ends

    settextstyle (SANS_SERIF_FONT, HORIZ_DIR, 4);

 if(w==0)
  {                              //if this block is true, player2 wins
   outtextxy(250,250,n2);
   settextstyle (DEFAULT_FONT, HORIZ_DIR, 2);
   outtextxy(250,280,"wins");
  }
 else if(b==0)
  {                              //if this block is true, player1 wins
   outtextxy(250,250,n1);
   outtextxy(250,280,"wins");
  } callmouse();
}//function ends

//this function accepts the name of the players
void name()
{
cleardevice1();     //clears the screen
setbkcolor(0);     //sets background color as black color
mousehide();
//accepting player 1's name
outtextxy(150,250,"Player 1, enter your name: (10 characters only)");
for (int i=0;i<10;i++)
{
 n1[i] = getch();
 if (n1[i]==13)
  {
   n1[i]=' ';
   break;
  }
 outtextxy(150,270,n1);
}//for loop ends

cleardevice1();     //clears the screen

//accepting player 2's name
outtextxy(150,250,"Player 2, enter your name: (10 characters only)");
for (i=0;i<10;i++)
{
 n2[i] = getch();
 if (n2[i]==13)
  {
   n2[i]=' ';
   break;
  }
 outtextxy(150,270,n2);
}//for loop ends
callmouse();
//converting names from small letters to capital letters
for (i=0;i<10;i++)
 {
  n1[i] = toupper(n1[i]);
  n2[i] = toupper(n2[i]);
 }//for loop ends

}//function ends

//this function displays 4 options.. it can start the game (or) call option
//function (or) display instructions (or) exit the game..
int start()
 {
    char ch[2];
    ch[0]=' ';
    ch[1]='\0';

  while (ch[0]!='1')
  {

    cleardevice1();     //clears the screen
    setbkcolor(0);     //sets background color as black color

    setcolor(15);      //sets text color as white
    mousehide();
    setfillstyle (SOLID_FILL,0);     //fills the background color
    floodfill(11,71,15);             //with black color

    outtextxy(200,40,"WELCOME TO AJ CHESS GAMES");

    outtextxy(100,100,"1.    PLAY GAME");
    outtextxy(100,130,"2.    CUSTOMIZE");
    outtextxy(100,160,"3.    INSTRUCTIONS");
    outtextxy(100,190,"4.    EXIT");
    outtextxy(100,210,"Enter your chioce : ");
     callmouse();
     ch[0]=getch();
    outtextxy(300,210,ch);
     getch();
   mousehide();
    if (ch[0]=='1')
     {

     }
     else if (ch[0]=='2')
     {
	outtextxy(200,40,"WELCOME TO AJ CHESS GAMES");

	//this function accepts the user's color combination of the board
	//and the characters
	option();
	cleardevice1();

     }
    else if (ch[0]=='3')
     {
	outtextxy(200,40,"WELCOME TO AJ CHESS GAMES");

	instructions();
     }
    else if (ch[0]=='4')
     return 0;

  } //while loop ends

    cleardevice1();     //clears the screen

    setfillstyle (SOLID_FILL,0);     //fills the background color
    floodfill(11,71,15);             //with black color

    setcolor(15);      //sets text color as white

    outtextxy(200,40,"WELCOME TO AJ CHESS GAMES");
   setcolor(4);
    line(10, 450, 620, 450);
    line(10, 470, 620,470 );
    line(10, 450, 10, 470);
    line(620, 450, 620, 470);

   for(int i=10;i<621;i++)
   {      setcolor(15);
    if (i%3==0)
     setcolor(4);
    delay(10);
    line(i, 450, i, 470);
   }//for loop ends

   outtextxy(240,420,"PRESS ANY KEY TO CONTINUE");
   callmouse();
   getch();
   return 1;
    }//function ends

//this function accpets the color combination of the board and
//characters from the user
void option(void) //apply mouse fn
{mousehide();
 setcolor(color);      //sets text color as grey

 line(10,70,630,70);
 line(630,70,630,380);
 line(630,380,10,380);
 line(10,380,10,70);

 setfillstyle (SOLID_FILL,0);        //fills the background color
 floodfill(11,71,color);             //with black color

   outtextxy(45,100,"Please select the color combination...");
   setcolor(color);    //sets text color as grey

   int j,i=120;

  outtextxy(30,135,"1.");
   j=50;
	rectangle(50,120,100,170);
	setfillstyle (SOLID_FILL,15);
	floodfill(51,121,color);

	setfillstyle (SOLID_FILL,color1);
	int t1[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,t1);
	rectangle(j+15,i+35,j+35,i+40);
	setfillstyle (SOLID_FILL,3);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);

   j=100;
	rectangle(100,120,150,170);
	setfillstyle (SOLID_FILL,1);
	floodfill(101,121,color);

	setfillstyle (SOLID_FILL,color1);
	int t2[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,t2);
	rectangle(j+15,i+35,j+35,i+40);
	setfillstyle (SOLID_FILL,0);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);

  outtextxy(180,135,"2.");
   j=200;
	rectangle(200,120,250,170);
	setfillstyle (SOLID_FILL,15);
	floodfill (201,121,color);

	setfillstyle (SOLID_FILL,color1);
	int t3[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle (j+25,i+10,5);
	rectangle (j+20,i+15,j+30,i+20);
	drawpoly (4,t3);
	rectangle (j+15,i+35,j+35,i+40);
	setfillstyle (SOLID_FILL,6);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);

   j=250;
	rectangle(250,120,300,170);
	setfillstyle (SOLID_FILL,4);
	floodfill (251,121,color);

	setfillstyle (SOLID_FILL,color1);
	int t4[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,t4);
	rectangle(j+15,i+35,j+35,i+40);
	setfillstyle (SOLID_FILL,0);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);

  outtextxy(330,135,"3.");
   j=350;
	rectangle(350,120,400,170);
	setfillstyle (SOLID_FILL,6);
	floodfill(351,121,color);

	setfillstyle (SOLID_FILL,color1);
	int t5[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,t5);
	rectangle(j+15,i+35,j+35,i+40);
	setfillstyle (SOLID_FILL,4);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);

   j=400;
	rectangle(400,120,450,170);
	setfillstyle (SOLID_FILL,7);
	floodfill(401,121,color);

	setfillstyle (SOLID_FILL,color1);
	int t6[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,t6);
	rectangle(j+15,i+35,j+35,i+40);
	setfillstyle (SOLID_FILL,0);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);

  outtextxy(480,135,"4.");
   j=500;
	rectangle(500,120,550,170);
	setfillstyle (SOLID_FILL,4);
	floodfill(501,121,color);

	setfillstyle (SOLID_FILL,color1);
	int t7[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,t7);
	rectangle(j+15,i+35,j+35,i+40);
	setfillstyle (SOLID_FILL,15);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);

   j=550;
	rectangle(550,120,600,170);
	setfillstyle (SOLID_FILL,0);
	floodfill(551,121,color);

	setfillstyle (SOLID_FILL,color1);
	int t8[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,t8);
	rectangle(j+15,i+35,j+35,i+40);
	setfillstyle (SOLID_FILL,1);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);


setcolor(15);
 char z[2];

Accept_option:

 outtextxy(45,350,"Choose your combination : ");
 z[0] = ' ';
 z[1] = '\0';
 z[0]=getch();
 outtextxy(260,350,z);
 getch();

 switch(z[0])
 {
 case '1': color3=15;
	   color4=1;
	   color1=3;
	   color2=0;
 break;
 case '2': color3=15;
	   color4=4;
	   color1=6;
	   color2=0;
 break;
 case '3': color3=7;
	   color4=6;
	   color1=4;
	   color2=0;
 break;
 case '4': color3=4;
	   color4=0;
	   color1=15;
	   color2=1;
 break;
 default:outtextxy(280,350,"(Invlaid move, select a valid option)");
 getch();

 setfillstyle (SOLID_FILL,0);        //fills the background color
 floodfill(11,71,color);             //with black color

 goto Accept_option;
 }//switch ends
callmouse();
}//function ends

//this function decides which player wins the game
int win(void)
{
  w=0;
  b=0;
  for(int i=0;i<8;i++)
  for(int j=0;j<8;j++)
  {
   if(n[i][j]==1)
    w++;
    if(n[i][j]==7)
    b++;
  }
 if(w==1&&b==1)
 return 1;
 return 0;
}//function ends

//this function gives a wish if the soldier of any side reaches the end of
//the board on the opposite side
void wish(int x,int y)
{
int w,i,j;
if ((n[x][y]==6&&x==7)||(n[x][y]==12&&x==0))
{
  mousehide();
 outtextxy(480,100,"Choose your character");
     outtextxy(480,110,"1 ----> Queen");
     outtextxy(480,120,"2 ----> Bishop");
     outtextxy(480,130,"3 ----> Horse");
     outtextxy(480,140,"4 ----> Elephant");
     callmouse();
     w=getch();
     w=w-49;
if(n[x][y]==6)
n[x][y]=w+2;
if(n[x][y]==12)
n[x][y]=w+8;

 }
}//function ends

//this function checks if castling move should be performed
int castling (int x1,int x2,int y1,int y2)
{
int mem;
mem = n[y1][x1];

if (y1!=y2 || (y1!=0 && y1!=7))
 return 0;

if (mem==7&&n[7][4]==7)
 {
  if (x2==x1-2&&n[7][0]==11)
   {
    if (n[7][1]==0&&n[7][2]==0&&n[7][3]==0)
     {   castling_value = 3;
	 return 3; }
   }
  else if (x2==x1+2&&n[7][7]==11)
   {
    if (n[7][5]==0&&n[7][6]==0)
     {   castling_value = 4;
	 return 4; }
   }
 }
else if (mem==1&&n[0][4]==1)
 {
  if (x2==x1-2&&n[0][0]==5)
   {
    if (n[0][1]==0&&n[0][2]==0&&n[0][3]==0)
     {   castling_value = 1;
	 return 1; }
   }
  else if (x2==x1+2&&n[0][7]==5)
   {
    if (n[0][5]==0&&n[0][6]==0)
     {   castling_value = 2;
	 return 2; }
   }
 }
else
return 0;
return 0;
}//function ends

//this function decides whether the move is valid or not
int valid(int x1,int x2,int y1,int y2)
{
 if(valid_move(x1,x2,y1,y2)&&valid_path(x1,x2,y1,y2))
  return 1;
 return 0;
}//function ends

//this function checks if any character obstructs the path
//of the character selected by the user
int valid_path(int x1,int x2,int y1,int y2)
{
 int i,j;
 //upward
 if(x1==x2&&y1>y2)
 {
 for(i=y1-1;i>y2;i--)
 {if(n[i][x2]!=0)
  return 0;}
  return 1;}

//downward
if(x1==x2&&y1<y2)
{for(i=y1+1;i<y2;i++)
{if(n[i][x2]!=0)
 return 0;}
return 1;}

//rightward
if(y1==y2&&x1>x2)
{for(i=x2+1;i<x1;i++)
{if(n[y1][i]!=0)
 return 0;}
return 1;}

//leftward
if(y1==y2&&x1<x2)
{for(i=x2-1;i>x1;i--)
{if(n[y1][i]!=0)
 return 0;}
return 1;}

//rightup
if(x2>x1&&y2<y1&&x2-x1==y1-y2)
{for(i=x1+1,j=y1-1;i<x2;i++,j--)
{if(n[j][i]!=0)
return 0;}
return 1;
}

//leftup
if(x2<x1&&y2<y1&&x1-x2==y1-y2)
{for(i=x2+1,j=y1-1;i<x1;i++,j--)
{if(n[j][i]!=0)
return 0;}
return 1;
}

//rightdown
if(x2>x1&&y2>y1&&x2-x1==y2-y1)
{for(i=x1+1,j=y1+1;i<x2;i++,j++)
{if(n[j][i]!=0)
return 0;}
return 1;
}

//leftdown
if(x1>x2&&y2>y1&&x1-x2==y2-y1)
{for(i=x1+1,j=y1+1;i<x1;i++,j++)
{if(n[j][i]!=0)
return 0;}
return 1;
}

return 1;
}//function ends

//this function checks for the validity of any move
int valid_move(int x1,int x2,int y1,int y2)
{
int mem1,mem2;
mem1=n[y1][x1];
mem2=n[y2][x2];

if((mem1==6||mem1==12)&&mem2!=0&&x1==x2)
return 0;
if(i%2==0&&mem1>6&&mem1<13)
return 0;
if(i%2!=0&&mem1<7&&mem1>0)
return 0;
if(mem2!=0)
if((mem1<7&&mem2<7&&mem1>0&&mem2>0)||(mem1>6&&mem2>6&&mem1<13&&mem2<13))
return 0;

switch(mem1)
{
case 1 :
case 7 : if ((x1==x2+1)||(y1==y2+1)||(x1==x2-1)||(y1==y2-1))
	  return 1;
	 return 0;
case 2 :
case 8 : if ((abs(x2-x1)==abs(y2-y1)) || (((x2==x1)&&(y2!=y1)) || ((y2==y1)&&(x2!=x1))))
	  return 1;
	 return 0;
case 3 :
case 9 : if ((abs(x2-x1)==abs(y2-y1)))
	  return 1;
	 return 0;
case 4 :
case 10 : if (((x2==x1+2||x2==x1-2)&&(y2==y1+1||y2==y1-1)) || ((y2==y1+2||y2==y1-2)&&(x2==x1+1||x2==x1-1)))
	   return 1;
	  return 0;
case 5 :
case 11 : if (((x2==x1)&&(y2!=y1)) || ((y2==y1)&&(x2!=x1)))
	  return 1;
	 return 0;
case 6 : if (((x2==x1&&(abs(y2-y1)==1)&&y2>y1)||(x1==x2)&&(y1==1&&y2==3))||((abs(x2-x1)==1)&&(abs(y2-y1)==1)&&(n[y2][x2]>6)&&y2>y1))
	  return 1;
	 return 0;
case 12 : if (x2==x1&&y2<y1&&(abs(y2-y1)==1)||(x1==x2)&&(y1==6&&y2==4)||((abs(x2-x1)==1)&&(abs(y2-y1)==1)&&(n[y2][x2]<7)&&y1>y2))
	   return 1;
	  return 0;
}//switch ends
return 0;
}//function ends

//this function performs castling
void move_castling(int x1,int x2,int y1,int y2)
{
  if (castling_value==1)
   {
    n[y2][x2]=1;
    n[0][3]=5;
    n[0][0]=0;
    n[y1][x1]=0;
   }
  else if (castling_value==2)
   {
    n[y2][x2]=1;
    n[0][5]=5;
    n[0][7]=0;
    n[y1][x1]=0;
   }
  else if (castling_value==3)
   {
    n[y2][x2]=7;
    n[7][3]=11;
    n[7][0]=0;
    n[y1][x1]=0;
   }
  else if (castling_value==4)
   {
    n[y2][x2]=7;
    n[7][5]=11;
    n[7][7]=0;
    n[y1][x1]=0;
   }
}//function ends

//this function moves the character selected by the user
//from one position to another valid position
void move(int x1,int x2,int y1,int y2)
{
if(valid(x1,x2,y1,y2))
{
n[y2][x2]=n[y1][x1];
n[y1][x1]=0;
}

else
outtextxy(480,70,"INVALID MOVE");

wish(y2,x2);
}//function ends

//this function displays the coordinates of the board
void disp_cordinate(void)
{ mousehide();
 if(count==0)
  delay(100);
outtextxy(75,40,"1");
 if(count==0)
  delay(100);
outtextxy(125,40,"2");
 if(count==0)
  delay(100);
outtextxy(175,40,"3");
 if(count==0)
  delay(100);
outtextxy(225,40,"4");
 if(count==0)
  delay(100);
outtextxy(275,40,"5");
 if(count==0)
  delay(100);
outtextxy(325,40,"6");
 if(count==0)
  delay(100);
outtextxy(375,40,"7");
 if(count==0)
  delay(100);
outtextxy(425,40,"8");
 if(count==0)
  delay(100);
outtextxy(40,75,"a");
 if(count==0)
  delay(100);
outtextxy(40,125,"b");
 if(count==0)
  delay(100);
outtextxy(40,175,"c");
 if(count==0)
  delay(100);
outtextxy(40,225,"d");
 if(count==0)
  delay(100);
outtextxy(40,275,"e");
 if(count==0)
  delay(100);
outtextxy(40,325,"f");
 if(count==0)
  delay(100);
outtextxy(40,375,"g");
 if(count==0)
  delay(100);
outtextxy(40,425,"h");
callmouse();
}//function ends

//this function displays the color combination of the board
//which is according to the user's specification
void disp_board(void)
{
int i,j,m=1,n;
mousehide();
for (i=50;i<=450;i+=50)
 {
  if(count==0)
   delay(100);
  line (50,i,450,i);
  if(count==0)
   delay(100);
  line (i,50,i,450);
 }//for loop ends

for (i=51;i<=450;i+=50,m++)
{
 n=1;
 for (j=51;j<=450;j+=50,n++)
  if((m+n)%2==0)
   {
    setfillstyle (SOLID_FILL, color3);
    if(count==0)
     delay(100);
    floodfill (i,j,color);
   }
   else
   {
    if(count==0)
     delay(100);
    setfillstyle (SOLID_FILL, color4);
    floodfill (i,j,color);
   }
}//for loop ends
rectangle(470,400,570,450);
settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
outtextxy(475,420,"EXIT");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
callmouse();
}//function ends

//this function displays the characters on the board
void disp_board_char()
{ mousehide();
int i,j,k,l;
for(i=50,k=0;i<450;i+=50,k++)
{
 for (j=50,l=0;j<450;j+=50,l++)
 {
  switch(n[k][l])
  {

   case 1 :// white king
	setfillstyle (SOLID_FILL,color1);
	int crs[26]={j+20,i+8,j+30,i+8,j+27,i+4,j+35,i+6,j+35,i+2,j+27,i+4,j+30,i,j+20,i,j+23,i+4,j+15,i+2,j+15,i+6,j+23,i+4,j+20,i+8};
	drawpoly(13,crs);
	int reck[10]={j+15,i+8,j+35,i+8,j+33,i+17,j+17,i+17,j+15,i+8};
	drawpoly(5,reck);
	line(j+20,i+17,j+15,i+37);
	line(j+30,i+17,j+35,i+37);
	rectangle(j+11,i+37,j+39,i+45);

	fillpoly(13, crs);
	floodfill (j+25,i+11,color);
	floodfill (j+21,i+18,color);
	floodfill (j+12,i+38,color);
   break;

   case 2 :// white queen
	setfillstyle (SOLID_FILL,color1);
	ellipse(j+25,i+5,0,360,2,2);
	int tria1[8]={j+18,i+2,j+21,i+8,j+15,i+8,j+18,i+2};
	drawpoly(4,tria1);
	int tria2[8]={j+32,i+2,j+29,i+8,j+35,i+8,j+32,i+2};
	drawpoly(4,tria2);
	int rec[10]={j+15,i+8,j+35,i+8,j+33,i+17,j+17,i+17,j+15,i+8};
	drawpoly(5,rec);
	line(j+20,i+17,j+15,i+37);
	line(j+30,i+17,j+35,i+37);
	rectangle(j+11,i+37,j+39,i+45);

	floodfill (j+25,i+5,color);
	floodfill (j+18,i+3,color);
	floodfill (j+32,i+3,color);
	floodfill (j+25,i+11,color);
	floodfill (j+21,i+18,color);
	floodfill (j+12,i+38,color);

   break;

   case 3 ://white bishop
	setfillstyle (SOLID_FILL,color1);
	ellipse(j+25,i+12,140,430,5,8);
	rectangle(j+20,i+20,j+30,i+25);
	line(j+22,i+25,j+18,i+40);
	line(j+28,i+25,j+32,i+40);
	line(j+25,i+12,j+27,i+5);
	line(j+25,i+12,j+22,i+6);
	rectangle(j+15,i+40,j+35,i+45);

	floodfill (j+25,i+12,color);
	floodfill (j+21,i+23,color);
	floodfill (j+23,i+28,color);
	floodfill (j+25,i+13,color);
	floodfill (j+16,i+43,color);

   break;

   case 4 ://white horse
       setfillstyle (SOLID_FILL,color1);
       ellipse(j+21,i+10,340,640,10,5);
       line(j+22,i+15,j+19,i+38);
       line(j+31,i+13,j+36,i+38);
       rectangle(j+15,i+38,j+39,i+45);

       putpixel(j+18,i+10,color);
       floodfill (j+21,i+10,color);
       floodfill (j+16,i+41,color);
   break;

   case 5 :// white elephant
	setfillstyle (SOLID_FILL,color1);
	rectangle(j+13,i+5,j+37,i+15);
	line(j+20,i+15,j+20,i+35);
	line(j+30,i+15,j+30,i+35);
	rectangle(j+13,i+35,j+37,i+45);

	floodfill (j+14,i+6,color);
	floodfill (j+21,i+16,color);
	floodfill (j+14,i+36,color);

   break;

   case 6 :// white soldier
	setfillstyle (SOLID_FILL,color1);
	int tri[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,tri);
	rectangle(j+15,i+35,j+35,i+40);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);

   break;

   case 7 :// black king
	setfillstyle (SOLID_FILL,color2);
	int crs1[26]={j+20,i+8,j+30,i+8,j+27,i+4,j+35,i+6,j+35,i+2,j+27,i+4,j+30,i,j+20,i,j+23,i+4,j+15,i+2,j+15,i+6,j+23,i+4,j+20,i+8};
	drawpoly(13,crs1);
	int reck1[10]={j+15,i+8,j+35,i+8,j+33,i+17,j+17,i+17,j+15,i+8};
	drawpoly(5,reck1);
	line(j+20,i+17,j+15,i+37);
	line(j+30,i+17,j+35,i+37);
	rectangle(j+11,i+37,j+39,i+45);

	fillpoly(13, crs1);
	floodfill (j+25,i+11,color);
	floodfill (j+21,i+18,color);
	floodfill (j+12,i+38,color);
   break;

   case 8 ://black queen
	setfillstyle (SOLID_FILL,color2);
	ellipse(j+25,i+5,0,360,2,2);
	int tria3[8]={j+18,i+2,j+21,i+8,j+15,i+8,j+18,i+2};
	drawpoly(4,tria3);
	int tria4[8]={j+32,i+2,j+29,i+8,j+35,i+8,j+32,i+2};
	drawpoly(4,tria4);
	int rec1[10]={j+15,i+8,j+35,i+8,j+33,i+17,j+17,i+17,j+15,i+8};
	drawpoly(5,rec1);
	line(j+20,i+17,j+15,i+37);
	line(j+30,i+17,j+35,i+37);
	rectangle(j+11,i+37,j+39,i+45);

	floodfill (j+25,i+5,color);
	floodfill (j+18,i+3,color);
	floodfill (j+32,i+3,color);
	floodfill (j+25,i+11,color);
	floodfill (j+21,i+18,color);
	floodfill (j+12,i+38,color);

   break;

   case 9 ://black bishop
	setfillstyle (SOLID_FILL,color2);
	ellipse(j+25,i+12,140,430,5,8);
	rectangle(j+20,i+20,j+30,i+25);
	line(j+22,i+25,j+18,i+40);
	line(j+28,i+25,j+32,i+40);
	line(j+25,i+12,j+27,i+5);
	line(j+25,i+12,j+22,i+6);
	rectangle(j+15,i+40,j+35,i+45);

	floodfill (j+25,i+12,color);
	floodfill (j+21,i+23,color);
	floodfill (j+23,i+28,color);
	floodfill (j+25,i+13,color);
	floodfill (j+16,i+43,color);

   break;

   case 10 ://black horse
	setfillstyle (SOLID_FILL,color2);
	ellipse(j+21,i+10,340,640,10,5);
	line(j+22,i+15,j+19,i+38);
	line(j+31,i+13,j+36,i+38);
	rectangle(j+15,i+38,j+39,i+45);

	putpixel(j+18,i+10,color);
	floodfill (j+21,i+10,color);
	floodfill (j+16,i+41,color);
   break;

   case 11 :// black elephant
	setfillstyle (SOLID_FILL,color2);
	rectangle(j+13,i+5,j+37,i+15);
	line(j+20,i+15,j+20,i+35);
	line(j+30,i+15,j+30,i+35);
	rectangle(j+13,i+35,j+37,i+45);

	floodfill (j+14,i+6,color);
	floodfill (j+21,i+16,color);
	floodfill (j+14,i+36,color);

   break;

   case 12 :// black soldier
	setfillstyle (SOLID_FILL,color2);
	int tri1[8]={j+25,i+20,j+30,i+35,j+20,i+35,j+25,i+20};
	circle(j+25,i+10,5);
	rectangle(j+20,i+15,j+30,i+20);
	drawpoly(4,tri1);
	rectangle(j+15,i+35,j+35,i+40);

	floodfill (j+26,i+11,color);
	floodfill (j+21,i+16,color);
	floodfill (j+25,i+30,color);
	floodfill (j+16,i+36,color);
   break;
 }//switch ends
 }//inner for loop ends
}//outer for loop ends
callmouse();
}//function ends

//this function assigns values to the board (or) in other words
//initialises the characters
void in_board()
{
for (int i=0;i<8;i++)
{
 for (int j=0;j<8;j++)
 {
 if (i==0  && (j==0 || j==7))
    n[i][j] = 5;
 else if (i==0  && (j==1 || j==6))
    n[i][j] = 4;
 else if (i==0  && (j==2 || j==5))
    n[i][j] = 3;
 else if (i==0  && j==3)
    n[i][j] = 2;
 else if (i==0  && j==4)
    n[i][j] = 1;
 else if (i==1)
    n[i][j] = 6;
 if (i==7  && (j==0 || j==7))
    n[i][j] = 11;
 else if (i==7  && (j==1 || j==6))
    n[i][j] = 10;
 else if (i==7  && (j==2 || j==5))
    n[i][j] = 9;
 else if (i==7  && j==3)
    n[i][j] = 8;
 else if (i==7  && j==4)
    n[i][j] = 7;
 else if (i==6)
    n[i][j] = 12;
 else if(i>1&&i<6)
   n[i][j]=0;
 }//inner for loop ends
}//outer for loop ends
}//function ends

//this function displays board, characters and coordinates
void board()
{
disp_board();
disp_board_char();
disp_cordinate();
}//function ends

char selection()
{
char c;
c=' ';
int x,y,cl;
mouseposi(x,y,cl);
if(x>50&&y>50&&x<450&&y<450)
 {
 if(x<100)
 {c='1';}
 else if(x<150)
 {c='2';}
 else if(x<200)
 {c='3';}
 else if(x<250)
 {c='4';}
 else if(x<300)
 {c='5';}
 else if(x<350)
 {c='6';}
 else if(x<400)
 {c='7';}
 else if(x<450)
 {c='8';}
}
return c;
}

char selection1()
{
char c;
c=' ';
int x,y,cl;
mouseposi(x,y,cl);
if(x>50&&y>50&&x<450&&y<450)
 {
 if(y<100)
 {c='a';}
 else if(y<150)
 {c='b';}
 else if(y<200)
 {c='c';}
 else if(y<250)
 {c='d';}
 else if(y<300)
 {c='e';}
 else if(y<350)
 {c='f';}
 else if(y<400)
 {c='g';}
 else if(y<450)
 {c='h';}
}
return c;
}

/*int between(int x1,int y1,int x2,int y2,int x,int y)
{
if(x>x1&&x<x2&&y>y1&&y<y2)
return 1;
return 0;
}*/
