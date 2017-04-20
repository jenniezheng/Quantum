#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QLabel>
#include <vector>
#include "arc.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
private slots:
    void buttonClicked1(){processChoice(1);}
    void buttonClicked2(){processChoice(2);}
    void buttonClicked3(){processChoice(3);}
private:
    void processChoice(int num);
    void changeNumButtons(int num);
    unsigned m_currentNumButtons;
    Ui::MainWindow *ui;
    vector<vector<QPushButton*>> m_buttons;
    QLabel* m_label;
    Arc* m_arc;
    const int WINDOW_WIDTH=900;
    const int WINDOW_HEIGHT=600;
    const int BUTTON_POSITION_Y=500;
    const int BUTTON_PADDING_X=50;
    const int BUTTON_HEIGHT=50;
    const unsigned MAX_BUTTONS=3;
};

#endif // MAINWINDOW_H
