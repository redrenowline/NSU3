#include "MainGUI.h"

MainGUI::MainGUI()
{
  this->setGeometry(0,0,SCREEN_SIZE.width(), SCREEN_SIZE.height());
  this->setFixedSize(SCREEN_SIZE);
  identMainLayout();
  identLeftLayout();

}

void MainGUI::identLeftLayout(){
  name = std::make_shared<QLabel>("Hello", this);
  numlabel = std::make_shared<QLabel>("12", this);
  enterItarations = std::make_shared<QLineEdit>(this);
  nextTikBtn = std::make_shared<QPushButton>();

  enterItarations->setValidator(new QIntValidator(0,100,this));

  name->setGeometry(NAME_RECT);
  numlabel->setGeometry(NUMLABEL_RECT);
  enterItarations->setGeometry(ENTERITR_RECT);
  std::cout << "Everything has been identificated\n";
}

void MainGUI::identMainLayout(){
  viewScene = std::make_shared<QGraphicsView>(this);
  scene = std::make_shared<QGraphicsScene>();

  viewScene->setScene(scene.get());
  viewScene->setGeometry(SCENE_RECT);
  scene->setSceneRect(0,0,viewScene->width(), viewScene->height());
}

void MainGUI::drawCell(int x, int y, cType typ){
  scene->addLine(x * 10, y * 10, (x + 1) * 10,  (y + 1) * 10,QPen(typ == cType::ALIVE ? Qt::black : Qt::white));
}
