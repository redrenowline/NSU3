#include "EvoGUI.h"

EvoGUI::EvoGUI(){
  core = std::make_unique<Core>();

  menuGUI = std::make_unique<MenuGUI>();
  menuGUI->show();
  connect(menuGUI->GetExitBtn().get(), SIGNAL(released()), this, SLOT(addExitStrategy()));
}

void EvoGUI::identMainGUI(){
  mainGUI = std::make_unique<MainGUI>();
  mainGUI->show();
}

void EvoGUI::addExitStrategy(){
  core->execStrategy(std::make_shared<ExitStrategy>());
}

void EvoGUI::addUploadStrategy(){
  std::string s = QFileDialog::getOpenFileName(0, QObject::tr(DIALOGFILEOPEN), QDir::homePath(), QObject::tr(DIALOGFILETYPE)).toStdString();

}

void EvoGUI::addSaveStrategy(){

}

void EvoGUI::addNextTikStrategy(){

}

void EvoGUI::addNextTiksStrategy(){

}

EvoGUI::~EvoGUI(){

}
