#include "question.h"

#include <ijengine/core/object.h>
#include <ijengine/core/environment.h>
#include <ijengine/core/text.h>
#include <ijengine/core/font.h>
#include <ijengine/core/texture.h>
#include <ijengine/util/button.h>
#include <ijengine/core/level.h>

#include <sstream>
#include <iostream>

using namespace std;

Question::Question(Object *parent, const string& title, const string& text,
    const vector<pair<string, string> >& buttons)
    : Level(parent->id(), "question"), m_waiting(true), m_answer(UNKNOWN)
	
{
    const double posy = 40;
    const double size[] = {80,40};

	Environment *env = Environment::get_instance();
    set_dimensions(env->canvas->w(), env->canvas->h());

    shared_ptr<Font> font =
        env->resources_manager->get_font("res/fonts/AjarSans-Regular.ttf");
    font->set_size(size[0]);
    font->set_style(Font::BOLD);
    env->canvas->set_font(font);

    auto lines = split(title);

    double y = posy;
    const double space = 5;

    for (auto line : lines)
    {
	    Text *m_title = new Text(this, line, Color::BLACK);

        if (m_title)
        {
            m_title->align_to(this, Object::CENTER, Object::NONE);
            m_title->set_y(y);
            add_child(m_title);
            y += m_title->h() + space;
        }
   }
	
	font->set_style(Font::NORMAL);
	font->set_size(size[1]);

	Text *m_text = new Text(this, text, Color::BLACK);
	m_text->align_to(this,Object::CENTER, Object::NONE);
	m_text->set_y(y);
	add_child(m_text);
	y += m_text->h() + space;

	for(unsigned int i = 0; i < buttons.size(); i++)
	{
		Button *bt = new Button(this, buttons[i].second, 330, 100);

    	if (bt)
    	{
    	    bt->set_text(buttons[i].first, Color::BLACK);
    	    bt->set_color(Color(20, 180, 55, 128), Color(20, 55, 128, 128));
    	    bt->set_border(5, Color(0, 0, 0, 128));
    	    bt->align_to(this, Object::CENTER, Object::NONE);
    	    bt->set_y(y);
		  	bt->add_observer(this);
    	}
		y += bt->h() + space;
    	add_child(bt);
	}
}

void
Question::update_self(unsigned long )
{
}    

Question::Answer
Question::answer() const
{
    return m_answer;
}

bool
Question::waiting() const
{
    return m_waiting;
}

vector<string>
Question::split(const string& text) const
{
    istringstream is(text);

	Environment *env = Environment::get_instance();
    double maxw = w() * 0.8;

    ostringstream os;
    bool first = true;
    vector<string> lines;
    string line = "";
    string word;

    while (is >> word)
    {
        if (not first)
            os << " ";

        os << word;

        Texture *texture = env->canvas->render_text(os.str(), Color::BLACK);

        if (texture->w() < maxw)
        {
            line = os.str();
        } else
        {
            lines.push_back(line);
            line = "";
            os.str("");
            os << word;
        }

        delete texture;

        if (first)
            first = false;
    }     

    if (line.size() > 0)
    {
        lines.push_back(line);
    }

    return lines;
}

bool
Question::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }
    id_button_click = object->id();
	this->finish();
    return true;
}

ObjectID
Question::next()
{
	return id_button_click;
}
