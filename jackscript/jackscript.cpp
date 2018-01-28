// jackify.cpp : Defines the entry point for the console application.
// Interpets JackScript code

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#define INCP	"jack" // >
#define DECP	"Jack" // <
#define INC		"jAck" // +
#define DEC		"jAcK" // -

#define OUT		"jACK" // . (output char)
#define IN		"JACk" // , (accept 1 char)

#define LOOP	"JAck" // [
#define LOOPEND	"jaCK" // ]

void generateInstructionTable( std::ifstream & dafile , std::vector<std::string> & output ) // Takes file stream and reference of an output vector !!! Warning it does frick up the file stream exdee
{
	char byte;
	std::string instruction;
	while ( dafile.get(byte) ) // for all of the valid sgits
	{
		switch (byte)
		{
		case 13:
		case 32: // spaces and newlines
		case 10:

			if (instruction == "") continue;
			else { output.push_back(instruction); instruction = ""; } // if we hit a space and theres sgit stored, put into instruktion tabelee

			break;

		default:
			instruction += byte; // Append character to current instruction buffer
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		std::ifstream jackscriptFile(argv[1], std::ios::binary); // load file

		if (!jackscriptFile.good() || !jackscriptFile.is_open()) { std::cerr << "error: file error" << std::endl; return 2; } // catch missing files

		// Assume file is ready!
		std::vector<std::string> Instructions;
		generateInstructionTable(jackscriptFile, Instructions); // "explode"

		//Teste
		int i = 0;
		for (auto & meme : Instructions)
		{
			std::cout << ++i << "\t" << meme << std::endl;
		}

		return 0;
	}
	else
	{
		std::cerr << "usage: jackscript <filepath>" << std::endl;
		return 1;
	}

	return -1; // this shouldnt happen dude
}

