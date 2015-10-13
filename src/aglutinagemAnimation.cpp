#include "aglutinagemAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/animation.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


AglutinagemAnimation::AglutinagemAnimation(const string& next)
    : Level("aglutinagem", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_despolpa_fase2.png");
    add_child(image);
    
    add_component(CANO, 0, 430, Cano::CURVO1);
    add_component(CANO, 40, 510, Cano::CURVO7);
    add_component(GEAR, 110, 480);
	add_component(CANO, 240, 510, Cano::CURVO6);
	add_component(CANO, 240, 430, Cano::CURVO5);
	add_component(CANO, 160, 430, Cano::RETO2);
	add_component(CANO, 80, 390, Cano::CURVO3);
	add_component(CANO, 80, 310, Cano::CURVO4);
	add_component(CANO, 160, 310, Cano::RETO1);
	add_component(CANO, 240, 310, Cano::RETO1);
	
	m_connections[1].push_back((int) m_components.size());
	
	add_component(CANO, 0, 0, Cano::RETO1);
	add_component(CANO, 80, 0, Cano::RETO1);
	add_component(CANO, 160, 0, Cano::RETO1);
	add_component(CANO, 240, 0, Cano::RETO1);
	add_component(CANO, 320, 0, Cano::RETO1);
	add_component(CANO, 400, 0, Cano::RETO1);
	add_component(CANO, 480, 0, Cano::RETO1);
	add_component(CANO, 560, 0, Cano::RETO1);
	add_component(CANO, 640, 0, Cano::RETO1);
	add_component(CANO, 720, 0, Cano::RETO1);
	add_component(CANO, 800, 0, Cano::RETO1);
	add_component(CANO, 880, 0, Cano::RETO1);
	add_component(CANO, 960, 0, Cano::RETO1);
	add_component(CANO, 1040, 0, Cano::RETO1);
	add_component(CANO, 1120, 0, Cano::RETO1);
	
    m_connections.back().clear();
    m_active.push_back(0);
    m_components[0]->start();
}


void
AglutinagemAnimation::add_component(Type type, double x, double y, Cano::Tipo p)
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
AglutinagemAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
AglutinagemAnimation::update_self(unsigned long elapsed)
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
