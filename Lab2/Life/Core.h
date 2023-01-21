#pragma once

#include <iostream>
#include <vector>

#include "Field.h"
#include "Strategy.h"

class Core : public QObject{
  Q_OBJECT
public:

  Core();
  ~Core();


  void start();
  std::shared_ptr<Field> getField();

  void execStrategy(std::shared_ptr<Strategy> cmd);
private:
  std::shared_ptr<Field> fd;

};

