//g++ 'ambulance.cpp' -lGL -lGLU -lglut

#include<GL/glut.h>
#include<math.h>

int seq=0;
float a,b1,b2,by1=0,by2=0,s=0;
int k=0;

void rgb(int r,int g,int b)
{
  glColor3f(r/255.0,g/255.0,b/255.0);	
}

void displaytext(float r,float g,float b,const char *string,int x,int y)
{
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *string++);   
}

void start()
{
     displaytext(0.9,0.5,0.8,"CG MINI PROJECT",460,320);
     displaytext(0.9,0.5,0.8,"________________",460,310);
     displaytext(0.9,0.5,0.8,"AMBULANCE ON TRAFFIC",440,280);
     displaytext(0.9,0.5,0.8,"4SF14CS007 & 4SF14CS015",430,240);
     if(k<10)
      displaytext(0.6,0.2,0.7,"Press any key!",470,70);
     k++;
     k=k%20;
     glutPostRedisplay();
     glutSwapBuffers();
}

void end()
{
	 glClearColor(0,0,0,1.0);
     displaytext(0.6,0.2,0.7,"GIVE WAY TO AMBULANCE",450,320);
     glutPostRedisplay();
     glutSwapBuffers();
}

void DrawCircle(float cx, float cy, float r) 
{ 
	int num_segments=360,degree=360;
	glBegin(GL_POLYGON);
	
	for(int i = 0; i < degree; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void sky()
{
  //sky
  glColor3f(0.0,0.9,0.9);
  glBegin(GL_POLYGON);
  glVertex2f(0,450);
  glVertex2f(0,700);
  glVertex2f(1100,700);
  glVertex2f(1100,450);
  glEnd();
}

void sun()
{
  //sun
  rgb(247, 92, 49);
  DrawCircle(645,620,40);
}

void bus()
{
  rgb(244, 66, 176);//side
  glBegin(GL_POLYGON);
  glVertex2f(10,145);
  glVertex2f(10,180);
  glVertex2f(100,180);
  glVertex2f(110,145);
  glEnd();
  
  rgb(249, 107, 195);//front
  glBegin(GL_POLYGON);
  glVertex2f(110,145);
  glVertex2f(100,180);
  glVertex2f(110,200);
  glVertex2f(120,165);
  glEnd();
  
  rgb(247, 245, 244);//glass
  glBegin(GL_POLYGON);
  glVertex2f(107,160);
  glVertex2f(102.5,178);
  glVertex2f(110.5,195);
  glVertex2f(115,175);
  glEnd();
  
  
  rgb(194, 197, 198);//top
  glBegin(GL_POLYGON);
  glVertex2f(10,180);
  glVertex2f(100,180);
  glVertex2f(110,200);
  glVertex2f(20,200);
  glEnd();
  
  glPointSize(8);//window
  glColor3f(1,1,1);
  glBegin(GL_POINTS);
  glVertex2f(20,170);
  glVertex2f(35,170);
  glVertex2f(50,170);
  glVertex2f(65,170);
  glVertex2f(80,170);
  glVertex2f(95,170);
  glEnd();
  
  rgb(255,255,255);
  glLineWidth(10);
  glBegin(GL_LINES);//headlight
  glVertex2f(111,155);
  glVertex2f(112,155);
  glEnd(); 
  
  glBegin(GL_LINES);//headlight
  glVertex2f(116,165);
  glVertex2f(117,165);
  glEnd();
  
  rgb(0,0,0);
  glPointSize(4);//
  glBegin(GL_POINTS);
  glVertex2f(107,167);
  glEnd();
  
  rgb(0,0,0);//tires
  DrawCircle(35,145,5);
  DrawCircle(95,145,5);
}

void ambulance()
{
  //side
  rgb(247, 245, 244);
  glBegin(GL_POLYGON);
  glVertex2f(10,145);
  glVertex2f(10,180);
  glVertex2f(100,180);
  glVertex2f(110,145);
  glEnd();
  
  rgb(200, 200, 200);//front
  glBegin(GL_POLYGON);
  glVertex2f(110,145);
  glVertex2f(100,180);
  glVertex2f(110,200);
  glVertex2f(120,165);
  glEnd();
  
  rgb(247, 245, 244);//glass
  glBegin(GL_POLYGON);
  glVertex2f(107,160);
  glVertex2f(102.5,178);
  glVertex2f(110.5,195);
  glVertex2f(115,175);
  glEnd();
  
  
  rgb(194, 197, 198);//top
  glBegin(GL_POLYGON);
  glVertex2f(10,180);
  glVertex2f(100,180);
  glVertex2f(110,200);
  glVertex2f(20,200);
  glEnd();
  
  glPointSize(15);//window
  rgb(220, 219, 221);
  glBegin(GL_POINTS);
  glVertex2f(25,165);
  glVertex2f(55,165);
  glVertex2f(85,165);
  glEnd();
  
  rgb(255,255,255);
  glLineWidth(10);
  glBegin(GL_LINES);//headlight
  glVertex2f(111,155);
  glVertex2f(112,155);
  glEnd(); 
  
  glBegin(GL_LINES);//headlight
  glVertex2f(116,165);
  glVertex2f(117,165);
  glEnd();
  
  rgb(0,0,0);
  glPointSize(4);//
  glBegin(GL_POINTS);
  glVertex2f(107,167);
  glEnd();
  
  rgb(0,0, 0);//tires
  DrawCircle(35,145,5);
  DrawCircle(95,145,5);
  
  if(k<15)//siren
    rgb(200,0,0);//red
  if(k>15)
    rgb(0,0,200);//blue
  glLineWidth(5);
  glBegin(GL_LINES);
  glVertex2f(97,182);
  glVertex2f(106,198);
  glEnd();
  k++;
  k=k%30;
  
}

void road()
{
   rgb(61, 60, 63);//vertical
   glBegin(GL_POLYGON);
   glVertex2f(500,0);
   glVertex2f(600,0);
   glVertex2f(450,445);
   glVertex2f(430,445);
   glEnd(); 
   
   glBegin(GL_POLYGON);//horizontal
   glVertex2f(0,215);
   glVertex2f(1100,215);
   glVertex2f(1100,300);
   glVertex2f(0,300);
   glEnd(); 
}

void mountain()
{
  rgb(160, 118, 1);
  glBegin(GL_POLYGON);
  glVertex2f(0,450);
  glVertex2f(250,600);
  glVertex2f(400,460);
  glVertex2f(550,650);
  glVertex2f(850,500);
  glVertex2f(1000,550);
  glVertex2f(1100,500);
  glVertex2f(1100,450);
  glEnd();
}

void tree()
{
  glColor3f(0.5019,0.0,0.0);
  glBegin(GL_POLYGON);//stem
  glVertex2f(350,325);
  glVertex2f(350,395);
  glVertex2f(365,395);
  glVertex2f(365,325);
  glEnd();

  glColor3f(0.0,0.5,0.0);
  glBegin(GL_TRIANGLES);//leaf
  glVertex2f(310,380);
  glVertex2f(410,380);
  glVertex2f(360,460);
  glEnd();
  
  
  glColor3f(0.0,0.5,0.0);
  glBegin(GL_TRIANGLES);//leaf
  glVertex2f(320,415);
  glVertex2f(400,415);
  glVertex2f(360,480);
  glEnd();
}

void draw_tree()
{
  glPushMatrix();
  glTranslated(50,0,0);
  tree();
  glPopMatrix();
  
  glPushMatrix();
  glTranslated(200,-380,0);
  glScaled(1.5,1.5,0);
  tree();
  glPopMatrix();
  
  glPushMatrix();
  glTranslated(400,230,0);
  glScaled(0.6,0.6,0);
  tree();
  glPopMatrix();
}

void process()
{
	glClearColor(0.1,0.7,0.0,1.0);
	sky();
    sun();
    mountain();
    road();
	
	a+=3;  
      
	if(a>1300)
	 a=-800;
	 
	b1+=2;
	if(b1>1300)
	{
      b1=-800;
	} 
	 
	b2+=2;
	if(b2>1300)
	{
      b2=-800;
	} 
    
    if(b1>=a/3+50 && b1<=a/3+100)
      by1+=0.5;
    if(b1>=a/3+300 && b1<=a/3+350)
      by1-=0.5;
      
    if(b2>=a/3+250 && b2<=a/3+300)
      by2+=0.5;
    if(b2>=a/3+500 && b2<=a/3+550)
      by2-=0.5;
        
    glPushMatrix();
    glTranslatef(b1+200,by1+100,0);
    bus();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(b2+400,by2+100,0);
    bus();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(a,95,0);
    ambulance();
    glPopMatrix();
    
    draw_tree();
	  
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  if(seq==0)
  {
    start();
  }
  if(seq==1)
  {  
	process();
  }
  if(seq==2)
  {
	 end(); 
  }
  
  glutPostRedisplay();
  glutSwapBuffers();
}

void myinit()
{
  glClearColor(0.0,0.0,0.0,1.0);
  gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void keys(unsigned char key,int x,int y)
{
	seq+=1;	
	if(seq>2)
	  seq=2;		
}

int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowSize(1100.0,700.0);
  glutInitWindowPosition(0,0);
  glutCreateWindow("AMBULANCE");
  glutKeyboardFunc(keys);
  myinit();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
