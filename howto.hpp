#include "cScreen.hpp"
#include <SFML/Graphics.hpp>

class howto : public cScreen{
private:

public:
	howto(void);
	virtual int Run(sf::RenderWindow &window);
};

howto::howto(void){

}

int howto::Run(sf::RenderWindow &window){

    sf::Font font;
    if (!font.loadFromFile("barn.otf")){
        //erro
    }

    sf::Text text;
    text.setFont(font);
    text.setString("HOW TO PLAY");
    text.setColor(sf::Color::Black);
    text.setPosition(sf::Vector2f(175,60));
    text.setCharacterSize(100);

    sf::Sprite background;
    sf::Texture texture;

    if(!texture.loadFromFile("fundo.bmp")){
        std::cout << "Error" << std::endl;
    }

    background.setTexture(texture);


    while (window.isOpen()){
        sf::Event event;
        // Checa os eventos em loop
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close(); 
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    return 0;
                }
            }
        }

        window.draw(background);
        window.draw(text);
        //window.clear(sf::Color::White);
        window.display();
    }
	return (-1);
}