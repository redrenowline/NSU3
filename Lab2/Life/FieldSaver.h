#ifndef FIELDSAVER_H
#define FIELDSAVER_H

#include <string>
#include <iostream>
#include <fstream>

#include "Field.h"

class FieldSaver{

public:
  FieldSaver();

  void save(std::string path, Field &fd);

  const char* INDICATOR = "#Life 1.06";
  const char* NAMEINDICATOR = "#N";
  const char* RULESINDICATOR = "#R";
  const char* BIRTHINDICATOR = "B";
  const char* SURVIVEINDICATOR = "/S";

private:

protected:

};

#endif // FIELDSAVER_H
