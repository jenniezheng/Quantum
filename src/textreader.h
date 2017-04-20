#ifndef TEXTREADER_H
#define TEXTREADER_H

#include "QFile"
#include "QIODevice"
#include "QString"
#include "QTextStream"
#include <string>
#include <iostream>
using namespace std;
void readFile(){
    cout<<"HI"<<endl;
    QFile inputFile("text");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       cout<<"OPENED"<<endl;
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          string utf8_text = line.toUtf8().constData();
          cout << utf8_text << endl;
       }
       inputFile.close();
    }
}


#endif // TEXTREADER_H
