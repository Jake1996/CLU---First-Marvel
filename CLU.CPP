#include <math.h>
#include <alloc.h>
#include <string.h>
#include <fstream.h>
#include <process.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <ctype.h>

int logoff;
char name1[20];

#include "mail.cpp"
#include "cp.cpp"
#include "game.cpp"
#include "note.cpp"
#include "calcu.cpp"
#include "paint.cpp"
#include "chat.cpp"
#include "ext.cpp"
#include "cluload.cpp"
#include "app.cpp"
#include "filebrw.cpp"
#include "archery.cpp"
#include "chess.cpp"
int chess();
int arch();
void chat(char []);
void note(char []);
void paint(char []);
void calcu();
void fb();
void app();
void cleardevice1();
void game();
void mailmain(char []);
void cp();
void ext();
void load();
void backgroundmain();
void backgroundlg();
int between(int,int,int,int,int,int);
void gettxt(int,int,int,char[]);
void gettxt1(int,int,int,char[]);
int check(char [],char []);
void bcgr();
union REGS in,out;
struct SREGS s;
int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);
      void changecursor(int *);

account a;
 int cursor[32]={
 0xffff, 0xffff, 0xffff, 0xffff,
 0xffff, 0xffff, 0xffff, 0xffff,
 0xffff, 0xffff, 0xffff, 0xffff,
 0xffff, 0xffff, 0xffff, 0xffff,
 0xff00, 0xff80, 0xc1c0, 0xdc60,
 0xd030, 0xd218, 0xde0c, 0xe256,
 0x63d5, 0x3055, 0x1877, 0x0c06,
 0x060c, 0x03f8, 0x01b0, 0x00e0
  };
       int callmouse()
       {      in.x.ax=1;
	      int86(51,&in,&out);
	      changecursor(cursor);
	      return 1;
       }
       void mouseposi(int &xpos,int &ypos,int &click)
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      click=out.x.bx;
	      xpos=out.x.cx;
	      ypos=out.x.dx;
	}
	void restrictmouseptr(int x1,int y1,int x2,int y2)
	{
		 in.x.ax=7;
		 in.x.cx=x1;
		 in.x.dx=x2;
		 int86(51,&in,&out);
		 in.x.ax=8;
		 in.x.cx=y1;
		 in.x.dx=y2;
		 int86(51,&in,&out);
	}
       int mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);
	      return 1;
       }
      void setposi(int &xpos,int &ypos)
      {
	     in.x.ax=4;
	     in.x.cx=xpos;
	     in.x.dx=ypos;
	     int86(51,&in,&out);
}
   void  changecursor(int *shape)
    {
    in.x.ax=9;
    in.x.bx=0;
    in.x.cx=0;
    in.x.dx=(unsigned)shape;
    segread(&s);
    s.es=s.ds;
    int86(0x33,&in,&in);
    }


