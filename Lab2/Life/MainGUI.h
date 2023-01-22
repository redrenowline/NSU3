#ifndef MAINGUI_H
#define MAINGUI_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>
#include <QIntValidator>
#include <QLabel>
#include <QWindow>
#include <QSize>

#include <iostream>

#include "Cells.h"

class MainGUI : public QWidget
{
  Q_OBJECT

public:

  MainGUI();

  void drawCell(int x, int y, cType typ);

  int getTiksCount();

private:

  const char* TIKSCOUNT_CHAR = "Количество шагов:";
  const char* NEXTTIKBTN_CHAR = "Следующий шаг";
  const char* NEXTTIKSBTN_CHAR = "Следующие несколько шагов";

  const QSize SCREEN_SIZE = QSize(800,600);

  const QRect NAME_RECT = QRect(0,0,100,20);
  const QRect NUMLABEL_RECT = QRect(0,50,100,20);
  const QRect ENTERITR_RECT = QRect(0,50,100,20);
  const QRect SCENE_RECT = QRect(100,0,700,600);

  std::shared_ptr<QLabel> name;
  std::shared_ptr<QLabel> numlabel;
  std::shared_ptr<QLineEdit> enterItarations;

  std::shared_ptr<QPushButton> nextTikBtn;

  std::shared_ptr<QGraphicsView> viewScene;
  std::shared_ptr<QGraphicsScene> scene;

  std::shared_ptr<QVBoxLayout> leftLayout;
  std::shared_ptr<QHBoxLayout> mainLayout;

  void identLeftLayout();
  void identMainLayout();

};

#endif // MAINGUI_H
