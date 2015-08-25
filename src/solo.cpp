/*
 * Implementação da classe Solo.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#include "solo.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Solo::Solo(const string& next)
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

    Text *title = new Text(this, "Preparando Solo", Color::BLACK);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::NONE);
        title->set_y(40);
    }

    add_child(title);

    font->set_style(Font::NORMAL);
    font->set_size(50);

    Text *question = new Text(this, "Colocar fertilizantes e calcário?", Color::BLACK);

    if (question)
    {
        question->align_to(this, Object::CENTER, Object::NONE);
        question->set_y(title->y() + title->h() + 50);
    }

    add_child(question);

    Button *yes = new Button(this, "trator", 200, 100);

    if (yes)
    {
        yes->set_text("Sim", Color::BLACK);
        yes->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        yes->set_border(5, Color(0, 0, 0, 128));
        yes->align_to(this, Object::CENTER, Object::NONE);
        yes->set_y(question->y() + question->h() + 40);
        yes->add_observer(this);
    }

    add_child(yes);

    Button *no = new Button(this, "gameover", 200, 100);

    if (no)
    {
        no->set_text("Não", Color::BLACK);
        no->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        no->set_border(5, Color(0, 0, 0, 128));
        no->align_to(this, Object::CENTER, Object::NONE);
        no->set_y(yes->y() + yes->h() + 20);
        no->add_observer(this);
    }

    add_child(no);
}

void
Solo::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

bool
Solo::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    set_next(object->id());
    finish();

    return true;
}
