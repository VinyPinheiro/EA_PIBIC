/*
 * Implementação da classe Credits.
 *
 * Autor: Edson Alves
 * Data: 17/05/2015
 * Licença: LGPL. Sem copyright.
 */
#include "credits.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/mousebuttonevent.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/environment.h>

#include <list>

using std::list;

Credits::Credits(const string& next)
    : Level("credits", next)
{
    Environment *env = Environment::get_instance();

    set_dimensions(env->canvas->w(), env->canvas->h());

    env->events_manager->register_mouse_button_event_listener(this);
    env->events_manager->register_keyboard_event_listener(this);

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");

    font->set_size(60);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);
    double y = 40;

    list<string> titles { "ALUNOS", "ORIENTADORES" };

    for (auto title : titles)
    {
        Text *text = new Text(this, title);
        text->align_to(this, Object::CENTER, Object::NONE);
        text->set_y(y);
        add_child(text);
        y += 400;
    }

    font->set_size(45);
    font->set_style(Font::NORMAL);
    y = 160;

    list<string> students
    {
        "Camila Carneiro Ferrer",
        "Gesiel dos Santos Freitas",
        "Vinícius Pinheiro da Silva Corrêa"
    };

    for (auto student : students)
    {
        Text *text = new Text(this, student);
        text->align_to(this, Object::CENTER, Object::NONE);
        text->set_y(y);
        add_child(text);
        y += 80;
    }

    list<string> professors
    { "Edson Alves da Costa Júnior", "Maria Vitória Duarte Ferrari Tome" };

    y = 560;

    for (auto professor : professors)
    {
        Text *text = new Text(this, professor);
        text->align_to(this, Object::CENTER, Object::NONE);
        text->set_y(y);
        add_child(text);
        y += 80;
    }
}

Credits::~Credits()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_mouse_button_event_listener(this);
    env->events_manager->unregister_keyboard_event_listener(this);
}

bool
Credits::onMouseButtonEvent(const MouseButtonEvent& event)
{
    if (event.state() == MouseButtonEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}

bool
Credits::onKeyboardEvent(const KeyboardEvent& event)
{
    if (event.state() == KeyboardEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}

void
Credits::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}
