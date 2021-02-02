// pixels.cpp: 
// using SFML to load a file, manipulate its pixels, write it to disk
// Fred Martin, fredm@cs.uml.edu, Sun Mar  2 15:57:08 2014

// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "LFSR.hpp"
#include <string>

using namespace std;
//PhotoMagic_0 input-file.png_1 output-file.png_2 seed_3 tap_pos_4
int main(int argc, char* argv[])
{
	sf::Image image;
	if (!image.loadFromFile(argv[1]))
		return -1;

	sf::Image output_image;
	if(!output_image.loadFromFile(argv[1]))
		return -1;

	// p is a pixel
	sf::Color p;
	LFSR borised(argv[3], atoi(argv[4]));
	
	for (int x = 0; x<1280; x++) {
		for (int y = 0; y< 720; y++) {
			p = image.getPixel(x, y);
			p.r = p.r ^ borised.generate(16);
			p.g = p.g ^ borised.generate(16);
			p.b = p.b ^ borised.generate(16);
			output_image.setPixel(x, y, p);
		}
	}

	sf::Vector2u size = image.getSize();
	sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input File");
	sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output File");
	sf::Texture texture;//----------input sprite----------
	texture.loadFromImage(image);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	//---------output sprite------------
	sf::Texture output_texture;
	output_texture.loadFromImage(output_image);

	sf::Sprite output_sprite;
	output_sprite.setTexture(output_texture);
	
	
	
/*	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
	}*/

	 while (window1.isOpen() && window2.isOpen()) {
		sf::Event event;
		 while (window1.pollEvent(event)) {
 			if (event.type == sf::Event::Closed)
 				window1.close();
 		}
		while (window2.pollEvent(event)) {
 			if (event.type == sf::Event::Closed)
 				window2.close();
 		}
 		window1.clear();
 		window1.draw(sprite );
 		window1.display();
 		window2.clear();
 		window2.draw(output_sprite);
 		window2.display();
 	}
	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!output_image.saveToFile(argv[2]))
		return -1;

	return 0;
}
