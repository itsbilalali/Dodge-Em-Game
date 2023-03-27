//============================================================================
// Name        : game.cpp
// Author      : Muhammad Bilal Ali
// Version     : Fast Project 
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_

#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
int x=80;
int y=745;
int screen;
int cx =300;
int cy =55;
	 int  xr = 600; 
     int yr = 745;
int flag=0;
float width = 10; 
float height = 5;
float* color = colors[WHITE]; 
float radius = 5.0;
int p;
int xc[64];
int yc[64];
int screen1;
int Food_X[64];
int Food_Y[64];
bool Food[64];
int point;
int life=3;
int level=1;






using namespace std;

void set_food_cordinates()
{
 int a = 0;
  for(int fy=70; fy<=750 ; fy=fy+85)
   {
       for(int fx=65;fx<=765;fx=fx+100)
       {
         if(fy!=410)
{
           Food_X[a]=fx;
	       Food_Y[a]=fy;
           a++;
 }      
       }
	 
   }
}







// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height)
 {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * Main Canvas drawing function.
 * */
//Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	if(screen==0)
	{if(screen1!=1){
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		DrawString(300, 800, "MENU" , color);	
		DrawString(300, 750, "START" , color);
		DrawString(300,700,"HIGHSCORE" ,color);
		DrawString(10,400,"INSTRUCTIONS" ,color);
		DrawString(10,300,"(I)   Press S To Start " ,color);
		DrawString(10,250,"(I)   Player Car :   BLUE " ,color);
		DrawString(10,200,"(I)   Opponent Car : WHITE" ,color);
		DrawString(10,150,"(II)   Press H For Help" ,color);
		}
	if(screen1==1)
	{
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		
		DrawString(10, 800, "HOW TO PLAY" , color);
		DrawString(10,700,"(I)    Press (Pg Up) To Move The Car Up" ,color);
		DrawString(10,650,"(II)   Press (Pg Down) To Move The Car Up" ,color);
		DrawString(10,600,"(III)  Press (Pg Right) To Move The Car Right" ,color);
		DrawString(10,550,"(IV)   Press (Pg Left) To Move The Car Left" ,color);
		DrawString(10,500,"(I)    Your Car Can Change Its Path Only During Gap Turn" ,color);
		
	}

	if(life==0)
{
	{
	
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	DrawString(400, 400, "YOUR SCORE" , color);
	DrawString(400, 400, "get lost"  ,color);

	}
	


		glutSwapBuffers();
}
	}
	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );
	
	


