#include "despolpamentoAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/text.h>
#include <ijengine/core/animation.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


DespolpamentoAnimation::DespolpamentoAnimation(const string& next)
    : Level("despolpamento", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(90);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);

    Image *image = new Image(this, "res/images/background_despolpa_fase1.png");
    add_child(image);
    
    add_component(CANO, 0, 125);
    add_component(GEAR, 70, 60);
	add_component(CANO, 200, 150, Cano::CURVO1);
	add_component(CANO, 200, 230, Cano::CURVO2);
	add_component(CANO, 120, 270, Cano::RETO2);
	add_component(CANO, 40, 270, Cano::CURVO8);
	add_component(CANO, 40, 350, Cano::CURVO7);
	add_component(CANO, 120, 390, Cano::CURVO1);
	add_component(CANO, 160, 470, Cano::CURVO7);

    m_connections[1].push_back((int) m_components.size());

	add_component(CANO, 200, 100, Cano::RETO1);
	add_component(CANO, 280, 100, Cano::CURVO1);
	add_component(CANO, 320, 180, Cano::CURVO7);
	
    m_connections.back().clear();
    m_active.push_back(0);
    m_components[0]->start();
}


void
DespolpamentoAnimation::add_component(Type type, double x, double y, Cano::Tipo p)
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
DespolpamentoAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
DespolpamentoAnimation::update_self(unsigned long elapsed)
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