void main()
{
    /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
load();
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
system("md CLU");
system("cd CLU");
   int x,y,cl,mx=getmaxx(),my=getmaxy(),check1;
   char string[16],id1[9],pass[32];

   cleardevice1();
   restrictmouseptr(10,10,mx-10,my-10);
   setcolor(3);
   callmouse();
   X:
   cleardevice1();
   mousehide();
   backgroundlg();
   callmouse();
  while(1)
  {
   mouseposi(x,y,cl);

   if (between(mx/2-35,my/2+85,mx/2+35,my/2+105,x,y) && cl==1)
   {
     cleardevice1();
     mousehide();
     backgroundmail();
     callmouse();
     a.getdata(120,60);
     ofstream fout1,fout2,fout3;
     fout1.open("idpass",ios::app|ios::binary);
     fout2.open("accounts",ios::app|ios::binary);
     fout1<<a.getid();
     fout1<<" ";
     fout1<<a.getpassword();
     fout1<<endl;
     fout2.write((char*)&a,sizeof(a));
     fout1.close();
     fout2.close();

     strcat(str1,a.getid());
     system(str1);
     strcpy(str1,"cd ");
     fout3.open("profile",ios::binary);
     fout3.write((char*)&a,sizeof(a));
     fout3.close();
     system("cd ..");
     goto X;
   }
   else if(between(mx/2-13,my-40,mx/2+13,my-14,x,y) && cl==1)
   {
    system("cd ..");
    mousehide();
    ext();
    exit(0);
   }
   else if (between(mx/2-150,my/2+12,mx/2+150,my/2+36,x,y) && cl==1)
   {
    gettxt(mx/2-145,my/2+20,8,id1);
    gettxt1(mx/2-145,my/2+50,32,pass);

    check1 = check(pass,id1);
    if (check1==0)
    { goto X; }
    else
    {
      strcat(str1,id1);
      system(str1);
      strcpy(str1,"cd ");
      strcpy(name1,id1);
      break;
    }
   }

  }
  cleardevice1();
  mousehide();
  backgroundmain();

    for(int i=0;i<15;i++)
    string[i]=' ';
    string[i]='\0';
    i=0;
    char ch[3]={"  "};
    callmouse();
    mouseposi(x,y,cl);
    changecursor(cursor);

    while(1)
    {
    mouseposi(x,y,cl);
     //apps
    if(between(130,190,280,290,x,y)&&cl==1)
    {app(); cleardevice1();backgroundmain(); callmouse();}
    //Game box
    if(between(130,310,260,410,x,y)&&cl==1)
    {game(); cleardevice1();backgroundmain(); callmouse();}
    //Mail
    if(between(410,310,mx-40,my-70,x,y)&&cl==1)
    {mailmain(id1); cleardevice1();backgroundmain(); callmouse();}
    //File browser
    if(between(130,70,280,170,x,y)&&cl==1)
    {fb(); cleardevice1();backgroundmain(); callmouse();}
    //CP
    if(between(270,310,400,my-70,x,y)&&cl==1)
    {
     logoff=1;
     cp(id1);
     if (logoff==0)
      goto X;
     cleardevice1(); backgroundmain(); callmouse();
    }
    //Turn off
    if(between(25,my-40,51,my-14,x,y)&&cl==1)
    { system("cd .."); system("cd ..");mousehide();ext(); exit(0);}

    if(kbhit())
    {
    ch[0]=getch();
    if(ch[0]==13)
     {
	if(!strcmp(string,"app"))
	{app(); cleardevice1();backgroundmain(); callmouse();}
	if(!strcmp(string,"game"))
	{game(); cleardevice1();backgroundmain(); callmouse();}
	if(!strcmp(string,"chess"))
	{chess(); cleardevice1();backgroundmain(); callmouse();}
	if(!strcmp(string,"archery"))
	{arch(); cleardevice1();backgroundmain(); callmouse();}
	if(!strcmp(string,"chat"))
	{system("cd..");
chat(name1); cleardevice1();backgroundmain(); callmouse();
         strcat(str1,name1);  system(str1);  strcpy(str1,"cd ");}
	if(!strcmp(string,"note"))
	{note("reserved"); cleardevice1();backgroundmain(); callmouse();}
	if(!strcmp(string,"scratch"))
	{paint("reserved"); cleardevice1();backgroundmain(); callmouse();}
	if(!strcmp(string,"mail"))
	{mailmain(id1); cleardevice1();backgroundmain(); callmouse();}
	if(!strcmp(string,"calculator"))
	{calcu(); cleardevice1();backgroundmain(); callmouse();}
	if(!strcmp(string,"filebrowser"))
	{fb(); cleardevice1();backgroundmain(); callmouse();}
    }
    if(ch[0]>=33&&ch[0]<=122&&i<14)
    {string[i]=ch[0];i++;}
    else if(ch[0]==8&&!i==0)
     {string[i-1]='\0';i--;
     setcolor(0);
     mousehide();
     for(int j=0;j<=20;j++)
     line(318+7*i+j,98,318+7*i+j,108);
     setcolor(3);
     callmouse();
    }
    string[i]='\0';
    mousehide();
    outtextxy(320,98,string);
    callmouse();
    }
    }
}

 void backgroundmain()
 {
  int mx=getmaxx(),my=getmaxy();
  bcgr();
  mousehide();
  outtextxy(80,22,name1);
    //file browser
    rectangle(130,70,280,170);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    outtextxy(150,80,"FILE BROWSER");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
    outtextxy(150,100,"Fb");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    //Game box
    rectangle(130,310,260,410);
    outtextxy(150,320,"GAME BOX");
    int k=140,l=340,color2=3,color21=11;
    setfillstyle (SOLID_FILL,color21);
    int crs[26]={k+20,l+8,k+30,l+8,k+27,l+4,k+35,l+6,k+35,l+2,k+27,l+4,k+30,l,k+20,l,k+23,l+4,k+15,l+2,k+15,l+6,k+23,l+4,k+20,l+8};
    drawpoly(13,crs);
    int reck[10]={k+15,l+8,k+35,l+8,k+33,l+17,k+17,l+17,k+15,l+8};
    drawpoly(5,reck);
    line(k+20,l+17,k+15,l+37);
    line(k+30,l+17,k+35,l+37);
    rectangle(k+11,l+37,k+39,l+45);
    fillpoly(13, crs);
    floodfill (k+25,l+11,color2);
    floodfill (k+21,l+18,color2);
    floodfill (k+12,l+38,color2);
    //queen
    k=190;l=340;
    setfillstyle (SOLID_FILL,color21);
    ellipse(k+25,l+5,0,360,2,2);
    int tria1[8]={k+18,l+2,k+21,l+8,k+15,l+8,k+18,l+2};
    drawpoly(4,tria1);
    int tria2[8]={k+32,l+2,k+29,l+8,k+35,l+8,k+32,l+2};
    drawpoly(4,tria2);
    int rec[10]={k+15,l+8,k+35,l+8,k+33,l+17,k+17,l+17,k+15,l+8};
    drawpoly(5,rec);
    line(k+20,l+17,k+15,l+37);
    line(k+30,l+17,k+35,l+37);
    rectangle(k+11,l+37,k+39,l+45);
    floodfill (k+25,l+5,color2);
    floodfill (k+18,l+3,color2);
    floodfill (k+32,l+3,color2);
    floodfill (k+25,l+11,color2);
    floodfill (k+21,l+18,color2);
    floodfill (k+12,l+38,color2);
    outtextxy(155,395,">>-------->");
    //cp
    rectangle(270,310,400,my-70);
    outtextxy(290,320,"CONTROL PANEL");
    int wrn[22]={285,350,310,337,330,347,390,347,390,373,330,373,310,383,285,370,310,370,310,350,285,350};
    drawpoly(11,wrn);
    circle(380,360,5);
    //apps
    rectangle(130,190,280,290);
    rectangle(160,225,250,285);
    arc(205,230,350,190,25);
    arc(205,230,355,188,27);
    circle(231,234,4);
    circle(179,234,4);
    outtextxy(185,250,"APPS");
    //mail
    rectangle(410,310,mx-40,my-70);
    outtextxy(430,320,"MAIL");
    rectangle(450,330,mx-80,my-90);
    line(450,330,mx-80,my-90);
    line(450,my-90,mx-80,330);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy((mx+370)/2-12,(my+240)/2-10,"");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    //search box
    rectangle(310,80,mx-40,120);
    rectangle(315,90,530,110);
    rectangle(535,85,mx-45,115);
    outtextxy(540,98,"SEARCH");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,7);
    outtextxy(mx-320,150,"CLU");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    outtextxy(mx-320,210,"A SYSTEM THAT RUNS BEHIND PERFECTION");
    outtextxy(mx-320,230,"Developed by 'GODS OF OLYMPUS':");
    outtextxy(mx-320,240,"-ARJUN SHARMA");
    outtextxy(mx-320,250,"-JATIN PM");
    outtextxy(mx-320,260,"-SHUBH MEHTA");
    callmouse();
}
int between(int x1,int y1,int x2,int y2,int x,int y)
{
if(x>x1&&x<x2&&y>y1&&y<y2)
return 1;
return 0;
}
void backgroundlg()
{
 int mx=getmaxx(),my=getmaxy();
   mousehide();
   rectangle(mx/2-98,my/2-158,mx/2+98,my/2+3);   //frame box
   rectangle(mx/2-95,my/2-155,mx/2+95,my/2);     //picture box
   rectangle(mx/2-150,my/2+12,mx/2+150,my/2+36); //id box
   rectangle(mx/2-150,my/2+42,mx/2+150,my/2+66); //password box
   rectangle(mx/2-35,my/2+85,mx/2+35,my/2+105);   //signup box
   outtextxy(mx/2-28,my/2+90,"SIGN UP");
   outtextxy(mx/2-230,my/2+20,"ID       :");
   outtextxy(mx/2-230,my/2+50,"PASSWORD :");
   //pic
   arc (mx/2,my/2,0,180,55);
   circle(mx/2,my/2-85,30);
    setfillstyle(SOLID_FILL,8);
    floodfill(mx/2,my/2-1,3);
    floodfill(mx/2,my/2-105,3);
      //shutdown
     arc(mx/2, my-27, 150,390, 7);
     line(mx/2,my-35,mx/2,my-29);
     circle(mx/2,my-27,13);
callmouse();
}

