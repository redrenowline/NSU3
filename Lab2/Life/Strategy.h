#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

#include <QApplication>

#include "Field.h"
#include "FieldLoader.h"
#include "FieldSaver.h"

namespace Life{

class Strategy
{
public:
  virtual void exec();

};

class ExitStrategy: public Strategy{
public:
  ExitStrategy();

  void exec();
};


class NextTikStrategy: public Strategy{
public:
  NextTikStrategy(std::shared_ptr<Field> f);

  void exec();
private:
  std::shared_ptr<Field> fd;
};


class NextTiksStrategy: public Strategy{
public:
    NextTiksStrategy(std::shared_ptr<Field> f, unsigned int k = 1);

    void exec();
private:
    std::shared_ptr<Field> fd;
  unsigned int num;
};


class UploadFieldStrategy: public Strategy{
public:
  UploadFieldStrategy(std::shared_ptr<Field> f, std::string p);

  void exec();
private:
  std::shared_ptr<Field> fd;
  std::string path;
};


class SaveFieldStrategy: public Strategy{
public:
  SaveFieldStrategy(std::shared_ptr<Field> f, std::string s);

  void exec();
private:
  std::shared_ptr<Field> fd;
  std::string path;
};

}

#endif // COMMAND_H
