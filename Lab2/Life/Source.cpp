#include <QApplication>

#include "EvoGUI.h"
#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
  if(argc == 2){
      if(argv[1] == "-t"){
          ::testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
        }else{
          QApplication app(argc, argv);
          std::shared_ptr<Life::EvoGUI> gui = std::make_shared<Life::EvoGUI>();
          return app.exec();
        }
    }
  QApplication app(argc, argv);
  std::shared_ptr<Life::EvoGUI> gui = std::make_shared<Life::EvoGUI>();
  return app.exec();
}

