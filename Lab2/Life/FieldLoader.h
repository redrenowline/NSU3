#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Field.h"

class FieldLoader
{
public:

  Field load(std::string path);
private:

  const char* INDICATOR = "#Life 1.06";
  const char* NAMEINDICATOR = "#N";
  const char* RULESINDICATOR = "#R";
  const char* BIRTHINDICATOR = "B";
  const char* SURVIVEINDICATOR = "/S";

  std::string readTitle(std::ifstream&);
  bool checkIdentity(std::ifstream& );
  Specification readRules(std::ifstream&);
protected:
};
