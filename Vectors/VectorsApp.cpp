#include "VectorsApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vector2.h"

VectorsApp::VectorsApp()
{
}

VectorsApp::~VectorsApp()
{
}

bool VectorsApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void VectorsApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void VectorsApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void VectorsApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	Vector2 lineStart = { 300, 300 };
	Vector2 lineDirection = { 300, 100 };
	Vector2 lineEnd = lineStart + lineDirection;
	m_2dRenderer->drawLine(lineStart.x, lineStart.y, lineEnd.x, lineEnd.y);

	// draw a circle
	Vector2 circleCentre = { 100, 100 };
	float circleRadius = 50;
	m_2dRenderer->drawCircle(circleCentre.x, circleCentre.y, circleRadius);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}