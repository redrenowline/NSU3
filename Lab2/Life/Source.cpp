#include <QApplication>

#include "EvoGUI.h"

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  std::shared_ptr<EvoGUI> gui = std::make_shared<EvoGUI>();
  return app.exec();
}

