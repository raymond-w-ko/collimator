#include "stdafx.h"
#include "Unit.hpp"

std::unordered_map<std::string, Unit> Unit::msUnits;
uint64_t Unit::msIdCounter = 0;

Unit::Unit() {
}

Unit Unit::CreateFromName(std::string name) {
  auto unit = msUnits.find(name);
  if (unit == msUnits.end()) {
    throw std::exception(("could not find unit of name: " + name).c_str());
  }

  auto new_unit = unit->second;
  new_unit.id = ++msIdCounter;
  return new_unit;
}

void Unit::RegisterUnit(const boost::property_tree::ptree& data) {
  std::string name = data.get<std::string>("name");

  Unit& unit = msUnits[name];

  const size_t name_size = sizeof(unit.name)/sizeof(char);
  if (name.length() >= name_size)
    throw std::exception("name too long");
  ::memset(unit.name, 0, name_size);
  strcpy(unit.name, name.c_str());

  unit.id = 0;
  unit.hp = data.get<int>("hp");
  unit.fragile = data.get<bool>("fragile");
  unit.attack = data.get<int>("attack");
}
