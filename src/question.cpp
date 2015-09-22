#include "question.h"

#include <ijengine/core/object.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/text.h>
#include <ijengine/core/font.h>

Question::Question(const string text, int posy, int size, Object *parent, double x, double y)
		:Object(parent, "question", x, y)
{
	Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(size);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);

	question = new Text(this, text, Color::BLACK);

    if (question)
    {
        question->align_to(this, Object::CENTER, Object::NONE);
        question->set_y(posy);
    }
}
void
Question::setY(int y)
{
	question->set_y(y);
}

void
Question::start()
{
	m_working = true;
}


bool
Question::stopped() const
{
	return not m_working;
}

void
Question::update_self(unsigned long )
{
}


Question::~Question(){}
