#pragma once

#include "Unit.hpp"

class BoardState {
 public:
  BoardState(std::string filename);

 private:
  std::vector<std::string>* mBuildableUnits;
  std::vector<Unit> mUnits1;
  std::vector<Unit> mUnits2;
};
