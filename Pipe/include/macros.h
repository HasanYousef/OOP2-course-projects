#pragma once

//----------
const int 
TEXTURE_SIZE = 32,
WINDOW_WIDTH = 640,
WINDOW_HEIGHT = 500,
NUMOFLEVELS = 3,
NUM_OF_TYPES = 10;

//----------
const char 
BOWPIPE = '1',
RECEIVER = '2',
PUMPER = '3',
THREESIDESPIPE = '4', 
TWOSIDESPIPE = '5',
L = 'l',
U = 'u',
D = 'd',
R = 'r';

//----------
enum Rotate {
	Left, Right
};

//----------
enum PipeType {
	BowP,
	ThreeSidesP,
	TwoSidesP,
	PumperP,
	ReceiverP
};

//-----------------------------------------------
//we use this when we want to print the array
//we chech the char in the array and return the 
//type on ObjectType
PipeType char_to_type(char ch) {
	switch (ch) {
	case BOWPIPE:
		return PipeType::BowPipe;
	case RECEIVER:
		return PipeType::Receiver;
	case PUMPER:
		return PipeType::Pumper;
	case THREESIDESPIPE:
		return PipeType::ThreeSidesPipe;
	case TWOSIDESPIPE:
		return PipeType::TwoSidesPipe;
	}
	return PipeType::BowPipe;
}

