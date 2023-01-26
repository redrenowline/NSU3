#ifndef MENUGUI_H
#define MENUGUI_H
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidget>
#include <QFileDialog>
#include <QLabel>
#include <QWindow>
#include <QDir>

#include <iostream>

namespace Life{

class MenuGUI : public QWidget
{

  Q_OBJECT
public:
  MenuGUI();
  ~MenuGUI();
  std::shared_ptr<QPushButton> GetFileBtn();
  std::shared_ptr<QPushButton> GetExampleBtn();
  std::shared_ptr<QPushButton> GetOfflineBtn();
  std::shared_ptr<QPushButton> GetExitBtn();


private:

  const char* FILEUNIVERSE_CHAR = "Загрузить вселенную из файла";
  const char* EXAMPLEUNIVERSE_CHAR = "Загрузить пример";
  const char* OFFLINE_CHAR = "Оффлайн режим";
  const char* EXIT_CHAR = "Выход";

  const char* DIALOGFILEOPEN = "Укажите файл с вселенной";
  const char* DIALOGFILETYPE = "Все файлы (*.*)";

  std::shared_ptr<QVBoxLayout> bottomLayout;
  std::shared_ptr<QListWidget> view;

  std::shared_ptr<QLabel> lbl;
  std::shared_ptr<QPushButton> file_btn;
  std::shared_ptr<QPushButton> example_btn;
  std::shared_ptr<QPushButton> offline_btn;
  std::shared_ptr<QPushButton> exit_btn;



  void identButtons();
};
}

#endif // MENUGUI_H
