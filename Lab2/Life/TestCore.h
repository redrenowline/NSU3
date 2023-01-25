#ifndef TESTCORE_H
#define TESTCORE_H

#include "Core.h"

class TestCore{

public:
  TestCore();

  Field generateField();
  Field generateNullField();
  Field generateTwiceField();
  Specification generateBaseSpecification();
  bool isThatCellAlive(Field &fd, int x, int y);
  void setCellAlive(Field &fd, int x, int y);

  Field detranspField(std::string strl, int h, int w);

  bool eqFields(Field fd1, Field fd2);

  void printField(Field fd);
private:

};

#endif // TESTCORE_H
