void cleardevice1();
void backgroundpaint(void);
void colorchange(int,int);
void drpen(void);
void drline(void);
int namchk(char [],char []);
void drrect(void);
void eraser(void);
void drcirc(void);
void ffil(void);
void mousescan(void);
void drawprevimage();
void writeimage();
void bcgr();
char fname2[8];
int fc=0,select=0,mx,my,clo=3;
int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);
void paint(char nm[])
{
cleardevice1();
callmouse();
setcolor(3);
backgroundpaint();
if(!strcmp(nm,"reserved"))
{
outtextxy(120,70,"Enter file name: ");
gettxt(250,70,8,fname2);
backgroundpaint();
if(!namchk("pntlist",fname2))
{
ofstream fwrt;
fwrt.open("pntlist",ios::binary|ios::app);
fwrt<<fname2<<endl;
fwrt.close();
}
else
drawprevimage();
}
else
{strcpy(fname2,nm);  drawprevimage();}
outtextxy(75,getmaxy()-28,fname2);
mx=getmaxx();my=getmaxy();
int x,y,cl;
mouseposi(x,y,cl);
restrictmouseptr(10,10,mx-10,my-10);
mousehide();
callmouse();
while(1)
  {
   mouseposi(x,y,cl);
   if(between(mx-35,17,mx-17,33,x,y)&&cl==1)
    {mousehide();
     writeimage();
     callmouse();
     return;
    }
   mousescan();
  }
}
 void drpen()
   {int x,y,cl;mouseposi(x,y,cl);
   mouseposi(x,y,cl);
   mousehide();
   putpixel(x,y,15);
   callmouse();
   mouseposi(x,y,cl);
   }

  void drline()
   { int x,y,cl;mouseposi(x,y,cl);
   int x1=x,y1=y;
   while(cl!=0)
   {mouseposi(x,y,cl);}
   int x2=x,y2=y;
   mousehide();
   if(y2<50||x2<110||x2>mx-20||y2>my-50)
   goto A;
   line(x1,y1,x2,y2);
   A:
   callmouse();
   }

   void eraser()
   {
   int x,y,cl,i;
   mouseposi(x,y,cl);
   setcolor(0);
   mousehide();
   if(y+10>my-52||x+10>mx-22)
   goto A;
   for(i=0;i<10;i++)
   line(x+i,y,x+i,y+10);
   A:
   callmouse();
   setcolor(clo);
   }

   void drrect()
   {int x,y,cl; mouseposi(x,y,cl);
   int x1=x,y1=y;
   while(cl!=0)
   {
   mouseposi(x,y,cl);}
   int x2=x,y2=y;
   mousehide();
   if(y2<50||x2<110||x2>mx-20||y2>my-50)
   goto A;
   rectangle(x1,y1,x2,y2);
   A:
   callmouse();
   }

   void drcirc()
    {int x,y,cl;mouseposi(x,y,cl);
   int x1=x,y1=y;
   while(cl!=0)
   {
   mouseposi(x,y,cl);}
   int x2=x,y2=y;
   mousehide();
   int z1,z2,r;
   z1=(y1+y2)/2;r=(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))/2);
   z2=(x1+x2)/2;
   if(z1+r<50||z1-r<50||z2+r<110||z2-r<110||z1+r>my-50||z1-r>my-50||z2+r>mx-20||z2-r>mx-20)
   goto A;
   circle((x1+x2)/2,(y1+y2)/2,r);
   A:
   callmouse();
   }

   void ffil()
   {int x,y,cl;
   mouseposi(x,y,cl);
   if(cl!=0)
    {
     mousehide();
    setfillstyle(SOLID_FILL,fc);
    floodfill(x,y,clo);
    callmouse();
   }
   }

void backgroundpaint()
{cleardevice1();
mousehide();
    rectangle(42,55,62,75);
    putpixel(52,65,clo);
    rectangle(42,80,62,100);
    line(46,84,58,96);
    rectangle(42,105,62,125);
    rectangle(46,109,58,120);
    rectangle(42,130,62,150);
    circle(52,140,5);
    rectangle(42,155,62,175);
    //fillcolor
    rectangle(46,162,58,170);
    rectangle(46,165,58,167);
    circle(59,160,2);
    rectangle(42,180,62,200);
    line(46,195,57,190);
    line(46,188,57,183);
    line(46,188,46,195);
    line(57,183,57,190);
    setfillstyle(SOLID_FILL,15);
    floodfill(48,189,clo);
    rectangle(35,400,55,420);
    rectangle(55,400,75,420);
    for(int i=210;i<350;i+=20)
    rectangle(35,i,75,i+20);
    line(55,210,55,350);
    rectangle(45,350,65,370);
    int k=0;
    for(i=211;i<350;i+=20)
    for(int j=36;j<57;j+=20)
    { if(k==3)
     {k=4;}
       setfillstyle(SOLID_FILL,k);
     floodfill(j,i,clo);
     k++;
    }
    setfillstyle(SOLID_FILL,15);
    floodfill(46,351,clo);
    outtextxy(80,22,"SCRATCH");
callmouse();
 bcgr();
}

