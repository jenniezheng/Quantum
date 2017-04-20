#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include "global.h"
using namespace std;

class Effect
{
private:
    string m_todo;
public:
    Effect(string todo);
    void act();
};

#endif // EFFECT_H
