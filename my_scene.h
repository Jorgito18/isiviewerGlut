/**
 * @file   my_scene.h
 * @author Bruno Jobard
 * @author Author1
 * @author Author2
 * @date   Oct 2006
 * 
 * @brief  Defines a custom 3D scene
 * 
 * 
 */
#ifndef _ISI_MY_SCENE_H_
#define _ISI_MY_SCENE_H_

#include <QObject>
#include <QKeyEvent>
#include "my_objects.h"

class MyScene : public QObject
{
  Q_OBJECT

  enum displayModeType {WIREFRAME, FLATSHADED, SMOOTHSHADED};
  enum objectName {CUBE, AXIS, SOLARSYSTEM, DANCERS};
//   enum objectName {CUBE, PYRAMID, DISK, DISKHOLE, CYLINDER, CONE, SPHERE,
// 		   AXIS, SOLARSYSTEM, DANCERS};
  
protected:
  // 3D Objects
  Cube   _cube;			/**< a 3D cube */

  
  // Parameters
  int   _currentObject;	        /**< id of the current displayed 3D object */
  int   _numberOfObjects;	/**< number of 3D objets available */
  float _radius;		/**< radius of the object from the graphical interface */
  int _rotationT;        /*how much the earth will rotate*/
  int _rotationL;        /*how much the moon will rotate*/
  int _rotationS;        /*how much the sun will rotate*/
  int  _displayMode;		/**< current display mode */

  // Info for GUI
  double _radiusMin;
  double _radiusMax;
  double _radiusIncr;

 public:
  MyScene(float radius=1.);
  ~MyScene();

  inline void setCurrentObject(int co){_currentObject=co;}
  inline int currentObject(){return _currentObject;}
  inline void setDisplayMode(int dm){_displayMode=dm;}
  inline int displayMode(){return _displayMode;}

  inline void setRadius(float radius){_radius=radius;}
  inline float radius(){return _radius;}
  inline double radiusMin (){return _radiusMin;}
  inline double radiusMax (){return _radiusMax;}
  inline double radiusIncr(){return _radiusIncr;}
  
  void init();
  void draw();

 signals:
  void sigCurrentObjectChanged(int co);
  void sigDisplayModeChanged(int dm);
  void sigRadiusChanged(double radius);

 public slots:
  void slotSetCurrentObject(int co);
  void slotSetDisplayMode(int dm);
  void slotSetRadius(double radius);
 
 public:
  bool keyPressEvent(QKeyEvent *e);
   
 
};


#endif
