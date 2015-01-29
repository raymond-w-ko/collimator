#include "stdafx.h"

#include "Action.hpp"
#include "BoardState.hpp"
#include "Util.hpp"

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

  int attacking_player = 0;
  int defending_player = 0;

  if (state->mPhase == BoardState::kPhasePlayer1CommitAttack) {
    attacking_player = 1;
    defending_player = 2;
  } else if (state->mPhase == BoardState::kPhasePlayer2CommitAttack) {
    attacking_player = 2;
    defending_player = 1;
  }
  state->mPendingAttack = Util::CountAttack(state, attacking_player);
  state->mPendingDefense = Util::CountDefense(state, defending_player);
  state->mPendingBreachDamage = state->mPendingAttack - state->mPendingDefense;

  state->IncrementPhase();
  return state;
}
