#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Azenith", sf::Style::Close | sf::Style::Resize);
    //Intialize Block - loading in Textures
    //Collision Test 
    sf::RectangleShape colrect(sf::Vector2f(100.f, 100.f));
    sf::Texture colrecttexture;
    colrecttexture.loadFromFile("Images/Tree.png");
    colrect.setTexture(&colrecttexture);
    colrect.setPosition(sf::Vector2f(300, 100));
   
    //Boundbox check (To be finished)
    //Background 
    sf::RectangleShape background1(sf::Vector2f(1000.f, 700.f));
    sf::Texture background1texture;
    background1texture.loadFromFile("Images/grassbackground.png");
    background1.setTexture(&background1texture);


    
    //Player
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    playerTexture.loadFromFile("Images/playermovementsheet.png");
    playerSprite.setTexture(playerTexture);

    
    //X, Y, Width, Height
    //width and height of rectangle object being used is 103 and 116.5 
    int XIndex = 0;
    int YIndex = 0;
    playerSprite.setTextureRect(sf::IntRect(XIndex * 103,YIndex * 116.5,103, 116.5)); 


    //Enemies 
    sf::Texture enemyTexture;
    sf::Sprite enemy1sprite;
    enemyTexture.loadFromFile("Images/enemy1.png");
    enemy1sprite.setTexture(enemyTexture);
    enemy1sprite.setOrigin(67, 67.5);
    enemy1sprite.setPosition(500, 350);
   
    std::cout << "Move player with W,A,S,D" << std::endl;
   
    //Game Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
       
        //get player position
        sf::Vector2f position = playerSprite.getPosition();
       
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

            int XIndex = 0;
            int YIndex = 2;
            playerSprite.setTextureRect(sf::IntRect(XIndex * 103, YIndex * 116.5, 103, 116.5));
            playerSprite.setPosition(position + sf::Vector2f(0.5, 0));

        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            int XIndex = 0;
            int YIndex = 1;
            playerSprite.setTextureRect(sf::IntRect(XIndex * 103, YIndex * 116.5, 103, 116.5));
            playerSprite.setPosition(position + sf::Vector2f(-0.5, 0));

        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            int XIndex = 4;
            int YIndex = 3;
            playerSprite.setTextureRect(sf::IntRect(XIndex * 103, YIndex * 116.5, 103, 116.5));
            playerSprite.setPosition(position + sf::Vector2f(0, -0.5));

        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            int XIndex = 0;
            int YIndex = 0;
            playerSprite.setTextureRect(sf::IntRect(XIndex * 103, YIndex * 116.5, 103, 116.5));
            playerSprite.setPosition(position + sf::Vector2f(0, 0.5));

        }
       

       //Collision Tests
        if (playerSprite.getGlobalBounds().intersects(colrect.getGlobalBounds())) 
        {
            playerSprite.setPosition(position);  
            

        } 
    
        
        
        
            
        
        
        
           
        






        window.clear();
        //Draw block     
        window.draw(background1);
        window.draw(colrect);
        window.draw(playerSprite);
        window.draw(enemy1sprite);
        //Draw Block
        window.display();
    }

    return 0;
}