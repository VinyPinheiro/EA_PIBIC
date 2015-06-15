/*
 * Tela de animação do Adubo das Árvores.
 *
 * Autor: Camila Ferrer
 * Data: 15/06/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef ARVORES_H
#define ARVORES_H

#include <ijengine/core/level.h>
#include <ijengine/core/listener.h>

class Image;

class Arvores : public Level
{
public:
    Arvores(const string& next = "");

private:
    void draw_self();
    void update_self(unsigned long);

    Image *rs, *fertilizer, *pesticide, *h2o;
    unsigned long last;
    double rs_speed;
    double fertilizer_speed;
    double pesticide_speed;
    double h2o_speed;
};

#endif
