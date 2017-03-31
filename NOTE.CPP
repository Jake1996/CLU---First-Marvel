void cleardevice1();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);
int namchk(char [],char []);
int between(int,int,int,int,int,int);
void screenclear();
void convert(char);
void read(void);
void bcgr();
void backgroundnote(void);
void gettxt(int,int,int,char []);
char fname[8];
int l,p;
void note(char input[])
{cleardevice1();
callmouse();
char ch=0;
int x,y,cl;
 setcolor(3);
  backgroundnote();
if(!strcmp(input,"reserved"))
{
outtextxy(120,70,"Enter file name: ");
gettxt(250,70,8,fname);
if(!namchk("notelist",fname))
{
ofstream fwrt;
fwrt.open("notelist",ios::binary|ios::app);
fwrt<<fname<<endl;
fwrt.close();
}
}
else
strcpy(fname,input);
ofstream fout;
fout.open(fname,ios::noreplace|ios::binary);
fout.close();
cleardevice1();
outtextxy(75,getmaxy()-28,fname);
backgroundnote();
read();
ch=getch();
while(1)
{
mouseposi(x,y,cl);
if(between(getmaxx()-35,15,getmaxx()-15,35,x,y)&&cl==1)
return;
if(kbhit())
{
ch=getch();
convert(ch);
read();
}
}
}

void convert(char c)
{
int a,q=0,o=0;
a=c;
if(!(a==8))
{
ofstream fout;
fout.open(fname,ios::app,ios::binary);
fout<<a<<endl;
fout.close();
}
else if(a==8)
{
ifstream fin;
ofstream fou;
fin.open(fname,ios::binary);
fou.open("temp",ios::binary);
while(!fin.eof())
{fin>>a;
if(!fin)
break;
q++;
}
fin.close();
q--;
ifstream fin2;
fin2.open(fname,ios::binary);
while(o<q)
{
fin2>>a;
fou<<a<<endl;
o++;
}
fin2.close();
fou.close();
remove(fname);
rename("temp",fname);
setcolor(0);
line(122+((p)*10),l-((l/350)*350)+70,132+((p)*10),l-((l/350)*350)+70);
setcolor(3);
}
setcolor(0);
for(int k=0;k<=10;k++)
line(112+(p*10)+k,l-((l/350)*350)+70,112+(p*10)+k,l-((l/350)*350)+60);
setcolor(3);

}
void read()
{
ifstream fin;
fin.open(fname,ios::binary);
char c;
int a;
p=0;l=0;
char x[2];
x[0]=' ';
x[1]='\0';
while(!fin.eof())
{
 fin>>a;
 if(!fin)
 break;
 setcolor(0);
 line(122+((p)*10),l-((l/350)*350)+70,132+((p)*10),l-((l/350)*350)+70);
 setcolor(3);
 c=a;
 if(p>47)
 {
 p=0;
 l+=10;
 if(l%350==0)
 screenclear();
 }
  x[0]=c;
  if(x[0]==13)
  {
  l+=10;p=0;
  if(l%350==0)
  screenclear();
  continue;
  }
  outtextxy(122+(p*10),(l-(l/350)*350)+60,x);
  line(122+((p+1)*10),(l-(l/350)*350)+70,132+((p+1)*10),(l-(l/350)*350)+70);
  p++;
  }
fin.close();
}

void backgroundnote()
{   bcgr();
    mousehide();
    outtextxy(80,22,"NOTEPAD");
    callmouse();
}


void screenclear()
{
int mx=getmaxx(),my=getmaxy();
setcolor(0);
for(int j=0;j<mx-135;j++)
line(112+j,60,112+j,my-58);
setcolor(3);
}