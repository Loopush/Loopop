/*
 * Sortable.hpp
 *
 *  Created on: Dec 7, 2011
 *      Author: issle
 */

#ifndef SORTABLE_HPP_
#define SORTABLE_HPP_

template < class T > class Sortable
{
public:
	static bool sorter(T t1, T t2)
	{
		return t1->compare(t2);
	}

	virtual bool compare(T t2)=0;
};

#endif /* SORTABLE_HPP_ */
