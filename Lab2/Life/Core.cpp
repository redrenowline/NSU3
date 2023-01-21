// EvoTest.cpp: super gui class which connected with Core
//
#include "Core.h"

Core::Core() {
  fd = std::make_shared<Field>();
  gui = std::make_shared<EvoGUI>();
  connect(gui.get(), SIGNAL(addStrategy(std::shared_ptr<Strategy>)), this, SLOT(executeStrategy(std::shared_ptr<Strategy>)));
}

void Core::executeStrategy(std::shared_ptr<Strategy> cmd){
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
