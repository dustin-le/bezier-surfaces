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
  int i, j, k, l, count = 0;
  double u[resolution], v[resolution], coefficients[16];

  double temp = 0;
  double increment = (1/((double) resolution - 1));
  for (i = 0; i < resolution; i++)
  {
    u[i] = temp;
    v[i] = temp;
    temp += increment;
  }

  // // Prints out model->m_patch
  // for (int i = 0; i < 2; i++)
  // {
  //   for (int j = 0; j < 16; j++)
  //   {
  //     printf("(%d, %d) = %d\n", i, j, model->m_patch[i][j]);
  //   }
  // }

  // // Print out vertices
  // for (i = 0; i < model->m_numVertices; i++)
  // {
  //   printf("x %d = %lf\n", i, model->m_vertex[i].x);
  //   printf("y %d = %lf\n", i, model->m_vertex[i].y);
  //   printf("z %d = %lf\n", i, model->m_vertex[i].z);
  // }

  // // Print out patch vertex.
  // for (i = 0; i < 16; i++)
  // {
  //   printf("x %d = %lf\n", i, model->m_patchVertex[i].x);
  //   printf("y %d = %lf\n", i, model->m_patchVertex[i].y);
  //   printf("z %d = %lf\n", i, model->m_patchVertex[i].z);
  // }

  // // Print out m_vertex values based on each patch array. (*.svfm)
  // for (int i = 0; i < model->m_numPatches; i++)
  // {
  //   for (int j = 0; j < 16; j++)
  //   {
  //     printf("%d: %lf %lf %lf\n", model->m_patch[i][j], model->m_vertex[model->m_patch[i][j]].x, model->m_vertex[model->m_patch[i][j]].y, model->m_vertex[model->m_patch[i][j]].z);
  //   }
  // }

  for (i = 0; i < model->m_numPatches; i++)
  {
    for (j = 0; j < resolution; j++)
    {
      for (k = 0; k < resolution; k++)
      {
        Vertex temp;
        temp.x = 0;
        temp.y = 0;
        temp.z = 0;
        _computeCoefficients(u[j], v[k], coefficients);
        for (l = 0; l < 16; l++)
        {
          temp.x += coefficients[l] * model->m_vertex[model->m_patch[i][l]].x;
          temp.y += coefficients[l] * model->m_vertex[model->m_patch[i][l]].y;
          temp.z += coefficients[l] * model->m_vertex[model->m_patch[i][l]].z;
        }
        model->m_patchVertex[count] = temp;
        count++;
      }
    }
  }
}

//----------------------------------------------------------
void generateBezierTriangles( Model *model, int resolution )
{
  int i, row, column, rowStart, here, there;

  for (i = 0; i < model->m_numPatches; i++)
  {
    for (row = 0; row < resolution - 1; row++)
    {
      rowStart = row * resolution;
      for (column = 0; column < resolution - 1; column++)
      {
        here = rowStart + column;
        there = here + resolution;

        dumpTriangle(&model->m_patchVertex[here], &model->m_patchVertex[there], &model->m_patchVertex[there+1]);
        dumpTriangle(&model->m_patchVertex[there+1], &model->m_patchVertex[here+1], &model->m_patchVertex[here]);
      }
    }
  }
}

//----------------------------------------------------------
void _computeCoefficients( double u, double v, double *coefficients )
{
  double u2 = u * u;
  double u3 = u * u * u;
  double v2 = v * v;
  double v3 = v * v * v;
  double minu2 = (1 - u) * (1 - u);
  double minu3 = (1 - u) * (1 - u) * (1 - u);
  double minv2 = (1 - v) * (1 - v);
  double minv3 = (1 - v) * (1 - v) * (1 - v);

  // c00  
  coefficients[0] = minu3 * minv3;

  // c01
  coefficients[1] = 3 * v * minu3 * minv2;

  // c02
  coefficients[2] = 3 * v2 * minu3 * (1 - v);

  // c03
  coefficients[3] = v3 * minu3;

  // c10
  coefficients[4] = 3 * u * minu2 * minv3;

  // c11
  coefficients[5] = 9 * u * v * minu2 * minv2;

  // c12
  coefficients[6] = 9 * u * v2 * minu2 * (1 - v);

  // c13
  coefficients[7] = 3 * u * v3 * minu2;

  // c20
  coefficients[8] = 3 * u2 * (1 - u) * minv3;

  // c21
  coefficients[9] = 9 * u2 * v * (1 - u) * minv2;

  // c22
  coefficients[10] = 9 * u2 * v2 * (1 - u) * (1 - v);

  // c23
  coefficients[11] = 3 * u2 * v3 * (1 - u);

  // c30
  coefficients[12] = u3 * minv3;

  // c31
  coefficients[13] = 3 * u3 * v * minv2;

  // c32
  coefficients[14] = 3 * u3 * v2 * (1 - v);

  // c33
  coefficients[15] = u3 * v3;
}

//----------------------------------------------------------

