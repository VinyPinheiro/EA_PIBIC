#include "biodiesel_armazenamentoAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/animation.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


Biodiesel_armazenamentoAnimation::Biodiesel_armazenamentoAnimation(const string& next)
    : Level("biodiesel_armazenamento", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_biodiesel.png");
    add_child(image);
    
    add_component(GEAR, 950, 20);
	add_component(CANO, 1080, 100, Cano::CURVO1);
	add_component(CANO, 1120, 180, Cano::RETO3);
	add_component(CANO, 1080, 260, Cano::CURVO2);
	add_component(CANO, 1000, 300, Cano::RETO2);
	add_component(CANO, 920, 300, Cano::CURVO8);
	add_component(CANO, 920, 380, Cano::RETO3);
	add_component(CANO, 920, 460, Cano::CURVO7);
	
    m_connections.back().clear();
    m_active.push_back(0);
    m_components[0]->start();
}


void
Biodiesel_armazenamentoAnimation::add_component(Type type, double x, double y, Cano::Tipo p)
{
    switch (type) {
    case CANO:
        {
	        Cano *cano = new Cano(this, x, y, p);
            m_components.push_back(cano);

            list<int> connections { (int) m_connections.size() + 1 };
            m_connections.push_back(connections);
            add_child(cano);
        }
        break;

    case GEAR:
        {
	        Gear *gear = new Gear(this, x, y);
            m_components.push_back(gear);

            list<int> connections { (int) m_connections.size() + 1 };
            m_connections.push_back(connections);
            add_child(gear);
        }
    }
}

void
Biodiesel_armazenamentoAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Biodiesel_armazenamentoAnimation::update_self(unsigned long elapsed)
{
    auto active = m_active;

    for (auto a : active)
    {
        if (m_components[a]->stopped())
        {
            for (auto c : m_connections[a])
            {
                m_components[c]->start();
                m_active.push_back(c);
            }

            m_active.remove(a);
        } else
        {
            m_components[a]->update(elapsed);
        }
    } 

    if (m_active.empty())
    {
		finish();
	}
}
