#include "biodiesel_branqueamentoAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/animation.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


Biodiesel_branqueamentoAnimation::Biodiesel_branqueamentoAnimation(const string& next)
    : Level("biodiesel_branqueamento", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_biodiesel.png");
    add_child(image);
    
    add_component(GEAR, 470, 490);
	add_component(CANO, 600, 530, Cano::CURVO6);
	add_component(CANO, 640, 450, Cano::RETO4);
	add_component(CANO, 640, 370, Cano::RETO4);
	add_component(CANO, 640, 290, Cano::CURVO4);
	
    m_connections.back().clear();
    m_active.push_back(0);
    m_components[0]->start();
}


void
Biodiesel_branqueamentoAnimation::add_component(Type type, double x, double y, Cano::Tipo p)
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
Biodiesel_branqueamentoAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Biodiesel_branqueamentoAnimation::update_self(unsigned long elapsed)
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