if(life!=0)
{
	
	if(screen==1)
	{
		string point2="Points ="+Num2Str(point);
	
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		
			// Drawing Opponent car
		 
		width = 10; 
		height = 5;
		radius = 5.0;
		
		DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
		DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
		DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
		DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
		DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
		DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
		DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
		

		// Drawing Player car
		  
		 width = 10; 
		 height = 5;
		 float* color1 = colors[BLUE]; 
		 radius = 5.0;

		DrawRoundRect(::xr,::yr,width,height,color1,radius); // bottom left tyre
		DrawRoundRect(::xr+width*3,::yr,width,height,color1,radius); // bottom right tyre
		DrawRoundRect(::xr+width*3,::yr+height*4,width,height,color1,radius); // top right tyre
		DrawRoundRect(::xr,::yr+height*4,width,height,color1,radius); // top left tyre
		DrawRoundRect(::xr, ::yr+height*2, width, height, color1, radius/2); // body left rect
		DrawRoundRect(::xr+width, ::yr+height, width*2, height*3, color1, radius/2); // body center rect
		DrawRoundRect(::xr+width*3, ::yr+height*2, width, height, color1, radius/2); // body right rect

	//FOR LEVEL NO.4
	
		if(level==4)
		{
			// Drawing Opponent car To Double The Number Of Cars
		

		int x4=300
		int y4=500 
		width = 10; 
		height = 5;
		radius = 5.0;
		
		DrawRoundRect(x4,y4,width,height,color,radius); // bottom left tyre
		DrawRoundRect(x4+width*3,y4,width,height,color,radius); // bottom right tyre
		DrawRoundRect(x4+width*3,y4+height*4,width,height,color,radius); // top right tyre
		DrawRoundRect(x4,y4+height*4,width,height,color,radius); // top left tyre
		DrawRoundRect(x4, y4+height*2, width, height, color, radius/2); // body left rect
		DrawRoundRect(x4+width, y4+height, width*2, height*3, color, radius/2); // body center rect
		DrawRoundRect(x4+width*3, y4+height*2, width, height, color, radius/2); // body right rect
		
		}








	/*
		//Drawing An Extra Circle To Check The Coordinates In The Arena
		float* s1color = colors[WHITE];
		DrawCircle(::cx,::cy,radius,s1color);*/
		
		// Drawing Arena 1
		int gap_turn = 60;
		int sx = 20;
		int sy = 10;
		int swidth = 800/2 - gap_turn/2; // half width
		int sheight = 10;
		float *scolor = colors[BROWN];
		DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
		DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
		DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
		DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
		DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
		DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down


		// Drawing Arena 2
		
		sx = 20+100;
		sy = 10+100;
		swidth = 600/2- gap_turn/2; // half width
		sheight = 8;
		DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
		DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
		DrawRectangle(sx + swidth + gap_turn, sy+810-200, swidth, sheight, scolor); // top left
		DrawRectangle(sx, sy+810-200, swidth, sheight, scolor); // top right
		DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
		DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

		// Drawing Arena 3
		
		sx = 20+100+100;
		sy = 10+100+100;
		swidth = 400/2 - gap_turn/2; // half width
		sheight = 8;
		DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
		DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
		DrawRectangle(sx + swidth + gap_turn, sy+810-200-200, swidth, sheight, scolor); // top left
		DrawRectangle(sx, sy+810-200-200, swidth, sheight, scolor); // top right
		DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
		DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down

		
		// Drawing Arena 4
		sx = 20+100+100+100;
		sy = 10+100+100+100;
		swidth = 200/2 - gap_turn/2; // half width
		sheight = 8;
		DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
		DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
		DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
		DrawRectangle(sx + swidth + gap_turn, sy+810-200-200-200, swidth, sheight, scolor); // top left
		DrawRectangle(sx, sy+810-200-200-200, swidth, sheight, scolor); // top right
		DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
		DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
		
		// DRawing food
    for(int a=0; a<64; a++)
   {
           if(Food[a]==0)
           {
           DrawCircle(Food_X[a],Food_Y[a],7,colors[MAGENTA]);
           }
   } 




		//STRING CATENATION TO DISPLAY THE POINTS LIFES AND LEVEL

		string point3="Points ="+Num2Str(point);
		DrawString(50, 900, point3 , color);

		string lives="Lifes ="+Num2Str(life);
		DrawString(700, 900, lives , color);
		
		string levels="Level  ="+Num2Str(level);
		DrawString(350, 900, levels , color);
	


	 
		
		int radius; 

/*

		
		int j; 	 
		int m;
		int n;
		radius=7;	
		
		//For First 1Half Line Of Food
		m=-35;
		n=760;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Second 1Half Line Of Food
		m=-35;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}
		
		//For Third 1Half Line Of Food
		m=-35;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Forth 1Half Line Of Food
		m=-35;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Fifth 1Half Line Of Food
		m=-35;
		n-=150;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Sixth 1Half Line Of Food
		m=-35;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Seventh 1Half Line Of Food
		m=-35;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Eighth 1Half Line Of Food
		m=-35;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}
		
									//Generation Of The Remaining Half Line
								
		
		//For First 2Half Line Of Food
		m=400;
		n=760;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Second 2Half Line Of Food
		m=400;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}
		
		//For Third 2Half Line Of Food
		m=400;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Forth 2Half Line Of Food
		m=400;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Fifth 2Half Line Of Food
		m=400;
		n-=150;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Sixth 2Half Line Of Food
		m=400;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Seventh 2Half Line Of Food
		m=400;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}

		//For Eighth 2Half Line Of Food
		m=400;
		n-=90;
		for(j=1;j<=4;j++)
		{
		 m+=95;
		if(j!=5)
		DrawCircle(m,n,radius,scolor);
		}
		

*/
} 
		
		glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	}
}

	








