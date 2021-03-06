#pragma once

#include "Common.h"
#include "ActionType.h"
#include "ActionSet.h"

namespace BOSS
{
class DFBB_BuildOrderSearchGoal
{
	std::vector<UnitCountType>  _goalUnits;                 // vector of goal number of units indexed by ActionType ID
	std::vector<UnitCountType>	_goalUnitsMax;              // vector of goal max number of units indexed by ActionType ID
	
	SupplyCountType		        _supplyRequiredVal;         // amount of supply required for all goal units in _goalUnits

    RaceID                      _race;                      // race of the action types in the goal
	
	void                        calculateSupplyRequired();
	
public:	
	
	DFBB_BuildOrderSearchGoal(const RaceID race = Races::None);
	
	bool                operator == (const DFBB_BuildOrderSearchGoal & g);
	bool                hasGoal() const;

	SupplyCountType     supplyRequired() const;
	UnitCountType       operator [] (const ActionID & a) const;
	UnitCountType       getGoal(const ActionType & a) const;
	UnitCountType       getGoalMax(const ActionType & a) const;
	
	void                setGoal(const ActionType & a, const UnitCountType num);
	void                setGoalMax(const ActionType & a, const UnitCountType num);
	void                printGoal() const;
};
}
