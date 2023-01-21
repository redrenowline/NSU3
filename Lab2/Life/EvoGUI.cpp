#include "EvoGUI.h"

EvoGUI::EvoGUI(){
  menuGUI = std::make_unique<MenuGUI>();
  menuGUI->show();
  connect(menuGUI->GetExitBtn().get(), SIGNAL(released()), this, SLOT(addExitStrategy()));
}

void EvoGUI::identMainGUI(){
  mainGUI = std::make_unique<MainGUI>();
  mainGUI->show();
}

void EvoGUI::addExitStrategy(){
  emit addStrategy(std::make_shared<ExitStrategy>());
}

void EvoGUI::addUploadStrategy(){
  std::string s = QFileDialog::getOpenFileName(0, QObject::tr(DIALOGFILEOPEN), QDir::homePath(), QObject::tr(DIALOGFILETYPE)).toStdString();
  emit addStrategy(std::make_shared<UploadFieldStrategy>(,s));
}

EvoGUI::~EvoGUI(){

}
