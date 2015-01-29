#include "stdafx.h"

#include "Util.hpp"
#include "BoardState.hpp"

namespace Util {
int CountDefense(BoardState* state, int player) {
  std::vector<Unit>* units = nullptr;
  if (player == 1) {
    units = &state->mUnits1;
  } else if (player == 2) {
    units = &state->mUnits2;
  }

  int defense = 0;
  for (const auto& unit : *units) {
    if (unit.can_block) {
      defense += unit.hp;
    }
  }

  return defense;
}

int CountAttack(BoardState* state, int player) {
  std::vector<Unit>* units = nullptr;
  if (player == 1) {
    units = &state->mUnits1;
  } else if (player == 2) {
    units = &state->mUnits2;
  }

  int attack = 0;
  for (const auto& unit : *units) {
    attack += unit.attack;
  }

  return attack;
}

void WipeOutDefenders(BoardState* state) {
  std::vector<Unit>* prev_units;
  if (state->mPhase == BoardState::kPhasePlayer1DealBreachDamage) {
    prev_units == &state->mUnits2;
  } else if (state->mPhase == BoardState::kPhasePlayer2DealBreachDamage) {
    prev_units == &state->mUnits1;
  }

  std::vector<Unit> filtered_units;
  for (const auto& unit : *prev_units) {
    if (!unit.can_block) {
      filtered_units.push_back(unit);
    }
  }
  *prev_units = filtered_units;
}
}
