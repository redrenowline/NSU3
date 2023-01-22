#include "MenuGUI.h"

MenuGUI::MenuGUI() : QWidget(){
  identButtons();
  bottomLayout = std::make_shared<QVBoxLayout>();

  bottomLayout->addWidget(file_btn.get());
  bottomLayout->addWidget(example_btn.get());
  bottomLayout->addWidget(offline_btn.get());
  bottomLayout->addWidget(exit_btn.get());
  setLayout(bottomLayout.get());
}

MenuGUI::~MenuGUI(){

}

void MenuGUI::identButtons(){
  exit_btn = std::make_shared<QPushButton>(EXIT_CHAR);
  example_btn = std::make_shared<QPushButton>(EXAMPLEUNIVERSE_CHAR);
  file_btn = std::make_shared<QPushButton>(FILEUNIVERSE_CHAR);
  offline_btn = std::make_shared<QPushButton>(OFFLINE_CHAR);
}
//std::string s = QFileDialog::getOpenFileName(0, QObject::tr(DIALOGFILEOPEN), QDir::homePath(), QObject::tr(DIALOGFILETYPE)).toStdString();

std::shared_ptr<QPushButton> MenuGUI::GetFileBtn(){
  return file_btn;
}

std::shared_ptr<QPushButton> MenuGUI::GetExampleBtn(){
  return example_btn;
}

std::shared_ptr<QPushButton> MenuGUI::GetOfflineBtn(){
  return offline_btn;
}

std::shared_ptr<QPushButton> MenuGUI::GetExitBtn(){
  return exit_btn;
}


