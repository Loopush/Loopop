/*
 * Backtracking.hpp
 *
 *  Created on: Dec 4, 2011
 *      Author: issle
 */

#ifndef BACKTRACKING_HPP_
#define BACKTRACKING_HPP_

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template < class Env > class AbstractActionT
{
public:
	typedef Env EnvType;
	virtual bool doAction(EnvType env) = 0;
	virtual void undoAction(EnvType env) = 0;
};

class AbstractEnv
{
public:
	virtual void isSolved() = 0;
};

template<class Env, class AbstractAction> class Proccessor
{
public:
	vector<AbstractAction> actions;

	bool proccess(Env env, AbstractAction action)
	{
		if(env->isSolved())
			return true;

		if(action->doAction(env))
		{
			u_int size = actions.size();

			for(u_int i = 0; i < size; i++)
			{
				AbstractAction nextAction = actions[i];

				if(proccess(env,nextAction))
					return true;
			}

			action->undoAction(env);
		}

		return false;
	}
};

#endif /* BACKTRACKING_HPP_ */
