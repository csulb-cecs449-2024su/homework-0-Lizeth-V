#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

/*
This program is a template for an SFML project using CMake and Vcpkg. 
You can duplicate the folder containing this project to easily set up a new 
SFML program. 
Just delete the "out" folder in the new project , or else you might get CMake errors.
*/

void drawPixel(sf::RenderWindow& window, sf::Vector2i position, sf::Color color) {
	std::array<sf::Vertex, 1> pixel = {
		sf::Vertex(sf::Vector2f(position.x, position.y), color)
	};
	window.draw(pixel.data(), 1, sf::Points);
}

int main() {
    // VideoMode -> changes the window size width x height
	sf::RenderWindow window{ sf::VideoMode{1000, 1000}, "SFML Demo" };
	sf::Clock c;
	auto last = c.getElapsedTime();

	while (window.isOpen()) {
		sf::Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();

		auto now = c.getElapsedTime();
		auto diff = now - last;
		last = now;
		std::cout << 1 / diff.asSeconds() << " FPS " << std::endl;

		/*
		* DRAWING GOES HERE.
		*/
        //   x,y corresponds to the origin of the line being draw
        //   Color changes color :0 much wow
		for (auto x = 100; x < 500; x++) {
			auto y = static_cast<int32_t>(2.0 / 3.0 * x + 40);
			drawPixel(window, sf::Vector2i(x, y), sf::Color::Magenta);
		}


		window.display();
	}

	return 0;
}


