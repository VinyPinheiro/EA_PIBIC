/*
 * Implementação da classe Plantio.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#include "plantio.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Plantio::Plantio(const string& next)
    : Level("solo", next)
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

    Text *title = new Text(this, "Plantio", Color::BLACK);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::NONE);
        title->set_y(40);
    }

    add_child(title);

    font->set_style(Font::NORMAL);
    font->set_size(50);

    Text *question = new Text(this, "Plantar quantas mudas?", Color::BLACK);

    if (question)
    {
        question->align_to(this, Object::CENTER, Object::NONE);
        question->set_y(title->y() + title->h() + 50);
    }

    add_child(question);

    seedlings = 1;

    amount = new Button(this, "amount", 150, 100);

    if (amount)
    {
        char text[20];
        sprintf(text, "%u", seedlings);

        amount->set_text(text, Color::BLACK);
        amount->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        amount->set_border(5, Color(0, 0, 0, 128));
        amount->align_to(this, Object::CENTER, Object::NONE);
        amount->set_x(amount->x() - 25);
        amount->set_y(question->y() + question->h() + 40);
        amount->add_observer(this);
    }

    add_child(amount);

    plus = new Button(this, "plus", 50, 50);

    if (plus)
    {
        plus->set_text("+", Color::BLACK);
        plus->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        plus->set_border(5, Color(0, 0, 0, 128));
        plus->set_position(amount->x() + amount->w(), amount->y());
        plus->add_observer(this);
    }

    add_child(plus);

    minus = new Button(this, "minus", 50, 50);

    if (minus)
    {
        minus->set_text("-", Color::BLACK);
        minus->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        minus->set_border(5, Color(0, 0, 0, 128));
        minus->set_position(amount->x() + amount->w(), amount->y() + 50);
        minus->add_observer(this);
    }

    add_child(minus);

    Button *ok = new Button(this, "worker", 200, 100);

    if (ok)
    {
        ok->set_text("Ok", Color::BLACK);
        ok->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        ok->set_border(5, Color(0, 0, 0, 128));
        ok->align_to(this, Object::CENTER, Object::NONE);
        ok->set_y(amount->y() + amount->h() + 20);
        ok->add_observer(this);
    }
   
    add_child(ok);
}

void
Plantio::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

bool
Plantio::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    if (object->id() == "amount")
        return false;

    if (object->id() == "plus")
    {
        if (seedlings < 9)
        {
            ++seedlings;
            char text[20];
            sprintf(text, "%u", seedlings);
            amount->set_text(text);
        }
        return true;
    }

    if (object->id() == "minus")
    {
        if (seedlings > 1)
        {
            --seedlings;
            char text[20];
            sprintf(text, "%u", seedlings);
            amount->set_text(text);
        }
        return true;
    }

    set_next(object->id());
    finish();

    return true;
}
