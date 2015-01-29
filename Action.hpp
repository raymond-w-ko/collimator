#pragma once

class Action {
 public:
  Action();
  virtual ~Action();
  virtual BoardState* ApplyTo(BoardState* state) = 0;
};

class NullAction : public Action {
 public:
  NullAction();
  virtual ~NullAction();
  virtual BoardState* ApplyTo(BoardState* state);
};

class AttackCountAction : public Action {
 public:
  AttackCountAction();
  virtual ~AttackCountAction();
  virtual BoardState* ApplyTo(BoardState* state);
};

