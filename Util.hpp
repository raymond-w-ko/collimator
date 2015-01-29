#pragma once

namespace Util {
  int CountDefense(BoardState* state, int player);
  int CountAttack(BoardState* state, int player);

  // mutation functions
  void WipeOutDefenders(BoardState* state);
}
