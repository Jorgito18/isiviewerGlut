#include "my_scene.h"

#include <iostream>
#include <math.h>
#include <GL/gl.h>  // OpenGL include file
#include <GL/glut.h>

using namespace std;

/** 
 * Constructor
 * 
 * @param radius 
 */
MyScene::MyScene(float radius)
{
  std::cout << "constructing :  MyScene" << std::endl;

  _currentObject = MyScene::AXIS;
  _numberOfObjects = 3;	         // increment it when you add a new 3D object!
 
  _displayMode = MyScene::FLATSHADED;
  _rotationT = 0;
  _rotationL = 0;
  _radius = radius;
  _radiusMin = 0.1;
  _radiusMax = 2.0;
  _radiusIncr = 0.1;
}

/** 
 * Destructor
 * 
 */
MyScene::~MyScene()
{
  std::cout<<"~MyScene"<<std::endl;
}

/** 
 * Init the scene and OpenGL state
 * 
 */
void MyScene::init()
{
  glColor3f(0.5, 0., 0.);

  // set antialiased lines
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glLineWidth(1.5);

  glEnable(GL_NORMALIZE); // normalize normal vectors when objects are scaled
}

/** 
 * Draw the scene
 * 
 */
void MyScene::draw()
{
  glPushMatrix();
  glScalef(_radius/12, _radius/12, _radius/12);

  switch(_currentObject%_numberOfObjects) {
  case MyScene::CUBE: // Draw the AXIS
    _cube.draw();
    break;
  case MyScene::AXIS:
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    glColor3f(0.8f,0.8f,0.8f);
    glutSolidSphere(1, 20,10);
    glPopMatrix();

    //axe Y
    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(0,0,1);
    glScalef(0.1,0.1,1);
    glColor3f(0.0f,1.0f,0.0f);
    glutSolidSphere(1, 20,10);
    glTranslatef(0,0,1);
    glutSolidCone(1,0.5,20,20);
    glPopMatrix();

    //axe X
    glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslatef(0,0,1);
    glScalef(0.1,0.1,1);
    glColor3f(1.0f,0.0f,0.0f);
    glutSolidSphere(1, 20,10);
    glTranslatef(0,0,1);
    glutSolidCone(1,0.5,20,20);
    glPopMatrix();

    //Axe Z
    glPushMatrix();
    glRotatef(90,0,0,1);
    glTranslatef(0,0,1);
    glScalef(0.1,0.1,1);
    glColor3f(0.0f,0.0f,1.0f);
    glutSolidSphere(1, 20,10);
    glTranslatef(0,0,1);
    glutSolidCone(1,0.5,20,20);
    glPopMatrix();

    break;
  case MyScene::SOLARSYSTEM: // Draw the SOLAR SYSTEM
    glMatrixMode(GL_MODELVIEW);

    //Soleil
    glRotatef(_rotationS,0,0,1);
    glPushMatrix();
    glScalef(1,1,1);
    glColor3f(1.0f,1.0f,0.0f);
    glutSolidSphere(1,25,15);
    glPopMatrix();

    //mercure
    glPushMatrix();
    glTranslatef(1, 1, 1);
    glScalef(0.5,0.5,0.5);
    glColor3f(0.3f,0.0f,0.0f);
    glutSolidSphere(1, 15,15);
    glPopMatrix();

    //Venus
    glPushMatrix();
    glTranslatef(2, 2, 2);
    glScalef(0.5,0.5,0.5);
    glColor3f(0.0f,0.5f,0.0f);
    glutSolidSphere(1, 15,15);
    glPopMatrix();

    //Terre et Lune
    glPushMatrix();
    glScalef(0.4,0.4,0.4);
    glTranslatef(7, 7, 7);
    glColor3f(0.0f,0.0f, 0.8f);
    glRotatef(_rotationT,0,0,1);
    glutSolidSphere(1,25,15);
    //Lune
    glTranslatef(1, 1, 1);
    glScalef(0.23,0.23,0.23);
    glColor3f(0.5f,0.5f,0.5f);
    glRotatef(_rotationL,0,0,1);
    glutSolidSphere(1, 15,15);
    glPopMatrix();

    //Mars
    glPushMatrix();
    glTranslatef(4, 4, 4);
    glScalef(0.5,0.5,0.5);
    glColor3f(0.8f,0.0f,0.0f);
    glutSolidSphere(1, 15,15);
    glPopMatrix();

    //Jupiter
    glPushMatrix();
    glTranslatef(6, 6, 6);
    glScalef(1,1,1);
    glColor3f(0.5f,0.1f,0.2f);
    glutSolidSphere(1, 15,15);
    glPopMatrix();

    //Saturn
    glPushMatrix();
    glTranslatef(7.5, 7.5, 7.5);
    glScalef(1,1,1);
    glColor3f(0.8f,0.6f,0.0f);
    gluDisk(gluNewQuadric(), 1.15, 1.7,50,50);
    glColor3f(0.8f,0.7f,0.6f);
    glutSolidSphere(1, 15,15);
    glPopMatrix();

    //Urane
    glPushMatrix();
    glTranslatef(9, 9, 9);
    glScalef(1,1,1);
    glColor3f(0.6f,0.5f,0.6f);
    glutSolidSphere(1, 15,15);
    glPopMatrix();

    //Neptune
    glPushMatrix();
    glTranslatef(10, 10, 10);
    glScalef(1,1,1);
    glColor3f(0.0f,0.0f,0.6f);
    glutSolidSphere(1, 15,15);
    glPopMatrix();

    //Pluto
    glPushMatrix();
    glTranslatef(11, 11, 11);
    glScalef(1,1,1);
    glColor3f(0.4f,0.5f,0.6f);
    glutSolidSphere(1, 15,15);
    glPopMatrix();
    break;

    //... insert here the other objects

  }

  glPopMatrix();

}

