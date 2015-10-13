#include "amendoaAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/animation.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


AmendoaAnimation::AmendoaAnimation(const string& next)
    : Level("amendoa", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_despolpa_fase1.png");
    add_child(image);
    
    add_component(GEAR, 670, 140);
	add_component(CANO, 800, 180, Cano::CURVO6);
	add_component(CANO, 840, 100, Cano::T);
	add_component(CANO, 920, 80, Cano::CURVO6);
	add_component(CANO, 960, 0, Cano::CURVO4);
	add_component(CANO, 1040, 0, Cano::RETO1);
	add_component(CANO, 1120, 0, Cano::RETO1);
	
    m_connections.back().clear();
    m_active.push_back(0);
    m_components[0]->start();
}


void
AmendoaAnimation::add_component(Type type, double x, double y, Cano::Tipo p)
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
AmendoaAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
AmendoaAnimation::update_self(unsigned long elapsed)
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
