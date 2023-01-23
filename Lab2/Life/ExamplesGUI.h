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

#include <iostream>

class ExamplesGUI : public QWidget{
  Q_OBJECT

public:
  ExamplesGUI();
  ~ExamplesGUI();

  std::shared_ptr<QPushButton> getUploadExamplesBtn();

  std::string GetExamplePath();

private:

  const char* UPLOAD_EXAMPLES_BTN_CHAR = "Загрузить пример";

  std::shared_ptr<QPushButton> uploadExampleBtn;

  std::shared_ptr<QBoxLayout> bottomLayout;

  std::shared_ptr<QComboBox> examplesBox;
};

#endif // EXAMPLESGUI_H
