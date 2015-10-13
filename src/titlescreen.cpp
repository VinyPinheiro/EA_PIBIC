/*
 * Implementação da classe TitleScreen.
 *
 * Autor: Edson Alves
 * Data: 13/05/2015
 * Licença: LGPL. Sem copyright.
 */
#include "titlescreen.h"

#include <ijengine/core/environment.h>
#include <ijengine/core/image.h>
#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/util/button.h>

#include <cstdio>
using namespace std;

TitleScreen::TitleScreen()
    : Level("title")
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/earth.png");

    if (image)
    {
        image->align_to(this, Object::CENTER, Object::MIDDLE);
    }

    add_child(image);

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(90);

    env->canvas->set_font(font);

    Text *title = new Text(this, "Simulação Ambiental", Color::WHITE);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::NONE);
        title->set_y(20);
    }

    add_child(title);

    font->set_size(45);

    Button *start = new Button(this, "start", 200, 100);

    if (start)
    {
        start->set_text("Iniciar", Color::WHITE);
        start->set_color(Color(0, 0, 0, 128), Color(64, 64, 64, 128));
        start->set_border(1, Color(128, 128, 128, 128));
        start->align_to(this, Object::CENTER, Object::NONE);
        start->set_y(260);
        start->add_observer(this);
    }

    add_child(start);

    Button *credits = new Button(this, "credits", 200, 100);

    if (credits)
    {
        credits->set_text("Créditos", Color::WHITE);
        credits->set_color(Color(0, 0, 0, 128), Color(64, 64, 64, 128));
        credits->set_border(1, Color(128, 128, 128, 128));
        credits->align_to(this, Object::CENTER, Object::NONE);
        credits->set_y(380);
        credits->add_observer(this);
    }

    add_child(credits);

    Button *quit = new Button(this, "quit", 200, 100);

    if (quit)
    {
        quit->set_text("Sair", Color::WHITE);
        quit->set_color(Color(0, 0, 0, 128), Color(64, 64, 64, 128));
        quit->set_border(1, Color(128, 128, 128, 128));
        quit->align_to(this, Object::CENTER, Object::NONE);
        quit->set_y(500);
        quit->add_observer(this);
    }

    add_child(quit);
}

void
TitleScreen::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear();
}

bool
TitleScreen::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    set_next(object->id());
    finish();

    return true;
}
