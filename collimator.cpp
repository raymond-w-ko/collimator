#include "stdafx.h"

#include "Unit.hpp"
#include "BoardState.hpp"
#include "Action.hpp"

static void LoadUnits() {
	using boost::property_tree::ptree;
	ptree pt;
	read_json("units.json", pt);
	for (auto kv : pt) {
        auto unit = kv.second;
        Unit::RegisterUnit(unit);
	}
}

static ActionStatePairVector EnumerateBuildPhase(ActionStatePairVector pairs) {
    ActionStatePairVector children;

    // TODO: actually enumerate, not needed for puzzle 1

    for (auto pair : pairs) {
        auto parent_state = pair.second;
        auto action = new NullAction;
        auto state = action->ApplyTo(parent_state);
        children.push_back(std::make_pair(action, state));
    }
    
    return children;
}

static ActionStatePairVector EnumerateAttack(ActionStatePairVector pairs) {
    std::vector<ActionStatePair> children;

    for (auto pair : pairs) {
        auto parent_state = pair.second;
        auto action = new AttackCountAction;
        auto state = action->ApplyTo(parent_state);
        children.push_back(std::make_pair(action, state));
    }
    
    return children;
}

static ActionStatePairVector EnumerateBreach(ActionStatePairVector pairs) {
    std::vector<ActionStatePair> children;

    for (auto pair : pairs) {
        auto parent_state = pair.second;
        auto action = new AttackCountAction;
        auto state = action->ApplyTo(parent_state);
        children.push_back(std::make_pair(action, state));
    }
    
    return children;
}

int main(int argc, char* argv[])
{
    std::vector<std::string> args(argv, argv + argc);
    if (args.size() != 2) {
        std::cout << args[0] << " <initial_state.json>\n";
        return 1;
    }

    LoadUnits();

    auto initial_state = BoardState(args[1]);

    auto states = std::vector<ActionStatePair>();

    states.push_back(std::make_pair(nullptr, &initial_state));

    states = EnumerateBuildPhase(states);
    states = EnumerateAttack(states);
    //states = EnumerateBreach(states);

	return 0;
}
