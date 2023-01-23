#include "ExamplesGUI.h"

ExamplesGUI::ExamplesGUI(){
  bottomLayout = std::make_shared<QVBoxLayout>();
  uploadExampleBtn = std::make_shared<QPushButton>();
  examplesBox = std::make_shared<QComboBox>();

  bottomLayout->addWidget(examplesBox.get());
  bottomLayout->addWidget(uploadExampleBtn.get());
  setLayout(bottomLayout.get());
}

ExamplesGUI::~ExamplesGUI(){

}

std::string ExamplesGUI::GetExamplePath(){
  return "";
}

std::shared_ptr<QPushButton> ExamplesGUI::getUploadExamplesBtn(){
  return uploadExampleBtn;
}
