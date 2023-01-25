#include "TestCore.h"

TestCore::TestCore(){

}

Field TestCore::generateField(){
  return Field();
}

Field TestCore::generateNullField(){
  Specification sp = generateBaseSpecification();
  Field fd(10,10,sp);
  for(int i = 0;i < fd.getHeight(); i++){
    for(int j = 0; j < fd.getWidth(); j++){
        fd.mass[i][j] = cType::DEAD;
      }
    }
  printField(fd);
  fd.processing();
  printField(fd);
  return fd;
}

Field TestCore::generateTwiceField(){
  Specification sp = generateBaseSpecification();
  Field fd(10,10,sp);
  for(int i = 0;i < fd.getHeight(); i++){
    for(int j = 0; j < fd.getWidth(); j++){
        if((i + j) % 2 == 0) fd.mass[i][j] = cType::DEAD;
        else fd.mass[i][j] = cType::ALIVE;
      }
    }
  printField(fd);
  fd.processing();
  printField(fd);
  return fd;
}

void TestCore::printField(Field fd){
  for(int i = 0;i < fd.getHeight(); i++){
    for(int j = 0; j < fd.getWidth(); j++){
        std::cout << int(fd.mass[i][j]) << " ";
      }
    std::cout << "\n";
    }
}

Field TestCore::detranspField(std::string strl, int h, int w){
  Field fd(h,w , generateBaseSpecification());
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(strl[i*w + j] == '0')
        fd.mass[i][j] = cType::DEAD;
      else
        fd.mass[i][j] = cType::ALIVE;
      }
    }
  return fd;
}

bool TestCore::isThatCellAlive(Field &fd, int x, int y){
  return fd.mass[x][y] == cType::ALIVE ? true : false;
}

void TestCore::setCellAlive(Field &fd, int x, int y){
  fd.mass[x][y] = cType::ALIVE;
}

Specification TestCore::generateBaseSpecification(){
  Specification sp;
  std::vector< unsigned char> sr = {'2', '3'},cr = {'3'};
  sp.setcrReason(sr);
  sp.setsrReason(cr);
  return sp;
}
