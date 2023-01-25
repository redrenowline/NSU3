#include "EvoGUI.h"

EvoGUI::EvoGUI(){
  core = std::make_unique<Core>();

  identMenuGUI();
}

void EvoGUI::identMenuGUI(){
  menuGUI = std::make_unique<MenuGUI>();
  menuGUI->show();
  connect(menuGUI->GetExitBtn().get(), SIGNAL(released()), this, SLOT(addExitStrategy()));
  connect(menuGUI->GetFileBtn().get(), SIGNAL(released()), this, SLOT(UploadFromFile()));
  connect(menuGUI->GetExampleBtn().get(), SIGNAL(released()), this, SLOT(showUploadExamples()));
}

void EvoGUI::closeMenuGUI(){
  menuGUI->close();
}

void EvoGUI::identMainGUI(){
  mainGUI = std::make_unique<MainGUI>(core->getField()->title);
  mainGUI->show();
  connect(mainGUI->getNextTikBtn().get(), SIGNAL(released()), this, SLOT(addNextTikStrategy()));
  connect(mainGUI->getNextTiksBtn().get(), SIGNAL(released()), this, SLOT(addNextTiksStrategy()));
  connect(mainGUI->getStartTimerBtn().get(), SIGNAL(released()), this, SLOT(startTimer()));
  connect(mainGUI->getStopTimerBtn().get(), SIGNAL(released()), this, SLOT(stopTimer()));
  connect(mainGUI->getSpeedUpBtn().get(), SIGNAL(released()), this, SLOT(removeTimeToTimer()));
  connect(mainGUI->getSlowDownBtn().get(), SIGNAL(released()), this, SLOT(addTimeToTimer()));
  connect(mainGUI->getSaveBtn().get(), SIGNAL(released()), this, SLOT(SaveField()));
}

void EvoGUI::closeMainGUI(){
  mainGUI->close();
}

void EvoGUI::identExamplesGUI(){
  examplesGUI = std::make_unique<ExamplesGUI>();
  examplesGUI->show();
  connect(examplesGUI->getUploadExamplesBtn().get(), SIGNAL(released()), this, SLOT(UploadExamples()));
}
void EvoGUI::closeExamplesGUI(){
  examplesGUI->close();
}

void EvoGUI::reDrawFieled(){
  std::string mask = core->getField()->transparentField();
  int height = core->getField()->getHeight();
  int width = core->getField()->getWidth();
  mainGUI->clearField();
  for(int i = 0; i < width; i++){
      for(int j = 0; j < height; j++){
          if(mask[i * height + j] == core->getField()->ONE)
            mainGUI->drawCell(i,j);
        }
    }
  mainGUI->drawCell(50,50);
}

void EvoGUI::startTimer(){
  timer = std::make_unique<QTimer>();
  connect(timer.get(), SIGNAL(timeout()), this, SLOT(addNextTikStrategy()));
  mainGUI->getNextTikBtn()->setEnabled(false);
  mainGUI->getNextTiksBtn()->setEnabled(false);
  timer->start(timerDist);
}

void EvoGUI::stopTimer(){
  timer->stop();
  mainGUI->getNextTikBtn()->setEnabled(true);
  mainGUI->getNextTiksBtn()->setEnabled(true);
}

void EvoGUI::addTimeToTimer(){
  timerDist += dTimer;
  startTimer();
}
void EvoGUI::removeTimeToTimer(){
  if(timerDist <= dTimer){
      timerDist = 100;
      startTimer();
  }
  timerDist -= dTimer;
  startTimer();
}

void EvoGUI::addExitStrategy(){
  core->execStrategy(std::make_shared<ExitStrategy>());
}

void EvoGUI::addUploadStrategy(std::string path){
  try{
    core->execStrategy(std::make_shared<UploadFieldStrategy>(core->getField(), path));
  }catch(std::exception e){
    std::cerr << e.what() << "\n";
    return;
  }
  closeMenuGUI();
  identMainGUI();
  reDrawFieled();
}

void EvoGUI::addSaveStrategy(std::string path){
  try{
    core->execStrategy(std::make_shared<SaveFieldStrategy>(core->getField(), path));
  }catch(std::exception e){
    std::cerr << e.what() << "\n";
    return;
  }
}

void EvoGUI::addNextTikStrategy(){
  try{
    core->execStrategy(std::make_shared<NextTikStrategy>(core->getField()));
  }catch(std::exception e){
    std::cerr << e.what() << "\n";
  }
  reDrawFieled();
}

void EvoGUI::addNextTiksStrategy(){
  try{
    core->execStrategy(std::make_shared<NextTiksStrategy>(core->getField(), mainGUI->getTiksCount()));
  }catch(std::exception e){
    std::cerr << e.what() << "\n";
  }
  reDrawFieled();
}

void EvoGUI::showUploadExamples(){
  identExamplesGUI();
  closeMenuGUI();
}

void EvoGUI::UploadFromFile(){
  std::string s = QFileDialog::getOpenFileName(0, QObject::tr(DIALOGFILEOPEN), QDir::homePath(), QObject::tr(DIALOGFILETYPE)).toStdString();
  addUploadStrategy(s);
}

void EvoGUI::UploadExamples(){
  std::string s = examplesGUI->GetExamplePath();
  addUploadStrategy(s);
  closeExamplesGUI();
}

void EvoGUI::SaveField(){
  std::string s = QFileDialog::getSaveFileName(0,QObject::tr(DIALOGSAVE), QDir::homePath(), QObject::tr(DIALOGFILETYPE)).toStdString();
  addSaveStrategy(s);
}

EvoGUI::~EvoGUI(){

}
