void cleardevice1();
void paint();
void disico(int);
void disnam(int);
void cle();
int totpg,pg=0;
void note(char []);
int scan(int,int);
int between(int,int,int,int,int,int);
int nofile(char []);
void backgroundfb();
void bcg();
void pntico(int,int);
void noteico(int,int);
void bcgr();
int fbi(char []);
int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);

void fb()
{ cleardevice1();
  bcg();
  callmouse();
  int x,y,cl,t;
 while(1)
 {
  mouseposi(x,y,cl);
  if(between(mx-35,17,mx-17,33,x,y)&&cl==1)
  return;
  else if(between(160,300,340,400,x,y)&&cl==1)
  {t=fbi("notelist");cleardevice1();
  if(t==-2)
  return;
  bcg();
  }
  else if(between(390,300,570,400,x,y)&&cl==1)
  {t=fbi("pntlist");cleardevice1();
  if(t==-2)
  return;
  bcg();
  }
 }

}
char flst[9];
int fbi(char flst1[9])
{strcpy(flst,flst1);
cleardevice1();
  backgroundfb();
  callmouse();
  int x,y,cl,no;
  no=nofile(flst);
  totpg=no/15;
  mouseposi(x,y,cl);
  int n=0,i,j;
  disico(no);
  disnam(no);
  ifstream fin;
  char str[9];
  int sel=0;
  while(1)
  {sel=0;
  mouseposi(x,y,cl);
  if(between(mx-35,17,mx-17,33,x,y)&&cl==1)
  return -2;
  if(cl==1)
  sel=scan(x,y);
  if(sel==-2)
  return -2;
  if(!sel==0)
  break;
  }
  if(sel==-1)
  return 0;
  if(!sel==0)
  {n=0;
  fin.open(flst,ios::binary);
  while(!fin.eof())
  {n++;
  fin>>str;
  if(!fin)
  break;
  if(n==sel)
  break;
  }
  fin.close();
  cleardevice1();
  if(!strcmp(flst,"notelist"))
  note(str);
  else
  paint(str);
  }
 return 0;
}

void backgroundfb()
{   setcolor(3);
    bcgr();
    mousehide();
    outtextxy(80,22,"FILE BROWSER");
    //back
    rectangle(20,100,95,125);
    outtextxy(23,110,"<-- BACK");
    //pg up and down
    rectangle(20,140,95,165);
    outtextxy(22,150,"^ PG UP");
    rectangle(20,170,95,195);
    outtextxy(22,180,"v PG DOWN");
    callmouse();
    }
void noteico(int x,int y)
{ mousehide();
  rectangle(x,y,x+62,y+80);
  int nt[12]={x+5,y+10,x+5,y+70,x+55,y+70,x+55,y+28,x+42,y+10,x+5,y+10};
  drawpoly(6,nt);
  line(x+42,y+10,x+37,y+28);
  line(x+55,y+28,x+37,y+28);
  line(x+10,y+20,x+27,y+20);
  line(x+10,y+25,x+27,y+25);
  line(x+10,y+30,x+27,y+30);
  line(x+10,y+35,x+47,y+35);
  line(x+10,y+35,x+47,y+35);
  line(x+10,y+45,x+47,y+45);
  line(x+10,y+55,x+47,y+55);
  line(x+10,y+65,x+47,y+65);
callmouse();
}

int nofile(char file[9])
{
char str[10];
int ret=0;
ifstream fin;
fin.open(file,ios::binary);
while(!fin.eof())
{fin>>str;
if(!fin)
break;
ret++;
}
fin.close();
return ret;
}

int scan(int x,int y)
{
  int n=0,i,j,mx=getmaxx(),my=getmaxy(),no;
  no=nofile(flst);
  for(j=90;j<my-100;j+=120)
  {
  if(n>=no)
  break;
  for(i=120;i<mx-100;i+=100)
  {
  n++;
  if(between(i,j,i+62,j+80,x,y))
  {return n+(pg*15);}
  if(n>=no)
  break;
  }
  }
  if(between(20,100,95,125,x,y))
  {return -1;}
  if(between(20,140,95,165,x,y))
  {if(!pg==0)
  {pg--;cle();disico(nofile(flst));disnam(nofile(flst));}
  }
  if(between(20,170,95,195,x,y))
  {if(pg<totpg)
  {pg++;cle();disico(nofile(flst));disnam(nofile(flst));}
  }
  if(between(mx-35,17,mx-17,33,x,y))
  return -2;

return 0;
}

void disico(int no)
{ int n=0,i,j;
  int mx=getmaxx(),my=getmaxy();
  for(j=90;j<my-100;j+=120)
  {if(n>=no)
  break;
  for(i=120;i<mx-100;i+=100)
  {
  if(n>=pg*15)
  {if(!strcmp(flst,"notelist"))
  noteico(i,j);
  else
  pntico(i,j);
  n++;
  if(n>=no)
  break;
  if(n==pg*15)
  {j=90;i=20;}
  }
  } }
}

void cle()
{
setcolor(0);
for(int t=115;t<getmaxx()-25;t++)
line(t,55,t,getmaxy()-51);
setcolor(3);
}

void disnam(int no)
{
  ifstream fin;
  fin.open(flst);
  char str[9];
  int i=120,j=180,n=0;
  while(!fin.eof())
  {
  fin>>str;
  if(!fin)
  break;
  if(n>=pg*15)
  outtextxy(i,j,str);
  i+=100;
  if(i>getmaxx()-100)
  {i=120;j+=120;}n++;
  if(n>=no)
  break;
  if(n==pg*15)
  {j=180;i=120;}
  }
  fin.close();
}

void pntico(int x,int y)
{ mousehide();
  rectangle(x,y,x+62,y+80);
  int nt[12]={x+5,y+10,x+5,y+70,x+55,y+70,x+55,y+28,x+42,y+10,x+5,y+10};
  drawpoly(6,nt);
  circle(x+36,y+23,7);
  line(x+8,y+70,x+20,y+45);
  line(x+20,y+45,x+32,y+70);
  line(x+32,y+70,x+44,y+45);
  line(x+44,y+45,x+54,y+70);
 callmouse();
 }

 void bcg()
 {
 cleardevice1();
  mousehide();
  backgroundfb();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
  outtextxy(120,70,"FILE BROWSER");
  outtextxy(270,130,"CLU");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  rectangle(160,300,340,400);
  outtextxy(210,335,"Note");
  rectangle(390,300,570,400);
  outtextxy(440,330,"Paint");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  callmouse();
 }