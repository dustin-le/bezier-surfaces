// Le, Dustin E.
// dxl0689
// 2019-11-11
//----------------------------------------------------------
#include <stdio.h>

#include "bezier.h"
#include "model.h"
#include "triangle.h"
#include "vertex.h"

void _computeCoefficients( double u, double v, double *c );

//----------------------------------------------------------
void generateBezierPoints( Model *model, int resolution )
{
  // TODO: Iterate through each patch, each value of u, and each
  //       value of v (so three nested loops in that order).
  //       Compute the 16 coefficients for the specific values of
  //       u and v.
  //       Iterate through the 16 coefficients multiplying each by
  //       the corresponding control point and accumulating the
  //       result in the current Bézier surface point.
  //       This is done for that point's x, y, and z coordinates.
}

//----------------------------------------------------------
void generateBezierTriangles( Model *model, int resolution )
{
  // TODO: Iterate through each patch, each row of that patch, and
  //       and each column of that patch (so three nested loops in
  //       that order).
  //       Dump the two triangles that correspond to the row and
  //       column positions using the dumpTriangle() routine.
  //       Remember that you have to consider only the first
  //       through the penultimate row and the first through the
  //       penultimate column when generating a patch's triangles.
  //       Ensure that you generate the triangles in the correct
  //       order and use the vertices in the correct order.
}

//----------------------------------------------------------
void _computeCoefficients( double u, double v, double *coefficients )
{
  // c00  
  coefficients[0] = pow((1 - u), 3) * pow((1 - v), 3);

  // c01
  coefficients[1] = 3 * v * pow((1 - u), 3) * pow((1 - v), 2);

  // c02
  coefficients[2] = 3 * pow((v), 2) * pow((1 - u), 3) * (1 - v);

  // c03
  coefficients[3] = pow(v, 3) * pow((1 - u), 3);

  // c10
  coefficients[4] = 3 * u * pow((1 - u), 2) * pow((1 - v), 3);

  // c11
  coefficients[5] = 9 * u * v * pow((1 - u), 2) * pow((1 - v), 2);

  // c12
  coefficients[6] = 9 * u * pow(v, 2) * pow((1 - u), 2) * (1 - v);

  // c13
  coefficients[7] = 3 * u * pow(v, 3) * pow((1 - u), 2);

  // c20
  coefficients[8] = 3 * pow(u, 2) * (1 - u) * pow((1 - v), 3);

  // c21
  coefficients[9] = 9 * pow(u, 2) * v * (1 - u) * pow((1 - v), 2);

  // c22
  coefficients[10] = 9 * pow(u, 2) * pow(v, 2) * (1 - u) * (1 - v);

  // c23
  coefficients[11] = 3 * pow(u, 2) * pow(v, 3) * (1 - u);

  // c30
  coefficients[12] = pow(u, 3) * pow((1 - v), 3);

  // c31
  coefficients[13] = 3 * pow(u, 3) * v * pow((1 - v), 2);

  // c32
  coefficients[14] = 3 * pow(u, 3) * pow(v, 2) * (1 - v);

  // c33
  coefficients[15] = pow(u, 3) * pow(v, 3);
}

//----------------------------------------------------------

