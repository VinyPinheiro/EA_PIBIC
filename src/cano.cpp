#include "cano.h"

Cano::Cano(Object *parent, double x, double y, Tipo tipo)
    : FactoryComponent(parent, "cano", x, y)
{
    switch (tipo) {
    case RETO1:
        m_animation = new Animation("res/images/cano_reto_tipo_1.png", 0, 0, 80, 40, 6, 150);
        break;
        
    case RETO2:
        m_animation = new Animation("res/images/cano_reto_tipo_2.png", 0, 0, 80, 40, 6, 150);
        break;
    
    case RETO3:
        m_animation = new Animation("res/images/cano_reto_tipo_3.png", 0, 0, 40, 80, 6, 150);
        break;
    
    case RETO4:
        m_animation = new Animation("res/images/cano_reto_tipo_4.png", 0, 0, 40, 80, 6, 150);
        break;
    
    case CURVO1:
        m_animation = new Animation("res/images/cano_curvo_tipo_1.png", 0, 0, 80, 80, 5, 150);
        break;
        
    case CURVO2:
        m_animation = new Animation("res/images/cano_curvo_tipo_2.png", 0, 0, 80, 80, 5, 150);
        break;
	
	case CURVO3:
        m_animation = new Animation("res/images/cano_curvo_tipo_3.png", 0, 0, 80, 80, 5, 150);
        break;
     
    case CURVO4:
        m_animation = new Animation("res/images/cano_curvo_tipo_4.png", 0, 0, 80, 80, 5, 150);
        break;
	
	case CURVO5:
        m_animation = new Animation("res/images/cano_curvo_tipo_5.png", 0, 0, 80, 80, 5, 150);
        break;
	
	case CURVO6:
        m_animation = new Animation("res/images/cano_curvo_tipo_6.png", 0, 0, 80, 80, 5, 150);
        break;
	
	case CURVO7:
        m_animation = new Animation("res/images/cano_curvo_tipo_7.png", 0, 0, 80, 80, 5, 150);
        break;
	
	case CURVO8:
        m_animation = new Animation("res/images/cano_curvo_tipo_8.png", 0, 0, 80, 80, 5, 150);
        break;
	
	case T:
        m_animation = new Animation("res/images/cano_T.png", 0, 0, 80, 80, 5, 150);
        break;
	
    default:
        m_animation = nullptr;
    }

    m_filling = false;
}

void
Cano::start()
{
    m_filling = true;
}

void
Cano::update_self(unsigned long elapsed)
{
    if (m_filling and m_animation)
    {
        m_animation->update(elapsed);
    }
}

void
Cano::draw_self()
{
    if (m_animation)
    {
        m_animation->draw(x(), y());
    }
}

bool
Cano::stopped() const
{
    return m_animation && m_animation->is_done();
}
