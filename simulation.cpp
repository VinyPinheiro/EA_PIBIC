#include "simulation.h"
#include "layer.h"
#include "bg.h"

Simulation::Simulation(Video *video)
    : m_video(video), m_done(false)
{
    Layer *top = new Layer(video, 0, 20, 1200, 260, Color::YELLOW);
    Layer *middle = new Layer(video, 0, 280, 1200, 260, Color::GREEN);
    Layer *bottom = new Layer(video, 0, 540, 1200, 260, Color::BLUE);

    Bg *mina = new Bg(video, "imgs/mina.png");

    mina->set_position(0, 164);
    top->add_children(mina);
    
    m_objs.push_back(top);
    m_objs.push_back(middle);
    m_objs.push_back(bottom);
}

Simulation::~Simulation()
{
    for (auto obj : m_objs)
        delete obj;
}

bool
Simulation::process_event(vector<SDL_Event>& events)
{
    return false;
}

void
Simulation::draw(int x, int y)
{
    for (auto obj : m_objs)
        obj->draw();
}

void
Simulation::update(Uint32 now)
{
}

void
Simulation::setDone(bool done)
{
}

void
Simulation::setNext(Level * n)
{
}


bool
Simulation::getDone() const
{
    return m_done;
}

Level *
Simulation::getNext() const
{
    return nullptr;
}

