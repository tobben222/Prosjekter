#include "include/systems/mouse_clicked.h"
#include "systems/pathfinding.h"

void MouseClicked::Clicked(anax::World &world, anax::Entity &player, sf::RenderWindow &window, sf::View cam)
{
    auto enteties = world.getEntities();
    PositionComponent& positionComponent = player.getComponent<PositionComponent>();
    SizeComponent& sizeComponent = player.getComponent<SizeComponent>();
    int reach = 50;
    sf::IntRect playerreach;
    playerreach.top = positionComponent.YPos - reach;
    playerreach.left = positionComponent.XPos -reach;
    playerreach.height = 2*reach + sizeComponent.SpriteWhith;
    playerreach.width = 2*reach + sizeComponent.SpriteHeight;
    sf::Vector2i mouse;
    mouse.x = sf::Mouse::getPosition(window).x;
    mouse.y = sf::Mouse::getPosition(window).y;
    sf::Vector2f mouseT = window.mapPixelToCoords(mouse, cam);
    //std::cout << "X: "<< mouseT.x <<"  Y:" <<mouseT.y << std::endl;
    for(auto i : enteties)
    {
        if(i.hasComponent<MousedOver>())
        {
            process(i,mouseT.x,mouseT.y, world,player, window, cam);
        }else
        {
            //Move player to mouse.x, mouse.y
            createPlayerPath(player, mouseT.x, mouseT.y);
        }
    }
}

void MouseClicked::createPlayerPath(anax::Entity player, float MouseX, float MouseY)
{
    PositionComponent positionComponent = player.getComponent<PositionComponent>();
    Moveble& moveble = player.getComponent<Moveble>();
    moveble.path = "";
    const int mapsize = 64;

    const int distaceX = (MouseX  - positionComponent.SpriteLeft)/10;
    const int distaceY = (MouseY  - positionComponent.SpriteTop)/10;

    std::string path= pathFind(mapsize/2,mapsize/2,mapsize/2 + distaceX,mapsize/2 + distaceY);
    moveble.path = path;
    std::cout << path << std::endl;
}
void MouseClicked::process(anax::Entity &e, float MouseX, float MouseY, anax::World &world, anax::Entity player,
                           sf::RenderWindow &window, sf::View cam)
{
    PositionComponent& positionComponent = e.getComponent<PositionComponent>();
    SizeComponent& sizeComponent = e.getComponent<SizeComponent>();
    sf::IntRect entityRect;
    entityRect.top = positionComponent.SpriteTop;
    entityRect.left = positionComponent.SpriteLeft;
    entityRect.width = sizeComponent.SpriteWhith;
    entityRect.height = sizeComponent.SpriteHeight;
    if(entityRect.contains(MouseX,MouseY))
    {
        if(e.hasComponent<Talkative>())
        {
            std::cout << e.getId() << std::endl;
            Talk talk;
            talk.talk(e,window);
        }

        if(e.hasComponent<Looteble>())
        {
            Loot loot;
            loot.loot(world,e, player);
        }
    }
}