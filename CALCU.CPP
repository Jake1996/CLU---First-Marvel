void cleardevice1();

int ii=0;
      int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);
      void bcgr();
int mod(float n1,float n2)
{
int ans=0,q,w;
q=n1;
w=n2;
ans=q%w;
return ans;
}
void calc (int x1,int y1,int a,int b)
{   mousehide();
    setfillstyle(SOLID_FILL,11);
    //first box
    rectangle(x1+20,y1+20,a-20 ,y1+100);
    rectangle(x1+(a-x1)/3,y1+20 ,x1+2*(a-x1)/3,y1+100);
    //small boxes
    for(int i=25;i<460;i+=46)
    rectangle(x1+i,y1+110,x1+45+i,y1+160);
    for(i=25;i<460;i+=46)
    rectangle(x1+i,y1+170,x1+45+i,y1+220);
    for(i=25;i<460;i+=46)
    rectangle(x1+i,y1+230,x1+45+i,y1+280);
   //clear and delete box
   rectangle(x1+20,b-90,a-20 ,b-20);
   rectangle(x1+25,b-85,x1+95,b-25);
   rectangle(x1+100,b-85,x1+170,b-25);
   rectangle(x1+175,b-85,a-25,b-25);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(x1+38 ,b-55 ,"CLEAR");
   outtextxy(x1+120,b-55 ,"DONE");

   floodfill(x1+1,x1+1,3);

 //numbers
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(x1+1*46 ,y1+135 ,"0");
   outtextxy(x1+2*46 ,y1+135 ,"1");
   outtextxy(x1+3*46 ,y1+135 ,"2");
   outtextxy(x1+4*46 ,y1+135 ,"3");
   outtextxy(x1+5*46 ,y1+135 ,"4");
   outtextxy(x1+6*46 ,y1+135 ,"5");
   outtextxy(x1+7*46 ,y1+135 ,"6");
   outtextxy(x1+8*46 ,y1+135 ,"7");
   outtextxy(x1+9*46 ,y1+135 ,"8");
   outtextxy(x1+10*46,y1+135 ,"9");

 //functions of line 2
   outtextxy(x1+1*46   ,y1+195 ,"+");
   outtextxy(x1+2*46   ,y1+195 ,"-");
   outtextxy(x1+3*46   ,y1+195 ,"*");
   outtextxy(x1+4*46   ,y1+195 ,"/");
   outtextxy(x1+5*46   ,y1+195 ,"%");
   outtextxy(x1+6*46   ,y1+195 ,"X");
   outtextxy(x1+7*46   ,y1+195 ,"X");
   outtextxy(x1+8*46   ,y1+195 ,"X");
   outtextxy(x1+9*46-10,y1+195 ,"1/X");
   outtextxy(x1+10*46  ,y1+195 ,"X");

   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   outtextxy(x1+8*46+7,y1+187 ,"3");
   outtextxy(x1+10*46+7,y1+187 ,"n");
   outtextxy(x1+6*46+7,y1+187 ,"2");

   line(x1+7*46-5 ,y1+190,x1+7*46-5 ,y1+200);
   line(x1+7*46-10,y1+195,x1+7*46-5 ,y1+200);
   line(x1+7*46-5 ,y1+190,x1+7*46 ,y1+190);

 //functions of line 2
   outtextxy(x1+1*46-10 ,y1+255 ,"sin");
   outtextxy(x1+2*46-10 ,y1+255 ,"cos");
   outtextxy(x1+3*46-10 ,y1+255 ,"tan");
   outtextxy(x1+4*46-15 ,y1+255 ,"cosec");
   outtextxy(x1+5*46-10 ,y1+255 ,"sec");
   outtextxy(x1+6*46-10 ,y1+255 ,"cot");
   outtextxy(x1+7*46-10 ,y1+255 ,"|x|");
   outtextxy(x1+8*46-10 ,y1+255 ,"[x]");
   outtextxy(x1+9*46-10 ,y1+255 ,"LOG");
   outtextxy(x1+10*46-10,y1+255 ,".");
   callmouse();
   }