/** 
 * Slot set current object
 * 
 * @param currentObject
 */
void MyScene::slotSetCurrentObject(int currentObject)
{
  std::cout << "slotSetCurrentObject "<< currentObject << std::endl;
  _currentObject = currentObject;
  emit sigCurrentObjectChanged(currentObject);
  
}

/** 
 * Slot set display mode
 * 
 * @param currentObject
 */
void MyScene::slotSetDisplayMode(int displayMode)
{
  std::cout << "slotSetDisplayMode "<< displayMode%3 << std::endl;
  _displayMode = displayMode;

  switch (displayMode%3) {
  case MyScene::WIREFRAME:
    glDisable(GL_LIGHTING);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);    
    break;
  case MyScene::FLATSHADED: 
    glEnable(GL_LIGHTING);
    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    break;
  case MyScene::SMOOTHSHADED:
    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH); 
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    break;
  }

  emit sigDisplayModeChanged(displayMode);
}

/** 
 * Slot set radius
 * 
 * @param radius 
 */
void MyScene::slotSetRadius(double radius)
{
  if (fabs(_radius - float(radius))>1e-6) {
    //std::cout << "slotSetRadius "<< radius << std::endl;
    _radius = radius;
    emit sigRadiusChanged(radius);
  }
}

/** 
 * Process keyboard events for QGLViewer widget
 * 
 * @param e a keyboard event from QGLViewer 
 * 
 * @return true if the event has been handled
 */
bool MyScene::keyPressEvent(QKeyEvent *e)
{
  const Qt::KeyboardModifiers modifiers = e->modifiers();

  // A simple switch on e->key() is not sufficient if we want to take
  // state key into account.  With a switch, it would have been
  // impossible to separate 'F' from 'CTRL+F'.  That's why we use
  // imbricated if...else and a "handled" boolean.

  bool handled = false;

  float epsilon = 1e-5;  // for float comparison
  
  // Increase radius with 'r'
  if ((e->key()==Qt::Key_R) && (modifiers==Qt::NoButton)) {
    if (_radius+_radiusIncr <= _radiusMax + epsilon)
      this->slotSetRadius(_radius+_radiusIncr);
    handled = true;
  } 
  // Decrease radius with 'R'
  else if ((e->key()==Qt::Key_R) && (modifiers==Qt::SHIFT)) {
    if (_radius-_radiusIncr >= _radiusMin - epsilon)
      this->slotSetRadius(_radius-_radiusIncr);
    handled = true;
  }
      
  // Increase current displayed object with 'o'
  if ((e->key()==Qt::Key_O) && (modifiers==Qt::NoButton)) { 
    this->slotSetCurrentObject(_currentObject+1);
    handled = true;
  } 
  // Decrease current displayed object with 'O'
  else if ((e->key()==Qt::Key_O) && (modifiers==Qt::SHIFT)) {
    this->slotSetCurrentObject(_currentObject-1);
    handled = true;
  }
      /*
  // change display mode with 's'
  else if ((e->key()==Qt::Key_S) && (modifiers==Qt::NoButton)) {
    this->slotSetDisplayMode(_displayMode+1);
    handled = true;
  }*/

  // simulate rotation with 'h'
  else if ((e->key()==Qt::Key_H) && (modifiers==Qt::NoButton)) {
    _rotationT += 20;
    _rotationL += 20;
    _rotationS += 5;
    emit sigCurrentObjectChanged(0);
    handled = true;
  }

  // simulate rotation with 'j'
  else if ((e->key()==Qt::Key_J) && (modifiers==Qt::NoButton)) {
    _rotationT += 45;
    _rotationL += 25;
    _rotationS += 10;
    emit sigCurrentObjectChanged(0);
    handled = true;
  }

  // simulate rotation with 's'
  else if ((e->key()==Qt::Key_S) && (modifiers==Qt::NoButton)) {
    _rotationT += 100;
    _rotationL += 100;
    _rotationS += 70;
    emit sigCurrentObjectChanged(0);
    handled = true;
  }

  // simulate rotation with 'm'
  else if ((e->key()==Qt::Key_M) && (modifiers==Qt::NoButton)) {
    _rotationT += 180;
    _rotationL += 180;
    _rotationS += 200;
    emit sigCurrentObjectChanged(0);
    handled = true;
  }

  // simulate rotation with 'H'
  else if ((e->key()==Qt::Key_H) && (modifiers==Qt::SHIFT)) {
    _rotationT -= 20;
    _rotationL -= 20;
    _rotationS -= 5;
    emit sigCurrentObjectChanged(0);
    handled = true;
  }

  // simulate rotation with 'J'
  else if ((e->key()==Qt::Key_J) && (modifiers==Qt::SHIFT)) {
    _rotationT -= 45;
    _rotationL -= 25;
    _rotationS -= 10;
    emit sigCurrentObjectChanged(0);
    handled = true;
  }

  // simulate rotation with 'S'
  else if ((e->key()==Qt::Key_S) && (modifiers==Qt::SHIFT)) {
    _rotationT -= 100;
    _rotationL -= 100;
    _rotationS -= 70;
    emit sigCurrentObjectChanged(0);
    handled = true;
  }

  // simulate rotation with 'M'
  else if ((e->key()==Qt::Key_M) && (modifiers==Qt::SHIFT)) {
    _rotationT -= 180;
    _rotationL -= 180;
    _rotationS -= 200;
    emit sigCurrentObjectChanged(0);
    handled = true;
  }


  return handled;
}
