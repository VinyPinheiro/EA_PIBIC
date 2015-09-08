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
    
/*
	Gear *gear = new Gear(this, 110, 490);
    add_child(gear);
    gear->start();
*/
	//if(gear->stopped())
	{
	Cano *cano = new Cano(this, 240, 550, Cano::RETO1);
		cano->start();
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 320, 550, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 400, 550, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 480, 550, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 560, 550, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 640, 550, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 720, 550, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 800, 550, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 880, 530, Cano::T);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 920, 610, Cano::RETO3);
		m_canos.push_back(cano);
		add_child(cano);
	}
	
    m_cano = 0;
    
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
    if (m_canos[m_cano]->stopped() and m_cano + 1 < (int) m_canos.size())
    {
        m_cano++;
        m_canos[m_cano]->start();
    }

    m_canos[m_cano]->update(elapsed);
    
    if (m_canos[m_cano]->stopped() and m_cano + 1 >= (int) m_canos.size()){
		finish();
	}
    
}