/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys( int key, int  x, int  y) {
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	/*	::cx-=3; */
     
		if((::yr>=370 && ::yr<=435) && ( (::xr>=120 && ::xr<=200) || (::xr>=180 && ::xr<=300) || (::xr>=280 && ::xr<=385) || (::xr>=600 && ::xr<=520) || (::xr>=490 && ::xr<=610) || (::xr>=590 && ::xr<=720)  || (::xr>=690 && ::xr<=810) ))  
			 


	    ::xr=::xr-90;	

	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
       
		if(((::yr>=370 && ::yr<=435) && ( (::xr>=-20 && ::xr<=110) || (::xr>=120 && ::xr<=200) || (::xr>=180 && ::xr<=300) || (::xr>=280 && ::xr<=320) || (::xr>=490 && ::xr<=520) || (::xr>=490 && ::xr<=610) || (::xr>=590 && ::xr<=720) || (::xr>=450 && ::xr<=490)  )) ) 
			::xr=::xr+90;	

	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
        
		if((::xr>=375  && ::xr<=425) && ( (::yr>=0 && ::yr<=115)|| (::yr>=95 && ::yr<=215) || (::yr>=185 && ::yr<=315) || (::yr>=285 && ::yr<=300) || (::yr>=425 && ::yr<=525) || (::yr>=500 && ::yr<=625) || (::yr>=605 && ::yr<=700) )) 
			 
		::yr=::yr+90;	
	
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	
		if((::xr>=375 && ::xr<=425 ) && (  (::yr>=95 && ::yr<=215) || (::yr>=185 && ::yr<=315) || (::yr>=300 && ::yr<=350) || (::yr>=425 && ::yr<=525) || (::yr>=500 && ::yr<=625) || (::yr>=605 && ::yr<=725) ||(::yr>=695 && ::yr<=815))) 

		
      ::yr=::yr-90;	

		




	}
		/*
	 This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'p' || key=='P')
			{
		
		//do something if b is pressed
		::p=1;
		cout << "b pressed" <<::p<< endl;

	}
	if (key == 'r' || key=='R')
			{
		
		//do something if b is pressed
		::p=0;
		cout << "r pressed" << ::p<<endl;

	}
	if(key=='s' || key=='S')
	
	{	screen=1;
	glutPostRedisplay();
	}




	if(key=='h' || key=='H')
	{	screen1=1;
	glutPostRedisplay();
	}






}






/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */


