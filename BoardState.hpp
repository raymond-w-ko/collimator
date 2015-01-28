#pragma once

#include "Unit.hpp"

class BoardState {
 public:
  enum Phase {
    // where you usually click on drones (or not), buy units (or not), click on
    // other unit abilities (or not)
    kPhasePlayer1Build,

    // where you end your turn, and attack is calculated
    kPhasePlayer1CommitAttack,

    // if all defenders are breached, then we have to choose what units to kill
    kPhasePlayer1DealBreachDamage,

    // where player 2 defend against player 1's attack.
    kPhasePlayer2Defend,

    kPhasePlayer2Build,
    kPhasePlayer2CommitAttack,
    kPhasePlayer2DealBreachDamage,

    kPhasePlayer1Defend,

    kNumPhases,
  };

  BoardState(std::string filename);
  BoardState* CreateChildClone();
  void IncrementPhase();

  const BoardState* mParent;
  Phase mPhase;
  int mPendingAttack;
  std::vector<std::string>* mBuildableUnits;
  std::vector<Unit> mUnits1;
  std::vector<Unit> mUnits2;
};
