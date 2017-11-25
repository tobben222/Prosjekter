
#ifndef ISORPG_MOUSE_CLICKED_H
#define ISORPG_MOUSE_CLICKED_H

#include <anax/System.hpp>
#include <states/state_base.h>


#include <include/components/Comp_size.h>
#include <include/components/Comp_mousedOver.h>
#include <components/Comp_position.h>
#include <iostream>
#include <include/components/Comp_looteble.h>
#include <include/components/Comp_talk.h>
#include <include/components/Comp_moveble.h>
#include "loot.h"
#include "talk.h"


struct MouseClicked : anax::System<anax::Requires<PositionComponent, SizeComponent, MousedOver>>
{
public:
    void Clicked(anax::World& world, anax::Entity& player, sf::RenderWindow& window, sf::View cam);
private:
    void process(anax::Entity& e, float MouseX, float MouseY, anax::World& world, anax::Entity player, sf::RenderWindow& window, sf::View cam);
    void createPlayerPath(anax::Entity player, float MouseX, float MouseY);
};

#endif //ISORPG_MOUSE_CLICKED_H
