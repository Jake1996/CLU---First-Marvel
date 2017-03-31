void cleardevice1();
int chess();
int arch();
      int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);
int between(int,int,int,int,int,int);
void backgroundgm();
void bcgr();
void game()
{
cleardevice1();
int x,y,cl;
setcolor(3);
 backgroundgm();
callmouse();
int mx=getmaxx();
mouseposi(x,y,cl);
  while(1)
 {mouseposi(x,y,cl);
  if(between(130,250,330,350,x,y)&&cl==1)
  {arch();cleardevice1();backgroundgm();callmouse(); }
  if(between(380,250,580,350,x,y)&&cl==1)
  {chess();cleardevice1();backgroundgm();callmouse();}
  if(between(mx-35,17,mx-17,33,x,y)&&cl==1)
  return;
}
}

void backgroundgm()
{
 bcgr();

   mousehide();
    outtextxy(80,22,"CLU GAMES");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,7);
  outtextxy(130,70,"GAME BOX");
  outtextxy(270,130,"CLU");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(425,290,"CHESS");
  outtextxy(140,310,"ARCHERY");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
  outtextxy (140,275,">>------->");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  circle(310,280,10);
  circle(310,280,8);
  circle(310,280,6);
  circle(310,280,4);
  line(310,280,310,280);
  rectangle(130,250,330,350);
  rectangle(380,250,580,350);
  int k=380,l=275,color2=3,color21=11;
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
	k=530;l=275;
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
	callmouse();
}

