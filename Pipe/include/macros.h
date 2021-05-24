#pragma once

//----------
const int 
TEXTURE_SIZE = 64,
WINDOW_WIDTH = 640,
WINDOW_HEIGHT = 500,
NUMOFLEVELS = 3,
NUM_OF_TYPES = 6;

//----------
const char
RECEIVER = '1',
PUMPER = '2',
TWO_SIDES_PIPE = '3',
CORNER_PIPE = '4',
THREE_SIDES_PIPE = '5',
FOUR_SIDES_PIPE = '6',

LEFT = 'l',
RIGHT = 'r',
TOP = 't',
BOTTOM = 'b';

//----------
enum Rotate {
	ToLeft,
	ToRight,
};

//----------
enum PipeType {
	Pumper,
	Receiver,
	TwoSides,
	Corner,
	ThreeSides,
	FourSides,
};

//-----------------------------------------------
//we use this when we want to print the array
//we chech the char in the array and return the 
//type on ObjectType
PipeType char_to_type(char ch) {
	switch (ch) {
	case '1':
		return PipeType::Receiver;
	case '2':
		return PipeType::Pumper;
	case '3': // (Two Sides Pipe)
		return PipeType::TwoSides;
	case '4':
		return PipeType::Corner;
	case '5':
		return PipeType::ThreeSides;
	case '6':
		return PipeType::FourSides;
	}
}

