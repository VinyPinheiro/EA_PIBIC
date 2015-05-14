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

#include <cstdio>
using namespace std;

TitleScreen::TitleScreen()
    : Level("title")
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    Image *image = new Image(this, "res/images/earth.png");

printf("Image antes = (%.1f, %.1f), %.1fx%.1f\n", image->x(), image->y(), image->w(), image->h());

    if (image)
    {
        image->align_to(this, Object::CENTER, Object::MIDDLE);
printf("Image depois = (%.1f, %.1f), %.1fx%.1f\n", image->x(), image->y(), image->w(), image->h());
    }

    add_child(image);

/*    double w = env->canvas->w();
    double h = env->canvas->h();

    double bw = 100;
    double bh = 50;

    double bx = (w - bw)/2;
    double by = h/2;

    Button *ok = new Button(this, "ok", bx, by, bw, bh);
    Button *exit = new Button(this, "exit", bx, by + bh + 20, bw, bh,
        Color::RED);

    ok->add_observer(this);
    exit->add_observer(this);

    add_child(ok);
    add_child(exit);
*/
}

TitleScreen::~TitleScreen()
{
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
/*    if (id != Button::clickedID)
    {
        return false;
    }

    Button *button = dynamic_cast<Button *>(object);

    if (not button)
    {
        return false;
    }

    if (button->id() == "ok")
    {
        set_next("stage1");
    }

    finish();
*/
    return true;
}
