/*
 * Implementação da classe do Caminhao Cheio.
 *
 * Autor: Camila Ferrer
 * Data: 03/07/2015
 * Licença: LGPL. Sem copyright.
 */
#include "full_truck.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/mousebuttonevent.h>

Full_truck::Full_truck(const string& next)
    : Level("empty_truck", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());
    env->events_manager->register_listener(this);

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

    rs = new Image(this, "res/images/rs.png");

    if (rs)
    {
        rs->set_position(env->canvas->w() * 0.4, env->canvas->h() - rs->h() - 100);
    }

    rs_speed = 250.0;
    rs->set_visible(false);
    add_child(rs);

    ro = new Image(this, "res/images/ro.png");

    if (ro)
    {
        ro->set_position(env->canvas->w() * 0.6, env->canvas->h() - ro->h() - 100);
    }

    ro_speed = 250.0;
    ro->set_visible(false);
    add_child(ro);

    unsigned int distance = env->canvas->w() / 9;
    unsigned int delta = 50;

    for (unsigned int i = 0; i < seedlings_amount; ++i)
    {
        Image *tree = new Image(this, "res/images/tree.png");

        if (tree)
        {
            double x = i*distance + delta;
            tree->set_position(x - tree->w() / 2, env->canvas->h() - tree->h() - 100);
        }

        add_child(tree);
    }


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

    Text *legenda2 = new Text(this, "RS: Resíduo Sólido", Color::BLACK);

    if (legenda2)
    {
        legenda2->align_to(this, Object::CENTER, Object::NONE);
        legenda2->set_position(legenda1->x(), legenda1->y()+legenda1->h());
    }

    add_child(legenda2);

    last = 0;

    Text *legenda3 = new Text(this, "RO: Resíduo Orgânico", Color::BLACK);

    if (legenda3)
    {
        legenda3->align_to(this, Object::CENTER, Object::NONE);
        legenda3->set_position(legenda2->x(), legenda2->y()+legenda2->h());
    }

    add_child(legenda3);

    last = 0;
}

void
Full_truck::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
Full_truck::update_self(unsigned long elapsed)
{
    if (last == 0)
        last = elapsed;

    unsigned long delta = elapsed - last;
    double dx = (delta/1000.0)*truck_speed;

    truck->set_x(truck->x() + dx);

    Environment *env = Environment::get_instance();

    if (truck->x() > env->canvas->w() * 0.2)
    {
        co2->set_visible();
        double dy = (delta/1000.0)*co2_speed;
        co2->set_y(co2->y() - dy);
    }

    if (truck->x() > env->canvas->w()*0.4)
    {
        rs->set_visible();
        double dy = (delta/1000.0)*rs_speed;
        rs->set_y(rs->y() - dy);
    }

    if (truck->x() > env->canvas->w()*0.5)
    {
        ro->set_visible();
        double dy = (delta/1000.0)*ro_speed;
        ro->set_y(ro->y() - dy);
    }

    if (truck->x() - 50 > env->canvas->w())
    {
        finish();
    }

    last = elapsed;
}

bool
Full_truck::on_event(const MouseButtonEvent& event)
{
    if (event.state() == MouseButtonEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}

bool
Full_truck::on_event(const KeyboardEvent& event)
{
    if (event.state() == KeyboardEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}


Full_truck::~Full_truck()
{
	Environment *env = Environment::get_instance();
	env->events_manager->unregister_listener(this);
}
