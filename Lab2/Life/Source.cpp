#include <QApplication>

#include "EvoGUI.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  EvoGUI* gui = new EvoGUI();
  return app.exec();
}
