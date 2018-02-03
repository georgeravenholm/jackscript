#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stack>

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
	JackScript(const std::vector<std::string> & instructions) // constructor
	{
		InstructionTable = instructions;

		DataTable.resize(30000, 0); // make sure we actually have sgit in da vektore leole
	}

	void Step(bool debug);

	bool complete = false;
private:
	std::vector<std::string>	InstructionTable;
	std::vector<int>			DataTable;
	int IP = 0; // instruction pointer
	int DP = 0; // data pointer

	// Stack for loops
	/*struct Stack
	{
		int SP = 0;
		int Array[255];

		void Push(const int x);
		int Pop();
		int Peek();
	};
	Stack stack;*/
	std::stack<int> stack; // std stack 

	std::string error;

	// Functions
	void Execute(std::string instruction);
};