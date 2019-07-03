#include "../inc/common.hpp"

#include "graphics/Graphics.hpp"
#include "input/Input.hpp"
#include "move/Move.hpp"
#include "object/Object.hpp"
#include "timeUtil/TimeUtil.hpp"
#include "mapEditor/MapEditor.hpp"

/*void createObjects();
void isWin();

void level1();*/

void setObjShapes();
void resetObjShapes();

Graphics graphics;
Input input;
Move move;
TimeUtil timer;
MapEditor map;

std::vector<Object> objects;
std::vector<sf::RectangleShape> objShapes;

int main() {
	objects.push_back(Object());

	while(graphics.isOpen()) {
		timer.setTime();

		input.events(
			graphics.getWindow()
		);

		if(input.getLeftMousePressed()) {
			//sf::Vector2f gridSize, bool isMousePressed
			map.setObjGrid(sf::Vector2f(32, 32), 1, graphics.getWindow());
			//std::string objType, sf::Vector2f objSize, sf::Vector2f objPos, sf::Color col, bool isColl, int objSpeed
			objects.push_back(Object("na", sf::Vector2f(32, 32), map.getObjPos(), sf::Color::Black, 1, 0));
		}

		move.resetCollide();
		move.collide(objShapes, 0);

		objects[0].setPosition(
			move.moveObject(input.getMoves(), objects[0].getSpeed(), timer.getTime(), objects[0].getShape())
		);

		resetObjShapes();

		//isWin();

		graphics.draw(sf::Color::White, objShapes);
	}

	return 0;
}

void setObjShapes() {
	for(int i = 0; i < objects.size(); i++) {
		objShapes.push_back(objects[i].getShape());
	}
}

void resetObjShapes() {
	objShapes.clear();
	setObjShapes();
}

/*void createObjects() {
	for(int i = 0; i < 10; i++) {
		objects.push_back(Object());
		objects[i].setPosition(sf::Vector2f(192, 32 * (i + 1)));
	}
}

void isWin() {
	if(move.isCollide(objects[0].getShape(), objects[objects.size() - 1].getShape()) == true) {
		objects[0].setPosition(sf::Vector2f(objects[30].getPosition().x + 32, objects[30].getPosition().y));
		std::cout << "Win!";
	}
}

void level1() {
	objects.clear();
	objShapes.clear();

	objects.push_back(Object());


	for(int i = 1; i < 11; i++) {
		objects.push_back(Object());
		objects[i].setPosition(sf::Vector2f(32 * i + 100, 128));
	}

	for(int i = 11; i < 22; i++) {
		objects.push_back(Object());
		objects[i].setPosition(sf::Vector2f(32 * (i - 10) + 100, 192));
	}

	for(int i = 22; i < 27; i++) {
		objects.push_back(Object());
		objects[i].setPosition(sf::Vector2f(384 + 100, -32 * (i - 21) + objects[21].getPosition().y + 32));
	}

	for(int i = 27; i < 30; i++) {
		objects.push_back(Object());
		objects[i].setPosition(sf::Vector2f(320 + 100, -32 * (i - 26) + objects[10].getPosition().y + 32));
	}

	objects.push_back(Object());
	objects[30].setPosition(sf::Vector2f(32 + 100, objects[1].getPosition().y + 32));

	objects.push_back(Object());
	objects[31].setPosition(sf::Vector2f(352 + 100, objects[29].getPosition().y));

	objects[0].setPosition(sf::Vector2f(objects[31].getPosition().x + 32, objects[31].getPosition().y));
}*/
