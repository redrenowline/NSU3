#include "Field.h"

namespace Life{
Field::Field(){
  this->height = 0;
  this->width = 0;
  this->sp = Specification();
  std::cout << "Field has been created\n";
}

Field::Field(unsigned int n,unsigned int m, Specification t_sp) {
  this->height = n;
  this->width = m;
  this->sp = t_sp;
  mass = std::vector<std::vector<cType>>();
  mass.resize(n);
  for (int itr = 0; itr < n; itr++) {
    mass[itr] = std::vector<cType>();
    mass[itr].resize(m);
    for (int j = 0; j < m; j++) {
      mass[itr][j] = cType::DEAD;
    }
  }
}

Field::~Field() {

}

unsigned int Field::calcLocalicity(unsigned int x, unsigned int y) {
  unsigned int res = 0;
  TorusCoordinatesCalculator calc(height, width);
  for (int i = -1; i < 2; i++)
    for (int j = -1; j < 2; j++)
      res += (mass[calc.calcX(x+i)][calc.calcY(y+j)] == cType::ALIVE) ? 1 : 0;
  if (mass[x][y] == cType::ALIVE)
    return res - 1;
  return res;
}

bool Field::calcSurvivalability(unsigned int neigh) {
  for (int itr = 0; itr < sp.getsrSize(); itr++)
    if (neigh == sp.getsrReason()[itr] - ZERO) return true;
  return false;
}

bool Field::calcBirth(unsigned int neigh) {
  for (int itr = 0; itr < sp.getsrSize(); itr++)
    if (neigh == sp.getcrReason()[itr] - ZERO) return true;
  return false;
}

void Field::processing() {
  std::vector<std::vector<cType>> cp_mass(mass);

  for (unsigned int i = 0; i < height; i++)
    for (unsigned int j = 0; j < width; j++) {
      unsigned int localicity = calcLocalicity(i, j);
      switch (mass[i][j]) {

      case cType::ALIVE:
        if (!calcSurvivalability(localicity))
          cp_mass[i][j] = cType::DEAD;
        break;

      case cType::DEAD:
        if (calcBirth(localicity))
          cp_mass[i][j] = cType::ALIVE;
        break;
      }
    }
  mass = cp_mass;
  return;
}

unsigned int Field::getHeight(){
  return height;
}

unsigned int Field::getWidth(){
  return width;
}

std::string Field::transparentField(){
  std::string answer = "";
  for(int i = 0; i < width; i++){
    for(int j = 0; j  < height; j++){
      answer += mass[i][j] == cType::ALIVE ? ONE : ZERO;
    }
  }
  return answer;
}

Specification::Specification(){

}

size_t Specification::getcrSize() const{
  return crSize;
}

size_t Specification::getsrSize() const{
  return srSize;
}

std::vector<unsigned char> Specification::getcrReason() const{
  return crReason;
}

std::vector<unsigned char> Specification::getsrReason() const{
  return srReason;
}

void Specification::setcrReason(std::vector<unsigned char> vec){
  this->crReason = vec;
  this->crSize = vec.size();
}

void Specification::setsrReason(std::vector<unsigned char> vec){
  this->srReason = vec;
  this->srSize = vec.size();
}

TorusCoordinatesCalculator::TorusCoordinatesCalculator(int arg1, int arg2): height(arg1), width(arg2){}

unsigned int TorusCoordinatesCalculator::calcX(int x){
  if(x == -1){
    return height-1;
  }
  if(x == height){
      return 0;
  }
  return x;
}

unsigned int TorusCoordinatesCalculator::calcY(int y){
  if(y == -1){
    return width-1;
  }
  if(y == width){
      return 0;
  }
  return y;
}
}
