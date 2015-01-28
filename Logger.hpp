#pragma once

class Logger {
 public:
  static void InitStatic();
  static void Log(std::string msg);
 private:
  static std::ofstream msLogFile;
};
