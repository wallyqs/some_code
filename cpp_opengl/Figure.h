using namespace std;

#include <cstdio>
#include <GL/glut.h>
#define GL_PI 3.1415f

#define MODE_SOLID 0
#define MODE_LINE  1
#define MODE_POINT 2
int iMode = MODE_SOLID;
GLboolean bEdgeFlag = GL_TRUE;
static int globalSelection = 0;
#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

class Figure{
public:

  GLfloat xRot1;
  GLfloat yRot1;
  GLfloat xPos;
  GLfloat yPos;
  GLfloat zPos;
  int origenON;

  virtual void paintMyself(){
    printf("this should not happen");
  }
  virtual void moveSceneXaxis(GLfloat x){
    printf("this should not happen 1");
  }
  virtual void moveSceneYaxis(GLfloat y){
    printf("this should not happen 2");
  }
  virtual void translateXaxis(GLfloat x){
    /* xPos += x; */
  }
  virtual void translateYaxis(GLfloat y){
    /* yPos += y; */
  }
  virtual void translateZaxis(GLfloat z){
    /* zPos += z; */
  }
  virtual void paintOrigin(){
    /* zPos += z; */
  }

};

 
 
class Star : public Figure
{
public: 

  GLfloat xRot1;
  GLfloat yRot1;
  GLfloat xPos;
  GLfloat yPos;
  GLfloat zPos;
  int origenON;
  
Star(GLfloat x, GLfloat y){
  xRot1 = x;
  yRot1 = y;
  xPos = 0;
  yPos = 0;
  zPos = 0;
  origenON = 0;
}

void paintMyself(){

  if(iMode == MODE_LINE)
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  if(iMode == MODE_POINT)
    glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
  if(iMode == MODE_SOLID)
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

  glPushMatrix();
   
  glTranslatef(xPos, yPos, zPos);
    glRotatef(xRot1, 1.0f, 0.0f, 0.0f);  
    glRotatef(yRot1, 0.0f, 1.0f, 0.0f);
    
    if (origenON == 1)   {      ponerOrigen();    }

    glBegin(GL_TRIANGLES);
    glEdgeFlag(bEdgeFlag);     glVertex2f(-20.0f, 0.0f);
    glEdgeFlag(GL_TRUE);       glVertex2f(20.0f, 0.0f);  
    glVertex2f(0.0f, 40.0f);
    glVertex2f(-20.0f,0.0f);   glVertex2f(-60.0f,-20.0f);
    glEdgeFlag(bEdgeFlag);     glVertex2f(-20.0f,-40.0f);
    glEdgeFlag(GL_TRUE);       glVertex2f(-20.0f,-40.0f);
    glVertex2f(0.0f, -80.0f);  glEdgeFlag(bEdgeFlag);
    glVertex2f(20.0f, -40.0f); glEdgeFlag(GL_TRUE);
    glVertex2f(20.0f, -40.0f); glVertex2f(60.0f, -20.0f);
    glEdgeFlag(bEdgeFlag);     glVertex2f(20.0f, 0.0f);
    glEdgeFlag(GL_TRUE);
    glEdgeFlag(bEdgeFlag);     glVertex2f(-20.0f, 0.0f);
    glVertex2f(-20.0f,-40.0f); glVertex2f(20.0f, 0.0f);
    glVertex2f(-20.0f,-40.0f); glVertex2f(20.0f, -40.0f);
    glVertex2f(20.0f, 0.0f);   glEdgeFlag(GL_TRUE);
    glEnd();
    

     
  glPopMatrix();
   
   
   
}
  void moveSceneXaxis(GLfloat x){
    if (globalSelection < 0) {globalSelection = 0; }
    xRot1 += x;
  }
  void moveSceneYaxis(GLfloat y){
    if (globalSelection < 0){ globalSelection = 0;  }
    yRot1 += y;
  }
  void translateXaxis(GLfloat x){
    xPos += x;
  }
  void translateYaxis(GLfloat y){
    yPos += y;
  }
  void translateZaxis(GLfloat z){
    zPos += z;
  }
  void paintOrigin(){
    printf("dibujando el origen de la estrella\n");
    if (origenON == 0)
      {
	origenON = 1;
      }else{
      origenON = 0;
    }
  }

