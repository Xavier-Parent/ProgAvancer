#pragma once
#include "Observer.h"
#include <list>
template<typename T>
class Subject
{
public:
	/// <summary>
	/// Add an observer to listen to the subject
	/// </summary>
	/// <param name="o"></param>
	void AddListener(Observer<T>* o)
	{
		m_Observers.push_back(o);
	}
	/// <summary>
	/// Remove an observer who listen to the subject
	/// </summary>
	/// <param name="o"></param>
	void RemoveListener(Observer<T>* o)
	{
		m_Observers.remove(o);
	}
	/// <summary>
	/// Invoke the action that the observer listen
	/// </summary>
	/// <param name="value"></param>
	void Invoke(const T& value)
	{
		for (Observer<T>* o : m_Observers)
		{
			o->OnNotify(value);
		}
	}
private:
	std::list<Observer<T>*> m_Observers;
};