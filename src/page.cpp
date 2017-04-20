#include "page.h"
#include "global.h"
using namespace std;


string Page::getOptionLabel(unsigned labelNum) const{
    if(m_options.size()<=labelNum)return "Error: Page out of bounds.";
    return get<0>(m_options[labelNum]);
}


void Page::processEffects(){
   for(unsigned i=0; i<m_effects.size(); i++){
        string s=m_effects[i];
        switch(s[0]){
            case 'r':
                relationship_level+=(s[1]-'0');
                break;
            case 'n':
                player_name=s.substr(1,s.size()-1);
                break;
            default:
                exit(1);
        }
    }
}

string Page::toString() const{
  string str="---Page---\n";
  str+=m_description+"\n";
  if(m_effects.size()>0){
      str+="  Effects: ";
      for(unsigned i=0; i<m_effects.size();i++)
          str+=m_effects[i]+" ";
      str+='\n';
  }
  if(m_options.size()>0){
      str+="  Options:";
      for(unsigned i=0; i<m_options.size();i++){
        auto option=m_options[i];
        str+=get<0>(option)+": "+(get<1>(option))->getDescription()+"; ";
      }
  }
  str+='\n';
  return str;
}