void Timer(int m) {
	
	// implement your functionality here
	cout<<"x    ="<<xr<<"   "<<"y    ="<<yr<<endl;
if(life!=0)
{

int h;
      for(h=0;h<64;h++)
    {
          
         if(Food[h]==0)
       {
         if((xr<=Food_X[h] && xr+width*3>=Food_X[h])&&(yr<=Food_Y[h] && yr+height*4>=Food_Y[h]))
         {
            Food[h]=1;
			point=point+1;
            
         }
      
       }
    }
}

if(::point==64)
	{
		::level=2;
	}




/*
//Life Decrement SCNZ

if(x>=xr && x<=xr+width*3)//Condition For Collision

{
	if(y>=yr && y<=yr+height*4)
	{
	//Reducing The Life
   life-=1;
  	
		//Taking Player Car Back To Initial Points
       xr=600;
   	   yr=745; 
       ////Taking Opponent Car Back To Initial Points

	   x=90;
	   y=745;
	}
}
*/
if(life!=0)
{
	
				//For PLAYER CAR

if(::screen==1)
{	
	


	
	
								//for  Arena 1

	if((::yr==55)   &&  (::xr>=55 && ::xr<=745))
	{
		flag=1;
		::xr-=5;
	}
	
	if((::xr==745 ) && (::yr>=55 && ::yr<=745) )
	{
		flag=1;
		::yr-=5;
	}
	
	if((::xr<=745 && ::xr>=55)  &&  (::yr==745) )
	{
		flag=1;
		::xr+=5;
	}
	
	if((::yr<=745 && ::yr>=55)  &&  (::xr==55))
	{
		flag=1;
		::yr+=5;
	}
	
	

	

	
								//for Arena 2
	
	if( (::yr>=150 && ::yr<=665) && (::xr==655) ) //at X
	{
		flag=1;
		::yr-=5;
	}
	
	if( (::yr==145) && (::xr>=140 && ::xr<=655) ) //at Y
	{
		flag=1;
		::xr-=5;
	}
		
	if( (::yr>=145 && ::yr<=655) && (::xr==145) ) //at Z
	{
		flag=1;
		::yr+=5;
	}

	if( (::xr>=145 && ::xr<=655) && (::yr==655) ) //at W
	{
		flag=1;
		::xr+=5;
	}
	
	

										//for Arena 3
	
	if((::yr>=240 && ::yr<=565) && (::xr==565)) //at M
	{
		flag=1;
		::yr-=5;
	}
	
	if((::yr==565) && (::xr>=235 && ::xr<=565)) //at N
	{
		flag=1;
		::xr+=5;
	}
		
	if((::yr>=235 && ::yr<=565) && (::xr==235)) //at O
	{
		flag=1;
		::yr+=5;
	}

	if((::xr>=235 && ::xr<=565) && (::yr==235)) //at P
	{
		flag=1;
		::xr-=5;
	}
	
	
	

										//for Arena 4
	
	if((::yr>=325  && ::yr<=480) && (::xr==475) ) //at E
	{
		flag=1;
		::yr-=5;
	}
	
	if((::xr>=325 && ::xr<=475) && (::yr==475)) //at F
	{
		flag=1;
		::xr+=5;
	}
		
	if((::yr>=320 && ::yr<=475) && (::xr==325)) //at G
	{
		flag=1;
		::yr+=5;
	}

	if((::xr>=325+5 && ::xr<=475) && (::yr==325)) //at H
	{
		flag=1;
		::xr-=5;
	}
	
	

	
	//OPPONENT  CAR

								//for  Arena 1

	if((::y==60)   &&  (::x>=55 && ::x<=745))
	{
		flag=1;
		::x+=5;
	}
	
	if((::x==745 ) && (::y>=60 && ::y<=745) )
	{
		flag=1;
		::y+=5;
	}
	
	if((::x<=745 && ::x>=55)  &&  (::y==745) )
	{
		flag=1;
		::x-=5;
	}
	
	if((::y<=745 && ::y>=60)  &&  (::x==55))
	{
		flag=1;
		::y-=5;
	}
	
	

	

	
								//for Arena 2
	
	if( (::y>=150 && ::y<=665) && (::x==655) ) //at X
	{
		flag=1;
		::y+=5;
	}
	
	if( (::y==150) && (::x>=140 && ::x<=655) ) //at Y
	{
		flag=1;
		::x+=5;
	}
		
	if( (::y>=150 && ::y<=655) && (::x==145) ) //at Z
	{
		flag=1;
		::y-=5;
	}

	if( (::x>=140 && ::x<=655) && (::y==655) ) //at W
	{
		flag=1;
		::x-=5;
	}
	
	

										//for Arena 3
	
	if((::y>=240 && ::y<=565) && (::x==565)) //at M
	{
		flag=1;
		::y+=5;
	}
	
	if((::y==565) && (::x>=235 && ::x<=565)) //at N
	{
		flag=1;
		::x-=5;
	}
		
	if((::y>=240 && ::y<=565) && (::x==235)) //at O
	{
		flag=1;
		::y-=5;
	}

	if((::x>=235 && ::x<=565) && (::y==240)) //at P
	{
		flag=1;
		::x+=5;
	}
	
	
	

										//for Arena 4
	
	if((::y>=325  && ::y<=470) && (::x==475) ) //at E
	{
		flag=1;
		::y+=5;
	}
	
	if((::x>=325 && ::x<=475) && (::y==475)) //at F
	{
		flag=1;
		::x-=5;
	}
		
	if((::y>=330 && ::y<=475) && (::x==325)) //at G
	{
		flag=1;
		::y-=5;
	}

	if((::x>=325 && ::x<=470) && (::y==330)) //at H
	{
		flag=1;
		::x+=5;
	}
	 

										//ARTIFICIAL INTELLIGENCE SCNZ
/*
PLAYER CAR CONDITIONS 

Arena 1
(yr==55 || xr==745 || yr==745 || xr==55)

Arena 2 
(yr==145 || xr==655 || yr==655 || xr==145)

Arena 3
(yr==565 || xr==565 || yr==235 || xr==235)

Arena 4
(yr==475 || xr==475 || yr==325 || xr==325)


OPPONENT CAR CONDITIONS

Arena 1
(y==60 || x==745 || y==745 || x==55)

Arena 2
(y==655 || x==145 || y==150 || x==655)

Arena 3
(y==565 || x==565 || y==240 || x==235)

Arena 4
(y==475 || x==475 || y==330 || x==325)


*/

									// (PART 1)  FOR ALL UP DOWN MOVEMENT)


					//(1)	FOR ALL DOWNWARD MOVEMENT 			




										// (I)FOR DOWNWARD MOVEMENT OF OPPONENT CAR FROM UPPER END 


//WHEN OPPONENT IS IN ARENA 1

if	( 
		(::yr==145 || ::xr==655 || ::yr==655 || ::xr==145) 	&& 	(::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::y==745) && 

		 ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)
	::y-=90;
	


else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235 || ::xr==235) 	&&	 (::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::y==745) &&  
	
		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y-=90;

else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	 && 	(::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::y==745) &&  
	
		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y-=90;

//WHEN OPPONENT IS IN ARENA 2
else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235  || ::xr==235) 	&&	 (::y==150 || ::x==145 || ::y==655 || ::x==655)	&& (::y==655) &&

	    ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y-=90;

else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	 	&& 	 (::y==150 || ::x==655 || ::y==655 || ::x==145)	&& (::y==655) && 
	
	    ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	y-=90;

//WHEN OPPONENT CAR IS IN ARENA 3
else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	    && 	 (::y==565 || ::x==565 || ::y==240 || ::x==235)	&& (::y==565) && 

	    ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y-=90;


									// (II) FOR DOWNWARD MOVEMENT OF OPPONENT CAR FROM LOWER END

	//PLAYER CAR IS IN ARENA 1
else
if	( 
		(::yr==55 || ::xr==745 || ::yr==745 || ::xr==55)	     &&	  (::y==150 || ::x==655 || ::y==655 || ::x==145) && (::y==150) && 

	    ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)

	::y-=90;

else
if	( 
	    (::yr==55 || ::xr==745 || ::yr==745 || ::xr==55) 		 &&  (::y==565 || ::x==565 || ::y==240 || ::x==235) && (::y==240) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)
	
	::y-=90;

else
if	( 
		(::yr==55 || ::xr==745 || ::yr==745 || ::xr==55) 		 && (::y==475 || ::x==475 || ::y==330 || ::x==325)	&& (::y==330) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)
	{
	y-=90;
	cout<<" 1 1 1 1 1 1 1";
	}
	//PLAYER CAR IS IN ARENA 2
else
if	( 
		(::yr==145 || ::xr==145 || ::yr==655 || ::xr==655) 		  &&  (::y==565 || ::x==565 || ::y==240 || ::x==235)	 && (::y==240) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)

	::y-=90;

else
if	( 
		(::yr==145 || ::xr==145 || ::yr==655 || ::xr==655)		  &&   (::y==475 || ::x==325 || ::y==330 || ::x==475)	&& (::y==330) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)

	::y-=90;

	
	//PLAYER CAR IS IN ARENA 3


else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235 || ::xr==235) 		  &&   (::y==475 || ::x==325 || ::y==330 || ::x==475)	&& (::y==330) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)

	::y-=90;

