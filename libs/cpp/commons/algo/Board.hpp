/*
 * Board.hpp
 *
 *  Created on: Dec 8, 2011
 *      Author: issle
 */

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <vector>
#include <iostream>

using namespace std;

/**
 * This class represents a 2D general purpose gaming
 * board. The board exposes a 2D template matrix in
 * which pawns can be placed along with methods to
 * check for pawn existence in a line, row or in all
 * diagonals of a given point.
 */
template<typename T> class Board
{
private:
	vector<vector<T> > board;

	bool isInBounds(T var)
	{
		if (var < 0 || var >= board.size())
			return false;

		return true;
	}

	bool isInBounds(T x, T y)
	{
		if (!isInBounds(x) || isInBounds(y))
			return false;

		return true;
	}

public:
	Board(int size)
	{
		board.resize(size);

		for (int i = 0; i < size; i++)
			board[i].resize(size);
	}

	vector<vector<T> >& getBoard()
	{
		return board;
	}

	/*
	 * Checks if an item exists in this line.
	 */
	bool itemInLine(T x)
	{
		if (!isInBounds(x))
			return false;

		int size = board.size();

		for (int i = 0; i < size; i++)
		{
			if (board[x][i] != 0)
				return true;
		}
	}


	/*
	 * Checks if an item exists in this row.
	 */
	bool itemInRow(T y)
	{
		if (!isInBounds(y))
			return false;

		int size = board.size();

		for (int i = 0; i < size; i++)
		{
			if (board[i][y] != 0)
				return true;
		}
	}

	/*
	 * Checks if an item exists the diagonals
	 * arriving / departing from this point.
	 */
	bool itemInDiag(T x, T y)
	{

		int size = board.size();

		//Up and left.
		for (int i = x - 1; i >= 0; i--)
		{
			int _y = y - x + i;
			if (_y < 0)
				continue;
			if (board[i][_y] != 0)
				return true;
		}

		//Down left.
		for (int i = x - 1; i >= 0; i--)
		{
			int _y = y + x - i;
			if (_y >= size)
				continue;
			if (board[i][y + x - i] != 0)
				return true;
		}

		//Down right.
		for (int i = x + 1; i < size; i++)
		{
			int _y = y - x + i;
			if (_y >= size)
				continue;
			if (board[i][_y] != 0)
				return true;
		}

		//Up right.
		for (int i = x + 1; i < size; i++)
		{
			if (board[i][y + x - i] != 0)
			{
				int _y = y + x - i;
				if (_y < 0)
					continue;
				return true;
			}
		}
	}

};

#endif /* BOARD_HPP_ */
