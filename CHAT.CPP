void cleardevice1();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);
int between(int,int,int,int,int,int);
void background3();
void clrchat();
void rdchat();
void bcgr();
void chat(char name[])
{  cleardevice1();
   int mx=getmaxx(),my=getmaxy(),x,y,cl;
   background3();
   int k=0,lc=0;
   char ch,string[50];
   fstream foi;
   callmouse();
   while(1)
   {
    mouseposi(x,y,cl);
    if(between(mx-35,17,mx-17,33,x,y)&&cl==1)
    return;
    foi.open("chbox",ios::binary|ios::in|ios::out|ios::binary|ios::app);
    string[0]='\0';
    k=0;
    while(k<48)
    {
    mouseposi(x,y,cl);
     if(between(mx-35,17,mx-17,33,x,y)&&cl==1)
    return;
    if(kbhit())
      {
       ch=getch();
       if(ch==13)
       break;
       else if(ch>=32&&ch<=122)
       { string[k]=ch;
	string[++k]='\0';
       }
      else if(ch==8&&k!=0)
      {string[--k]='\0';
      setcolor(0);
      for(int n1=0;n1<10;n1++)
      line(127+n1+8*k,my-95,127+n1+8*k,my-85);
      setcolor(3);
      }
      outtextxy(127,my-95,string);
    }
    }//while end
    setcolor(0);
    for(int n=0;n<mx-240;n++)
    line(127+n,my-95,127+n,my-85);
    setcolor(3);
    foi<<name<<" :"<<string;
    foi<<endl;
    foi.close();
    clrchat(); //clearchat screen
    rdchat(); // display chat
    lc++;
    }//end of while

}
  void background3()
  { setcolor(3);
  mousehide();
    int mx=getmaxx(),my=getmaxy();
    rectangle(120,my-70,mx-50,my-100);
    rectangle(118,my-68,mx-48,my-102);
    rectangle(mx-112,my-72,mx-52,my-98);
    outtextxy(80,22,"CLU CHAT");
    outtextxy(mx-100,my-88,"SEND");
     callmouse();
       bcgr();

  }
  int linecnt()
  {
  int cnt=0;
  char str[50];
  ifstream fin1;
  fin1.open("chbox",ios::binary);
  while(!fin1.eof())
  {fin1.getline(str,49,'\n');
  if(!fin1)
  break;
  cnt++;
  }
  fin1.close();
  return cnt;
  }
  void rdchat()
  { int my=getmaxy();
  int lc=0,nol;
  char string[50];
  nol=linecnt();
  ifstream fin;
  fin.open("chbox",ios::binary);
  while(!fin.eof())
  { fin.getline(string,49,'\n');
  if(!fin)
  break;
  if(nol>25)
  {if(lc>nol-25)
  outtextxy(145,65+(nol-lc)*12,string);
  }
  else
  outtextxy(145,my-120-lc*12,string);
  lc++;
  }
  fin.close();
 }
   void clrchat()
   { int mx=getmaxx(),my=getmaxy();
     setcolor(0);
   for(int n=0;n<mx-240;n++)
   line(130+n,my-115,130+n,60);
   setcolor(3);
   }