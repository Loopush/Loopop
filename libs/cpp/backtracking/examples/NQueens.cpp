/*
 * Queens.hpp
 *
 *  Created on: Dec 4, 2011
 *      Author: issle
 */

#ifndef QUEENS_HPP_
#define QUEENS_HPP_

#include "../Backtracking.hpp"

using namespace std;

class Env
{
public:
	int queensRemaining;

	int boardSize;

	vector<vector<int> > board;

	Env()
	{
		queensRemaining = 8;

		boardSize = 8;

		board.resize(boardSize);

		for(int i =0; i < boardSize; i++)
			board[i].resize(boardSize);
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
		for(int i = 0; i < 8; i++)
		{
			for(int j =0; j < 8; j++)
			{
				cout << board[i][j]<< " ";
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
		int size = env->boardSize;
		for(int i =0; i < size; i++)
		{
			if(env->board[x][i] != 0)
				return false;
		}

		for(int i =0; i < size; i++)
		{
			if(env->board[i][y] != 0)
				return false;
		}

		//Up and left.
		for(int i = x-1; i >=0; i--)
		{
			int _y = y -x +i;
			if(_y< 0)
				continue;
			if(env->board[i][_y]!=0)
				return false;
		}

		//Down left.
		for(int i = x-1; i >=0; i--)
		{
			int _y = y + x -i;
			if(_y >= 8)
				continue;
			if(env->board[i][y+x-i]!=0)
				return false;
		}


		//Down right.
		for(int i = x+1; i < size; i++)
		{
			int _y = y -x+i;
			if(_y >=8)
				continue;
			if(env->board[i][_y]!=0)
				return false;
		}


		//Up right.
		for(int i = x+1; i < size; i++)
		{
			if(env->board[i][y+x-i]!=0)
			{
				int _y = y + x - i;
				if(_y < 0)
					continue;
				return false;
			}
		}

		env->board[x][y] = 1;


		env->queensRemaining--;

		return true;

	}

	void undoAction(AbstractAction::EnvType env)
	{
		env->board[x][y]=0;
		env->queensRemaining++;
	}

};

typedef Proccessor<Env*,AbstractAction*> Proc;

int main(void) {

	Proc* proc = new Proc();

	Env* env = new Env();

	for(int i =0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			proc->actions.push_back(new Place(i,j));

	if(proc->proccess(env,new Place(0,0)) == false)
	{
		cout <<"Could not solve the problem. "<< endl;
	}


	env->print();
	return EXIT_SUCCESS;
}

#endif /* QUEENS_HPP_ */
