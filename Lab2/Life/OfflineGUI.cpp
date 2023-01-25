#include "OfflineGUI.h"


OfflineGUI::OfflineGUI(){
  bottomLayout = std::make_shared<QVBoxLayout>();
  lineForData = std::make_shared<QLineEdit>();
  uploadBtn = std::make_shared<QPushButton>();

  bottomLayout->addWidget(lineForData.get());
  bottomLayout->addWidget(uploadBtn.get());
  setLayout(bottomLayout.get());
}

OfflineGUI::~OfflineGUI(){

}

std::shared_ptr<QPushButton> OfflineGUI::getUploadBtn(){
  return uploadBtn;
}

int OfflineGUI::getTiksCount(){
  return lineForData->text().toInt();
}
