#include "start.h"

#include <ijengine/core/environment.h>
#include <ijengine/core/image.h>
#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/util/button.h>

#include <cstdio>
using namespace std;

Start::Start()
    : Level("start")
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
        title->set_y(60);
    }

    add_child(title);

    font->set_size(45);

    Button *macauba = new Button(this, "macauba", 450, 100);

    if (macauba)
    {
        macauba->set_text("Macauba", Color::WHITE);
        macauba->set_color(Color(0, 0, 0, 128), Color(64, 64, 64, 128));
        macauba->set_border(1, Color(128, 128, 128, 128));
        macauba->align_to(this, Object::CENTER, Object::NONE);
        macauba->set_y(240);
        macauba->add_observer(this);
    }

    add_child(macauba);

    Button *litio = new Button(this, "litio", 450, 100);

    if (litio)
    {
        litio->set_text("Ciclo de Vida do Lítio", Color::WHITE);
        litio->set_color(Color(0, 0, 0, 128), Color(64, 64, 64, 128));
        litio->set_border(1, Color(128, 128, 128, 128));
        litio->align_to(this, Object::CENTER, Object::NONE);
        litio->set_y(360);
        litio->add_observer(this);
    }

    add_child(litio);

    Button *understand = new Button(this, "understand", 450, 100);

    if (understand)
    {
        understand->set_text("Entenda", Color::WHITE);
        understand->set_color(Color(0, 0, 0, 128), Color(64, 64, 64, 128));
        understand->set_border(1, Color(128, 128, 128, 128));
        understand->align_to(this, Object::CENTER, Object::NONE);
        understand->set_y(480);
        understand->add_observer(this);
    }

    add_child(understand);
    
    Button *back = new Button(this, "title", 450, 100);

    if (back)
    {
        back->set_text("Voltar", Color::WHITE);
        back->set_color(Color(0, 0, 0, 128), Color(64, 64, 64, 128));
        back->set_border(1, Color(128, 128, 128, 128));
        back->align_to(this, Object::CENTER, Object::NONE);
        back->set_y(600);
        back->add_observer(this);
    }

    add_child(back);
}

void
Start::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear();
}

bool
Start::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    set_next(object->id());
    finish();

    return true;
}
