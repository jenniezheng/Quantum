#ifndef ARC_H
#define ARC_H

#include <string>
#include "page.h"
using namespace std;

//forward declaration
class Page;

class Arc {
public:
    string toString();
    Arc(int num);
    ~Arc(){cleanUp();}
    void cleanUp();
    string getLabel(){return currentPage->getDescription();}
    int getNumOptions(){return currentPage->getNumOptions();}
    string getOptionLabel(int optNum){return currentPage->getOptionLabel(optNum);}
    void choose(int choiceNum);

private:
    vector<Page*> m_pages;
    Page* currentPage;
    void createArcOne();
    void createArcTwo();
    void createArcThree();
};

#endif
