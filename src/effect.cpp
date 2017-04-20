#include "effect.h"
#include <iostream>
using namespace std;

Effect::Effect(string todo)
{
    if(todo.size()==0) return;
    else if('a'<=todo[0]&&todo[0]<='z'){
        m_todo=todo;
    }
    else exit(1);
}

void Effect::act(){
    switch(m_todo[0]){
        case 'r':
            relationship_level+=(m_todo[1]-'0');
            break;
        case 'n':
            player_name=m_todo.substr(1,m_todo.size()-1);
            break;
        default:
            exit(1);
            break;
    }
}
