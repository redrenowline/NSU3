#pragma once

#include <iostream>
#include <vector>

#include "Field.h"
#include "Strategy.h"
#include "EvoGUI.h"

class Core : public QObject{
  Q_OBJECT
public:

  Core();
  ~Core();


  void start();
  std::shared_ptr<Field> getField();
private:
  std::shared_ptr<Field> fd;

  std::shared_ptr<EvoGUI> gui;

public slots:
  void executeStrategy(std::shared_ptr<Strategy> cmd);

};

