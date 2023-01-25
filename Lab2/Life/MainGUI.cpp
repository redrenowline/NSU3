#include "MainGUI.h"

MainGUI::MainGUI(std::string n) : QWidget(), nam(n)
{
  this->setGeometry(0,0,SCREEN_SIZE.width(), SCREEN_SIZE.height());
  this->setFixedSize(SCREEN_SIZE);
  identMainLayout();
  identLeftLayout();

}

void MainGUI::identLeftLayout(){
  name = std::make_shared<QLabel>(QString::fromStdString(nam), this);
  enterItarations = std::make_shared<QLineEdit>(this);
  nextTikBtn = std::make_shared<QPushButton>(this);
  nextTiksBtn = std::make_shared<QPushButton>(this);
  startTimerBtn = std::make_shared<QPushButton>(this);
  stopTimerBtn = std::make_shared<QPushButton>(this);
  speedUpBtn = std::make_shared<QPushButton>(this);
  slowDownBtn = std::make_shared<QPushButton>(this);
  saveBtn = std::make_shared<QPushButton>(this);

  enterItarations->setValidator(new QIntValidator(0,100,this));
  nextTikBtn->setText(NEXTTIKBTN_CHAR);
  nextTiksBtn->setText(NEXTTIKSBTN_CHAR);
  startTimerBtn->setText(STARTTIMER_CHAR);
  stopTimerBtn->setText(STOPTIMER_CHAR);
  speedUpBtn->setText(SPEEDUP_CHAR);
  slowDownBtn->setText(SLOWDOWN_CHAR);
  saveBtn->setText(SAVE_CHAR);

  name->setGeometry(NAME_RECT);
  enterItarations->setGeometry(ENTERITR_RECT);
  nextTikBtn->setGeometry(NEXTIKBTN_RECT);
  nextTiksBtn->setGeometry(NEXTIKSBTN_RECT);
  startTimerBtn->setGeometry(STARTTIMER_RECT);
  stopTimerBtn->setGeometry(STOPTIMER_RECT);
  speedUpBtn->setGeometry(SPEEDUP_RECT);
  slowDownBtn->setGeometry(SLOWDOWN_RECT);
  saveBtn->setGeometry(SAVE_RECT);
}

void MainGUI::identMainLayout(){
  viewScene = std::make_shared<QGraphicsView>(this);
  scene = std::make_shared<QGraphicsScene>();

  viewScene->setScene(scene.get());
  viewScene->setGeometry(SCENE_RECT);
  scene->setSceneRect(0,0,viewScene->width(), viewScene->height());
}

void MainGUI::drawCell(int x, int y){
  scene->addRect(QRect(x*10,y*10, 10, 10), QPen(Qt::black), QBrush(Qt::black));
}

void MainGUI::clearField(){
  scene->clear();
}

int MainGUI::getTiksCount(){
    return enterItarations->text().toInt();
}

std::shared_ptr<QPushButton> MainGUI::getNextTikBtn(){
  return nextTikBtn;
}

std::shared_ptr<QPushButton> MainGUI::getNextTiksBtn(){
  return nextTiksBtn;
}

std::shared_ptr<QPushButton> MainGUI::getStartTimerBtn(){
  return startTimerBtn;
}

std::shared_ptr<QPushButton> MainGUI::getStopTimerBtn(){
  return stopTimerBtn;
}

std::shared_ptr<QPushButton> MainGUI::getSpeedUpBtn(){
  return speedUpBtn;
}
std::shared_ptr<QPushButton> MainGUI::getSlowDownBtn(){
  return slowDownBtn;
}

std::shared_ptr<QPushButton> MainGUI::getSaveBtn(){
  return saveBtn;
}


