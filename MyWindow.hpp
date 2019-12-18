// MyWindow.hpp

#ifndef MYWINDOW_HPP
#define MYWINDOW_HPP

#include "FormeS.hpp"

class MyWindow : public EZWindow {
  FormeS formes;
  Forme  *pforme;
 public:
  MyWindow(int w, int h,const char *name);
  ~MyWindow();
  void expose();
  void keyPress(EZKeySym keysym);
  void buttonPress(int mouse_x,int mouse_y,int button);
  void motionNotify(int mouse_x,int mouse_y,int button);
  void buttonRelease(int mouse_x,int mouse_y,int button);
};

#endif
