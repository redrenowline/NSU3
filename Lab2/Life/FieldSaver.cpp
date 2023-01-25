#include "FieldSaver.h"

FieldSaver::FieldSaver(){

}

void FieldSaver::save(std::string path, Field &fd){
  std::ofstream fl;
  fl.open(path);
  fl << INDICATOR << "\n";
  fl << NAMEINDICATOR << " " << fd.title << "\n";
  fl << RULESINDICATOR << " " << BIRTHINDICATOR;
  for(int i = 0; i < fd.sp.getcrSize(); i++){
    fl << fd.sp.getcrReason()[i];
  }
  fl << SURVIVEINDICATOR;
  for(int i = 0; i < fd.sp.getsrSize(); i++){
      fl << fd.sp.getsrReason()[i];
  }
  fl << "\n";
  for(int i = 0; i < fd.getHeight(); i++){
      for(int j = 0; j < fd.getWidth(); j++){
        if(fd.mass[i][j] == cType::ALIVE) fl << i << " " << j << "\n";
      }
  }
  fl.close();
  return;
}
