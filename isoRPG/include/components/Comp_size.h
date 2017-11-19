#ifndef ISORPG_COMP_SIZE_H
#define ISORPG_COMP_SIZE_H

#include <anax/Component.hpp>

#include "states/state_base.h"

struct SizeComponent : public anax::Component
{
public:
    float Width;
    float Height;
};
#endif //ISORPG_COMP_SIZE_H
