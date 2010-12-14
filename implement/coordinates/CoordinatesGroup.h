/*-------------------------------------------------------------------------*
 | $Id::                                                                 $ |
 *-------------------------------------------------------------------------*
 ***************************************************************************
 *   Copyright (C) 2009                                                    *
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

#ifndef COORDINATESGROUP_H
#define COORDINATESGROUP_H

// Standard library header files
#include <iostream>
#include <string>

// DAL header files
#include <HDF5CommonInterface.h>
#include <DirectionCoordinate.h>
#include <LinearCoordinate.h>

namespace DAL { // Namespace DAL -- begin
  
  /*!
    \class CoordinatesGroup
    
    \ingroup DAL
    \ingroup coordinates
    
    \brief High-level interface to the system logs attached to a beamformed dataset
    
    \author Lars B&auml;hren

    \date 2009/11/26

    \test tCoordinatesGroup.cc
    
    <h3>Prerequisite</h3>
    
    <ul type="square">
      <li>LOFAR Data Format ICDs:
      <ul>
	<li>LOFAR Data Format ICD: Representations of World Coordinates
	(LOFAR-USG-ICD-002)
	<li>LOFAR Data Format ICD: Beam-Formed Data (LOFAR-USG-ICD-003)
	<li>LOFAR Data Format ICD: LOFAR Sky Image (LOFAR-USG-ICD-004)
      </ul>
      <li>Components of the LOFAR user software:
      <ul>
	<li>HDF5CommonInterface -- Common functionality for the high-level
	interfaces to the datasets
      </ul>
    </ul>
    
    \todo addCoordinate -- add a further coordinate object to the coordinates group.
    \todo getCoordinate -- retrieve an individual coordinate embedded within this
          group write coordinates group to a HDF5 file
    \todo cast embedded information into a casa::CoordinateSystem object; this
          however will be incomplete, as the latter only stores a subset of the
	  information this classes handles.
    \todo get/set reference lcoation as casa::MPosition
    
    <h3>Synopsis</h3>

    The coordinates group, as defined through LOFAR-USG-ICD-002, works as a
    container to collect coordinate descriptions as attached to an image or
    some other LOFAR data-set.

    <h3>Example(s)</h3>
    
  */  
  class CoordinatesGroup : public HDF5CommonInterface {

    //! Group type descriptor
    std::string itsGroupType;
    //! Reference location value
    std::vector<double> refLocationValue_p;
    //! Reference location unit
    std::vector<std::string> refLocationUnit_p;
    //! Reference location frame
    std::string refLocationFrame_p;
    //! Reference time value
    double refTimeValue_p;
    //! Reference time unit
    std::string refTimeUnit_p;
    //! Reference time frame
    std::string refTimeFrame_p;
    //! nof. embedded coordinate objects
    int nofCoordinates_p;
    //! nof. coordinate axes
    int nofAxes_p;
    //! Container for book-keeping on the embedded coordinate objects
    std::vector<std::string> itsCoordinateTypes;
    //! Container for the coordinate objects embedded within this group
    std::vector<Coordinate*> coordinates_p;
    
  public:
    
    // === Construction =========================================================
    
    //! Default constructor
    CoordinatesGroup ();
    
    //! Argumented constructor
    CoordinatesGroup (hid_t const &location,
		      bool const &create);
    
    // === Destruction =========================================================
    
    //! Default destructor
    virtual ~CoordinatesGroup ();
    
    // === Parameter access =====================================================
    
    /*!
      \brief Get the name of the class
      
      \return className -- The name of the class, CoordinatesGroup.
    */
    inline std::string className () const {
      return "CoordinatesGroup";
    }
    
    //! Provide a summary of the internal status
    inline void summary () {
      summary (std::cout);
    }
    
    /*!
      \brief Provide a summary of the internal status
      
      \param os -- Output stream to which the summary is written.
    */
    void summary (std::ostream &os);    
    
    // === Methods ==============================================================
    
    //! Open the file containing the beamformed data.
    bool open (hid_t const &location,
	       std::string const &name,
	       bool const &create=true);
    //! Get the group type identifier
    inline std::string groupType () const {
      return itsGroupType;
    }
    //! Get the reference location value
    inline std::vector<double> refLocationValue () const {
      return refLocationValue_p;
    }
    //! Get the reference location unit
    inline std::vector<std::string> refLocationUnit () const {
      return refLocationUnit_p;
    }
    //! Get the reference location frame identifier
    inline std::string refLocationFrame () const {
      return refLocationFrame_p;
    }
    //! Get the reference time value
    inline double refTimeValue () const {
      return refTimeValue_p;
    }
    //! Get the reference time unit
    inline std::string refTimeUnit () const {
      return refTimeUnit_p;
    }
    //! Get the reference time frame identifier
    inline std::string refTimeFrame () const {
      return refTimeFrame_p;
    }

    //! Get the nof. embedded coordinate objects
    inline int nofCoordinates () const {
      return nofCoordinates_p;
    }
    //! Get the nof. coordinate axes
    inline int nofAxes () const {
      return nofAxes_p;
    }

  protected:
    
    //! Open the structures embedded within the current one
    bool openEmbedded (bool const &create);
    //! Set up the list of attributes attached to the structure
    void setAttributes ();
    
  private:

    //! Initialize the internal parameter of the object
    bool init ();
    //! Unconditional deletion 
    void destroy(void);
    //! Read the values of the attributes from the dataset
    bool readAttributes ();
    //! Write the values of the attributes to the dataset
    bool writeAttributes ();
    
  }; // Class CoordinatesGroup -- end
  
} // Namespace DAL -- end

#endif /* COORDINATESGROUP_H */

