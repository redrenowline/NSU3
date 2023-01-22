#pragma once
#include <QWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGuiApplication>

#include "MenuGUI.h"
#include "MainGUI.h"
#include "Strategy.h"
#include "Core.h"

class EvoGUI : public QWidget{
  Q_OBJECT
public:
  EvoGUI();
  ~EvoGUI();

private:
  std::unique_ptr<MenuGUI> menuGUI;
  std::unique_ptr<MainGUI> mainGUI;

  std::unique_ptr<Core> core;

  void identMainGUI(); // identification of Main Layout (contains scene)
  void closeMainGUI(); // closing of Main Layout

  void identMenuGUI(); // identification of Menu Layout (contains menu), start point for programm
  void closeMenuGUI(); // closing of Menu Layout

  const char* DIALOGFILEOPEN = "Укажите файл с вселенной";
  const char* DIALOGFILETYPE = "Все файлы (*.*)";

private slots:
  void addExitStrategy(); // creating ExitStrategy and try to execute that in the Core, the result is closing programm
  void addUploadStrategy(); // creating UploadStrategy and try to execute that in the Core, the result is uploading field in the Core
  void addSaveStrategy();
  void addNextTikStrategy();
  void addNextTiksStrategy();

  void UploadExamples();
};
