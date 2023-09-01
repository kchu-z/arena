#include <Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Cube");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        // Draw the cube
        sf::RectangleShape frontFace(sf::Vector2f(100, 100));
        frontFace.setFillColor(sf::Color::Red);
        frontFace.setPosition(150, 150);
        window.draw(frontFace);

        sf::RectangleShape topFace(sf::Vector2f(100, 100));
        topFace.setFillColor(sf::Color::Blue);
        topFace.setPosition(150, 50);
        window.draw(topFace);

        sf::RectangleShape bottomFace(sf::Vector2f(100, 100));
        bottomFace.setFillColor(sf::Color::Yellow);
        bottomFace.setPosition(150, 250);
        window.draw(bottomFace);

        window.display();
    }

    return 0;
}
