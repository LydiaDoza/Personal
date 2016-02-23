/***********************************************************
* Pure Abstract Class:			iIterator
************************************************************/
#ifndef IITERATOR_H
#define IITERATOR_H

template <typename T>
class iIterator
{
protected:
	virtual void MoveNext() = 0;
	virtual void Reset() = 0;
	virtual bool IsDone() = 0;
	virtual T GetCurrent() = 0;
};

#endif