// EvoTest.cpp: super gui class which connected with Core
//
#include "Core.h"

Core::Core() {
  fd = std::make_shared<Field>();

}

void Core::execStrategy(std::shared_ptr<Strategy> cmd){
  std::cout << "New strategy has been get\n";
  try{
    cmd->exec();
  }catch(std::exception e){
    std::cerr << e.what();
  }
}

std::shared_ptr<Field> Core::getField(){
  return this->fd;
}

Core::~Core() {

}
