#include "prensagem_polpaAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/text.h>
#include <ijengine/core/animation.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


Prensagem_PolpaAnimation::Prensagem_PolpaAnimation(const string& next)
    : Level("prensagem_polpa", next)
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
	
    add_component(GEAR, 110, 490);
	add_component(CANO, 240, 550, Cano::RETO1);
	add_component(CANO, 320, 550, Cano::RETO1);
	add_component(CANO, 400, 550, Cano::RETO1);
	add_component(CANO, 480, 550, Cano::RETO1);
	add_component(CANO, 560, 550, Cano::RETO1);
	add_component(CANO, 640, 550, Cano::RETO1);
	add_component(CANO, 720, 550, Cano::RETO1);
	add_component(CANO, 800, 550, Cano::RETO1);
	add_component(CANO, 880, 530, Cano::T);
	add_component(CANO, 920, 610, Cano::RETO3);

    //m_connections[1].push_back((int) m_components.size());

    m_connections.back().clear();
    m_active.push_back(0);
    m_components[0]->start();
}


void
Prensagem_PolpaAnimation::add_component(Type type, double x, double y, Cano::Tipo p)
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
Prensagem_PolpaAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Prensagem_PolpaAnimation::update_self(unsigned long elapsed)
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
