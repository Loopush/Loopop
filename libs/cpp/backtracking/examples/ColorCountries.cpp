/*
 * ColorCountries.hpp
 *
 *  Created on: Dec 7, 2011
 *      Author: issle
 */

#ifndef COLORCOUNTRIES_HPP_
#define COLORCOUNTRIES_HPP_

#include <iostream>
#include <vector>

#include "../Backtracking.hpp"
#include "../../commons/benchmark/TimeBench.hpp"

using namespace std;

class Country
{
private:
	string name;
	int color;
	vector<Country*> adjacents;
public:

	static const int GREY = 0;
	static const int RED = 1;
	static const int BLUE = 2;
	static const int YELLOW = 3;
	static const int GREEN = 4;

	string getName() const
    {
        return name;
    }

    vector<Country*>* getAdjacents()
	{
		return &adjacents;
	}

	Country(string name)
	{
		this->name = name;
		color = GREY;
	}

	int getColor() const
	{
		return color;
	}

	void setColor(int color)
	{
		this->color = color;
	}

	void addCountry(Country* country)
	{
		country->getAdjacents()->push_back(this);
		adjacents.push_back(country);
	}

};

class Environment
{
private:
	vector<Country*> countries;
	int countryIndex;
public:

	Environment()
	{

	}

	vector<Country*>* getCountries()
	{
		return &countries;
	}

	void setCountries(vector<Country*> countries)
	{
		this->countries = countries;
	}

	bool isSolved()
	{
		if (countryIndex == countries.size())
			return true;
		else
			return false;
	}

	int getCountryIndex() const
	{
		return countryIndex;
	}

	void setCountryIndex(int countryIndex)
	{
		this->countryIndex = countryIndex;
	}

	void print()
	{
		int size = countries.size();

		cout << "Final color for each country: " << endl;
		for(int i = 0; i < size; i++)
		{
			cout << countries[i]->getName() << countries[i]->getColor() << endl;
		}
	}
};

typedef AbstractActionT<Environment*> AbstractAction;

class Color: public AbstractAction
{
private:
	int color;
public:

	Color(int _color)
	{
		color = _color;
	}

	bool doAction(AbstractAction::EnvType env)
	{
		int index = env->getCountryIndex();

		Country* country = (*env->getCountries())[index];

		int size = (*country->getAdjacents()).size();

		for (int i = 0; i < size; i++)
		{
			if ((*country->getAdjacents())[i]->getColor() == color)
				return false;
		}

		country->setColor(color);

		env->setCountryIndex(env->getCountryIndex() + 1);
	}

	void undoAction(AbstractAction::EnvType env)
	{
		int index = env->getCountryIndex();

		Country* country = (*env->getCountries())[index];



		country->setColor(Country::GREY);

		env->setCountryIndex(env->getCountryIndex() - 1);
	}

};

typedef Proccessor<Environment*, Color*> Proc;

int main(void)
{
	Proc* proc = new Proc();


	Environment* env = new Environment();

	Country greece("Greece"), albania("Albania"), skopia("Skopia"), bulgaria("Bulgaria"), romania("Romania");

	env->getCountries()->push_back(&greece);
	env->getCountries()->push_back(&albania);
	env->getCountries()->push_back(&skopia);
	env->getCountries()->push_back(&bulgaria);
	env->getCountries()->push_back(&romania);

	greece.addCountry(&albania);
	greece.addCountry(&bulgaria);
	greece.addCountry(&skopia);

	albania.addCountry(&bulgaria);
	bulgaria.addCountry(&skopia);
	bulgaria.addCountry(&romania);
	romania.addCountry(&skopia);

	proc->actions.push_back(new Color(Country::RED));
	proc->actions.push_back(new Color(Country::BLUE));
	proc->actions.push_back(new Color(Country::YELLOW));
	proc->actions.push_back(new Color(Country::GREEN));

	proc->proccess(env,new Color(Country::RED));

	env->print();
	return 0;
}
#endif /* COLORCOUNTRIES_HPP_ */