void gettxt(int x,int y,int lim,char string[])
{
char ch[3]={" "};
string[0]='\0';
int i=0;
while(i<lim)
{
ch[0]=getch();
if(ch[0]==13)
break;
if(ch[0]>=33&&ch[0]<=122)
{string[i]=ch[0];i++;string[i]='\0';}
else if(ch[0]==8&&!i==0)
{string[i-1]='\0';i--;
setcolor(0);
mousehide();
for(int j=0;j<=20;j++)
line(x-2+7*i+j,y,x-2+7*i+j,y+9);
setcolor(3);
callmouse();
}
mousehide();
outtextxy(x,y,string);
callmouse();
}string[i]='\0';
// mousehide();
outtextxy(x,y,string);
// callmouse();
}

void gettxt1(int x,int y,int lim,char string[])
{
char ch[3]={" "},pass[32];
string[0]='\0';
int i=0;
while(i<lim)
{
ch[0]=getch();
if(ch[0]==13)
break;
if(ch[0]>=33&&ch[0]<=122)
{string[i]=ch[0];pass[i]='*';pass[i+1]='\0';i++;}
else if(ch[0]==8&&!i==0)
{string[i-1]='\0';pass[i-1]='\0';i--;
setcolor(0);
 mousehide();
for(int j=0;j<=20;j++)
line(x-2+7*i+j,y,x-2+7*i+j,y+9);
setcolor(3);
callmouse();
}
mousehide();
outtextxy(x,y,pass);
callmouse();
}string[i]='\0';
// mousehide();
outtextxy(x,y,pass);
// callmouse();
}