/*
PLAYER CAR CONDITIONS 

Arena 1
(yr==55 || xr==745 || yr==745 || xr==55)

Arena 2 
(yr==145 || xr==655 || yr==655 || xr==145)

Arena 3
(yr==565 || xr==565 || yr==235 || xr==235)

Arena 4
(yr==475 || xr==475 || yr==325 || xr==325)


OPPONENT CAR CONDITIONS

Arena 1
(y==60 || x==745 || y==745 || x==55)

Arena 2
(y==655 || x==145 || y==150 || x==655)

Arena 3
(y==565 || x==565 || y==240 || x==235)

Arena 4
(y==475 || x==475 || y==330 || x==325)


*/







						//(2)	FOR ALL UPWARD MOVEMENT 

			
			// (I)FOR UPWARD MOVEMENT OF OPPONENT CAR IN UPPER END

		
		

	//PLAYER CAR IS IN ARENA 1
else
if	( 
		(::yr==55 || ::xr==745 || ::yr==745 || ::xr==55)	     &&	  (::y==150 || ::x==655 || ::y==655 || ::x==145) && (::y==655) && 

	    ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)

	::y+=90;

else
if	( 
	    (::yr==55 || ::xr==745 || ::yr==745 || ::xr==55) 		 &&  (::y==565 || ::x==565 || ::y==240 || ::x==235) && (::y==565) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)
	
	::y+=90;

