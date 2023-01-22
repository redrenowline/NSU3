// EvoTest.cpp: super gui class which connected with Core
//
#include "Core.h"

Core::Core() {
  fd = std::make_shared<Field>();

}

void Core::execStrategy(std::shared_ptr<Strategy> cmd){
  std::cout << "New strategy has been get\n";
  cmd->exec();
}

std::shared_ptr<Field> Core::getField(){
  return this->fd;
}

Core::~Core() {

}
