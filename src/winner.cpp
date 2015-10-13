#include "winner.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/keyboardevent.h>
#include <ijengine/core/mousebuttonevent.h>

Winner::Winner(const string& next)
    : Level("finalizacao", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());
    env->events_manager->register_listener(this);

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(90);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);

    Image *image = new Image(this, "res/images/background_winner.png");
    add_child(image);

    Text *title = new Text(this, "Vencedor!", Color::BLACK);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::NONE);
        title->set_y(30);
    }

    add_child(title);
}

Winner::~Winner()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_listener(this);
}

void
Winner::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

bool
Winner::on_event(const KeyboardEvent& event)
{
    if (event.state() == KeyboardEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}

bool
Winner::on_event(const MouseButtonEvent& event)
{
    if (event.state() == MouseButtonEvent::PRESSED)
    {
        finish();
        return true;
    }

    return false;
}