else
if	( 
		(::yr==55 || ::xr==745 || ::yr==745 || ::xr==55) 		 && (::y==475 || ::x==475 || ::y==330 || ::x==325)	&& (::y==475) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)
	{
	::y+=90;
	cout<<" 1 1 1 1 1 1 1";
	}
	//PLAYER CAR IS IN ARENA 2
else
if	( 
		(::yr==145 || ::xr==145 || ::yr==655 || ::xr==655) 		  &&  (::y==565 || ::x==565 || ::y==240 || ::x==235)	 && (::y==565) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)

	::y+=90;

else
if	( 
		(::yr==145 || ::xr==145 || ::yr==655 || ::xr==655)		  &&   (::y==475 || ::x==325 || ::y==330 || ::x==475)	&& (::y==475) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)

	::y+=90;

	
	//PLAYER CAR IS IN ARENA 3


else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235 || ::xr==235) 		  &&   (::y==475 || ::x==325 || ::y==330 || ::x==475)	&& (::y==475) &&  

		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)

	::y+=90;

					// (II)FOR UPWARD MOVEMENT OF OPPONENT CAR IN LOWER END 


//WHEN OPPONENT IS IN ARENA 1
else
if	( 
		(::yr==145 || ::xr==655 || ::yr==655 || ::xr==145) 	&& 	(::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::y==60) && 

		 ((::x>=400  && ::x<=425) && ( (::y>=0 && ::y<=115)|| (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=285 && ::y<=300) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=700) ))
			
	)
	::y+=90;
	


else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235 || ::xr==235) 	&&	 (::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::y==60) &&  
	
		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y+=90;

