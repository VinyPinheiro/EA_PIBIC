#include "fragmentacaoAnimation.h"
#include "global.h"
#include "cano.h"
#include "gear.h"
#include <vector>

#include <ijengine/core/text.h>
#include <ijengine/core/animation.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


FragmentacaoAnimation::FragmentacaoAnimation(const string& next)
    : Level("fragmentacao", next)
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
	Gear *gear = new Gear(this, 350, 340);
    add_child(gear);
    gear->start();
*/
	//if(gear->stopped())
	{
	Cano *cano = new Cano(this, 480, 380, Cano::CURVO6);
		cano->fill();
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 520, 300, Cano::RETO4);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 480, 220, Cano::CURVO5);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 400, 180, Cano::CURVO3);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 400, 100, Cano::CURVO4);
		m_canos.push_back(cano);
		add_child(cano);
	cano = new Cano(this, 480, 100, Cano::RETO1);
		m_canos.push_back(cano);
		add_child(cano);
	}
	
    m_cano = 0;
    
}

void
FragmentacaoAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
FragmentacaoAnimation::update_self(unsigned long elapsed)
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
