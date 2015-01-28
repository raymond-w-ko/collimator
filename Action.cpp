#include "stdafx.h"

#include "Action.hpp"
#include "BoardState.hpp"

Action::Action() {
  ;
}

Action::~Action() {
  ;
}

////////////////////////////////////////////////////////////////////////////////

NullAction::NullAction() {
  ;
}

NullAction::~NullAction() {
  ;
}

BoardState* NullAction::ApplyTo(BoardState* state) {
  state = state->CreateChildClone();
  state->IncrementPhase();
  return state;
}

////////////////////////////////////////////////////////////////////////////////

AttackCountAction::AttackCountAction() {
  ;
}

AttackCountAction::~AttackCountAction() {
  ;
}

BoardState* AttackCountAction::ApplyTo(BoardState* state) {
  state = state->CreateChildClone();

  std::vector<Unit>* units = nullptr;
  if (state->mPhase == BoardState::kPhasePlayer1CommitAttack) {
    units = &state->mUnits1;
  }
  if (state->mPhase == BoardState::kPhasePlayer2CommitAttack) {
    units = &state->mUnits2;
  }

  int attack = 0;
  for (const auto& unit : *units) {
    attack += unit.attack;
  }
  state->mPendingAttack = attack;

  state->IncrementPhase();
  return state;
}
