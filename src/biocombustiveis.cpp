#include "biocombustiveis.h"
#include "global.h"

#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>

#include <ijengine/util/button.h>

Biocombustiveis::Biocombustiveis(const string& next)
    : Level("biocombustiveisAnimation", next)
{
    Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(90);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);

    Image *image = new Image(this, "res/images/background_biocombustiveis.png");
    add_child(image);

    Text *title = new Text(this, "Biocombustíveis", Color::BLACK);

    if (title)
    {
        title->align_to(this, Object::CENTER, Object::NONE);
        title->set_y(40);
    }

    add_child(title);

    font->set_style(Font::NORMAL);
    font->set_size(50);

    Text *question = new Text(this, "Qual biocombustível deseja produzir?", Color::BLACK);

    if (question)
    {
        question->align_to(this, Object::CENTER, Object::NONE);
        question->set_y(title->y() + title->h() + 50);
    }

    add_child(question);
	
	font->set_style(Font::NORMAL);
    font->set_size(30);
	
    Button *biodiesel = new Button(this, "biodieselAnimation", 250, 100);

    if (biodiesel)
    {
        biodiesel->set_text("Biodiesel", Color::BLACK);
        biodiesel->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        biodiesel->set_border(5, Color(0, 0, 0, 128));
        biodiesel->align_to(this, Object::CENTER, Object::NONE);
        biodiesel->set_y(question->y() + question->h() + 40);
        biodiesel->add_observer(this);
    }

    add_child(biodiesel);

    Button *bioquerosene = new Button(this, "bioqueroseneAnimation", 250, 100);

    if (bioquerosene)
    {
        bioquerosene->set_text("Bioquerosene", Color::BLACK);
        bioquerosene->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        bioquerosene->set_border(5, Color(0, 0, 0, 128));
        bioquerosene->align_to(this, Object::CENTER, Object::NONE);
        bioquerosene->set_y(biodiesel->y() + biodiesel->h() + 20);
        bioquerosene->add_observer(this);
    }

    add_child(bioquerosene);
    
    Button *biooleo = new Button(this, "biooleoAnimation", 250, 100);

    if (bioquerosene)
    {
        biooleo->set_text("Bio Óleo", Color::BLACK);
        biooleo->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
        biooleo->set_border(5, Color(0, 0, 0, 128));
        biooleo->align_to(this, Object::CENTER, Object::NONE);
        biooleo->set_y(bioquerosene->y() + bioquerosene->h() + 20);
        biooleo->add_observer(this);
    }

    add_child(biooleo);
}

void
Biocombustiveis::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

bool
Biocombustiveis::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    set_next(object->id());
    finish();

    return true;
}
