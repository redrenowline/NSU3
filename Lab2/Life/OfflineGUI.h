#ifndef OFFLINEGUI_H
#define OFFLINEGUI_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QFileDialog>
#include <QLineEdit>
#include <QLabel>
#include <QWindow>
#include <QDir>

#include <iostream>

namespace Life{

class OfflineGUI : public QWidget{
  Q_OBJECT


public:
  OfflineGUI();
  ~OfflineGUI();

  std::shared_ptr<QPushButton> getUploadBtn();

  int getTiksCount();
private:

  std::shared_ptr<QPushButton> uploadBtn;
  std::shared_ptr<QLineEdit> lineForData;
  std::shared_ptr<QLabel> label;

  std::shared_ptr<QBoxLayout> bottomLayout;
};

}

#endif // OFFLINEGUI_H
