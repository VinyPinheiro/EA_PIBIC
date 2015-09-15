#include "prensagem_polpa.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Prensagem_Polpa::Prensagem_Polpa(const string& next)
    : Level("despolpamentoAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(90);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);
    
    Image *image = new Image(this, "res/images/background_despolpa_fase1.png");
    add_child(image);

    Text *title = new Text(this, "Despolpa", Color::BLACK);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::NONE);
        title->set_y(40);
    }

    add_child(title);

    font->set_style(Font::NORMAL);
    font->set_size(50);

    Text *question1 = new Text(this, "Prensar polpa", Color::BLACK);
    Text *question2 = new Text(this, "da Macaúba?", Color::BLACK);

    if (question1)
    {
        question1->align_to(this, Object::CENTER, Object::NONE);
        question1->set_y(title->y() + title->h() + 50);
    }

    add_child(question1);

    if (question2)
    {
        question2->align_to(this, Object::CENTER, Object::NONE);
        question2->set_y(question1->y() + question1->h() + 50);
    }

    add_child(question2);

    Button *yes = new Button(this, "prensagem_polpaAnimation", 200, 100);

    if (yes)
    {
        yes->set_text("Sim", Color::BLACK);
        yes->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        yes->set_border(5, Color(0, 0, 0, 128));
        yes->align_to(this, Object::CENTER, Object::NONE);
        yes->set_y(question2->y() + question2->h() + 40);
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
Prensagem_Polpa::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

bool
Prensagem_Polpa::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    set_next(object->id());
    finish();

    return true;
}
