#include "stdafx.h"
#include "interpet.h"

#include <assert.h> 

void JackScript::Step(bool debug)
{
	if (IP+1 > InstructionTable.size()) { complete = true; return; } // Do nothing if end of program
	std::string instruction = InstructionTable[IP];
	Execute(instruction); // execute instruction and then increment instruction pointer


	if (debug)
	{
		// Show the table of sgit
		/*int i = 0;
		for (auto data : DataTable)
		{
			std::cout << (i++ == DP ? "*" : "") << data << " ";
		}*/
		std::cout << "IP=" << IP << "\tCurrent Data: " << DataTable[DP] << std::endl;
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
		//if (DP > DataTable.size()) DataTable.resize(DataTable.size()*2,0);
		DataTable[DP]++;
		IP++;
	}
	else if (instruction == DEC) // -
	{
		assert(DP>=0);
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
			int n = 1;
			std::string c;
			while (true)
			{
				c = InstructionTable[++IP];
				if ( c == LOOP)
				{
					n++;
					
				}
				else if (c == LOOPEND) 
				{
					n--;
					if (n == 0) { IP++; return; };
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
			IP = stack.Pop();
			//IP++;
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
