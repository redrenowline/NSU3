#pragma once
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

#include "Cells.h"

class Specification {
public:
  Specification();

  size_t getcrSize() const; // getter for crSize
  size_t getsrSize() const; // getter for srSize
  std::vector<unsigned char> getcrReason() const; // getter for crReason
  std::vector<unsigned char> getsrReason() const; // getter for srReason

  // setter for crSize is not available, crSize changes depend on crReason changes
  // setter for srReason is not available?, srSize changes depend on srReason changes
  void setcrReason(std::vector<unsigned char>); // setter for crReason
  void setsrReason(std::vector<unsigned char>); // setter for srReason

private:
  size_t crSize; // size of crReason
  size_t srSize; // size of srReason
  std::vector<unsigned char> crReason; // creationReason - count of nearby alive cells for birth new cell
  std::vector<unsigned char> srReason; // surviveReason - count of nearby alive cells for surviving
};

class Field {
  friend class FieldLoader;

public:

  Field();
  Field(unsigned int,unsigned int, Specification);
  ~Field();

  void processing();
  std::string title;

  unsigned int getHeight();
  unsigned int getWidth();
  cType getType();

private:
  std::vector<std::vector<cType>> mass;
  unsigned int height, width;

  Specification sp;

  unsigned int calcLocalicity(unsigned int, unsigned int);
  bool calcSurvivalability(unsigned int);
  bool calcBirth(unsigned int);

protected:
};
