#ifndef EXAMPLESGUI_H
#define EXAMPLESGUI_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>
#include <QIntValidator>
#include <QComboBox>
#include <QLabel>
#include <QWindow>
#include <QSize>
#include <QDir>

#include <iostream>

class Example{
public:
  Example(std::string, std::string);
  ~Example();

  std::string getPath();
  std::string getName();
private:
  std::string path;
  std::string name;
};

class ExamplesGUI : public QWidget{
  Q_OBJECT

public:
  ExamplesGUI();
  ~ExamplesGUI();

  std::shared_ptr<QPushButton> getUploadExamplesBtn();

  std::string GetExamplePath();

private:

  const char* UPLOAD_EXAMPLES_BTN_CHAR = "Загрузить пример";
  const char* DELETER = "/";
  const char* FILTER = "*life";

  std::shared_ptr<QPushButton> uploadExampleBtn;
  std::shared_ptr<QBoxLayout> bottomLayout;
  std::shared_ptr<QComboBox> examplesBox;

  std::vector<Example> examples;

  void identComboBox();
  void loadExamples();
};

#endif // EXAMPLESGUI_H
