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

  MainGUI(std::string n);

  void drawCell(int x, int y);
  void clearField();

  int getTiksCount();

  std::shared_ptr<QPushButton> getNextTikBtn();
  std::shared_ptr<QPushButton> getNextTiksBtn();
  std::shared_ptr<QPushButton> getStartTimerBtn();
  std::shared_ptr<QPushButton> getStopTimerBtn();

private:

  const char* TIKSCOUNT_CHAR = "Количество шагов:";
  const char* NEXTTIKBTN_CHAR = "Шаг";
  const char* NEXTTIKSBTN_CHAR = "N шагов";
  const char* STARTTIMER_CHAR = "Вкл. таймер";
  const char* STOPTIMER_CHAR = "Выклю таймер";

  const QSize SCREEN_SIZE = QSize(800,600);

  const QRect NAME_RECT = QRect(10,0,100,20);
  const QRect NUMLABEL_RECT = QRect(5,50,90,20);
  const QRect ENTERITR_RECT = QRect(5,75,90,20);
  const QRect NEXTIKBTN_RECT = QRect(5,95,90,20);
  const QRect NEXTIKSBTN_RECT = QRect(5,115,90,20);
  const QRect STARTTIMER_RECT = QRect(5, 135, 90, 20);
  const QRect STOPTIMER_RECT = QRect(5, 155, 90, 20);
  const QRect SCENE_RECT = QRect(100,0,700,600);

  std::string nam;

  std::shared_ptr<QLabel> name;
  std::shared_ptr<QLabel> numlabel;
  std::shared_ptr<QLineEdit> enterItarations;

  std::shared_ptr<QPushButton> nextTikBtn;
  std::shared_ptr<QPushButton> nextTiksBtn;
  std::shared_ptr<QPushButton> startTimerBtn;
  std::shared_ptr<QPushButton> stopTimerBtn;

  std::shared_ptr<QGraphicsView> viewScene;
  std::shared_ptr<QGraphicsScene> scene;

  std::shared_ptr<QVBoxLayout> leftLayout;
  std::shared_ptr<QHBoxLayout> mainLayout;

  void identLeftLayout();
  void identMainLayout();

};

#endif // MAINGUI_H