int check(char pass[],char id1[])
{
 char id[9],password[32];
 ifstream fin;
 fin.open("idpass",ios::binary);
 while(!fin.eof())
 {
  fin.getline(id,9,' ');
  fin.getline(password,32,'\n');
  if (!fin)
   break;
  if ( strcmp(pass,password)==0 && strcmp(id1,id)==0 )
  { fin.close();
    return 1;     }
 }
 fin.close();

 return 0;
}

void bcgr()
{   mousehide();
    setcolor(3);
    int mx=getmaxx(),my=getmaxy();
    rectangle(10,10,mx-10,my-10);  //outer box
    rectangle(15,45,100,my-45);    //option box
    rectangle(70,15,mx-15,35);     //upper rectangle
    rectangle(70,my-15,mx-15,my-35);//lower rectangle
    rectangle(110,50,mx-20,my-50);  //workspace
    setfillstyle(SOLID_FILL,11);
    floodfill(11,11,3);
     //logo
     setcolor(0);
     arc(39, 27, 90, 290, 10);
     arc(39, 27, 140, 290, 7);
     arc(39, 27, 130, 410, 4);
     circle(39,27,14);
     setcolor(3);
     //shutdown
     setcolor(0);
     arc(38, my-27, 150,390, 7);
     line(38,my-35,38,my-29);
     circle(38,my-27,13);
     setcolor(3);
     //close button
     rectangle(mx-35,17,mx-17,33);
     rectangle(mx-34,18,mx-18,32);
     outtextxy(mx-29,22,"X");
     callmouse();
}

void cleardevice1()
{
mousehide();
cleardevice();
callmouse();
}