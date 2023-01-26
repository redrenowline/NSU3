#include "ExamplesGUI.h"


namespace Life{
ExamplesGUI::ExamplesGUI() : QWidget(){
  bottomLayout = std::make_shared<QVBoxLayout>();
  uploadExampleBtn = std::make_shared<QPushButton>(UPLOAD_EXAMPLES_BTN_CHAR);
  examplesBox = std::make_shared<QComboBox>();

  loadExamples();
  identComboBox();

  bottomLayout->addWidget(examplesBox.get());
  bottomLayout->addWidget(uploadExampleBtn.get());
  setLayout(bottomLayout.get());
}

ExamplesGUI::~ExamplesGUI(){

}

void ExamplesGUI::loadExamples(){
  std::string m_path = QDir::currentPath().toStdString();
  m_path += DELETER;
  int itr = 0;
  foreach(QFileInfo item, QDir(QDir::currentPath()).entryInfoList(QStringList(FILTER), QDir::Files)){
    examples.push_back(Example("Example #" + std::to_string(itr), item.absoluteFilePath().toStdString()));
    itr++;
  }
}

void ExamplesGUI::identComboBox(){
  for(int i = 0; i < examples.size(); i++){
    examplesBox->addItem(QString::fromStdString(examples[i].getName()));
  }
}

std::string ExamplesGUI::GetExamplePath(){
  std::string path;
  for(int i = 0; i < examples.size(); i++){
      if(examples[i].getName() == examplesBox->currentText().toStdString())
        return examples[i].getPath();
    }
  throw std::exception();
  return "";
}

std::shared_ptr<QPushButton> ExamplesGUI::getUploadExamplesBtn(){
  return uploadExampleBtn;
}

Example::Example(std::string n, std::string p) : path(p), name(n){}

Example::~Example(){

}

std::string Example::getName(){
  return name;
}
std::string Example::getPath(){
  return path;
}
}
