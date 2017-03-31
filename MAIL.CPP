void cleardevice1();
void backgroundmail();
int between(int,int,int,int,int,int);
void gettxt(int,int,int,char[]);
void gettxt1(int,int,int,char[]);
void getcontent(int,int,char[]);
void bcgr();
int check(char [],char []);
      int callmouse();
      void mouseposi(int &,int &,int &);
      int mousehide();
      void setposi(int &,int &);
      void restrictmouseptr(int,int,int,int);

char str1[20]="cd ",str2[20]="md ";

int idcheck (char id[])
{
 char id1[9],password[32];
 ifstream fin;
 fin.open("idpass",ios::binary);
 while(!fin.eof())
 {
  fin.getline(id1,9,' ');
  fin.getline(password,32,'\n');
  if(!fin)
   break;
  if ( strcmp(id,id1)==0 )
   return 0;
 }
 fin.close();

 return 1;
}

class mail
{
char receiver[9],sub[20],sender[9],content[100];

public :

char* getreceiver()
{
return receiver;
}

char* getsender()
{
return sender;
}

void getmail(int , int , char []);
void sentmail(int , int );
void inbox(int , int );
void dispmail(int , int );

};
void mail::dispmail(int x, int y)
{
outtextxy(x,y,"Sender : ");
outtextxy(x+150,y,sender);
outtextxy(x,y+10,"Sub : ");
outtextxy(x+150,y+10,sub);
outtextxy(x,y+20,"Content : ");
outtextxy(x,y+40,content);
}

void mail::inbox(int x, int y)
{
char cont[50];
for (int i=0;i<49;i++)
 cont[i] = content[i];
cont[i]='\0';
outtextxy(x,y,sender);
outtextxy(x+100,y,cont);
}

void mail::sentmail(int x, int y)
{
char cont[50];
for (int i=0;i<49;i++)
 cont[i] = content[i];
cont[i]='\0';
outtextxy(x,y,receiver);
outtextxy(x+100,y,cont);
}

void mail::getmail(int x, int y, char sendername[])
{
 int cancel,l,m,cl;
 char ch;

mousehide();
outtextxy(x,y,"To id : ");
outtextxy(x,y+10,"Sub : ");
outtextxy(x,y+20,"Content : ");

callmouse();

 gettxt(x+150,y,8,receiver);
 gettxt(x+150,y+10,20,sub);
 getcontent(x,y+40,content);

 strcpy(sender,sendername);

}

class account
{
char name[20],id[9],password[32],country[15],age[4];

public :

char* getname()
{
return name;
}

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

};

void account::getdata(int x, int y)
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

