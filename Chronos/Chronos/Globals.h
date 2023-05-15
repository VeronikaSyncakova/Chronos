#pragma once
#include "SFML/Graphics.hpp"

enum class GameMode
{ //game modes 
	None,
	Splash,
	Menu,
	Instructions,
	End,
	Present,
	PuzzleOne,
	PuzzleTwo,
	PuzzleThree,
	FinalPuzzle,
};

 //the side of screen
const int TOP = 0;
const int BOTTOM = 1;
const int RIGHT = 2;
const int LEFT = 3;


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600; 

const int MAX_PORTALS = 4;
const int MAX_DOORS = 3;

extern int e_doorLocked; //0 locked, 1 unlocked
extern int e_portalUsed; //0 false, 1 true