# include "iGraphics.h"

int ballPosition_x =670, ballPosition_y = 36, ballDirection=1,randomNumber, ballMidPoint;
int stickPosition_x= 620, stickPositon_y= 10;
int flag=1 ,i,j,choice=0,L_choice=0,baltu=0,exit_f=0,file_fp=0,score=0;
int dx=4, dy=4, intrigation=0, r_play=0,life_count=0;
int brick_a[100]={},brick_a2[200][200]={},BrickNum[100],db=0,dbCount=0,test=0, i2,p2,j2,k2;
char str[100];
int count_i2=0,count_j2=0;
void brickDestruction(){

  if(ballPosition_y >=664 ){
    for(j=0;j<70;j++){

        if(ballPosition_x>=280+73*j && ballPosition_x<=((73*j+280)+70)){
                for(dbCount=0;dbCount<db;dbCount++){
                if(BrickNum[dbCount]==j){
                    continue;
                }

            }

            brick_a[j]=1;
              score+=2;printf("%d %d level %d\n",score,db,L_choice);
              BrickNum[db]=j;
              db++;
              sprintf(str,"1: %d",db*6);

        }
        if(!test)
         {  test=0;
           if(ballDirection==1)
             ballDirection=3;
           else if (ballDirection==2)
              ballDirection=4;
         }
    }
  }
}

void ballMovement(){
  if(baltu){
    if(ballPosition_y<26){
        exit_f=1;
        life_count--;
        r_play=0;
        iPauseTimer(0);
        ballPosition_x =670, ballPosition_y = 36;
        stickPosition_x= 620, stickPositon_y= 10;
    }
 }

    if(ballPosition_y == 36){

          if(ballDirection==3){

           if(ballPosition_x<=stickPosition_x+100 && ballPosition_x>= stickPosition_x ){
               ballDirection=1;
        }
    }
        else if ( ballDirection==4){
            if(ballPosition_x<=stickPosition_x+100 && ballPosition_x>= stickPosition_x)
                  ballDirection = 2;
        }

    }
    else if(ballPosition_y>=690){
        if(ballDirection==1)
        ballDirection=3;
        else if(ballDirection==2)
        ballDirection=4;

        }
    else if(ballPosition_x<=280){

            if(ballDirection==1){
                ballDirection=2;
            }
            else if(ballDirection==3){
                ballDirection=4;
            }
        }
    else if(ballPosition_x>=1330){

            if(ballDirection==2){
                ballDirection=1;
            }
            else if(ballDirection==4){
                ballDirection=3;
            }
        }

        if(ballDirection==1){
            ballPosition_x-=dx;
            ballPosition_y+=dy;

        }
        else  if(ballDirection==2){
            ballPosition_x+=dx;
            ballPosition_y+=dy;

        }
        else  if(ballDirection==3){
            ballPosition_x-=dx;
            ballPosition_y-=dy;

        }
        else  if(ballDirection==4){
            ballPosition_x+=dx;
            ballPosition_y-=dy;

        }

  }

/*
	function iDraw() is called again and again by the system.

	*/

