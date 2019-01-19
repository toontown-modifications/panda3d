// Filename: config_toontown.cxx
// Created by:  jwcotejr (19Jan19)
//
////////////////////////////////////////////////////////////////////
//
// TOONTOWN OFFLINE SOFTWARE
// Copyright (c) The Toontown Offline Team.  All rights reserved.
//
// Use of this software by anyone other than those of the Toontown Offline team
// is strictly prohibited without explicit permission from the Toontown Offline team.
//
////////////////////////////////////////////////////////////////////

#include "DNAStorage.h"
#include "DNASuitPoint.h"
#include "DNASuitEdge.h"
#include "DNASuitPath.h"
#include "DNAGroup.h"
#include "DNAVisGroup.h"
#include "DNANode.h"
#include "DNAProp.h"
#include "DNASign.h"
#include "DNASignBaseline.h"
#include "DNASignGraphic.h"
#include "DNAFlatBuilding.h"
#include "DNAWall.h"
#include "DNAWindows.h"
#include "DNACornice.h"
#include "DNAData.h"
#include "DNALandmarkBuilding.h"
#include "DNAAnimProp.h"
#include "DNAInteractiveProp.h"
#include "DNAAnimBuilding.h"
#include "DNADoor.h"
#include "DNAFlatDoor.h"
#include "DNAStreet.h"
#include "DNABattleCell.h"

#include "config_toontown.h"

NotifyCategoryDef(dna, "");

ConfigureDef(config_toontown)
ConfigureFn(config_toontown)
{
    DNASuitPoint::init_type();
    DNASuitEdge::init_type();
    DNASuitPath::init_type();
    DNAGroup::init_type();
    DNAVisGroup::init_type();
    DNANode::init_type();
    DNAProp::init_type();
    DNASign::init_type();
    DNASignBaseline::init_type();
    DNASignGraphic::init_type();
    DNAFlatBuilding::init_type();
    DNAWall::init_type();
    DNAWindows::init_type();
    DNACornice::init_type();
    DNAData::init_type();
    DNALandmarkBuilding::init_type();
    DNAAnimProp::init_type();
    DNAInteractiveProp::init_type();
    DNAAnimBuilding::init_type();
    DNADoor::init_type();
    DNAFlatDoor::init_type();
    DNAStreet::init_type();
    DNABattleCell::init_type();
}
