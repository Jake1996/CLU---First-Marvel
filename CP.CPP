void cleardevice1();
void bcgr();
class account1
{
char name[20],id[9],password[32],country[15],age[4];

public :

char* getid()
{
return id;
}

char* getpassword()
{
return password;
}

void changepassword(int x, int y)
{
outtextxy(x,y,"New password :");
gettxt(x+150,y,32,password);
}

void getdata(int , int );
void profile(int , int , char [], char []);

};
void account1::profile(int x, int y, char id2[], char pass1[])
{
 int l,m,cl;
 char id1[9],pass[32];
 account1 a1;

 mousehide();
 outtextxy(x,y,"Name : ");
 outtextxy(x+150,y,name);
 outtextxy(x,y+10,"ID : ");
 outtextxy(x+150,y+10,id);
 outtextxy(x,y+20,"Password : ");
 outtextxy(x+150,y+20,password);
 outtextxy(x,y+30,"Country : ");
 outtextxy(x+150,y+30,country);
 outtextxy(x,y+40,"Age : ");
 outtextxy(x+150,y+40,age);
 outtextxy(x,y+100,"CHANGE PASSWORD");
 outtextxy(25,55,"<-- BACK");
 callmouse();

 while(1)
 {
  mouseposi(l,m,cl);

  if (l>x && l<x+120 && m>y+100 && m<y+110 && cl==1)
  {
   system("cd ..");
   ifstream fin;
   fin.open("accounts",ios::binary);
   ofstream fout;
   fout.open("temp",ios::binary|ios::app);
   while(!fin.eof())
   {
    fin.read((char*)&a1,sizeof(a1));
    if(!fin)
     break;
    if ( strcmp(id,a1.getid()) )
     fout.write((char*)&a1,sizeof(a1));
   }
   fin.close();
   fout.close();

   remove("accounts");
   rename("temp","account1s");

   fin.open("idpass",ios::binary);
   fout.open("temp",ios::binary|ios::app);
   while(!fin.eof())
   {
    fin>>id1;
    fin>>pass;
    if (!fin)
     break;
    if ( strcmp(id,id1) )
     { fout<<id1<<" "<<pass<<endl; }
   }
   fin.close();
   fout.close();

   remove("idpass");
   rename("temp","idpass");

   mousehide();
   cleardevice1();
   backgroundmail();
   callmouse();
   changepassword(x,y);

   fout.open("accounts",ios::binary|ios::app|ios::nocreate);
   fout.write((char*)this,sizeof(account1));
   fout.close();

   fout.open("idpass",ios::binary|ios::app|ios::nocreate);
   fout<<id<<" "<<password<<endl;
   fout.close();

   strcpy(id2,id);
   strcpy(pass1,password);

   strcat(str1,id2);
   system(str1);
   strcpy(str1,"cd ");

   fout.open("profile",ios::binary);
   fout.write((char*)this,sizeof(account1));
   fout.close();
   break;
  }
  else if (l>25 && l<89 && m>55 && m<65 && cl==1)
  {
   break;
  }
 }
}

void account1::getdata(int x, int y)
{
 int val;

 mousehide();
 outtextxy(x,y,"Name : ");
 outtextxy(x,y+10,"ID : ");
 outtextxy(x,y+20,"Password : ");
 outtextxy(x,y+30,"Country : ");
 outtextxy(x,y+40,"Age : ");
 callmouse();

 for (int i=0;i<19;i++)
  name[i]=' ';
 name[i]='\0';
 gettxt(x+150,y,20,name);

 A:

 for (i=0;i<7;i++)
  id[i]=' ';
 id[i]='\0';
 gettxt(x+150,y+10,8,id);

 val = idcheck(id);
 if (val==0)
 {
  setcolor(0);
  for (int i=0;i<305;i++)
   line(i,0,i,9);
  for (i=x+150;i<x+279;i++)
   line(i,y+10,i,y+19);
  setcolor(3);
  outtextxy(0,0,"id already exists.. select a diff one!");
  goto A;
 }
 else
 {
  setcolor(0);
  for (int i=0;i<305;i++)
   line(i,0,i,9);
  setcolor(3);
 }

 for (i=0;i<31;i++)
  password[i]=' ';
 password[i]='\0';
 gettxt(x+150,y+20,32,password);

 for (i=0;i<14;i++)
  country[i]=' ';
 country[i]='\0';
 gettxt(x+150,y+30,15,country);

 age[0]=age[1]=age[2]=' ';
 age[3]='\0';
 gettxt(x+150,y+40,4,age);

 strcat(str2,id);
 system(str2);
 strcpy(str2,"md ");
 strcat(str1,id);
 system(str1);
 strcpy(str1,"cd ");
 ofstream fout;
 fout.open("profile",ios::binary);
 fout.close();
 fout.open("inbox",ios::binary);
 fout.close();
 fout.open("sent",ios::binary);
 fout.close();
 system("cd ..");

}

void backgroundmail();
void backgroundcp();
int between(int,int,int,int,int,int);
void gettxt(int,int,int,char[]);
      int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);

void cp(char id[])
{
 int l,m,cl,mx=getmaxx(),my=getmaxy();
 account1 a;

 restrictmouseptr(0,0,mx,my);

 setcolor(3);
 callmouse();

 char ch,id1[9],pass[32],pass1[32];
 int i,check1;

    P:
  cleardevice1();
  backgroundcp();
  mousehide();
  rectangle(150,65,450,165);
  rectangle(150,190,450,290);
  rectangle(150,315,450,415);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(175,105,"ADD ACCOUNT");
  outtextxy(175,230,"SWITCH USER");
  outtextxy(175,355,"  PROFILE");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  callmouse();

  while (1)
  {
    mouseposi(l,m,cl);

    if(between(25,my-40,51,my-14,l,m) && cl==1)
    { system("cd .."); system("cd .."); exit(0); }
    else if (between(mx-34,18,mx-18,32,l,m) && cl==1)
    {
     break;
    }
    else if (between(150,65,450,165,l,m) && cl==1)
    {
     system("cd ..");
     mousehide();
     cleardevice1();
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
     strcat(str1,id);
     system(str1);
     strcpy(str1,"cd ");

     goto P;
    }
    else if (between(150,315,450,415,l,m) && cl==1)
    {   account1 a1;
	mousehide();
	cleardevice1();
	backgroundcp();
	callmouse();
	ifstream fin1;
	fin1.open("profile",ios::binary);
	while(!fin1.eof())
	{
	 fin1.read((char*)&a1,sizeof(a1));
	 if (!fin1)
	  break;
	 a1.profile(120,60,id1,pass);
	}
	fin1.close();
	goto P;
    }
    else if (between(150,190,450,290,l,m) && cl==1)
    {    logoff=0;   break;    }
  }
  if (logoff==0)
  { system("cd .."); return; }
  mousehide();
  strcat(str1,id);
  system(str1);
  strcpy(str1,"cd ");

}

void backgroundcp ()
{ bcgr();
    outtextxy(80,22,"CONTROL PANEL");
 }