else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	 && 	(::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::y==60) &&  
	
		((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y+=90;

//WHEN OPPONENT IS IN ARENA 2
else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235  || ::xr==235) 	&&	 (::y==150 || ::x==145 || ::y==655 || ::x==655)	&& (::y==150) &&

	    ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y+=90;

else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	 	&& 	 (::y==150 || ::x==655 || ::y==655 || ::x==145)	&& (::y==150) && 
	
	    ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y+=90;

//WHEN OPPONENT CAR IS IN ARENA 3
else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	    && 	 (::y==565 || ::x==565 || ::y==240 || ::x==235)	&& (::y==240) && 

	    ((::x>=400 && ::x<=425 ) && (  (::y>=95 && ::y<=215) || (::y>=185 && ::y<=315) || (::y>=300 && ::y<=350) || (::y>=425 && ::y<=525) || (::y>=500 && ::y<=625) || (::y>=605 && ::y<=725) ||(::y>=695 && ::y<=815) ))

	)


	::y+=90;


}

//THIS CONDITION IS VALID IN LEVEL 2
if(level==2)
{

										// (PART 2) FOR ALL RIGHT / LEFT MOVEMENT
								

					//(1)FOR ALL LEFT MOVEMENT 	


										// (I)FOR MOVEMENT OF OPPONENT CAR TO LEFT ON LEFT SIDE


//WHEN OPPONENT IS IN ARENA 1

if	( 
		(::yr==145 || ::xr==655 || ::yr==655 || ::xr==145) 	&& 	(::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::x==745) && 

		 ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::xr<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  
	)
	::x-=90;
	


else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235 || ::xr==235) 	&&	 (::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::x==745) &&  
	
		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	::x-=90;

else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	 && 	(::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::x==745) &&  
	
		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	::x-=90;

//WHEN OPPONENT IS IN ARENA 2
else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235  || ::xr==235) 	&&	 (::y==150 || ::x==145 || ::y==655 || ::x==655)	&& (::x==655) &&

	    ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	::x-=90;

else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	 	&& 	 (::y==150 || ::x==655 || ::y==655 || ::x==145)	&& (::x==655) && 
	
	    ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	x-=90;

//WHEN OPPONENT CAR IS IN ARENA 3
else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	    && 	 (::y==565 || ::x==565 || ::y==240 || ::x==235)	&& (::x==565) && 

	    ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	::x-=90;

										// (II)FOR MOVEMENT OF OPPONENT CAR TO LEFT ON RIGHT SIDE

	//PLAYER CAR IS IN ARENA 1
else
if	( 
		(::yr==55 || ::xr==745 || ::yr==745 || ::xr==55)	     &&	  (::y==150 || ::x==655 || ::y==655 || ::x==145) && (::x==145) && 

	    ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)

	::x-=90;

else
if	( 
	    (::yr==55 || ::xr==745 || ::yr==745 || ::xr==55) 		 &&  (::y==565 || ::x==565 || ::y==240 || ::x==235) && (::x==235) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)
	
	::x-=90;

else
if	( 
		(::yr==55 || ::xr==745 || ::yr==745 || ::xr==55) 		 && (::y==475 || ::x==475 || ::y==330 || ::x==325)	&& (::x==325) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)
	{
	::x-=90;
	cout<<" 1 1 1 1 1 1 1";
	}
	//PLAYER CAR IS IN ARENA 2
else
if	( 
		(::yr==145 || ::xr==145 || ::yr==655 || ::xr==655) 		  &&  (::y==565 || ::x==565 || ::y==240 || ::x==235)	 && (::x==235) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)

	::x-=90;

else
if	( 
		(::yr==145 || ::xr==145 || ::yr==655 || ::xr==655)		  &&   (::y==475 || ::x==325 || ::y==330 || ::x==475)	&& (::x==325) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)

	::x-=90;

	
	//PLAYER CAR IS IN ARENA 3


else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235 || ::xr==235) 		  &&   (::y==475 || ::x==325 || ::y==330 || ::x==475)	&& (::x==325) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)

	::x-=90;


					//(2)FOR ALL RIGHT MOVEMENT 	


										// (I)FOR MOVEMENT OF OPPONENT CAR TO RIGHT ON RIGHT SIDE


//WHEN OPPONENT IS IN ARENA 1

