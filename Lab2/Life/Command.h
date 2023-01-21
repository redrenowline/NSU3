#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

#include <QApplication>

#include "Field.h"
#include "FieldLoader.h"

class Strategy
{
public:
  virtual void exec();

};

// Command for exiting
class ExitStrategy: public Strategy{
public:
  ExitStrategy();

  void exec();
};

// Command which calculate next state of universum
class NextTikStrategy: public Strategy{
public:
  NextTikStrategy(std::shared_ptr<Field> f);

  void exec();
private:
  std::shared_ptr<Field> fd;
};

// Command which calculating some states of universum
class NextTiksStrategy: public Strategy{
public:
    NextTiksStrategy(std::shared_ptr<Field> f, unsigned int k = 1);

    void exec();
private:
    std::shared_ptr<Field> fd;
  unsigned int num;
};

// Command which upload universum from file
class UploadFieldStrategy: public Strategy{
public:
  UploadFieldStrategy(std::shared_ptr<Field> f, std::string p);

  void exec();
private:
  std::shared_ptr<Field> fd;
  std::string path;
};

// Command which save field to file
class SaveFieldStrategy: public Strategy{
public:
  SaveFieldStrategy(std::shared_ptr<Field> f, std::string s);

  void exec();
private:
  std::shared_ptr<Field> fd;
  std::string path;
};

#endif // COMMAND_H
