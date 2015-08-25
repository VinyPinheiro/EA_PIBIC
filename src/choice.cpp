/*
 * Implementação da classe Escolha.
 *
 * Autor: Camila Ferrer
 * Data: 08/07/2015
 * Licença: LGPL. Sem copyright.
 */
#include "choice.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Choice::Choice(const string& next)
    : Level("choice", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(90);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);

    Image *image = new Image(this, "res/images/background.png");
    add_child(image);

    Text *title = new Text(this, "Escolha de Produção", Color::BLACK);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::NONE);
        title->set_y(40);
    }

    add_child(title);

    font->set_style(Font::NORMAL);
    font->set_size(50);

    Text *question = new Text(this, "Qual a forma de extração?", Color::BLACK);

    if (question)
    {
        question->align_to(this, Object::CENTER, Object::NONE);
        question->set_y(title->y() + title->h() + 50);
    }

    add_child(question);
    
    seedlings_amount = 5;
    
    Button *ext = new Button(this, "colheita", 330, 100);

    if (ext)
    {
        ext->set_text("Extrativismo", Color::BLACK);
        ext->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        ext->set_border(5, Color(0, 0, 0, 128));
        ext->align_to(this, Object::CENTER, Object::NONE);
        ext->set_y(question->y() + question->h() + 30);
        ext->add_observer(this);
    }

    add_child(ext);

    Button *plt = new Button(this, "solo", 200, 100);

    if (plt)
    {
        plt->set_text("Plantio", Color::BLACK);
        plt->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        plt->set_border(5, Color(0, 0, 0, 128));
        plt->align_to(this, Object::CENTER, Object::NONE);
        plt->set_y(ext->y() + ext->h() + 20);
        plt->add_observer(this);
    }

    add_child(plt);
}

void
Choice::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

bool
Choice::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    set_next(object->id());
    finish();

    return true;
}
