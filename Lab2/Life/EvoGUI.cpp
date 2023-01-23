#include "EvoGUI.h"

EvoGUI::EvoGUI(){
  core = std::make_unique<Core>();

  identMenuGUI();
}

void EvoGUI::identMenuGUI(){
  menuGUI = std::make_unique<MenuGUI>();
  menuGUI->show();
  connect(menuGUI->GetExitBtn().get(), SIGNAL(released()), this, SLOT(addExitStrategy()));
  connect(menuGUI->GetFileBtn().get(), SIGNAL(released()), this, SLOT(addUploadStrategy()));
  connect(menuGUI->GetExampleBtn().get(), SIGNAL(released()), this, SLOT(UploadExamples()));
}

void EvoGUI::closeMenuGUI(){
  menuGUI->close();
}

void EvoGUI::identMainGUI(){
  mainGUI = std::make_unique<MainGUI>();
  mainGUI->show();
  connect(mainGUI->getNextTikBtn().get(), SIGNAL(released()), this, SLOT(addNextTikStrategy()));
  connect(mainGUI->getNextTiksBtn().get(), SIGNAL(released()), this, SLOT(addNextTiksStrategy()));
}

void EvoGUI::closeMainGUI(){
  mainGUI->close();
}

void EvoGUI::addExitStrategy(){
  core->execStrategy(std::make_shared<ExitStrategy>());
}

void EvoGUI::addUploadStrategy(){
  std::string s = QFileDialog::getOpenFileName(0, QObject::tr(DIALOGFILEOPEN), QDir::homePath(), QObject::tr(DIALOGFILETYPE)).toStdString();
  try{
    core->execStrategy(std::make_shared<UploadFieldStrategy>(core->getField(), s));
  }catch(std::exception e){
    std::cerr << e.what() << "\n";
    return;
  }
  std::cout << "Field has been uploaded from file " << s << "\n";
  closeMenuGUI();
  identMainGUI();
}

void EvoGUI::addSaveStrategy(){

}

void EvoGUI::addNextTikStrategy(){
  try{
    core->execStrategy(std::make_shared<NextTikStrategy>(core->getField()));
  }catch(std::exception e){
    std::cerr << e.what() << "\n";
  }
}

void EvoGUI::addNextTiksStrategy(){
  try{
    core->execStrategy(std::make_shared<NextTiksStrategy>(core->getField(), mainGUI->getTiksCount()));
  }catch(std::exception e){
    std::cerr << e.what() << "\n";
  }
}

void EvoGUI::UploadExamples(){
  std::string path;

}

EvoGUI::~EvoGUI(){

}
