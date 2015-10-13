#include "lavagemAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/animation.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


LavagemAnimation::LavagemAnimation(const string& next)
    : Level("lavagem", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_despolpa_fase2.png");
    add_child(image);
    
    add_component(GEAR, 310, 250);
	add_component(CANO, 440, 290, Cano::CURVO6);
	add_component(CANO, 440, 210, Cano::CURVO5);
	add_component(CANO, 360, 210, Cano::RETO2);
	add_component(CANO, 280, 210, Cano::RETO2);
	add_component(CANO, 200, 170, Cano::CURVO3);
	add_component(CANO, 200, 90, Cano::CURVO4);
	add_component(CANO, 280, 90, Cano::RETO1);
	add_component(CANO, 360, 90, Cano::RETO1);
	add_component(CANO, 440, 90, Cano::RETO1);
	add_component(CANO, 520, 90, Cano::RETO1);
	add_component(CANO, 600, 90, Cano::RETO1);
	
    m_connections.back().clear();
    m_active.push_back(0);
    m_components[0]->start();
}


void
LavagemAnimation::add_component(Type type, double x, double y, Cano::Tipo p)
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
LavagemAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
LavagemAnimation::update_self(unsigned long elapsed)
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