void mousescan()
{
 int x,y,cl;
 const int mx=getmaxx();
 mouseposi(x,y,cl);
 if(x>35&&x<75&&y>210&&y<370&&cl==1)
 colorchange(x,y);
 if(x>42&&x<62&&cl==1)
 {setcolor(0);
 for(int k=0;k<19;k++)
 line(56+k,401,56+k,419);
 setcolor(clo);
 if(y>55&&y<75)
 {select=1;// drpen();
  putpixel(65,410,15);}
 if(y>80&&y<100)
 {select=2;// drline();
 line(59,404,71,416);}
 if(y>105&&y<125)
 {select=3;// drrect();
  rectangle(59,404,71,416);}
 if(y>130&&y<150)
 {select=4;// drcirc();
 circle(65,410,5);
 }
 if(y>155&&y<175)
{ select=5;// ffil();
  rectangle(58,407,70,415);
    rectangle(58,410,70,412);
  circle(71,404,2);
}
 if(y>180&&y<200)
{ select=6;// eraser();
  line(58,416,69,410);
  line(61,408,72,403);
  line(61,408,58,415);
  line(72,403,69,410);
  setfillstyle(SOLID_FILL,15);
  floodfill(64,412,clo);
 }}
 if(y>50&&x>110&&x<mx-20&&y<my-50&&cl!=0)
 {if(select==1)
 {drpen();}
 if(select==2)
 {drline();}
 if(select==3)
 {drrect();}
 if(select==4)
 {drcirc();}
 if(select==5)
 {ffil();}
 if(select==6)
 {eraser();}
 }
}


   void colorchange(int x,int y)
   {
   if(x<55)
   {
    if(y<230)
    fc=0;
    else if(y<250)
    fc=2;
    else if(y<270)
    fc=5;
    else if(y<290)
    fc=7;
    else if(y<310)
    fc=9;
    else if(y<330)
    fc=11;
    else if(y<350)
    fc=13;
    }
   else if(x>55)
   {
    if(y<230)
    fc=1;
    else if(y<250)
    fc=4;
    else if(y<270)
    fc=6;
    else if(y<290)
    fc=8;
    else if(y<310)
    fc=10;
    else if(y<330)
    fc=12;
    else if(y<350)
    fc=14;
    }
    if(x>45&&x<65&&y>350&&y<370)
    fc=15;
    mousehide();
    setfillstyle(SOLID_FILL,fc);
    floodfill(36,401,clo);
    callmouse();
    }
void writeimage()
{
void *img;
unsigned int size;
   ofstream fout;
   fout.open(fname2,ios::binary);
   size=imagesize(364,240,mx-20,429);
   if((img=malloc(size))==NULL)
   exit(0);
   getimage(110,50,364,239,img);
   fout.write((char*)img,size);
   getimage(364,50,mx-20,239,img);
   fout.write((char*)img,size);
   getimage(110,240,364,429,img);
   fout.write((char*)img,size);
   getimage(364,240,mx-20,429,img);
   fout.write((char*)img,size);
   fout.close();
   free(img);
}

void drawprevimage()
{cleardevice1();
backgroundpaint();
void *img;
unsigned int size;
   ifstream fin;
   fin.open(fname2,ios::binary);
   size=imagesize(110,50,364,239);
   if((img=malloc(size))==NULL)
   exit(0);
   fin.read((char*)img,size);
   putimage(110,50,img,2);
   fin.read((char*)img,size);
   putimage(364,50,img,2);
   fin.read((char*)img,size);
   putimage(110,240,img,2);
   fin.read((char*)img,size);
   putimage(364,240,img,2);
   fin.close();
 free(img);
}
int namchk(char str1[],char str2[])
{
char cmp[9];
ifstream fin;
fin.open(str1,ios::binary);
while(!fin.eof())
{
fin>>cmp;
if(!fin)
break;
if(!strcmp(str2,cmp))
return 1;
}
return 0;
}