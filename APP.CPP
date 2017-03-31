void cleardevice1();
void bcgr();
void calcu();
void chat(char []);
void note(char []);
void paint(char []);
int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);
int between(int,int,int,int,int,int);
void backgroundapp();
void app()
{
cleardevice1();
int x,y,cl;
setcolor(3);
backgroundapp();
callmouse();
mouseposi(x,y,cl);
  while(1)
 {
 mouseposi(x,y,cl);
  if(between(mx-35,17,mx-17,33,x,y)&&cl==1)
  { break; }
  else if(between(130,210,270,310,x,y)&&cl==1)
  {note("reserved");cleardevice1();backgroundapp();}
  else if(between(290,210,425,310,x,y)&&cl==1)
  {paint("reserved");cleardevice1();backgroundapp();}
  else if(between(440,210,580,310,x,y)&&cl==1)
  {calcu();cleardevice1();backgroundapp();}
  else if(between(200,330,520,420,x,y)&&cl==1)
  {char thru[10]="cd ";
  system("cd..");
  chat(name1);cleardevice1();
  strcat(thru,name1);
  system(thru);
  strcpy(thru,"cd ");
  backgroundapp();}
 }
}

void backgroundapp()
{cleardevice1();
bcgr();
mousehide();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
  outtextxy(130,70,"APP CENTRE");
  outtextxy(280,130,"CLU");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  rectangle(130,210,270,310);
  rectangle(290,210,425,310);
  rectangle(440,210,580,310);
  rectangle(200,330,520,420);
  outtextxy(138,220,"NOTE 2.0");
  outtextxy(305,220,"SCRATCH");
 // outtextxy(460,220,"CALC");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(215,360,"CLU CHAT");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

  //chat icon
  ellipse(450,365,-30,298,30,15);
  line(474,374,480,390);
  line(464,379,480,390);
  //notpad icon
  int nt[12]={153,240,153,300,248,300,248,258,230,240,153,240};
  drawpoly(6,nt);
  line(230,240,210,258);
  line(248,258,210,258);
  line(158,250,200,250);
  line(158,255,200,255);
  line(158,260,200,260);
  line(158,265,200,265);
  line(158,265,240,265);
  line(158,275,240,275);
  line(158,285,240,285);
  //scratch icon
  line(305,300,340,255);
  line(305,300,350,260);
  line(340,255,350,260);
  for(int i=0;i<12;i++)
  line(340+i,255+i/2,340+(2*i),245+i);
  rectangle(355,270,405,300);
  rectangle(370,240,390,260);
  rectangle(370,240,390,250);
  line(370,260,355,270);
  line(390,260,405,270);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  outtextxy(360,280,"PAINT");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  //calc icon
outtextxy(460,220,"CALC");
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

  rectangle(460,250,550,305);
  rectangle(463,253,547,267);
  for(i=0;i<5;i++)
  { rectangle(463,270+ 7*i,504,275+ 7*i);
  rectangle(506,270+ 7*i,547,275+7*i); }
 callmouse();
}

