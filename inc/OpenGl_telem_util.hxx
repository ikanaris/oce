// Copyright (c) 1995-1999 Matra Datavision
// Copyright (c) 1999-2012 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.

/***********************************************************************

FONCTION :
----------
File Include OpenGl_telem_util :


REMARQUES:
---------- 


HISTORIQUE DES MODIFICATIONS   :
--------------------------------
xx-xx-xx : xxx ; Creation.
22-04-96 : FMN ; Ajout TelReadImage TelDrawImage
23-12-96 : CAL ; Probleme dans la macro vecmag
12-02-97 : FMN ; Suppression TelEnquireFacilities()
07-10-97 : FMN ; Simplification WNT
23-12-97 : FMN ; Suppression TelBackInteriorStyle, TelBackInteriorStyleIndex

************************************************************************/

#ifndef  OPENGL_TELEM_UTIL_H
#define  OPENGL_TELEM_UTIL_H

#include <InterfaceGraphic_telem.hxx>
#include <cmath>

/*
* ShortRealLast () = 3.40282346638528860e+38
* ShortRealFirst () = 3.40282346638528860e+38
*/
#define  shortreallast()     (3.e+38)
#define  shortrealfirst()    (-3.e+38)

/* vector manipulation macros */
#define  square(a)      ((a)*(a))

/* add */
#define  vecadd(a,b,c)  { (a)[0]=(b)[0]+(c)[0]; \
  (a)[1]=(b)[1]+(c)[1]; \
  (a)[2]=(b)[2]+(c)[2]; }

/* subtract */
#define  vecsub(a,b,c)  { (a)[0]=(b)[0]-(c)[0]; \
  (a)[1]=(b)[1]-(c)[1]; \
  (a)[2]=(b)[2]-(c)[2]; }

/* dot product */
#define  vecdot(a,b)    ((a)[0]*(b)[0]+(a)[1]*(b)[1]+(a)[2]*(b)[2])

/* cross product */
#define  veccrs(a,b,c)  { Tfloat x, y, z; \
  x = (b)[1]*(c)[2] - (b)[2]*(c)[1]; \
  y = (b)[2]*(c)[0] - (b)[0]*(c)[2]; \
  z = (b)[0]*(c)[1] - (b)[1]*(c)[0]; \
  (a)[0] = x; \
  (a)[1] = y; \
  (a)[2] = z; }
/* scale */
#define  vecscl(a,b)     { (b)[0] *= (a); (b)[1] *= (a); (b)[2] *= (a); }

/* magnitude square */
#define  vecmg2(a)       (square((a)[0])+square((a)[1])+square((a)[2]))

/* magnitude */
#define  vecmag(a)       (std::sqrt((double)vecmg2(a)))

/* normalize */
#define  vecnrmd(a,d)    ( d = (Tfloat)vecmag(a), \
  ( d > 1e-10 ? (a[0] /= d, a[1] /= d, a[2] /= d, d) : (Tfloat)0. ) )
#define  vecnrm(a)       { Tfloat d; vecnrmd(a,d); }

/* angle between two vectors */
#define  vecang(a,b,d)   { d = (Tfloat)(vecmag(a)*vecmag(b)); \
  d = vecdot(a,b)/d; \
  d = d < -1.0F ? -1.0F : d > 1.0F ? 1.0F : d; \
  d = ( Tfloat )acos(d); }

/* point along a vector at a distance */
#define  vecgnd(a,b,c,d) { Tfloat w; w = d/vecmag(c); \
  (a)[0] = (b)[0]+(c)[0]*w;  \
  (a)[1] = (b)[1]+(c)[1]*w;  \
  (a)[2] = (b)[2]+(c)[2]*w;  }
/* copy */
#define  veccpy(a,b)     ((a)[0]=(b)[0],(a)[1]=(b)[1],(a)[2]=(b)[2])

/* end vector macros */

typedef  struct
{
  Tmatrix3  mat;
}
Tmatrix3Struct;

#define  matcpy(d,s) { *((Tmatrix3Struct*)(d)) = *((Tmatrix3Struct*)(s)); }
/*
(d)[0][0]=(s)[0][0],(d)[0][1]=(s)[0][1],(d)[0][2]=(s)[0][2],(d)[0][3]=(s)[0][3],
(d)[1][0]=(s)[1][0],(d)[1][1]=(s)[1][1],(d)[1][2]=(s)[1][2],(d)[1][3]=(s)[1][3],
(d)[2][0]=(s)[2][0],(d)[2][1]=(s)[2][1],(d)[2][2]=(s)[2][2],(d)[2][3]=(s)[2][3],
(d)[3][0]=(s)[3][0],(d)[3][1]=(s)[3][1],(d)[3][2]=(s)[3][2],(d)[3][3]=(s)[3][3]
*/

#define matdump(m) { \
  int i, j; \
  for (i=0; i<4; i++) {\
  printf ("\t"); \
  for (j=0; j<4; j++) \
  printf ("%f ", m[i][j]); \
  printf ("\n"); \
  } \
}

extern int TelGetPolygonNormal( tel_point, Tint*, Tint, Tfloat* );
extern int TelGetNormal( Tfloat*, Tfloat*, Tfloat*, Tfloat* );
extern void TelMultiplymat3( Tmatrix3, Tmatrix3, Tmatrix3 );

#endif
