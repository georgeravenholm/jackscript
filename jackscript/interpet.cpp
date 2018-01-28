#include "stdafx.h"
#include "interpet.h"

void JackScript::Step(bool debug)
{
	if (IP+1 > InstructionTable.size()) { complete = true; return; } // Do nothing if end of program
	std::string instruction = InstructionTable[IP];
	Execute(instruction); // execute instruction and then increment instruction pointer


	if (debug)
	{
		// Show the table of sgit
		int i = 0;
		for (auto data : DataTable)
		{
			std::cout << (i++ == DP ? "*" : "") << data << " ";
		}
	}
}

void JackScript::Execute(std::string instruction)
{
	if (instruction == INCP) // > 
	{
		DP++;
		IP++;
	}
	else if (instruction == DECP) // <
	{
		DP--;
		if (DP < 0)
		{
			std::cerr << "jackscript fatal error: data pointer below zero!" << std::endl;
			exit(20);
		}
		IP++;
	}
	else if (instruction == INC) // +
	{
		DataTable[DP]++;
		IP++;
	}
	else if (instruction == DEC) // -
	{
		DataTable[DP]--;
		IP++;
	}
	else if (instruction == OUT) // .
	{
		std::cout << (char) DataTable[DP]; // conv to char so we see the ASCII!
		IP++;
	}
	else if (instruction == IN) // ,
	{
		std::cin >> DataTable[DP];							// ALERT MAY BE VERY BIG BUGS HERE :^))))))
		IP++;
	}
	else if (instruction == LOOP) // [
	{
		if (DataTable[DP]==0) 
		{
			// find the next good bracket becuse skipe time
			int n = 0;
			std::string c;
			while (true)
			{
				c = InstructionTable[++IP];
				if ( c == "[")
				{
					n++;
					
				}
				else if (c == "]")
				{
					n--;
				}
				else if (n == 0)
				{
					IP++;
					return;
				}
			}
		}
		else
		{
			stack.Push(IP);
			IP++;
		}
	}
	else if (instruction == LOOPEND) // ]
	{
		if (DataTable[DP] != 0)
		{
			IP = stack.Pop();
		}
		else
		{
			IP++;
		}
	}
	else
	{
		// Error!
		error = "jackscript error: invalid command, you fool!";
	}
}



// The stack
void JackScript::Stack::Push(const int x)
{
	if (SP == 255)
	{
		std::cerr << "jackscript fatal error: stack overflow!" << std::endl;
		exit(10);
	}
	Array[SP++] = x;
}

int JackScript::Stack::Pop()
{
	if (SP == -1)
	{
		std::cerr << "jackscript fatal error: stack underflow!" << std::endl;
		exit(11);
	}
	return Array[--SP];
}

int JackScript::Stack::Peek()
{
	return Array[SP];
}