  void ponerOrigen(){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 50.0f);
    glEnd( );
  }

  
};
 
 
class Sphere : public Figure
{
public: 
  GLfloat xRot1;
  GLfloat yRot1;
  GLfloat xPos;
  GLfloat yPos;
  GLfloat zPos;
  int origenON;

Sphere(GLfloat x, GLfloat y){
  xRot1 = x;
  yRot1 = y;
  xPos = 0;
  yPos = 0;
  zPos = 0;
  origenON = 0;
}

void paintMyself(){
   
  if(iMode == MODE_LINE) { glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); }
  if(iMode == MODE_POINT){ glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);}
  if(iMode == MODE_SOLID){ glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); }
    
  glPushMatrix();

     
    glTranslatef(xPos, yPos, zPos);
    glRotatef(xRot1, 1.0f, 0.0f, 0.0f);  
    glRotatef(yRot1, 0.0f, 1.0f, 0.0f);
      
    if (origenON == 1)    {           ponerOrigen();    }
      glutSolidSphere(20, 30 ,20);
  glPopMatrix();
}

  void moveSceneXaxis(GLfloat x){if (globalSelection < 0) {globalSelection = 0; }
    xRot1 += x + globalSelection;
  }
  void moveSceneYaxis(GLfloat y){if (globalSelection < 0){ globalSelection = 0; }
    yRot1 += y + globalSelection;
  }
  void translateXaxis(GLfloat x){
    xPos += x;
  }
  void translateYaxis(GLfloat y){
    yPos += y;
  }
  void translateZaxis(GLfloat z){
    zPos += z;
  }
  
  void paintOrigin(){
    printf("dibujando el origen de la estrella\n");
    if (origenON == 0)
      {
	origenON = 1;
      }else{
      origenON = 0;
    }
  }

  void ponerOrigen(){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 50.0f);
    glEnd( );
  }
  
};
 
 
class Cube : public Figure
{
public: 
  GLfloat xRot1;
  GLfloat yRot1;
  GLfloat xPos;
  GLfloat yPos;
  GLfloat zPos;
  int origenON;

Cube(GLfloat x, GLfloat y){
  xRot1 = x;
  yRot1 = y;
  xPos = 0;
  yPos = 0;
  zPos = 0;
}

void paintMyself(){
   
  if(iMode == MODE_LINE) { glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); }
  if(iMode == MODE_POINT){ glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);}
  if(iMode == MODE_SOLID){ glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); }
    
  glPushMatrix();
     
     
    glTranslatef(xPos, yPos, zPos);
    glRotatef(xRot1, 1.0f, 0.0f, 0.0f);  
    glRotatef(yRot1, 0.0f, 1.0f, 0.0f);
     
    if (origenON == 1)    {           ponerOrigen();    }
     
    glutSolidCube(20);
     
  glPopMatrix();
}

  void moveSceneXaxis(GLfloat x){if (globalSelection < 0) {globalSelection = 0; }
    xRot1 += x + globalSelection;
  }
  void moveSceneYaxis(GLfloat y){if (globalSelection < 0){ globalSelection = 0; }
    yRot1 += y + globalSelection;
  }
  void translateXaxis(GLfloat x){
    xPos += x;
  }
  void translateYaxis(GLfloat y){
    yPos += y;
  }
  void translateZaxis(GLfloat z){
    zPos += z;
  }
  void paintOrigin(){
    printf("painting the origin of a star\n");
    if (origenON == 0)
      {
	origenON = 1;
      }else{
      origenON = 0;
    }
  }

  void ponerOrigen(){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 50.0f);
    glEnd( );
  }
};
 
 
class Cone : public Figure
{
public: 
  GLfloat xRot1;
  GLfloat yRot1;
  GLfloat xPos;
  GLfloat yPos;
  GLfloat zPos;
  int origenON;
  
Cone(GLfloat x, GLfloat y){
  xRot1 = 0;
  yRot1 = 0;
  xPos = 0;
  yPos = 0;
  zPos = 0;
}

void paintMyself(){
  if(iMode == MODE_LINE) { glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); }
  if(iMode == MODE_POINT){ glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);}
  if(iMode == MODE_SOLID){ glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); }
  glPushMatrix();
  glTranslatef(xPos, yPos, zPos);
  glRotatef(xRot1, 1.0f, 0.0f, 0.0f);  
  glRotatef(yRot1, 0.0f, 1.0f, 0.0f);
    if (origenON == 1)    {           ponerOrigen();    }
    glutSolidCone(20, 40, 30, 10);
  glPopMatrix();
}

  void moveSceneXaxis(GLfloat x){if (globalSelection < 0) {globalSelection = 0; }
    xRot1 += x + globalSelection;
  }
  void moveSceneYaxis(GLfloat y){if (globalSelection < 0){ globalSelection = 0; }
    yRot1 += y + globalSelection;
  }
  void translateXaxis(GLfloat x){
    xPos += x;
  }
  void translateYaxis(GLfloat y){
    yPos += y;
  }
  void translateZaxis(GLfloat z){
    zPos += z;
  }
    void paintOrigin(){
    printf("dibujando el origen de la estrella\n");
    if (origenON == 0)
      {
	origenON = 1;
      }else{
      origenON = 0;
    }
  }

  void ponerOrigen(){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 50.0f);
    glEnd( );
  }

};
 
 
class Torus : public Figure
{
public: 
  GLfloat xRot1;
  GLfloat yRot1;
  GLfloat xPos;
  GLfloat yPos;
  GLfloat zPos;
  int origenON;

Torus(GLfloat x, GLfloat y){
  xRot1 = x;
  yRot1 = y;
  xPos = 0;
  yPos = 0;
  zPos = 0;
}

void paintMyself(){
   
  if(iMode == MODE_LINE) { glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); }
  if(iMode == MODE_POINT){ glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);}
  if(iMode == MODE_SOLID){ glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); }
    
   
   
     
  glPushMatrix();
    glTranslatef(xPos, yPos, zPos);
    glRotatef(xRot1, 1.0f, 0.0f, 0.0f);  
    glRotatef(yRot1, 0.0f, 1.0f, 0.0f);
         
    if (origenON == 1)    {           ponerOrigen();    }
    glutSolidTorus(10,30,20,20);
  glPopMatrix();
   
   
}

  void moveSceneXaxis(GLfloat x){if (globalSelection < 0) {globalSelection = 0; }
    xRot1 += x + globalSelection;
  }
  void moveSceneYaxis(GLfloat y){if (globalSelection < 0){ globalSelection = 0; }
    yRot1 += y + globalSelection;
  }
  void translateXaxis(GLfloat x){
    xPos += x;
  }
  void translateYaxis(GLfloat y){
    yPos += y;
  }
  void translateZaxis(GLfloat z){
    zPos += z;
  }
        void paintOrigin(){
    printf("dibujando el origen de la estrella\n");
    if (origenON == 0)
      {
	origenON = 1;
      }else{
      origenON = 0;
    }
  }

  void ponerOrigen(){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 50.0f);
    glEnd( );
  }


};
 