int getnum(int x3,int y3,int x4)
{

int y4=110,n1=0;
x4+=ii;
       if(x3>125 && y3>160 && x3<174 && y3<210)
	  {  outtextxy(x4,y4,"0");   n1= 0; x4+=10 ;}
else if(x3>174 && y3>160 && x3<220 && y3<210)
	  {  outtextxy(x4,y4,"1");   n1=1; x4+=10 ;}
else if(x3>220 && y3>160 && x3<266 && y3<210)
	  {  outtextxy(x4,y4,"2");   n1= 2; x4+=10 ;}
else if(x3>266 && y3>160 && x3<312 && y3<210)
	  {  outtextxy(x4,y4,"3");   n1=3; x4+=10 ;}
else if(x3>312 && y3>160 && x3<358 && y3<210)
	  {  outtextxy(x4,y4,"4");   n1=4; x4+=10 ;}
else if(x3>358 && y3>160 && x3<404 && y3<210)
	  {  outtextxy(x4,y4,"5");   n1=5; x4+=10 ;}
else if(x3>404 && y3>160 && x3<450 && y3<210)
	  {  outtextxy(x4,y4,"6");   n1= 6; x4+=10 ;}
else if(x3>450 && y3>160 && x3<496 && y3<210)
	  {  outtextxy(x4,y4,"7");   n1= 7; x4+=10 ;}
else if(x3>496 && y3>160 && x3<542 && y3<210)
	  {  outtextxy(x4,y4,"8");   n1= 8; x4+=10 ;}
else if(x3>542 && y3>160 && x3<588 && y3<210)
	  {  outtextxy(x4,y4,"9");   n1= 9; x4+=10 ;}
ii+=10;
return n1;
}
int assignoper(int x3,int y3,int cl1,int oper)
{
int x4=350,y4=110;
  if (cl1==1)
   {
//row 1 operators
	 if(x3>125 && y3>220 && x3<174 && y3<270)
	  {  outtextxy(x4,y4,"+");  x4+=10 ;cl1=0;oper=0;}
else if(x3>174 && y3>220 && x3<220 && y3<270)
	  {  outtextxy(x4,y4,"-"); x4+=10 ;cl1=0;oper=1;}
else if(x3>220 && y3>220 && x3<266 && y3<270)
	  {  outtextxy(x4,y4,"*");  x4+=10 ;cl1=0;oper=2;}
else if(x3>266 && y3>220 && x3<312 && y3<270)
	  {  outtextxy(x4,y4,"/");  x4+=10 ;cl1=0;oper=3;}
else if(x3>312 && y3>220 && x3<358 && y3<270)
	  {  outtextxy(x4,y4,"%");  x4+=10 ;cl1=0;oper=4;}
else if(x3>358 && y3>220 && x3<404 && y3<270)
	  { outtextxy(x4+5,y4-5,"2"); outtextxy(x4,y4,"X");
	    x4+=10 ;cl1=0;oper=5;}
else if(x3>404 && y3>220 && x3<450 && y3<270)
	  { outtextxy(x4+5,y4-5,"1/2"); outtextxy(x4,y4,"X");
	  x4+=10 ;cl1=0;oper=6;}
else if(x3>450 && y3>220 && x3<496 && y3<270)
	  { outtextxy(x4+5,y4-5,"3"); outtextxy(x4,y4,"X");
	   x4+=10 ;cl1=0;oper=7;}
else if(x3>496 && y3>220 && x3<542 && y3<270)
	  {  outtextxy(x4,y4-5,"1/X");  x4+=10 ;cl1=0;oper=8;}
else if(x3>542 && y3>220 && x3<588 && y3<270)
	  { outtextxy(x4+5,y4-5,"n");  outtextxy(x4,y4,"X");
	    x4+=10 ;cl1=0;oper=9;}
//row 2 operators
else if(x3>125 && y3>280 && x3<174 && y3<330)
	  {  outtextxy(x4,y4,"sin");  x4+=10 ;cl1=0;oper=10;}
else if(x3>174 && y3>280 && x3<220 && y3<330)
	  {  outtextxy(x4,y4,"cos"); x4+=10 ;cl1=0;oper=11;}
else if(x3>220 && y3>280 && x3<266 && y3<330)
	  {  outtextxy(x4,y4,"tan");  x4+=10 ;cl1=0;oper=12;}
else if(x3>266 && y3>280 && x3<312 && y3<330)
	  {  outtextxy(x4,y4,"cosec");  x4+=10 ;cl1=0;oper=13;}
else if(x3>312 && y3>280 && x3<358 && y3<330)
	  {  outtextxy(x4,y4,"sec");  x4+=10 ;cl1=0;oper=14;}
else if(x3>358 && y3>280 && x3<404 && y3<330)
	  { outtextxy(x4,y4,"cot");  x4+=10 ;cl1=0;oper=15;}
else if(x3>404 && y3>280 && x3<450 && y3<330)
	  { outtextxy(x4,y4,"|X|"); x4+=10 ;cl1=0;oper=16;}
else if(x3>450 && y3>280 && x3<496 && y3<330)
	  { outtextxy(x4,y4, "[X]");  x4+=10 ;cl1=0;oper=17;}
else if(x3>496 && y3>280 && x3<542 && y3<330)
	  { outtextxy(x4,y4,"log");  x4+=10 ;cl1=0;oper=18;}
else if(x3>542 && y3>280 && x3<588 && y3<330)
	  { outtextxy(x4,y4,"."); x4+=10 ;cl1=0;oper=19;}
}
return oper;
}
void cal()
{   clear:
cleardevice1();
    int mx=getmaxx(),inum=0,my=getmaxy(),oper=0,out=0,x1,y1,a,b,x3,y3,no=0,x4,y4,cl1,ncount=0;
    long float ans=0,n1=0,n2=0;
    restrictmouseptr(10,10,mx-10,my-10);
     callmouse();
    //call main screen
     bcgr();
     x4=160;
     y4=110;
     inum=0;
     int dotinit=0,neginit1=0;
      calc(100,50,mx-20,my-50);
while(out==0)
{     //call for calc
      mouseposi(x3,y3,cl1);
      //assign cl
      int t=0;
      while(cl1==1)
      {mouseposi(x3,y3,cl1);t=1;}
      cl1=t;
      outtextxy(160,80,"Variable 1 is");
      //check for clear
      if(cl1==1 && x3>125 && y3>my-135 && x3<195 && y3<my-75)
      { cout<<"hi"; cleardevice1(); goto clear;}
      //Check for done
      if(cl1==1 && x3>200 && x3<275 && y3>my-135 && y3<my-75)
      {no=1;out=1;}
      //get .
     if(cl1==1 && x3>542 && y3>280 && x3<588 && y3<330)
      {{ if(dotinit!=1)
	 {outtextxy(x4+(10*ncount),y4 ,".");   dotinit=1; }
       }}
      //get number
  if (cl1==1 && no==0)
   { if(dotinit==1)
      n1=n1+(getnum(x3,y3,x4))*pow(10,-inum++);
      else
      n1=10*n1+(getnum(x3,y3,x4));
     ncount++;
     if (ncount>5)
     break;
 }
  //check for -
      if(cl1==1 && x3>170 && x3<216 && y3>220 && y3<270 )
      { neginit1=1 ; outtextxy(x4,y4,"-"); n1=-1*n1;}
}
if (neginit1==1)
n1=-1*n1;
x4=520;ii=0;
//operations
//get operator
 oper=25;int t=0;
while(oper==25)
{       //check for clear
       if(cl1==1 && x3>125 && y3>my-135 && x3<195 && y3<my-75)
      {cleardevice1(); goto clear;}
      mouseposi(x3,y3,cl1);
      //assign cl
      t=0;
      while(cl1==1)
      {mouseposi(x3,y3,cl1);t=1;}
      cl1=t;
      outtextxy(320,80,"Operator is");
     oper=assignoper(x3,y3,cl1,oper);
}
int neginit2=0;  dotinit=0; inum=0;
ncount=0;no=0;
out=0;inum=0;
calc(100,50,mx-20,my-50);
while(out==0 && (oper <=4 || oper==9))
{     //call for calc
      mouseposi(x3,y3,cl1);
      //assign cl
      int t=0;
      while(cl1==1)
      {mouseposi(x3,y3,cl1);t=1;}
      cl1=t;
       outtextxy(480,80,"Variable 2 is");
     //check for clear
       if(cl1==1 && x3>125 && y3>my-135 && x3<195 && y3<my-75)
      { cout<<"hi"; cleardevice1(); goto clear;}
      //Check for done
      if(cl1==1 && x3>200 && x3<275 && y3>my-135 && y3<my-75)
      {no=1;out=1;}
      //get .
     if(cl1==1 && x3>542 && y3>280 && x3<588 && y3<330)
      {       { if(dotinit!=1)
	 {outtextxy(x4+(10*ncount),y4 ,".");   dotinit=1; }
       }   }
      //get number
  if (cl1==1 && no==0)
   { if(dotinit==1)
      n2=n2+(getnum(x3,y3,x4))*pow(10,-inum++);
      else
      n2=10*n2+(getnum(x3,y3,x4));
     ncount++;
     if (ncount>5)
     break;
   }
   //check for -
      if(cl1==1 && x3>170 && x3<216 && y3>220 && y3<270 )
      { neginit2=1 ; outtextxy(x4,y4,"-"); n2=-1*n2;}
}
if(neginit2==1)
n2=n2*-1;
switch(oper)
{
case 0:ans=n1+n2;
	break;
case 1:ans=n1-n2;
	break;
case 2:ans=n1*n2;
	break;
case 3:ans=n1/n2;
	break;
case 4: ans=mod(n1,n2);
	break;
case 5: ans=n1*n1;
	break;
case 6: ans=sqrt(n1);
	break;
case 7: ans=n1*n1*n1;
	break;
case 8:ans=1.0/n1;
	break;
case 9:ans=pow(n1,n2);
	break;
case 10:ans=sin(n1);
	break;
case 11:ans=cos(n1);
	break;
case 12:ans=tan(n1);
	break;
case 13:ans=1.0/sin(n1);
	break;
case 14:ans=1.0/cos(n1);
	break;
case 15:ans=1.0/tan(n1);
	break;
case 16:if(n1>0)
	ans=n1;
	else ans=-n1;
	break;
case 17:if(n1>0)
	ans=(int)n1;
	else
	ans=-((int) n1-1);
	break;
case 18:ans=log(n1);
	break;
default:break;
}
outtextxy(355,370,"ANSWER = ");
window (60,24,80,25);
textcolor(BLACK);
textbackground(WHITE);
cout<<ans;
delay(1000);
while (1)
{  mouseposi(x1,y1,cl1);
if (between(mx-34,18,mx-18,32,x1,y1) && cl1==1)
{return;}
}
}

void calcu()
{
mousehide();
cleardevice1();
callmouse();
bcgr();
cal();
}