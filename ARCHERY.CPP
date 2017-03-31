//Function of instructions.

void cleardevice1();

void instructions2s()
{
settextstyle(0,0,3);
setcolor(9);
outtextxy(50,50,"INSTRUCTIONS");
settextstyle(0,0,0);
setcolor(5);
outtextxy(100,110,"RULE 1:Player gets only 3 chances.");
outtextxy(100,140,"RULE 2:Please enter the coordinates within the given range");
outtextxy(100,170,"RULE 3:You have the clue in the game");
outtextxy(100,230,"CLUE: $*%,!)) ");
setcolor(4);
settextstyle(0,0,3);
outtextxy(200,300,"WARNING");
settextstyle(0,0,1);
outtextxy(100,350," Enter the co-ordinates within the given range");
outtextxy(130,380,"or the game will terminate !!!");
outtextxy(100,400,"Press any key to resume");
}
int arch()
{

    int choice,u,s,i,j,midx,midy,a,b,c,ch,s1=0,s2=0,s3=0,s4=0,v,p,h,k,f;
    char y ;
   int d=10;
   //Graphics Declaration End
   //Welcome Movement.
   for(k=1;k<20;k++)
   {
   f=random(14);
   p=random(40);
   h=random(50);
   setcolor(f+1);
   settextstyle(0,0,3);
   outtextxy(p*10,h*10,"WELCOME   ");
   delay(d);
   cleardevice1();
   }
   // S S ARCHERY intial position.
   settextstyle(0,0,6);
   setcolor(14);
    outtextxy(8,10,"S S ARCHERY");
    //Goto brings it back here.
    gotofn:

    delay(100);

    settextstyle(0,0,6);
    setcolor(14);
     //Moving SS ARCHERY.
    for(int q=0 ;q<400 ;q=q+5)
    {
    outtextxy(8,q," S S ARCHERY ");
    delay(d);
    cleardevice1();
    }
    //Final Position of SS ARCHERY.
    outtextxy(8,q," S S ARCHERY ");

    cout<<"\n";
    cout<<"\t\t\t\t\n\n\n";
    setcolor(3);
    settextstyle(0,0,2);
     outtextxy(200,10,"LOADING...");

    //loop for loading
    char aaa;
    for(int jj=0;jj<26;jj++)
    for (int ii = 176; ii<179; ii++)
     {
       aaa = (char) ii;
       cout<<aaa;
       delay(d);
     }
//SS Archery final position after moving.
    settextstyle (0,0,6);
    delay(1000);
    setcolor(14);
    outtextxy(8,q," S S ARCHERY ");
    delay(d);
//Press key to continue
    settextstyle(0,0,2);
    setcolor(12);
    outtextxy(100,200,"Press Any Key To Continue ");
    getch();
//To get control to required position.
    cout<<"\n\n\t\t\t\n\n\n\n\t\t\t\t";

    settextstyle(0,0,6);
    setcolor(14);
    //To return SS ARCHERY back.
    for( q=400 ;q>1 ;q=q-30)
    {
    outtextxy(8,q," S S ARCHERY ");
    delay(d);
    cleardevice1();
    }
    //Menu SCreen begins.
    cleardevice1();
    //goto for instrucions.
      back123:
      settextstyle(0,0,6);
      setcolor(14);

    outtextxy(8,10," S S ARCHERY ");
    setcolor(8);
    settextstyle(0,0,3);

    outtextxy(200,190," M E N U ");
      delay(d);
    delay(d);

 settextstyle(0,0,2);


    setcolor(6);
    outtextxy(60,240,"1....P L A Y  T H E  G A M E   ....");
    delay(1000);
    setcolor(3);
    outtextxy(60,290,"2....I N S T R U C T I O N S....");
    delay(1000);
    setcolor(4);
    outtextxy(60,340,"3....E X I T....");
    delay(1000);
    setcolor(4);

    settextstyle(0,0,2);
    setcolor(1);
    outtextxy(60,100,"E N T E R  Y O U R  C H O I C E ");
    outtextxy(190,145,"  ");
    int r;
    window(36,10,40,20);
    cin>>r;
    cleardevice1();
    //menu end.

    //switch for choice.
    switch(r)
    {
    //Choice Game
    case 1   :
	{
	{for(u=1;u<=3;u++)
	 {   s2=0;
	     cleardevice1();
	     setcolor(15);
//************concentric circles*******************.
	    { {
		circle(485,100,91);
		setfillstyle(SOLID_FILL,8);
		floodfill(485,100,15);
		delay(d);
	     }
	     {
		circle(485,100,76);
		setfillstyle(SOLID_FILL,6);
		floodfill(485,100,15);
			delay(d);
	     }
	     {
		circle(485,100,61);
		setfillstyle(SOLID_FILL,5);
		floodfill(485,100,15);
			delay(d);
	     }
	     {
		circle(485,100,47);
		setfillstyle(SOLID_FILL,3);
		floodfill(485,100,15);
			delay(d);
	     }
	     {
		circle(485,100,34);
		setfillstyle(SOLID_FILL,2);
		floodfill(485,100,15);
			delay(d);
	     }
	     {
	       circle(485,100,16);
	       setfillstyle(SOLID_FILL,1);
	       floodfill(485,100,15);
		delay(d);
	     }
	     {
	       circle(485,100,3);
	       setfillstyle(SOLID_FILL,4);
	       floodfill(485,100,15);
		delay(d);
	     }

	     line(385,100,585,100);
	    line(485,10,485,190);

	    }
//*************** Entering the co ordinates***************.
	    settextstyle(0,0,2);
	    setcolor(11);
	    outtextxy(10,10,"Enter Co-Ordinate") ;
	    settextstyle(0,0,1);
	    outtextxy(10,50,"X range is (385,585)");
	    outtextxy(10,100,"Y range is (10,190)");
	    window(10,15,40,20);
	    textcolor(BLACK);
	    textbackground(WHITE);
	    cin>>c;
	    window(14,15,40,20);
	    cout<<",";
	    window(16,15,40,20);
	    cin>>b;


	    settextstyle(0,0,1);
//setcolor(14);

	      if (c<385 || c>585)
		   {
		   outtextxy(20,150,"You have entered the wrong Y co-ordinates, you have violated the game rules");
		   setcolor(4);
		   settextstyle(0,0,4);
		   outtextxy(50,250,"Player disquallified");
		   delay(d);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		   return 0;
		   }
	      if(b<10 || b>190)
		 {
		   outtextxy(20,150,"You have entered the wrong Y co-ordinates, you have violated the game rules");
		   setcolor(4);
		   settextstyle(0,0,4);
		   outtextxy(50,250,"Player disquallified");
		   delay(d);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		   return 0;
		  }
	cleardevice1();
//****************Loop to move the arrow*******************.
	for(i=b , j=c; i<=c-50 || j>=b+50 ; i=i+10,j=j-10)
	 {

//******To color the circles outline*****.
	    setcolor(15);
//*********color the circles**********.
	    {
//******************circles*****************.
	      {
		circle(485,100,91);
		setfillstyle(SOLID_FILL,8);
		floodfill(485,100,15);
	      }

	      {
		circle(485,100,76);
		setfillstyle(SOLID_FILL,6);
		floodfill(485,100,15);
	      }
	      {
		circle(485,100,61);
		setfillstyle(SOLID_FILL,5);
		floodfill(485,100,15);
	      }
	      {
		circle(485,100,47);
		setfillstyle(SOLID_FILL,3);
		floodfill(485,100,15);
	      }
	      {
		circle(485,100,34);
		setfillstyle(SOLID_FILL,2);
		floodfill(485,100,15);
	      }
	      {
		circle(485,100,16);
		setfillstyle(SOLID_FILL,1);
		floodfill(485,100,15);
	      }
	      {

		circle(485,100,3);
		setfillstyle(SOLID_FILL,4);
		floodfill(485,100,15);

	      }
	       line(385,100,585,100);
	       line(485,10,485,190);


	      }
//**circle area filled**.

//**********Arrow.*****************

	     line(i-1,j-1,i+51,j-51);
	     line(i,j,i+50,j-50);
	     line(i+1,j+1,i+49,j-49);

	     circle(i-4,j+4,5);
	     circle(i-4,j+4,4);
	     circle(i-4,j+4,3);
	     circle(i-4,j+4,2);
	     circle(i-4,j+4,1);
	     delay(75);


	}
//**for loop close**.


	  cleardevice1();

//*****************************Concentric cirlces.**************************

	   {

	      {

			circle(485,100,91);
		setfillstyle(SOLID_FILL,8);
		  floodfill(485,100,15);

	      }
	   {
		circle(485,100,76);
		setfillstyle(SOLID_FILL,6);
		  floodfill(485,100,15);

	      }
	      {
		circle(485,100,61);
		setfillstyle(SOLID_FILL,5);
		floodfill(485,100,15);

	      }
	      {
		circle(485,100,47);
		setfillstyle(SOLID_FILL,3);
		floodfill(485,100,15);

	      }
	      {
		circle(485,100,34);
		setfillstyle(SOLID_FILL,2);
		floodfill(485,100,15);

	      }
	      {
		circle(485,100,16);
		setfillstyle(SOLID_FILL,1);
		floodfill(485,100,15);

	      }
	      {
		circle(485,100,3);
		setfillstyle(SOLID_FILL,4);
		floodfill(485,100,15);

	      }
//*********PLus line.******************
	       line(385,100,585,100);
	       line(485,10,485,190);

	   }


//**********************Arrow's final position*****************************.
		i=i-5;
		j=j+5;

	     line(i-1,j-1,i+51,j-51);
	     line(i,j,i+50,j-50);
	     line(i+1,j+1,i+49,j-49);
	     circle(i-4,j+4,5);
	     circle(i-4,j+4,4);
	     circle(i-4,j+4,3);
	     circle(i-4,j+4,2);
	     circle(i-4,j+4,1);

//Distance From Centre.
    s1=sqrt(((c-485)*(c-485))+((b-100)*(b-100)));
//Score if else if.
    if(s1<3)
    {s2+=100;}
    else if(s1<16)
	   s2+=60;
	   else if(s1<34)
		 s2+=50;
		 else if(s1<47)
		     s2+=40;
		      else if(s1<61)
			   s2+=30;
			   else if(s1<76)
				s2+=20;
				else if(s1<91)
				     s2+=10;
				     s3=s2;
//*************Print score.**********
	cout<<endl<<"You Scored "<<s3<<" in this shot";
	     s4=s4+s3;
	setcolor(11);
	settextstyle(0,0,2);
	outtextxy(100,400,"Press any key to resume");
	getch();
	}
	getch();
	}
	cleardevice1();
	  for(int qq=0;qq<500;qq++)
	  {
	  int ww=random(14);
	  int rr=random(500);
	  setcolor(ww+1);
	   circle(rr+10,200,rr);
		   delay(10);
	}
	window(30,15,40,20);
	cout<<"Your Final Score Is "<<s4;
getch();
	cleardevice1();
//End game menu
			 settextstyle(0,0,2);
			 outtextxy(200,200,"Ending Game");

	 for(int e=0;e<=900;e=e+8)
			      {
			       int aa=random(14);
			       setcolor(aa+1);
			       circle(e,100,4);
			       sound(50);
			       delay(d);
			       nosound();
			       }
		 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	return 0;

	}


//Instructions
    case 2   :        instructions2s();
		      getch();
		      cleardevice1();
		      goto back123;
//Exit
    case 3   :
	       //Exit The game Exit .
		      setcolor(7);
		      settextstyle(0,0,2);
		      outtextxy(200,200,"Ending Game");
	       //Loop to exit.
	       for(int e=0;e<=900;e=e+8)
		  {
		    int aa=random(14);
		    setcolor(aa+1);
		    circle(e,100,4);
		    sound(50);
		    delay(d);
		    nosound();
		  }

		 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	     return 0;
     default  :
	       //Invalid case.
		      cout<<"\nInvalid Choice\n";
	  //Endgame loop.
			 setcolor(7);
			 settextstyle(0,0,2);
			 outtextxy(200,200,"Ending Game");
	  //exit game.
				for(int ee=0;ee<=900;ee=ee+8)
			   {
			  int ab=random(14);
				  setcolor(ab+1);
			  circle(ee,100,4);
			  delay(d);
		   }
	  //Sonds during loop
		      sound(50);
		      delay(d);
		      nosound();
}
//Switch close.
/* clean up */
 closegraph();

		 settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
 return 0;
}