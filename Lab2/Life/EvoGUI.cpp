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
}

void EvoGUI::closeMainGUI(){

}

void EvoGUI::addExitStrategy(){
  core->execStrategy(std::make_shared<ExitStrategy>());
}

void EvoGUI::addUploadStrategy(){
  std::string s = QFileDialog::getOpenFileName(0, QObject::tr(DIALOGFILEOPEN), QDir::homePath(), QObject::tr(DIALOGFILETYPE)).toStdString();
  try{
    core->execStrategy(std::make_shared<UploadFieldStrategy>(core->getField(), s));
  }catch(std::exception e){
    return;
  }
  std::cerr << "Field has been uploaded from file " << s << "\n";
  identMainGUI();
  closeMenuGUI();
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

}

void EvoGUI::UploadExamples(){

}

EvoGUI::~EvoGUI(){

}
