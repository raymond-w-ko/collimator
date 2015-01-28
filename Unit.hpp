#pragma once

class Unit {
 public:
  static Unit CreateFromName(std::string name);
  static void RegisterUnit(const boost::property_tree::ptree& data);

  Unit();

  uint64_t id;
  char name[16];
  int hp;
  int attack;
  bool fragile;
  bool can_block;

 private:
  static std::unordered_map<std::string, Unit> msUnits;
  static uint64_t msIdCounter;
};