if	( 
		(::yr==145 || ::xr==655 || ::yr==655 || ::xr==145) 	&& 	(::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::x==55) && 

		 ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::xr<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  
	)
	::x+=90;
	


else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235 || ::xr==235) 	&&	 (::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::x==55) &&  
	
		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	::x+=90;

else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	 && 	(::y==60 || ::x==745 || ::y==745 || ::x==55)	&& (::x==55) &&  
	
		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	::x+=90;

//WHEN OPPONENT IS IN ARENA 2
else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235  || ::xr==235) 	&&	 (::y==150 || ::x==145 || ::y==655 || ::x==655)	&& (::x==145) &&

	    ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	::x+=90;

else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	 	&& 	 (::y==150 || ::x==655 || ::y==655 || ::x==145)	&& (::x==145) && 
	
	    ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	x+=90;

//WHEN OPPONENT CAR IS IN ARENA 3
else
if	( 
		(::yr==475 || ::xr==475 || ::yr==325 || ::xr==325)	    && 	 (::y==565 || ::x==565 || ::y==240 || ::x==235)	&& (::x==235) && 

	    ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)


	::x+=90;

									// (I)FOR MOVEMENT OF OPPONENT CAR TO RIGHT ON LEFT SIDE

	//PLAYER CAR IS IN ARENA 1
else
if	( 
		(::yr==55 || ::xr==745 || ::yr==745 || ::xr==55)	     &&	  (::y==150 || ::x==655 || ::y==655 || ::x==145) && (::x==655) && 

	    ((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)

	::x+=90;

else
if	( 
	    (::yr==55 || ::xr==745 || ::yr==745 || ::xr==55) 		 &&  (::y==565 || ::x==565 || ::y==240 || ::x==235) && (::x==565) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)
	
	::x+=90;

else
if	( 
		(::yr==55 || ::xr==745 || ::yr==745 || ::xr==55) 		 && (::y==475 || ::x==475 || ::y==330 || ::x==325)	&& (::x==475) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)
	{
	::x+=90;
	cout<<" 1 1 1 1 1 1 1";
	}
	//PLAYER CAR IS IN ARENA 2
else
if	( 
		(::yr==145 || ::xr==145 || ::yr==655 || ::xr==655) 		  &&  (::y==565 || ::x==565 || ::y==240 || ::x==235)	 && (::x==565) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)

	::x+=90;

else
if	( 
		(::yr==145 || ::xr==145 || ::yr==655 || ::xr==655)		  &&   (::y==475 || ::x==325 || ::y==330 || ::x==475)	&& (::x==475) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)

	::x+=90;

	
	//PLAYER CAR IS IN ARENA 3


else
if	( 
		(::yr==565 || ::xr==565 || ::yr==235 || ::xr==235) 		  &&   (::y==475 || ::x==325 || ::y==330 || ::x==475)	&& (::x==475) &&  

		((::y>=400 && ::y<=425) && ( (::x>=-20 && ::x<=110) || (::x>=120 && ::x<=200) || (::x>=180 && ::x<=300) || (::x>=280 && ::x<=320) || (::x>=490 && ::x<=520) || (::x>=490 && ::x<=610) || (::x>=590 && ::x<=720) || (::x>=450 && ::x<=490)  ))  

	)

	::x+=90;



}

	

	

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutPostRedisplay();
	glutTimerFunc(2.5, Timer, 0);
}
	
	
}


/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {

	

	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {
	
{
	cout<<"X  =   "<<::x<<"    "<<"Y   =   "<<::y<<endl;

	//cout<<"XR  =   "<<::xr<<"    "<<"YR   =   "<<::yr<<endl;

	

   
	//cout<<"XC  =  "<<::cx<<"     "<<"YR   =  "<<::cy<<endl;
	
	   	
}
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
				
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	for(int i=0;i<64;i++)
	{
	 	Food[i]=0;
	}
	set_food_cordinates();








	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 1000; // i have set my window size to be 840 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 20); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("DODGE EM "); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	
	

	

	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
