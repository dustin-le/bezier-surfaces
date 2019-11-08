// Le, Dustin E.
// dxl0689
// 2019-11-11
//----------------------------------------------------------
#include <stdio.h>

#include "line.h"
#include "triangle.h"

View *_view = NULL;

//----------------------------------------------------------
void dumpTriangle( Vertex *v1, Vertex *v2, Vertex *v3 )
{
  Line line1, line2, line3;
  double v1pX = v1->x;
  double v1pY = v1->y;
  double v2pX = v2->x;
  double v2pY = v2->y;
  double v3pX = v3->x;
  double v3pY = v3->y;

  // Line 1: Vertex 1 to Vertex 2
  line1.p1X = v1pX;
  line1.p1Y = v1pY;
  line1.p2X = v2pX;
  line1.p2Y = v2pY;

  // Line 2: Vertex 2 to Vertex 3
  line2.p1X = v2pX;
  line2.p1Y = v2pY;
  line2.p2X = v3pX;
  line2.p2Y = v3pY;

  // Line 3: Vertex 3 to Vertex 1
  line3.p1X = v3pX;
  line3.p1Y = v3pY;
  line3.p2X = v1pX;
  line3.p2Y = v1pY;

  int test1 = clipLine(_view, &line1);
  if (test1)
  {
    dumpLine(&line1);
  }

  int test2 = clipLine(_view, &line2);
  if (test2)
  {
    dumpLine(&line2);
  }

  int test3 = clipLine(_view, &line3);
  if (test3)
  {
    dumpLine(&line3);
  }
}

//----------------------------------------------------------
void setPortal( View *v )
{
  _view = v;
}

//----------------------------------------------------------

