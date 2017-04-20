#ifndef PAGE_H
#define PAGE_H

#include <tuple>
#include <vector>
#include <iostream>
using namespace std;

class Page {
private:
  string m_description;
  vector<tuple<string, Page*>> m_options;
  vector<string> m_effects;

public:
  Page(string description){ m_description=description;}
  ~Page(){std::cout<<"DELETED THIS: "<<getDescription()<<std::endl;}
  void addOption(string label, Page* page){ auto tup=make_tuple(label, page); m_options.push_back(tup);}
  void addEffect(string todo){m_effects.push_back(todo);}
  string getDescription() const{return m_description;}
  string getOptionLabel(unsigned labelNum) const;
  int getNumOptions() const{return m_options.size();}
  Page* getChosenPage(unsigned choice) const {if(choice>=m_options.size())return nullptr; return get<1>(m_options[choice]);}
  void processEffects();
  string toString() const;//FOR TESTING
};


#endif // PAGE_H