void mailmain(char id1[9])
{
 int l,m,cl,mx=getmaxx(),my=getmaxy();

 restrictmouseptr(0,0,mx,my);

 setcolor(3);
 callmouse();

 char ch;
 int i,check1,k=80,v=-1;
 mail m1;

    P:
  mousehide();
  cleardevice1();
  backgroundmail();
  rectangle(150,65,350,165);
  rectangle(150,190,350,290);
  rectangle(150,315,350,415);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(175,105,"COMPOSE");
  outtextxy(175,230," INBOX");
  outtextxy(180,355," SENT");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  callmouse();

  while (1)
  {
    mouseposi(l,m,cl);

    if(between(25,my-40,51,my-14,l,m) && cl==1)
    { system("cd .."); system("cd .."); exit(0); }
    else if (between(mx-35,17,mx-17,33,l,m) && cl==1)
    {
     break;
    }
    else if (between(150,65,350,165,l,m) && cl==1)
    {
	mousehide();
	cleardevice1();
	backgroundmail();
	callmouse();
	m1.getmail(120,60,id1);
	getch();

	ofstream fout;
	fout.open("sent",ios::app|ios::binary);
	fout.write((char*)&m1,sizeof(m1));
	fout.close();

	system("cd ..");
	strcat(str1,m1.getreceiver());
	system(str1);
	strcpy(str1,"cd ");
	fout.open("inbox",ios::app|ios::binary);
	fout.write((char*)&m1,sizeof(m1));
	fout.close();
	system("cd ..");

	strcat(str1,m1.getsender());
	system(str1);
	strcpy(str1,"cd ");
	goto P;
    }
    else if (between(150,190,350,290,l,m) && cl==1)
    {   B:

	mousehide();
	cleardevice1();
	backgroundmail();
	outtextxy(120,60,"SENDER");
	outtextxy(220,60,"CONTENT");
	outtextxy(25,55,"<-- BACK");    //back
	callmouse();

	ifstream fin;
	fin.open("inbox");
	while(!fin.eof())
	{
	 fin.read((char*)&m1,sizeof(m1));
	 if (!fin)
	  break;
	 mousehide();
	 m1.inbox(120,k);
	 callmouse();
	 k+=10;

	}
	fin.close();
	k=80;
	
	while(1)
	{
	 mouseposi(l,m,cl);
	 if (between(mx-35,17,mx-17,33,l,m) && cl==1)
	  { return; }
	 else if(between(25,my-40,51,my-14,l,m) && cl==1)
	  { system("cd .."); system("cd .."); exit(0); }
	 else if (l>25 && l<89 && m>55 && m<65 && cl==1)
	  { goto P; }
	 else if (((l>120&&l<670))&&m>80&&m<88&&cl==1)
	  { v=0; break; }
	 else if (((l>120&&l<670))&&m>90&&m<98&&cl==1)
	  { v=1; break; }
	 else if (((l>120&&l<670))&&m>100&&m<108&&cl==1)
	  { v=2; break; }
	 else if (((l>120&&l<670))&&m>110&&m<118&&cl==1)
	  { v=3; break; }
	 else if (((l>120&&l<670))&&m>120&&m<128&&cl==1)
	  { v=4; break; }
	 else if (((l>120&&l<670))&&m>130&&m<138&&cl==1)
	  { v=5; break; }
	 else if (((l>120&&l<670))&&m>140&&m<148&&cl==1)
	  { v=6; break; }
	 else if (((l>120&&l<670))&&m>150&&m<158&&cl==1)
	  { v=7; break; }
	 else if (((l>120&&l<670))&&m>160&&m<168&&cl==1)
	  { v=8; break; }
	 else if (((l>120&&l<670))&&m>170&&m<178&&cl==1)
	  { v=9; break; }
	 else if (((l>120&&l<670))&&m>180&&m<188&&cl==1)
	  { v=10; break; }
	 else if (((l>120&&l<670))&&m>190&&m<198&&cl==1)
	  { v=11; break; }
	 else if (((l>120&&l<670))&&m>200&&m<208&&cl==1)
	  { v=12; break; }
	 else if (((l>120&&l<670))&&m>210&&m<218&&cl==1)
	  { v=13; break; }
	 else if (((l>120&&l<670))&&m>220&&m<228&&cl==1)
	  { v=14; break; }
	 else if (((l>120&&l<670))&&m>230&&m<238&&cl==1)
	  { v=15; break; }
	 else if (((l>120&&l<670))&&m>240&&m<248&&cl==1)
	  { v=16; break; }
	 else if (((l>120&&l<670))&&m>250&&m<258&&cl==1)
	  { v=17; break; }
	 else if (((l>120&&l<670))&&m>260&&m<268&&cl==1)
	  { v=18; break; }
	 else if (((l>120&&l<670))&&m>270&&m<278&&cl==1)
	  { v=19; break; }
	 else if (((l>120&&l<670))&&m>280&&m<288&&cl==1)
	  { v=20; break; }
	 else if (((l>120&&l<670))&&m>290&&m<288&&cl==1)
	  { v=21; break; }
	 else if (((l>120&&l<670))&&m>300&&m<308&&cl==1)
	  { v=22; break; }
	 else if (((l>120&&l<670))&&m>310&&m<318&&cl==1)
	  { v=23; break; }
	 else if (((l>120&&l<670))&&m>320&&m<328&&cl==1)
	  { v=24; break; }
	}
	if (v!=-1)
	{
	 ifstream fin;
	 fin.open("inbox",ios::binary);
	 fin.seekg(v*sizeof(mail),ios::beg);
	 fin.read((char*)&m1,sizeof(mail));
	 if (!fin)
	  break;
	 mousehide();
	 cleardevice1();
	 backgroundmail();
	 m1.dispmail(120,60);
	 callmouse();
	 getch();
	 goto B;
	}
    }
    else if (between(150,315,320,415,l,m) && cl==1)
    {   C:

	mousehide();
	cleardevice1();
	backgroundmail();
	outtextxy(120,60,"RECEIVER");
	outtextxy(220,60,"CONTENT");
	outtextxy(25,55,"<-- BACK");          	//back
	callmouse();

	ifstream fin;
	fin.open("sent");
	while(!fin.eof())
	{
	 fin.read((char*)&m1,sizeof(m1));
	 if (!fin)
	  break;
	 m1.sentmail(120,k);
	 k+=10;

	}
	fin.close();

	k=80;
	while(1)
	{
	 mouseposi(l,m,cl);
	 if (between(mx-35,17,mx-17,33,l,m) && cl==1)
	  { return; }
	 else if(between(25,my-40,51,my-14,l,m) && cl==1)
	  { system("cd .."); system("cd .."); exit(0); }
	 else if (l>25 && l<89 && m>55 && m<65 && cl==1)
	  {  goto P; }
	 else if (((l>120&&l<670))&&m>80&&m<88&&cl==1)
	  { v=0; break; }
	 else if (((l>120&&l<670))&&m>90&&m<98&&cl==1)
	  { v=1; break; }
	 else if (((l>120&&l<670))&&m>100&&m<108&&cl==1)
	  { v=2; break; }
	 else if (((l>120&&l<670))&&m>110&&m<118&&cl==1)
	  { v=3; break; }
	 else if (((l>120&&l<670))&&m>120&&m<128&&cl==1)
	  { v=4; break; }
	 else if (((l>120&&l<670))&&m>130&&m<138&&cl==1)
	  { v=5; break; }
	 else if (((l>120&&l<670))&&m>140&&m<148&&cl==1)
	  { v=6; break; }
	 else if (((l>120&&l<670))&&m>150&&m<158&&cl==1)
	  { v=7; break; }
	 else if (((l>120&&l<670))&&m>160&&m<168&&cl==1)
	  { v=8; break; }
	 else if (((l>120&&l<670))&&m>170&&m<178&&cl==1)
	  { v=9; break; }
	 else if (((l>120&&l<670))&&m>180&&m<188&&cl==1)
	  { v=10; break; }
	 else if (((l>120&&l<670))&&m>190&&m<198&&cl==1)
	  { v=11; break; }
	 else if (((l>120&&l<670))&&m>200&&m<208&&cl==1)
	  { v=12; break; }
	 else if (((l>120&&l<670))&&m>210&&m<218&&cl==1)
	  { v=13; break; }
	 else if (((l>120&&l<670))&&m>220&&m<228&&cl==1)
	  { v=14; break; }
	 else if (((l>120&&l<670))&&m>230&&m<238&&cl==1)
	  { v=15; break; }
	 else if (((l>120&&l<670))&&m>240&&m<248&&cl==1)
	  { v=16; break; }
	 else if (((l>120&&l<670))&&m>250&&m<258&&cl==1)
	  { v=17; break; }
	 else if (((l>120&&l<670))&&m>260&&m<268&&cl==1)
	  { v=18; break; }
	 else if (((l>120&&l<670))&&m>270&&m<278&&cl==1)
	  { v=19; break; }
	 else if (((l>120&&l<670))&&m>280&&m<288&&cl==1)
	  { v=20; break; }
	 else if (((l>120&&l<670))&&m>290&&m<288&&cl==1)
	  { v=21; break; }
	 else if (((l>120&&l<670))&&m>300&&m<308&&cl==1)
	  { v=22; break; }
	 else if (((l>120&&l<670))&&m>310&&m<318&&cl==1)
	  { v=23; break; }
	 else if (((l>120&&l<670))&&m>320&&m<328&&cl==1)
	  { v=24; break; }
	}
	if (v!=-1)
	{
	 ifstream fin;
	 fin.open("sent",ios::binary);
	 fin.seekg(v*sizeof(mail),ios::beg);
	 fin.read((char*)&m1,sizeof(mail));
	 if (!fin)
	  break;
	 mousehide();
	 cleardevice1();
	 backgroundmail();
	 m1.dispmail(120,60);
	 callmouse();
	 getch();
	 goto C;
	}
    }
  }
  mousehide();

}

void backgroundmail ()
{
 bcgr();
 outtextxy(80,22,"CLU MAIL");
}
void getcontent(int z,int w,char string [])
{
string[0]='\0';
int a=0;
int p=0,l=0;
char x[2];
x[0]=' ';
x[1]='\0';
while(a<500)
{
 x[0]=getch();
 if(x[0]==27)
 break;
 setcolor(0);
 line(z+((p)*10),l+w+10,132+((p)*10),l+w+10);
 setcolor(3);
 if(x[0]>=32&&x[0]<=122)
 {string[a]=x[0];a++;}
 if(p>47)
 {a++;
 p=0;
 l+=10;
 }
  if(x[0]==13)
  {
  l+=10;p=0;
  continue;
  }
  setcolor(3);
  outtextxy(z+(p*10),l+w,x);
  line(z+((p+1)*10),l+w+10,z+10+((p+1)*10),l+w+10);
  p++;
  }
  string[a]='\0';
}
