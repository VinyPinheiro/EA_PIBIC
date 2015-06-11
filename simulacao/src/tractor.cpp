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

    rs = new Image(this, "res/images/rs.png");

    if (rs)
    {
        rs->set_position(env->canvas->w() * 0.4, env->canvas->h() - rs->h() - 100);
    }

    rs_speed = 250.0;
    rs->set_visible(false);
    add_child(rs);

    last = 0;
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
