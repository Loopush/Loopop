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

/**
 * Defines the interface an action should implement.
 * Since different action classes can exist in the same
 * problem this class should get extended from another
 * class which realizes the abstract methods that this
 * class defines.
 */
template < class Env > class AbstractActionT
{
public:
	typedef Env EnvType;

	/*
	 * Called when this action is checked for
	 * validity inside the environment and/or
	 * when the action must do changes to the
	 * environment.
	 */
	virtual bool doAction(EnvType env) = 0;

	/*
	 * Called when this action must revert all
	 * the actions it did to the environment when
	 * doAction() was called.
	 */
	virtual void undoAction(EnvType env) = 0;
};

/**
 * There is one environment class/object during the
 * execution of backtracking thus extending this
 * class is not necessary. Although since the algo-
 * rithm expects a bool isSolved() method to exist
 * inside the environment, not implementing this
 * method's signature in your environment will cause
 * a compile time error.
 */
class AbstractEnv
{
public:

	/*
	 * Returns true if the environment is in a state
	 * where a solution to the problem is found.
	 */
	virtual bool isSolved() = 0;
};

/**
 * The Processor is the class that implements the
 * backtracking algorithm. It's template takes as
 * an argument the class of the Environment and the
 * abstract class of the actions since they are called
 * polymorphicaly.
 */
template<class Env, class AbstractAction> class Processor
{
public:
	/*
	 * Contains a list of actions that can be
	 * performed on an environment.
	 */
	vector<AbstractAction> actions;

	/*
	 * Call this with a dummy action to initialize
	 * backtracking.
	 */
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
