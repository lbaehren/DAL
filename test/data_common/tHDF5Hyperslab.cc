/*-------------------------------------------------------------------------*
 | $Id:: tNewClass.cc 3179 2009-10-14 13:20:10Z baehren                  $ |
 *-------------------------------------------------------------------------*
 ***************************************************************************
 *   Copyright (C) 2010                                                    *
 *   Lars B"ahren (bahren@astron.nl)                                       *
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

#include <HDF5Dataset.h>
#include <HDF5Hyperslab.h>

// Namespace usage
using std::cout;
using std::endl;
using DAL::HDF5Dataset;
using DAL::HDF5Hyperslab;

/*!
  \file tHDF5Hyperslab.cc

  \ingroup DAL
  \ingroup data_common

  \brief A collection of test routines for the HDF5Hyperslab class
 
  \author Lars B&auml;hren
 
  \date 2010/02/09
*/

//_______________________________________________________________________________
//                                                              test_constructors

/*!
  \brief Test constructors for a new HDF5Hyperslab object

  \return nofFailedTests -- The number of failed tests encountered within this
          function.
*/
int test_constructors ()
{
  cout << "\n[tHDF5Hyperslab::test_constructors]\n" << endl;

  int nofFailedTests (0);
  
  cout << "[1] HDF5Hyperslab () ..." << endl;
  try {
    HDF5Hyperslab slab;
    //
    slab.summary(); 
  } catch (std::string message) {
    std::cerr << message << endl;
    nofFailedTests++;
  }
  
  cout << "[2] HDF5Hyperslab (shape) ..." << endl;
  try {
    int rank (2);
    std::vector<hsize_t> shape (rank);
    //
    shape[0] = 1024;
    shape[1] = 10;
    //
    HDF5Hyperslab slab (shape);
    slab.summary(); 
  } catch (std::string message) {
    std::cerr << message << endl;
    nofFailedTests++;
  }
  
  cout << "[3] HDF5Hyperslab (shape,start,block) ..." << endl;
  try {
    int rank (2);
    std::vector<hsize_t> shape (rank);
    std::vector<int> start (rank);
    std::vector<int> block (rank);
    //
    shape[0] = 1024;
    shape[1] = 10;
    start[0] = 0;
    start[1] = 0;
    block[0] = shape[0]/2;
    block[1] = shape[1]/2;
    //
    HDF5Hyperslab slab (shape,start,block);
    slab.summary(); 
  } catch (std::string message) {
    std::cerr << message << endl;
    nofFailedTests++;
  }
  
  cout << "[4] HDF5Hyperslab (shape,start,stride,count,block) ..." << endl;
  try {
    int rank (2);
    std::vector<hsize_t> shape (rank);
    std::vector<int> start (rank);
    std::vector<int> stride (rank);
    std::vector<int> count (rank);
    std::vector<int> block (rank);
    //
    shape[0]  = 1024;
    shape[1]  = 10;
    start[0]  = shape[0]/4;
    start[1]  = shape[1]/4;
    stride[0] = 1;
    stride[1] = 1;
    count[0]  = 1;
    count[1]  = 1;
    block[0]  = shape[0]/2;
    block[1]  = shape[1]/2;
    //
    HDF5Hyperslab slab (shape,start,stride,count,block);
    slab.summary(); 
    //
    count[0]  = 2;
    count[1]  = 2;
    //
    HDF5Hyperslab slab2 (shape,start,stride,count,block);
    slab2.summary(); 
  } catch (std::string message) {
    std::cerr << message << endl;
    nofFailedTests++;
  }
  
  return nofFailedTests;
}

//_______________________________________________________________________________
//                                                          test_static_functions

/*!
  \brief Test the static methods

  \return nofFailedTests -- The number of failed tests encountered within this
          function.
*/
int test_static_functions ()
{
  cout << "\n[tHDF5Hyperslab::test_test_static_functions]\n" << endl;

  int nofFailedTests (0);

  try {
    unsigned int nelem (3);
    std::vector<int> start (nelem,0);
    std::vector<int> block (nelem,10);
    std::vector<int> stride;
    std::vector<int> count;

    cout << "-- start        = " << start  << endl;
    cout << "-- block        = " << block  << endl;
    cout << "-- stride       = " << stride << endl;
    cout << "-- count        = " << count  << endl;
    cout << "--> end         = " << HDF5Hyperslab::end (start,stride,count,block) << endl;
    cout << "--> nof. points = " << HDF5Hyperslab::nofDatapoints (count,block) << endl;
    cout << endl;

    count.resize(nelem);
    count = std::vector<int> (nelem,5);

    cout << "-- start        = " << start  << endl;
    cout << "-- block        = " << block  << endl;
    cout << "-- stride       = " << stride << endl;
    cout << "-- count        = " << count  << endl;
    cout << "--> end         = " << HDF5Hyperslab::end (start,stride,count,block) << endl;
    cout << "--> nof. points = " << HDF5Hyperslab::nofDatapoints (count,block) << endl;
    cout << endl;
    
    stride.resize(nelem);
    stride = std::vector<int> (nelem,2);

    cout << "-- start        = " << start  << endl;
    cout << "-- block        = " << block  << endl;
    cout << "-- stride       = " << stride << endl;
    cout << "-- count        = " << count  << endl;
    cout << "--> end         = " << HDF5Hyperslab::end (start,stride,count,block) << endl;
    cout << "--> nof. points = " << HDF5Hyperslab::nofDatapoints (count,block) << endl;
    
  } catch (std::string message) {
    std::cerr << message << endl;
    nofFailedTests++;
  }
  
  return nofFailedTests;
}

//_______________________________________________________________________________
//                                                              test_setHyperslab

/*!
  \brief Test setting hyperslab selection for a dataset

  \return nofFailedTests -- The number of failed tests encountered within this
          function.
*/
int test_setHyperslab ()
{
  cout << "\n[tHDF5Hyperslab::test_setHyperslab]\n" << endl;

  int nofFailedTests (0);
  std::string filename ("tHDF5Hyperslab.h5");

  //________________________________________________________
  // Open the file to work with
  
  hid_t fileID = H5Fcreate (filename.c_str(),
			    H5F_ACC_TRUNC,
			    H5P_DEFAULT,
			    H5P_DEFAULT);
  
  if (H5Iis_valid(fileID)) {
    std::cout << "-- Create file " << filename << std::endl;
  } else {
    std::cerr << "Failed to open file " << filename << endl;
    return 0;
  }
  
  //________________________________________________________
  // Create datasets
  
  std::cout << "-- Creating datasets ..." << std::endl;

  unsigned int nofAxes (3);
  std::vector<hsize_t> shape (nofAxes);

  shape[0] = 200;
  shape[1] = 200;
  shape[2] = 512;

  HDF5Dataset data1 (fileID,"Dataset1",shape);
  HDF5Dataset data2 (fileID,"Dataset2",shape);
  HDF5Dataset data3 (fileID,"Dataset3",shape);
  HDF5Dataset data4 (fileID,"Dataset4",shape);

  //________________________________________________________
  // Close the file

  H5Fclose(fileID);
  
  return nofFailedTests;
}

//_______________________________________________________________________________
//                                                                           main

//! Main function
int main ()
{
  int nofFailedTests (0);

  // Test for the constructor(s)
  nofFailedTests += test_constructors ();
  // Test the static methods
  nofFailedTests += test_static_functions ();
  //! Test setting hyperslab selection for a dataset
  nofFailedTests += test_setHyperslab ();

  return nofFailedTests;
}