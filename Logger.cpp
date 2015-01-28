#include "stdafx.h"

#include "Logger.hpp"

std::ofstream Logger::msLogFile;

void Logger::InitStatic() {
  msLogFile = std::ofstream("log.txt");
}

void Logger::Log(std::string msg) {
  msLogFile << msg << "\n";
}
