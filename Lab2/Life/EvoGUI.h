#pragma once
#include <QWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTimer>
#include <QGraphicsScene>
#include <QGuiApplication>

#include "MenuGUI.h"
#include "MainGUI.h"
#include "ExamplesGUI.h"
#include "Strategy.h"
#include "Core.h"

class EvoGUI : public QWidget{
  Q_OBJECT
public:
  EvoGUI();
  ~EvoGUI();

private:
  unsigned int timerDist = 1000;
  const int dTimer = 200;

  std::unique_ptr<MenuGUI> menuGUI;
  std::unique_ptr<MainGUI> mainGUI;
  std::unique_ptr<ExamplesGUI> examplesGUI;

  std::unique_ptr<Core> core;

  std::unique_ptr<QTimer> timer;

  void identMainGUI(); // identification of Main Layout (contains scene)
  void closeMainGUI(); // closing of Main Layout

  void identMenuGUI(); // identification of Menu Layout (contains menu), start point for programm
  void closeMenuGUI(); // closing of Menu Layout

  void identExamplesGUI(); // identification of Examples GUI (contains examples)
  void closeExamplesGUI(); // closing of Examples GUI

  void reDrawFieled();



  const char* DIALOGFILEOPEN = "Укажите файл с вселенной";
  const char* DIALOGSAVE = "Сохранить файл в ";
  const char* DIALOGFILETYPE = "Life файлы (*.life)";

private slots:
  void addExitStrategy(); // creating ExitStrategy and try to execute that in the Core, the result is closing programm
  void addUploadStrategy(std::string path); // creating UploadStrategy and try to execute that in the Core, the result is uploading field in the Core
  void addSaveStrategy(std::string path);
  void addNextTikStrategy();
  void addNextTiksStrategy();

  void showUploadExamples();
  void UploadExamples();
  void UploadFromFile();
  void SaveField();

  void startTimer();
  void stopTimer();
  void addTimeToTimer();
  void removeTimeToTimer();
};
