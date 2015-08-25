/*
 * Implementação da classe GameOver.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#include "gameover.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/mousebuttonevent.h>

GameOver::GameOver(const string& next)
    : Level("solo", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());
    env->events_manager->register_listener(this);

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(90);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);

    Image *image = new Image(this, "res/images/background.png");
    add_child(image);

    Text *title = new Text(this, "GameOver", Color::BLACK);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::MIDDLE);
    }

    add_child(title);
}

GameOver::~GameOver()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_listener(this);
}

void
GameOver::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

bool
GameOver::on_event(const KeyboardEvent& event)
{
    if (event.state() == KeyboardEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}

bool
GameOver::on_event(const MouseButtonEvent& event)
{
    if (event.state() == MouseButtonEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}
