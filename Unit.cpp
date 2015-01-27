#include "stdafx.h"
#include "Unit.hpp"

std::unordered_map<std::string, Unit> Unit::msUnits;

Unit::Unit() {
}

Unit Unit::GetFromName(std::string name) {
  auto unit = msUnits.find(name);
  if (unit == msUnits.end()) {
    throw std::exception(("could not find unit of name: " + name).c_str());
  }
  return unit->second;
}

void Unit::RegisterUnit(const boost::property_tree::ptree& data) {
  std::string name = data.get<std::string>("name");

  Unit& unit = msUnits[name];

  if (name.length() >= 16)
    throw std::exception("name too long");
  strcpy(unit.name, name.c_str());

  unit.hp = data.get<int>("hp");
  unit.fragile = data.get<bool>("fragile");
  unit.attack = data.get<int>("attack");
}
