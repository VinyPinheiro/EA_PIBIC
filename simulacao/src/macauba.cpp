/*
 * Implementação da classe Macauba.
 *
 * Autor: Edson Alves
 * Data: 11/06/2015
 * Licença: LGPL. Sem copyright.
 */
#include "macauba.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Macauba::Macauba(const string& next)
    : Level("macauba", next)
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

    Text *title = new Text(this, "Gerenciamento de", Color::BLACK);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::NONE);
        title->set_y(40);
    }

    add_child(title);

    Text *title2 = new Text(this, "Produção de Energia", Color::BLACK);

    if (title2)
    {
        title2->align_to(this, Object::CENTER, Object::NONE);
        title2->set_y(title->y() + title->h() + 20);
    }

    add_child(title2);

    font->set_style(Font::NORMAL);
    font->set_size(50);

    Text *subtitle = new Text(this, "Biodiesel - Macaúba", Color(20, 180, 55));

    if (subtitle)
    {
        subtitle->align_to(this, Object::CENTER, Object::NONE);
        subtitle->set_y(title2->y() + title2->h() + 35);
    }

    add_child(subtitle);
    
    Button *start = new Button(this, "solo", 200, 100);

    if (start)
    {
        start->set_text("Iniciar", Color::BLACK);
        start->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        start->set_border(5, Color(0, 0, 0, 128));
        start->align_to(this, Object::CENTER, Object::NONE);
        start->set_y(subtitle->y() + subtitle->h() + 30);
        start->add_observer(this);
    }

    add_child(start);

    Button *back = new Button(this, "start", 200, 100);

    if (back)
    {
        back->set_text("Voltar", Color::BLACK);
        back->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        back->set_border(5, Color(0, 0, 0, 128));
        back->align_to(this, Object::CENTER, Object::NONE);
        back->set_y(start->y() + start->h() + 20);
        back->add_observer(this);
    }

    add_child(back);
}

void
Macauba::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

bool
Macauba::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    set_next(object->id());
    finish();

    return true;
}
