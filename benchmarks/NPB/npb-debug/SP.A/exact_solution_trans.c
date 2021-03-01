//-------------------------------------------------------------------------//
//                                                                         //
//  This benchmark is a serial C version of the NPB SP code. This C        //
//  version is developed by the Center for Manycore Programming at Seoul   //
//  National University and derived from the serial Fortran versions in    //
//  "NPB3.3-SER" developed by NAS.                                         //
//                                                                         //
//  Permission to use, copy, distribute and modify this software for any   //
//  purpose with or without fee is hereby granted. This software is        //
//  provided "as is" without express or implied warranty.                  //
//                                                                         //
//  Information on NPB 3.3, including the technical report, the original   //
//  specifications, source code, results and information on how to submit  //
//  new results, is available at:                                          //
//                                                                         //
//           http://www.nas.nasa.gov/Software/NPB/                         //
//                                                                         //
//  Send comments or suggestions for this C version to cmp@aces.snu.ac.kr  //
//                                                                         //
//          Center for Manycore Programming                                //
//          School of Computer Science and Engineering                     //
//          Seoul National University                                      //
//          Seoul 151-744, Korea                                           //
//                                                                         //
//          E-mail:  cmp@aces.snu.ac.kr                                    //
//                                                                         //
//-------------------------------------------------------------------------//

//-------------------------------------------------------------------------//
// Authors: Sangmin Seo, Jungwon Kim, Jun Lee, Jeongho Nah, Gangwon Jo,    //
//          and Jaejin Lee                                                 //
//-------------------------------------------------------------------------//

#include "header.h"

//---------------------------------------------------------------------
// this function returns the exact solution at point xi, eta, zeta  
//---------------------------------------------------------------------
void exact_solution(double xi, double eta, double zeta, double dtemp[5])
{
   long double xi_H = xi;
   long double eta_H = eta;
   long double zeta_H = zeta;
  int m;

  for (m = 0; m < 5; m++) {
    dtemp[m] = ce[m][0] +
      xi_H  *(ce[m][1] + xi_H  *(ce[m][4] + xi_H  *(ce[m][7] + xi_H  *ce[m][10]))) +
      eta_H *(ce[m][2] + eta_H *(ce[m][5] + eta_H *(ce[m][8] + eta_H *ce[m][11]))) +
      zeta_H*(ce[m][3] + zeta_H*(ce[m][6] + zeta_H*(ce[m][9] + zeta_H*ce[m][12])));
  }
}
