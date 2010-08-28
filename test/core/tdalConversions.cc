/*-------------------------------------------------------------------------*
 | $Id::                                                                 $ |
 *-------------------------------------------------------------------------*
 ***************************************************************************
 *   Copyright (C) 2010                                                    *
 *   Lars B"ahren <bahren@astron.nl>                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <dalCommon.h>
#include <dalConversions.h>

using std::cout;
using std::endl;

/*!
  \file tdalConversions.cc

  \ingroup DAL
  \ingroup core

  \brief A collection of test routines for the dalConversions class
 
  \author Lars B&auml;hren
 
  \date 2010/08/27
*/

//_______________________________________________________________________________
//                                                             test_convertVector

/*!
  \brief Test conversion of vectors

  \return nofFailedTests -- The number of failed tests encountered within this
          function.
*/
int test_convertVector ()
{
  std::cout << "\n[tdalConversions::test_constructors]\n" << std::endl;

  int nofFailedTests (0);
  unsigned int nelem (10);
  
  std::cout << "[1] Convert std::vector<int> to casa::Vector<T> ..." << std::endl;
  try {
    std::vector<int> vectorInt (nelem);
    casa::Vector<int> VectorInt;
    casa::Vector<float> VectorFloat;
    casa::Vector<double> VectorDouble;

    // assign values to the original vector
    for (unsigned int n(0); n<nelem; ++n) {
      vectorInt[n] = n;
    }

    // convert vector and display results

    DAL::convertVector (VectorInt, vectorInt);
    DAL::convertVector (VectorFloat, vectorInt);
    DAL::convertVector (VectorDouble, vectorInt);

    cout << "-- <int> -> <int>    : " << vectorInt << " -> " << VectorInt    << endl;
    cout << "-- <int> -> <float>  : " << vectorInt << " -> " << VectorFloat  << endl;
    cout << "-- <int> -> <double> : " << vectorInt << " -> " << VectorDouble << endl;

  } catch (std::string message) {
    std::cerr << message << std::endl;
    nofFailedTests++;
  }
  
  std::cout << "[2] Convert std::vector<float> to casa::Vector<T> ..." << std::endl;
  try {
    std::vector<float> vectorFloat (nelem);
    casa::Vector<int> VectorInt;
    casa::Vector<float> VectorFloat;
    casa::Vector<double> VectorDouble;

    // assign values to the original vector
    for (unsigned int n(0); n<nelem; ++n) {
      vectorFloat[n] = n;
    }

    // convert vector and display results

    DAL::convertVector (VectorInt, vectorFloat);
    DAL::convertVector (VectorFloat, vectorFloat);
    DAL::convertVector (VectorDouble, vectorFloat);

    cout << "-- <float> -> <int>    : " << vectorFloat << " -> " << VectorInt    << endl;
    cout << "-- <float> -> <float>  : " << vectorFloat << " -> " << VectorFloat  << endl;
    cout << "-- <float> -> <double> : " << vectorFloat << " -> " << VectorDouble << endl;
  } catch (std::string message) {
    std::cerr << message << std::endl;
    nofFailedTests++;
  }
  
  std::cout << "[3] Convert std::vector<double> to casa::Vector<T> ..." << std::endl;
  try {
    std::vector<double> vectorDouble (nelem);
    casa::Vector<int> VectorInt;
    casa::Vector<float> VectorFloat;
    casa::Vector<double> VectorDouble;

    // assign values to the original vector
    for (unsigned int n(0); n<nelem; ++n) {
      vectorDouble[n] = n;
    }

    // convert vector and display results

    DAL::convertVector (VectorInt, vectorDouble);
    DAL::convertVector (VectorFloat, vectorDouble);
    DAL::convertVector (VectorDouble, vectorDouble);

    cout << "-- <float> -> <int>    : " << vectorDouble << " -> " << VectorInt    << endl;
    cout << "-- <float> -> <float>  : " << vectorDouble << " -> " << VectorFloat  << endl;
    cout << "-- <float> -> <double> : " << vectorDouble << " -> " << VectorDouble << endl;
  } catch (std::string message) {
    std::cerr << message << std::endl;
    nofFailedTests++;
  }
  
  return nofFailedTests;
}

//_______________________________________________________________________________
//                                                                           main

int main ()
{
  int nofFailedTests (0);

  // Test for the constructor(s)
  nofFailedTests += test_convertVector ();

  return nofFailedTests;
}
