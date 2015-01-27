#include "stdafx.h"

#include "Unit.hpp"
#include "BoardState.hpp"

static void LoadUnits() {
	using boost::property_tree::ptree;
	ptree pt;
	read_json("units.json", pt);
	for (auto kv : pt) {
        auto unit = kv.second;
        Unit::RegisterUnit(unit);
	}
}

int main(int argc, char* argv[])
{
    std::vector<std::string> args(argv, argv + argc);
    if (args.size() != 2) {
        std::cout << args[0] << " <initial_state.json>\n";
        return 1;
    }

    LoadUnits();

    auto state = BoardState(args[1]);

	return 0;
}
