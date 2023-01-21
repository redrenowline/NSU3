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

  void identMainGUI();

  const char* DIALOGFILEOPEN = "Укажите файл с вселенной";
  const char* DIALOGFILETYPE = "Все файлы (*.*)";

private slots:
  void addExitStrategy();
  void addUploadStrategy();
  void addSaveStrategy();
  void addNextTikStrategy();
  void addNextTiksStrategy();
};
