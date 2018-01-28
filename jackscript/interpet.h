#pragma once

#include <string>
#include <vector>
#include <iostream>

class JackScript
{
#define INCP	"jack" // >
#define DECP	"Jack" // <
#define INC		"jAck" // +
#define DEC		"jAcK" // -

#define OUT		"jACK" // . (output char)
#define IN		"JACk" // , (accept 1 char)

#define LOOP	"JAck" // [
#define LOOPEND	"jaCK" // ]

public:
	JackScript(std::vector<std::string> instructions) // constructor
	{
		InstructionTable = instructions;
	}
private:
	std::vector<std::string>	InstructionTable;
	std::vector<int>			DataTable;
	int IP = 0; // instruction pointer
	int DP = 0; // data pointer

	// Stack for loops
	struct Stack
	{
		int SP = 0;
		int Stack[255];
	};

	std::string error;
};