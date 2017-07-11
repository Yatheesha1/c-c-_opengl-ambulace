#include <GL/glut.h>
#include <math.h>

GLfloat m=600,b=-1000;
int seq=0,k=0;

int flag=0;

void rgb(int r,int g,int b)
{
  glColor3f(r/255.0,g/255.0,b/255.0);	
}

void Printtext(float r,float g,float b,const char *string,int x,int y)
{
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void start()
{
   Printtext(0.9,0.5,0.5,"DEPARTMENT OF COMPUTER SCIENCE ",-200,0); 
   Printtext(0.9,0.5,0.5,"       CG MINI PROJECT         ",-120,-30); 
   Printtext(0.9,0.5,0.5,"______________________________ ",-200,-60);
   Printtext(0.9,0.5,0.5,"           ACCIDENT            ",-100,-90);   
   Printtext(0.9,0.5,0.5,"SHANIDA NIHMATH KOTA-4SF13CS085",-200,-120);
   Printtext(0.9,0.5,0.5,"SREEREKHA NAMBIAR -  4SF13CS101",-180,-150); 
   if(k)
      Printtext(0.6,0.2,0.7,"Press any key!",-40,-250);
   k=~k;
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

void mobile()
{
  glLineWidth(40);
  rgb(133, 134, 135);
  glBegin(GL_LINES);
  glVertex2f(-350,-250);
  glVertex2f(-340,-260);
  glEnd();
}

void man()
{
	glColor3f(0.98,0.89,0.535);//face
	glBegin(GL_POLYGON);
	glVertex2f(22,4);
	glVertex2f(21,8);
	glVertex2f(20,8);
	glVertex2f(18,10);
	glVertex2f(21,13);
	glVertex2f(18,13);
	glVertex2f(18,14);
	glVertex2f(17,14);
	glVertex2f(17.5,14.5);
	glVertex2f(16,15);
	glVertex2f(20,20);
	glVertex2f(30,20);
	glVertex2f(30,8);
	glVertex2f(28,7);
	glVertex2f(28,5);
	glEnd();
	
	glColor3f(0,0,0);//hair
	glBegin(GL_POLYGON);
	glVertex2f(20,20);
	glVertex2f(28.5,18);
	glVertex2f(27,15);
	glVertex2f(30,20);
	glVertex2f(30,15);
	glVertex2f(32,14);
	glVertex2f(34,15);
	glVertex2f(22,25);
	glVertex2f(20,23);
	glEnd();

	glPointSize(2.5);//eye
	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex2f(20,16.5);
	glEnd();

	glLineWidth(0.5);//mouth
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(18,11.5);
	glVertex2f(19,10.5);
	glVertex2f(20,10);
	glEnd();
	
	rgb(155, 92, 9);//shirt
	glBegin(GL_POLYGON);
	glVertex2f(21,3.5);
	glVertex2f(28,5);
	glVertex2f(29,-25);
	glVertex2f(17,-25);
	glVertex2f(20,0);
	glVertex2f(21,1);
	glEnd();
	
	glLineWidth(0.5);
	glColor3f(0,0,0);//handblack
	glBegin(GL_LINE_LOOP);
	glVertex2f(23,2);
	glVertex2f(27,-12);
	glVertex2f(31,-10);
	glEnd();

	glColor3f(0.98,0.89,0.535);//hand
	glBegin(GL_POLYGON);
	glVertex2f(27.5,-11.5);
	glVertex2f(28,-13.5);
	glVertex2f(19,-19);
	glVertex2f(20,-21.5);
	glVertex2f(22.5,-21.5);
	glVertex2f(22,-19.5);
	glVertex2f(32,-15);
	glVertex2f(31,-10.5);
	glEnd();
		
	glColor3f(0.98,0.89,0.535);//leg1
	glBegin(GL_POLYGON);
	glVertex2f(21.5,-40);
	glVertex2f(26,-40);
	glVertex2f(26.5,-50);
	glVertex2f(23,-50);
	glEnd();

	glColor3f(1,1,1);//sock
	glBegin(GL_POLYGON);
	glVertex2f(23,-50);
	glVertex2f(26.5,-50);
	glVertex2f(27,-59);
	glVertex2f(18,-60);
	glVertex2f(17.5,-59.5);
	glVertex2f(17.5,-58);
	glVertex2f(21,-58);
	glVertex2f(23,-57);
	glVertex2f(23,-50);
	glEnd();
	
	glColor3f(1,0,0);//short
	glBegin(GL_POLYGON);
	glVertex2f(18,-25);
	glVertex2f(20,-40);
	glVertex2f(26,-40);
	glVertex2f(28,-25);
	glEnd();
}

void sky()
{
  glColor3f(0.0,0.9,0.9);
  glBegin(GL_POLYGON);
  glVertex2f(-550,100);
  glVertex2f(-550,350);
  glVertex2f(550,350);
  glVertex2f(550,100);
  glEnd();
}

void sea()
{
  //sea
  glBegin(GL_POLYGON);
  glColor3f(0.0,0.627,0.627);
  glVertex2f(-550,0);
  glVertex2f(550,0);
  glColor3f(0.0,0.2,0.2);
  glVertex2f(550,100);
  glVertex2f(-550,100);
  glEnd();
}

void land()
{
	glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-550,-350);
    glVertex2f(-550,-300);
    glVertex2f(550,-300);
    glVertex2f(550,-350);
    glEnd(); 
    
    glBegin(GL_POLYGON);
    glVertex2f(-550,-200);
    glVertex2f(550,-200);
    rgb(70, 132, 64);
    glVertex2f(550,0);
    glVertex2f(-550,0);
    glEnd(); 
}
void path()
{
	rgb(1, 38, 63);
    glBegin(GL_POLYGON);
    glVertex2f(-550,-300);
    glVertex2f(-550,-200);
    glVertex2f(550,-200);
    glVertex2f(550,-300);
    glEnd(); 
}

void bus()
{
  rgb(219, 86, 41);//side
  glBegin(GL_POLYGON);
  glVertex2f(10,145);
  glVertex2f(10,180);
  glVertex2f(105,180);
  glVertex2f(110,145);
  glEnd();
  
  rgb(70, 71, 71);//front
  glBegin(GL_POLYGON);
  glVertex2f(109,145);
  glVertex2f(105,180);
  glVertex2f(115,200);
  glVertex2f(120,165);
  glEnd();
  
  rgb(247, 245, 244);//glass
  glBegin(GL_POLYGON);
  glVertex2f(109,160);
  glVertex2f(106.5,178);
  glVertex2f(114.5,196);
  glVertex2f(117,175);
  glEnd();
  
  rgb(194, 197, 198);//top
  glBegin(GL_POLYGON);
  glVertex2f(10,180);
  glVertex2f(105,180);
  glVertex2f(115,200);
  glVertex2f(20,200);
  glEnd();
  
  glPointSize(20);//window
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
  
  rgb(30,30, 30);//tires
  DrawCircle(35,145,5);
  DrawCircle(95,145,5);
}

void process()
{
	land();
	sea();
    path();
    sky();
    
    glPushMatrix();
    glTranslatef(-250+b,-550,0);
    glScaled(2,2,0);
    bus(); 
    glPopMatrix();
    
    if(b<230)
    {
      glPushMatrix();
      glTranslatef(m,-190,0);	
      man();
      glPopMatrix();
    
      glPushMatrix();
      glTranslatef(360+m,50,0);
      mobile(); 
      glPopMatrix();
      m--;
      b+=3;
    }  
    else
    {
	  glPushMatrix();
      glTranslatef(m,-260,0);	
      glRotatef(270, 0, 0, 1);//rotate
      glTranslatef(-20,60,0);	
      man();
      glPopMatrix();
    
      glPushMatrix();
      glTranslatef(380+m,10,0);
      mobile(); 
      glPopMatrix();
	}
    
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
  glutPostRedisplay();
  glutSwapBuffers();
}

void myinit()
{
glClearColor(0,0,0,1);
gluOrtho2D(-550.0,550.0,-350.0,350.0);
}

void keys(unsigned char key,int x,int y)
{
	seq=1;			
}

int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Accident");
	myinit();
	glutKeyboardFunc(keys);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
