#include "page.h"
#include <string>
#include <list>
using namespace std;

list<Page> firstArc(){
    list<Page> li;
    Page start("Start");
    Page b("Day1");
     start.addOption("go to b",&b);
    Page c("Week2");
     b.addOption("go to c",&c);
     b.addOption("go to b",&b);
    Page d("Month2");
    Page e("Month2");
    li.push_back(start);
    li.push_back(b);
    li.push_back(c);
    li.push_back(d);
    li.push_back(e);

    return li;
}
