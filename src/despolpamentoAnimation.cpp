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
    
    Cano *cano = new Cano(this, 0, 125, Cano::RETO1);
    cano->fill();
    m_canos.push_back(cano);
    add_child(cano);
/*
	Gear *gear = new Gear(this, 70, 60);
    add_child(gear);
    gear->start();
*/
	/*if(gear->stopped()){
		
	}*/
	{//Parte 1
	cano = new Cano(this, 200, 150, Cano::CURVO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 200, 230, Cano::CURVO2);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 120, 270, Cano::RETO2);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 40, 270, Cano::CURVO8);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 40, 350, Cano::RETO3);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 40, 430, Cano::RETO3);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 40, 510, Cano::CURVO7);
		m_canos.push_back(cano);
		add_child(cano);
	}
	
	{//Parte 2
	cano = new Cano(this, 200, 100, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 280, 100, Cano::CURVO1);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 320, 180, Cano::RETO3);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 280, 260, Cano::CURVO2);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 200, 300, Cano::CURVO8);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 200, 380, Cano::CURVO7);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 280, 420, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	
	}
    
    m_cano = 0;
    
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
    if (m_canos[m_cano]->filled() and m_cano + 1 < (int) m_canos.size())
    {
        m_cano++;
        m_canos[m_cano]->fill();
    }

    m_canos[m_cano]->update(elapsed);
    
    if (m_canos[m_cano]->filled() and m_cano + 1 >= (int) m_canos.size()){
		finish();
	}
    
}
