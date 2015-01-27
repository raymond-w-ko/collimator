#include "stdafx.h"

#include "Unit.hpp"

int main(int argc, char* argv[])
{
	using boost::property_tree::ptree;
	ptree pt;
	read_json("units.json", pt);
	for (auto kv : pt) {
        auto unit = kv.second;
        Unit::RegisterUnit(unit);
	}
	return 0;
}
