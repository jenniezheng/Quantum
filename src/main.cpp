#include <iostream>
#include "game.h"
#include <QApplication>
#include "textreader.h"


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