class Cylinder : public Figure
{
public: 
  GLfloat xRot1;
  GLfloat yRot1;
  GLfloat xPos;
  GLfloat yPos;
  GLfloat zPos;
  int origenON;
  
Cylinder(GLfloat x, GLfloat y){
  xRot1 = x;
  yRot1 = y;
  xPos = 0;
  yPos = 0;
  zPos = 0;
}

void paintMyself(){
   
  if(iMode == MODE_LINE) { glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); }
  if(iMode == MODE_POINT){ glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);}
  if(iMode == MODE_SOLID){ glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); }
    
  glPushMatrix();

    glTranslatef(xPos, yPos, zPos);
    glRotatef(xRot1, 1.0f, 0.0f, 0.0f);  
    glRotatef(yRot1, 0.0f, 1.0f, 0.0f);

     
    if (origenON == 1)    {           ponerOrigen();    }
    GLUquadricObj *quadratic;	
    quadratic=gluNewQuadric();
    gluQuadricNormals(quadratic, GLU_SMOOTH);

    gluCylinder(quadratic,1.0f,1.0f,10.0f,40,40);	

  glPopMatrix();
}

  void moveSceneXaxis(GLfloat x){if (globalSelection < 0) {globalSelection = 0; }
    xRot1 += x + globalSelection;
  }
  void moveSceneYaxis(GLfloat y){if (globalSelection < 0){ globalSelection = 0; }
    yRot1 += y + globalSelection;
  }
  void translateXaxis(GLfloat x){
    xPos += x;
  }
  void translateYaxis(GLfloat y){
    yPos += y;
  }
  void translateZaxis(GLfloat z){
    zPos += z;
  }
    void paintOrigin(){
    printf("dibujando el origen de la estrella\n");
    if (origenON == 0)
      {
	origenON = 1;
      }else{
      origenON = 0;
    }
  }

  void ponerOrigen(){
    glBegin(GL_LINES);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(50.0f, 0.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 50.0f, 0.0f);
    glEnd( );
    glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 50.0f);
    glEnd( );
  }

};
 

