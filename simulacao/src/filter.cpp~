/*
 * Implementação da classe do Caminhao Cheio.
 *
 * Autor: Camila Ferrer
 * Data: 03/07/2015
 * Licença: LGPL. Sem copyright.
 */
#include "filter.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/mousebuttonevent.h>

Filter::Filter(const string& next)
    : Level("industry", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/filter.png");
    add_child(image);

    brine = new Image(this, "res/images/brine.png");

    if (brine)
    {
        brine->set_position(-210, env->canvas->h() - brine->h() - 300);
    }

    brine_speed = 200.0;
    add_child(brine);

    co2 = new Image(this, "res/images/co2.png");

    if (co2)
    {
        co2->set_position(env->canvas->w() * 0.7, env->canvas->h() - co2->h() - 100);
    }

    co2_speed = 250.0;
    co2->set_visible(false);
    add_child(co2);

    last = 0;
}

void
Filter::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Filter::update_self(unsigned long elapsed)
{
    if (last == 0)
        last = elapsed;

    unsigned long delta = elapsed - last;
    double dx = (delta/1000.0)*brine_speed;

    brine->set_x(brine->x() + dx);

    Environment *env = Environment::get_instance();

    if (brine->x() > (env->canvas->w() * 2)/3)
    {
        co2->set_visible();
        double dy = (delta/1000.0)*co2_speed;
        co2->set_y(co2->y() - dy);
    }

    if (brine->x() > env->canvas->w() + 50)
    {
        finish();
    }

    last = elapsed;
}
