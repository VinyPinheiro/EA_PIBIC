/*
 * Implementação da classe da Entrega do Caminhao Cheio.
 *
 * Autor: Camila Ferrer
 * Data: 08/07/2015
 * Licença: LGPL. Sem copyright.
 */
#include "delivery.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/mousebuttonevent.h>

Delivery::Delivery(const string& next)
    : Level("full_truck", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

	shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(35);
    font->set_style(Font::NORMAL);
    env->canvas->set_font(font);

    Image *image = new Image(this, "res/images/background.png");
    add_child(image);

    truck = new Image(this, "res/images/truck_full.png");

    if (truck)
    {
        truck->set_position(0 - truck->w() - 50, env->canvas->h() - truck->h() - 100);
    }

    truck_speed = 200.0;
    add_child(truck);

    co2 = new Image(this, "res/images/co2.png");

    if (co2)
    {
        co2->set_position(env->canvas->w() * 0.2, env->canvas->h() - co2->h() - 100);
    }

    co2_speed = 250.0;
    co2->set_visible(false);
    add_child(co2);

	Image *industry = new Image(this, "res/images/industry.png");

    if (industry)
    {
        industry->set_position(env->canvas->w() - industry->w(), env->canvas->h() - industry->h() - 100);
    }

    add_child(industry);
    
    Image *ground = new Image(this, "res/images/ground.png");

	if (ground)
    {
        ground->set_y(env->canvas->h() - ground->h());
    }

    add_child(ground);
    
    Text *legenda1 = new Text(this, "CO2: Gás Carbônico", Color::BLACK);

    if (legenda1)
    {
        legenda1->align_to(this, Object::CENTER, Object::NONE);
        legenda1->set_position(env->canvas->w() * 0.6, env->canvas->h()*0.28);
    }

    add_child(legenda1);
    
    
    last = 0;
}

void
Delivery::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Delivery::update_self(unsigned long elapsed)
{
    if (last == 0)
        last = elapsed;

    unsigned long delta = elapsed - last;
    double dx = (delta/1000.0)*truck_speed;

    truck->set_x(truck->x() + dx);

    Environment *env = Environment::get_instance();

    if (truck->x() > env->canvas->w()*0.2)
    {
        co2->set_visible();
        double dy = (delta/1000.0)*co2_speed;
        co2->set_y(co2->y() - dy);
    }

    
    if (truck->x() - 50 > (env->canvas->w() * 0.5))
    {
        finish();
    }

    last = elapsed;
}
