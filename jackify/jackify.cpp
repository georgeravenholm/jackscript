// jackify.cpp : Defines the entry point for the console application.
// Converts brainfuck into Jackscript

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#define INCP	62 // >
#define DECP	60 // <
#define INC		43 // +
#define DEC		45 // -

#define OUT		46 // . (output char)
#define IN		44 // , (accept 1 char)

#define LOOP	91 // [
#define LOOPEND	93 // ]

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		std::ifstream brainfuckFile( argv[1] , std::ios::binary ); // load file
		if (!brainfuckFile.good() || !brainfuckFile.is_open()) { std::cerr << "error: file error" << std::endl; return 2; } // catch missing files

		char byte;
		while (brainfuckFile.get(byte)) // for all of the valid sgits
		{
			switch (byte)
			{
			case 13:
			case 32: // spaces and newlines
			case 10:
				continue;
				break;

			case INCP:
				std::cout << "jack";
				break;

			case DECP:
				std::cout << "Jack";
				break;

			case INC:
				std::cout << "jAck";
				break;

			case DEC:
				std::cout << "jAcK";
				break;

			case LOOP:
				std::cout << "JAck";
				break;

			case LOOPEND:
				std::cout << "jaCK";
				break;

			case OUT:
				std::cout << "jACK";
				break;

			case IN:
				std::cout << "JACk";
				break;

			default:
				std::cerr << "error: bad character" << std::endl;
				return 3;
				break;
			}
			std::cout << " "; // add a space
		}
		return 0;
	}
	else
	{
		std::cerr << "usage: jackify <filepath>" << std::endl;
		return 1;
	}

	return -1; // this shouldnt happen dude
}

