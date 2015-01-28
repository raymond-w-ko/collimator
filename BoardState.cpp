#include "stdafx.h"

#include "BoardState.hpp"

BoardState::BoardState(std::string filename) {
  mParent = nullptr;
  mPhase = kPhasePlayer1Build;
  mPendingAttack = 0;

	using boost::property_tree::ptree;
	ptree pt;
  read_json(filename, pt);

  auto buildable_units = new std::vector<std::string>();
  for (auto kv : pt.get_child("buildable_units.units")) {
    auto unit_name = kv.second.data();
    buildable_units->push_back(unit_name);
  }
  mBuildableUnits = buildable_units;

  for (auto kv : pt.get_child("units1.units")) {
    auto unit_name = kv.second.data();
    auto unit = Unit::CreateFromName(unit_name);
    mUnits1.push_back(unit);
  }

  for (auto kv : pt.get_child("units2.units")) {
    auto unit_name = kv.second.data();
    auto unit = Unit::CreateFromName(unit_name);
    mUnits2.push_back(unit);
  }
}

BoardState* BoardState::CreateChildClone() {
  BoardState* state = new BoardState(*this);
  state->mParent = this;
  return state;
}

void BoardState::IncrementPhase() {
  mPhase = (Phase)((mPhase + 1) % kNumPhases);
}
