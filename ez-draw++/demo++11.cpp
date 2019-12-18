/* demo++11.cpp : demonstration de EZ-Draw
 *
 * eric.remy@univ-provence.fr - 29/03/2008 - version 0.8
 *
 * Compilation sous Unix :
 *     g++ -Wall demo++11.cpp ez-draw++.o -o demo++11 -L/usr/X11R6/lib -lX11 -lXext
 * Compilation sous Windows :
 *     g++ -Wall demo++11.cpp ez-draw++.o -o demo++11.exe -lgdi32
 *
 * This program is free software under the terms of the
 * GNU Lesser General Public License (LGPL) version 2.1.
*/

#include <iostream>
#include <sstream>
#include <iomanip>

#define _USE_MATH_DEFINES // Enable M_PI constant from the next inclusion
#include <cmath>

using namespace std;

#include "ez-draw++.hpp"

class MyWindow1 : public EZWindow 
{
public:
 MyWindow1(int w,int h,const char *name)
  : EZWindow(w,h,name)
 { setDoubleBuffer(true); }

 void expose()
  {
    const char *color_names [9] = { "ez_black", "ez_white", "ez_grey", "ez_red", 
        "ez_green", "ez_blue", "ez_yellow", "ez_cyan", "ez_magenta" };
    EZColor c[9];
    int i, x, y, r, g, b;

    c[0] = ez_black; c[1] = ez_white; c[2] = ez_grey;   c[3] = ez_red ;
    c[4] = ez_green; c[5] = ez_blue;  c[6] = ez_yellow; c[7] = ez_cyan;
    c[8] = ez_magenta;

    for (i = 0; i < 9; i++) {
        x = 20+(i%3)*100; y = 20+(i/3)*60;
        setColor (ez_black);
        drawText (EZAlign::TL, x, y, color_names[i]);
        drawRectangle (x, y+20, x+60, y+40);
        setColor (c[i]);
        fillRectangle (x+1, y+21, x+59, y+39);
    }

    setColor (ez_black);
    drawText (EZAlign::TL, 20, 200, "Grey levels: 0..255");
    drawRectangle ( 20, 220, 277, 240);
    for (i = 0; i < 256; i++) {
        setColor (getGrey(i));
        drawLine (21+i, 221, 21+i, 239);
    }

    setColor (ez_black);
    drawText (EZAlign::TL, 20, 260, "HSV color: H = 0..360, S = V = 1");
    drawRectangle ( 20, 280, 380, 300);
    for (i = 0; i < 360; i++) {
        setColor (getHSV (i, 1, 1));
        drawLine ( 21+i, 281, 21+i, 299);
    }

    r = EZDraw::random (256); g = EZDraw::random (256); b = EZDraw::random (256);
    setColor (ez_black);
    ostringstream oss;
    oss << "Random RGB\n" 
        << setw(3) << r << " "
        << setw(3) << g << " "
        << setw(3) << b;

    drawText (EZAlign::TLF, 320, 160, oss.str());
    drawRectangle (320, 200, 380, 240);
    setColor (getRGB (r, g, b));
    fillRectangle (321, 201, 379, 239);
  }

 void keyPress(EZKeySym keysym)
  {
    switch (keysym)
     {
        case EZKeySym::Escape:
        case EZKeySym::q  :
          EZDraw::quit();
          break;
        default: // Dans tous les autres cas on ne fait rien (necessaire
          break; // pour eviter un warning a la compilation).
     }
  }

 void close()
  { EZDraw::quit(); }
};


int main (int /*argc*/, char */*argv*/[])
{
    EZDraw ezDraw;
    MyWindow1 win1(410, 320, "Demo++11 : Couleurs");

    ezDraw.mainLoop();

    return 0;
}


