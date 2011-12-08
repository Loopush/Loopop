/*
 * Queens.hpp
 *
 *  Created on: Dec 4, 2011
 *      Author: issle
 */

#ifndef QUEENS_HPP_
#define QUEENS_HPP_

#include "../Backtracking.hpp"
#include "../../commons/benchmark/TimeBench.hpp"
#include "../../commons/algo/Board.hpp"

typedef Board<int> IntBoard;

using namespace std;

class Env: public AbstractEnv,public IntBoard
{
public:
	int queensRemaining;


	Env(int size):IntBoard(size)
	{
		queensRemaining = size;

	}

	bool isSolved()
	{
		if(queensRemaining == 0)
		{
			cout << "Placed all queens." << endl;
			return true;
		}

		return false;
	}

	void print()
	{
		int size = getBoard().size();
		for(int i = 0; i < size; i++)
		{
			for(int j =0; j < size; j++)
			{
				cout << getBoard()[i][j]<< " ";
			}
			cout << endl;
		}
	}

};

typedef AbstractActionT<Env*> AbstractAction;

class Place: public AbstractAction
{
public:
	int x;
	int y;

	Place(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	bool doAction(AbstractAction::EnvType env)
	{
		if(x == -1 && y == -1)
			return true;

		if(env->itemInLine(x) || env->itemInRow(y) || env->itemInDiag(x,y))
			return false;

		env->getBoard()[x][y] = 1;


		env->queensRemaining--;

		return true;

	}

	void undoAction(AbstractAction::EnvType env)
	{
		env->getBoard()[x][y]=0;
		env->queensRemaining++;
	}

};

typedef Processor<Env*,AbstractAction*> Proc;

int main(void) {

	TimeBench* tb = new TimeBench();

	int size = 8;

	cout<< "Enter the size of the board: ";
	cin >> size;
	cout << endl;

	Proc* proc = new Proc();

	Env* env = new Env(size);

	for(int i =0; i < size; i++)
		for(int j = 0; j < size; j++)
			proc->actions.push_back(new Place(i,j));

	tb->openProbe("Computation delay");
	if(proc->proccess(env,new Place(-1,-1)) == false)
	{
		cout <<"Could not solve the problem. "<< endl;
	}

	env->print();

	tb->closeProbe("Computation delay");
	tb->printProbe("Computation delay");

	delete tb;

	return EXIT_SUCCESS;
}

#endif /* QUEENS_HPP_ */
