/*
 * Implementação da classe Tractor.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#include "tractor.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/mousebuttonevent.h>

Tractor::Tractor(const string& next)
    : Level("solo", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());
    env->events_manager->register_listener(this);

	shared_ptr<Font> font =
    env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(40);
    font->set_style(Font::NORMAL);
    env->canvas->set_font(font);

    Image *image = new Image(this, "res/images/background.png");
    add_child(image);

    tractor = new Image(this, "res/images/tractor_field.png");

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

    rs = new Image(this, "res/images/rs.png");

    if (rs)
    {
        rs->set_position(env->canvas->w() * 0.4, env->canvas->h() - rs->h() - 100);
    }

    rs_speed = 250.0;
    rs->set_visible(false);
    add_child(rs);
    
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

Tractor::~Tractor()
{
	Environment *env = Environment::get_instance();
	env->events_manager->unregister_listener(this);
}

void
Tractor::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Tractor::update_self(unsigned long elapsed)
{
    if (last == 0)
        last = elapsed;

    unsigned long delta = elapsed - last;
    double dx = (delta/1000.0)*tractor_speed;

    tractor->set_x(tractor->x() - dx);

    Environment *env = Environment::get_instance();

    if (tractor->x() < (env->canvas->w() * 2)/3)
    {
        co2->set_visible();
        double dy = (delta/1000.0)*co2_speed;
        co2->set_y(co2->y() - dy);
    }

    if (tractor->x() < env->canvas->w()/3)
    {
        rs->set_visible();
        double dy = (delta/1000.0)*rs_speed;
        rs->set_y(rs->y() - dy);
    }

    if (tractor->x() + tractor->w() < -50)
    {
        finish();
    }

    last = elapsed;
}

bool
Tractor::on_event(const MouseButtonEvent& event)
{
    if (event.state() == MouseButtonEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}

bool
Tractor::on_event(const KeyboardEvent& event)
{
    if (event.state() == KeyboardEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}
