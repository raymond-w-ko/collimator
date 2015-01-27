#pragma once

class Unit {
 public:
  static Unit GetFromName(std::string name);
  static void RegisterUnit(const boost::property_tree::ptree& data);

  Unit();

 private:
  static std::unordered_map<std::string, Unit> msUnits;

  char name[16];
  int hp;
  int attack;
  bool fragile;
};
