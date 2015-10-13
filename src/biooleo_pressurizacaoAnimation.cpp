#include "biooleo_pressurizacaoAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/animation.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


Biooleo_pressurizacaoAnimation::Biooleo_pressurizacaoAnimation(const string& next)
    : Level("biooleo_pressurizacao", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/background_biooleo.png");
    add_child(image);
    
    add_component(CANO, 0, 570, Cano::RETO1);
    add_component(GEAR, 70, 480);
	add_component(CANO, 200, 530, Cano::CURVO6);
	add_component(CANO, 240, 450, Cano::RETO4);
	add_component(CANO, 200, 370, Cano::CURVO5);
	add_component(CANO, 120, 370, Cano::RETO2);
	add_component(CANO, 40, 330, Cano::CURVO3);
	add_component(CANO, 40, 250, Cano::RETO4);
	add_component(CANO, 40, 170, Cano::RETO4);
	add_component(CANO, 40, 90, Cano::CURVO4);
	
    m_connections.back().clear();
    m_active.push_back(0);
    m_components[0]->start();
}


void
Biooleo_pressurizacaoAnimation::add_component(Type type, double x, double y, Cano::Tipo p)
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
Biooleo_pressurizacaoAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Biooleo_pressurizacaoAnimation::update_self(unsigned long elapsed)
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
