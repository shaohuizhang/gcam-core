#ifndef _BUILDING_COOLING_DMD_TECHNOLOGY_H_
#define _BUILDING_COOLING_DMD_TECHNOLOGY_H_
#if defined(_MSC_VER)
#pragma once
#endif

/*! 
* \file building_cooling_dmd_technology.h
* \ingroup CIAM
* \brief The building cooling service demand technology.
* \author Steve Smith
* \date $Date$
* \version $Revision$
*/

#include <vector>
#include <map>
#include <xercesc/dom/DOMNode.hpp>

#include "technologies/include/building_heating_dmd_technology.h"

// Forward declaration
class GDP;
class MarketInfo;


/*! 
* \ingroup CIAM
* \brief This building technology class calculates demand for building cooling services.
*
* Building demand technology objects, act differently than normal technology objects in that they 
* each generate a demand for a 
* specific building service (heating, cooling, lighting, etc.), which is then provided by 
* a supply sector.
* These technologies do not consume fuels or generate GHG emissions. These come from the supply sectors.
*
* The building cooling service is identical to the building heating service except for the use of cooling degree days
* instead of heatingdegreedays and a change of sign on the internal gains calcuation.
* \author Steve Smith
*/

class BuildingCoolingDmdTechnology : public BuildingHeatCoolDmdTechnology
{
public:
    BuildingCoolingDmdTechnology(); // default construtor
    virtual BuildingCoolingDmdTechnology* clone() const;
    virtual const std::string& getXMLName1D() const;
    static const std::string& getXMLNameStatic1D();
    virtual void initCalc( const MarketInfo* aSubsectorInfo );
protected:
    double getInternalGainsSign() const;
    double getDemandFnPrefix( const std::string& regionName, const int period );
    double coolingDegreeDays; // !< Heating degree days -- cached from Sector
private:
    static const std::string XML_NAME1D; //!< tag name for toInputXML
};
#endif // _BUILDING_COOLING_DMD_TECHNOLOGY_H_
