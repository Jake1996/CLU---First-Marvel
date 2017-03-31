void cleardevice1();
void load(void)
{      int c1=getmaxx()/2,c2=getmaxy()/2;
       int speed=140;
setcolor(3);
for(int i=0;i<50;i++)
{circle(c1,c2,i+50);}
setcolor(0);
for(i=100;i>50;i--)
{circle(c1,c2,i);delay(speed);}
setcolor(3);
for(i=0;i<50;i++)
{circle(c1,c2,i+50); delay(speed);}

settextstyle(DEFAULT_FONT, HORIZ_DIR,3);
outtextxy(c1-35,c2-10,"CLU");
delay(1000);
speed=300;
     cleardevice1();
     setcolor(3);
     arc(c1, c2, 90, 290, 95);
     arc(c1, c2, 140, 290, 65);
     arc(c1, c2, 130, 410, 35);
     circle(c1,c2,145);
     arc(c1, c2, 90, 290, 100);
     arc(c1, c2, 140, 290, 70);
     arc(c1, c2, 130, 410, 40);
     circle(c1,c2,150);
    line(c1+1,c2-100,c1+1,c2-95);
    line(c1+31,c2+90,c1+35,c2+93);
    line(c1-55,c2-43,c1-49,c2-42);
    line(c1+21,c2+63,c1+23,c2+66);
    line(c1+23,c2-25,c1+27,c2-31);
    line(c1-23,c2-25,c1-27,c2-31);
    speed=100;
    for(i=0;i<9;i++)
    {if(i%2==0)
    setfillstyle(SOLID_FILL,11);
    else
    setfillstyle(SOLID_FILL,0);
    floodfill(c1-148,c2,3);
    floodfill(c1+148,c2,3);   delay(speed);
    floodfill(c1-98,c2,3);    delay(speed);
    floodfill(c1-68,c2,3);    delay(speed);
    floodfill(c1-38,c2,3);
    floodfill(c1+37,c2,3);    delay(speed);
    }
   delay(1000);
}
