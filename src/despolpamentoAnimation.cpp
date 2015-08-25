#include "despolpamentoAnimation.h"
#include "global.h"
#include "cano.h"
#include <vector>

#include <ijengine/core/text.h>
#include <ijengine/core/animation.h>
#include <ijengine/core/font.h>
#include <ijengine/core/image.h>
#include <ijengine/core/environment.h>


DespolpamentoAnimation::DespolpamentoAnimation(const string& next)
    : Level("mudas", next)
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
    
    Cano *cano = new Cano(this, 0, 129, Cano::RETO);
    cano->fill();
    m_canos.push_back(cano);
    add_child(cano);

    cano = new Cano(this, 200, 102, Cano::RETO);
    m_canos.push_back(cano);
    add_child(cano);

    m_cano = 0;
}

void
DespolpamentoAnimation::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
}

void
DespolpamentoAnimation::update_self(unsigned long elapsed)
{
    if (m_canos[m_cano]->filled() and m_cano + 1 < (int) m_canos.size())
    {
        m_cano++;
        m_canos[m_cano]->fill();
    }

    m_canos[m_cano]->update(elapsed);
}
