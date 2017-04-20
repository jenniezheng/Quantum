#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("The Messenger");
    this->setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    this->setStyleSheet("background-color: black;");

    for(unsigned i=0; i<MAX_BUTTONS; i++){
        m_buttons.push_back(vector<QPushButton*>());
        int buttonWidth=(WINDOW_WIDTH-(i+2)*BUTTON_PADDING_X)/(i+1);
        for(unsigned j=0; j<=i; j++){
            QPushButton* button=new QPushButton(this);
            button->setVisible(false);
            button->setGeometry(BUTTON_PADDING_X*(1+j)+buttonWidth*j,BUTTON_POSITION_Y,buttonWidth, BUTTON_HEIGHT);
            button->setStyleSheet("background-color: blue");
            switch (j+1){
            case 1:connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked1()));break;
            case 2:connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked2()));break;
            case 3:connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked3()));break;
            }
            m_buttons[i].push_back(button);
        }
    }
    m_label= new QLabel("LabelHere!", this);
    m_label->setStyleSheet("QLabel { color : cyan; }");
    QFont font = m_label->font();
    font.setPointSize(14);
    m_label->setFont(font);
    m_label->setGeometry(50,50,800, 400);
    m_label->setWordWrap(true);
    m_currentNumButtons=1;

    m_arc=new Arc(1);
    QString strLabel = QString::fromStdString(m_arc->getLabel());
    m_label->setText(strLabel);
    changeNumButtons(m_arc->getNumOptions());
    for(unsigned i=0; i<m_currentNumButtons; i++){
        QString strOptionLabel = QString::fromStdString(m_arc->getOptionLabel(i));
        m_buttons[m_currentNumButtons-1][i]->setText(strOptionLabel);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_label;
}

void MainWindow::processChoice(int num){
    m_arc->choose(num-1);//to zero based indexing
    QString strLabel = QString::fromStdString(m_arc->getLabel());
    m_label->setText(strLabel); //set text labels
    int choices=m_arc->getNumOptions();
    if(choices==0) {std::cout<<"Game ended "<<std::endl; exit(1);}
    changeNumButtons(m_arc->getNumOptions());
    for(unsigned i=0; i<m_currentNumButtons; i++){
        QString strOptionLabel = QString::fromStdString(m_arc->getOptionLabel(i)); //set option labels
        m_buttons[m_currentNumButtons-1][i]->setText(strOptionLabel);
    }
}

void MainWindow::changeNumButtons(int num){//adjust visible buttons
    for(unsigned i=0; i<m_buttons[m_currentNumButtons-1].size(); i++)
        m_buttons[m_currentNumButtons-1][i]->setVisible(false);
    m_currentNumButtons=num;
    for(unsigned i=0; i<m_buttons[m_currentNumButtons-1].size(); i++)
        m_buttons[m_currentNumButtons-1][i]->setVisible(true);
}


