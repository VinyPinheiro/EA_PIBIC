#ifndef FACTORY_COMPONENT_H
#define FACTORY_COMPONENT_H

#include <ijengine/core/object.h>

class FactoryComponent : public Object
{
public:
    FactoryComponent(Object *parent, ObjectID id, double x, double y) : Object(parent, id, x, y) {}
    virtual ~FactoryComponent() {}

    virtual void start() = 0;
    virtual bool stopped() const = 0;
};

#endif
