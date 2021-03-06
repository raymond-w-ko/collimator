// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef _WIN32
#  define _CRT_SECURE_NO_WARNINGS
#endif
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <memory>

#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>
#include <boost/flyweight.hpp>
#include <boost/thread.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "Logger.hpp"

void print(std::string msg) {
  Logger::Log(msg);
}

class Action;
class BoardState;
typedef std::pair<Action*, BoardState*> ActionStatePair;
typedef std::vector<ActionStatePair> ActionStatePairVector;