void iDraw() {
	//place your drawing codes here
	iClear();
    iSetColor(100,100,100);
    iFilledRectangle(10,10, 1330,680);
    iSetColor(300,150,150);
	iRectangle(10,10, 1330,680);
	iLine(280,690,280,10);
    iSetColor(300,150,150);
    iFilledRectangle(50,510,190,65);
    iFilledRectangle(50,410,190,65);
	iFilledRectangle(50,310,190,65);
    iFilledRectangle(50,210,190,65);
    iFilledRectangle(50,110,190,65);
    if(exit_f && !r_play){
        iFilledRectangle(670,350,190,65);
        iSetColor(250,300,0);
	   iText(710,375,"REPLAY",GLUT_BITMAP_TIMES_ROMAN_24);
    }

	   iSetColor(250,300,0);
	   iText(105,535,"START",GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(105,435,"LEVEL",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(62,335,"SCORE BOARD",GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(105,235,"HELP",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(105,135,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

     if(choice==1 && choice!=6 ){
        iLine(280,690,280,10);
     iSetColor(20, 200, 200);
	iFilledCircle(ballPosition_x,ballPosition_y,10);
	iSetColor(200,510,0);
	iFilledRectangle(stickPosition_x,stickPositon_y,100,16);
	iSetColor(300,150,150);
	iFilledRectangle(50,15,190,65);
	iSetColor(250,300,0);
	iText(105,35,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	if(L_choice==1){
	 for(i=0;i<70;i++)
	{
      {if(i%2==0)
	      iSetColor(300,0,100);
        else iSetColor(250,200,10);}
         if(brick_a[i]==0)
	       iFilledRectangle(280+73*i,674,70,16);
	 }
	}

	if(L_choice==2){

       k2=330;
   p2=50;
        for(j2=350;j2<650;j2+=15) {

       for(i2=k2;i2<1060-p2;i2+=50)
       {
           if((i2+j2)%3==0)
           {
               iSetColor(0,255,0);
           }
           else if((i2+j2)%13==0)
           {
               iSetColor(0,0,255);
           }
          if(brick_a2[count_i2][count_j2]==0)
           iFilledRectangle(i2,j2,50,15);
           count_j2++;
       }
       k2=k2+50;
       p2=p2+50;
     count_i2++;
   }
   k2=330;
   p2=50;
    for(j2=335;j2>50;j2=j2-=15)
    {
      for(i2=k2+50;i2<1060-p2-50;i2=i2+=50)
       {

          if((i2+j2)%3==0)
           {
               iSetColor(0,255,0);
           }
            if((i2+j2)%13==0)
           {
               iSetColor(200,0,255);
           }

           iFilledRectangle(i2,j2,50,15);


       }
       k2=k2+50;
       p2=p2+50;
    }


	}
  }


     else if( choice==2 && choice!=6 ){

            iSetColor(300,150,150);
	 iFilledRectangle(290,410,190,65);
	  iFilledRectangle(290,310,190,65);
	  iFilledRectangle(290,210,190,65);
	  iSetColor(250,300,0);
	 iText(320,445,"EASY",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(315,345,"MEDIUM",GLUT_BITMAP_TIMES_ROMAN_24);
	 iText(320,245,"HARD",GLUT_BITMAP_TIMES_ROMAN_24);
	 iSetColor(300,150,150);
	iFilledRectangle(50,15,190,65);
	iSetColor(250,300,0);
	iText(105,35,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
     }

      else if( choice==3){
           iSetColor(250,300,0);
	 iText(320,445,str,GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(300,150,150);
	iFilledRectangle(50,15,190,65);
	iSetColor(250,300,0);
	iText(105,35,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
     }
      else if( choice==4 ){
            iSetColor(300,150,150);
	iFilledRectangle(50,15,190,65);
	iSetColor(250,300,0);
	iText(105,35,"BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(290,535,"Catch the ball before it goes down.Press the",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(290,510,"mouse and move it to move the stick.Continue",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(290,485,"this until all the brick destroyed.Thus  ",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(290,460,"complete the level & try the next hard one.",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(290,300,"Copyright-2016 @ MAHBUB",GLUT_BITMAP_TIMES_ROMAN_24);

     }

      else if( choice==5 ){
             exit(0);
     }
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//printf("x = %d, y= %d\n",mx,my);
	//place your codes here
	stickPosition_x=mx;

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
        if( mx>=50 && mx<=240 && my >=510 && my<=575 ){
            choice=1;
        }

        if ( mx>=50 && mx<=240 && my >=410 && my<=475){
            choice=2;

        }
        if(choice==2){
            if ( mx>=290 && mx<=480 && my >=410 && my<=475){
            L_choice=1;

        }
        if( mx>=290 && mx<=480 && my >=310 && my<=375){
            L_choice=2;
        }
         if( mx>=290 && mx<=480 && my >=210 && my<=275){
           L_choice=3;
        }
        }
        if( mx>=50 && mx<=240 && my >=310 && my<=375){
            choice=3;
        }
        if( mx>=50 && mx<=340 && my >=210 && my<=275){
            choice=4;
        }
        if( mx>=50 && mx<=240 && my >=110 && my<=175){
            choice=5;
        }
        else if(mx>=50 && mx<=240 && my>=15 && my<=80){
            choice=6;
        }
         else if(mx>=670 && mx<=860 && my>=350 && my<=415){
            r_play=1;
            iResumeTimer(0);
        }

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {
	//place your codes for other keys here
	if(key==GLUT_KEY_F1){
        baltu=1;
        iResumeTimer(0);
	}

}


int main() {
	//place your own initialization codes here.


	iSetTimer(10,ballMovement);
	iSetTimer(10,brickDestruction);
	if( exit_f )
        iPauseTimer(0);
	//PlaySound("Video_Game_Splash-Ploor-699235037",NULL,SND_LOOP|SND_ASYNC);
	iInitialize(1350, 700, "DX Ball");
	return 0;
}
