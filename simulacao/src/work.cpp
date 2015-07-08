/*
 * Implementação da classe Trabalhadores.
 *
 * Autor: Camila Ferrer
 * Data: 08/07/2015
 * Licença: LGPL. Sem copyright.
 */
#include "work.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/mousebuttonevent.h>

Work::Work(const string& next)
    : Level("plantio", next)
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

    tractor = new Image(this, "res/images/tractor.png");

    if (tractor)
    {
        tractor->set_position(env->canvas->w(), env->canvas->h() - tractor->h() - 100);
    }

    tractor_speed = 200.0;
    add_child(tractor);

    co2 = new Image(this, "res/images/co2.png");

    if (co2)
    {
        co2->set_position(env->canvas->w() * 0.7, env->canvas->h() - co2->h() - 100);
    }

    co2_speed = 250.0;
    co2->set_visible(false);
    add_child(co2);

    
    Text *legenda1 = new Text(this, "CO2: Gás Carbônico", Color::BLACK);

    if (legenda1)
    {
        legenda1->align_to(this, Object::CENTER, Object::NONE);
        legenda1->set_position(env->canvas->w() * 0.6, env->canvas->h()*0.28);
    }

    add_child(legenda1);
    
    Text *legenda2 = new Text(this, "RS: Resíduo Sólido", Color::BLACK);
    
    if (legenda2)
    {
        legenda2->align_to(this, Object::CENTER, Object::NONE);
        legenda2->set_position(legenda1->x(), legenda1->y()+legenda1->h());
    }

    add_child(legenda2);

    last = 0;
}

void
Work::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Work::update_self(unsigned long elapsed)
{
    if (last == 0)
        last = elapsed;

    unsigned long delta = elapsed - last;
    double dx = (delta/1000.0)*tractor_speed;

    tractor->set_x(tractor->x() - dx);

    Environment *env = Environment::get_instance();
   	for(int i = seedlings_amount - 1; i >= 0; i--)
	{
			if(tractor->x() + tractor->w() - 24 < i * env->canvas->w() / 9)
			{
				Image *sprout = new Image(this, "res/images/sprout.png");

				if (sprout)
				{
					sprout->set_position( i * env->canvas->w() / 9 + 50 - sprout->w() / 2, env->canvas->h() - sprout->h() - 100);
				}

				add_child(sprout);

			} 
	}
    if (tractor->x() < (env->canvas->w() * 2)/3)
    {
        co2->set_visible();
        double dy = (delta/1000.0)*co2_speed;
        co2->set_y(co2->y() - dy);
    }

    if (tractor->x() + tractor->w() < -50)
    {
        finish();
    }

    last = elapsed;
}
