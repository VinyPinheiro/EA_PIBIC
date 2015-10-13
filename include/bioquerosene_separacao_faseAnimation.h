#ifndef BIOQUEROSENE_SEPARACAO_FASEANIMATION_H
#define BIOQUEROSENE_SEPARACAO_FASEANIMATION_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

#include <vector>
#include <list>

using namespace std;

#include "factory_component.h"
#include "cano.h"

class Image;

class Bioquerosene_separacao_faseAnimation : public Level
{
public:
    Bioquerosene_separacao_faseAnimation(const string& next = "");
    ~Bioquerosene_separacao_faseAnimation() {}

private:
    void draw_self();
    void update_self(unsigned long elapsed);

    list<int> m_active;
    vector<FactoryComponent *> m_components;
    vector< list<int> > m_connections;

    typedef enum { CANO, GEAR } Type;

    void add_component(Type, double x, double y, Cano::Tipo p = Cano::RETO1); 
};

#endif
