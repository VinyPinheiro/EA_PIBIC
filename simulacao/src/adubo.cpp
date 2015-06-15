/*
 * Implementação da classe Adubo de Mudas.
 *
 * Autor: Camila Ferrer
 * Data: 15/06/2015
 * Licença: LGPL. Sem copyright.
 */
#include "adubo.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/mousebuttonevent.h>

Adubo::Adubo(const string& next)
    : Level("mudas", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());
    
    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(40);
    font->set_style(Font::NORMAL);
    env->canvas->set_font(font);

    Image *image = new Image(this, "res/images/background.png");
    add_child(image);
		
    fertilizer = new Image(this, "res/images/adubo.png");

    if (fertilizer)
    {
        fertilizer->set_position(env->canvas->w() * 0.1, fertilizer->h());
    }

    fertilizer_speed = 200.0;
    fertilizer->set_visible(false);
    add_child(fertilizer);
    
    pesticide = new Image(this, "res/images/pesticida.png");

    if (pesticide)
    {
        pesticide->set_position(env->canvas->w() * 0.2, pesticide->h());
    }

    pesticide_speed = 200.0;
    pesticide->set_visible(false);
    add_child(pesticide);
    
    h2o = new Image(this, "res/images/h2o.png");

    if (h2o)
    {
        h2o->set_position(env->canvas->w() * 0.3, h2o->h());
    }

    h2o_speed = 200.0;
    h2o->set_visible(false);
    add_child(h2o);
	
	rs = new Image(this, "res/images/rs.png");

    if (rs)
    {
        rs->set_position(env->canvas->w() * 0.2, env->canvas->h() - rs->h() - 100);
    }

    rs_speed = 200.0;
    rs->set_visible(false);
    add_child(rs);
	
	Image *sprout1 = new Image(this, "res/images/sprout.png");

	if (sprout1)
    {
        sprout1->set_position(25, env->canvas->h() - sprout1->h() - 100);
    }

    add_child(sprout1);
    
    Image *sprout2 = new Image(this, "res/images/sprout.png");

    if (sprout2)
    {
        sprout2->set_position(sprout1->w() + 25, env->canvas->h() - sprout2->h() - 100);
    }

    add_child(sprout2);
    
    Image *sprout3 = new Image(this, "res/images/sprout.png");

	if (sprout3)
    {
        sprout3->set_position(sprout1->w() + 200, env->canvas->h() - sprout3->h() - 100);
    }

    add_child(sprout3);
	
	Image *ground = new Image(this, "res/images/ground.png");

	if (ground)
    {
        ground->set_y(env->canvas->h() - ground->h());
    }

    add_child(ground);
	
	Text *legenda = new Text(this, "A: Adubo", Color::BLACK);

    if (legenda)
    {
        legenda->align_to(this, Object::CENTER, Object::NONE);
        legenda->set_position(env->canvas->w() * 0.6, env->canvas->h()*0.28);
    }

    add_child(legenda);
    
    Text *legenda2 = new Text(this, "P: Pesticida", Color::BLACK);
    if (legenda2)
    {
        legenda2->align_to(this, Object::CENTER, Object::NONE);
        legenda2->set_position(legenda->x(), legenda->y()+legenda->h());
    }

    add_child(legenda2);
    
    Text *legenda3 = new Text(this, "H2O: Água", Color::BLACK);
    if (legenda3)
    {
        legenda3->align_to(this, Object::CENTER, Object::NONE);
        legenda3->set_position(legenda->x(), legenda2->y()+legenda2->h());
    }

    add_child(legenda3);
	
    last = 0;
    
    Text *legenda4 = new Text(this, "RS: Resíduo Sólido", Color::BLACK);
    if (legenda4)
    {
        legenda4->align_to(this, Object::CENTER, Object::NONE);
        legenda4->set_position(legenda->x(), legenda3->y()+legenda3->h());
    }

    add_child(legenda4);
	
    last = 0;
}

void
Adubo::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Adubo::update_self(unsigned long elapsed)
{
    if (last == 0)
        last = elapsed;

    unsigned long delta = elapsed - last;
    
    if (elapsed/1000 > 2)
    {
        fertilizer->set_visible();
        double dy = (delta/1000.0)*fertilizer_speed;
        fertilizer->set_y(fertilizer->y() + dy);
    }
    
    if (elapsed/1000 > 3)
    {
        pesticide->set_visible();
        double dy = (delta/1000.0)*fertilizer_speed;
        pesticide->set_y(pesticide->y() + dy);
    }
    
    if (elapsed/1000 > 4)
    {
        h2o->set_visible();
        double dy = (delta/1000.0)*fertilizer_speed;
        h2o->set_y(h2o->y() + dy);
    }
    
    if (elapsed/1000 > 5)
    {
        rs->set_visible();
        double dy = (delta/1000.0)*rs_speed;
        rs->set_y(rs->y() - dy);
    }

    if (elapsed/1000 > 15)
    {
        finish();
    }

    last = elapsed;
}
