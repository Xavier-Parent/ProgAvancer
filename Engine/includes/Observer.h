#pragma once

template<typename T>
class Observer
{
public:
	/// <summary>
	/// Destructor by default
	/// </summary>
	virtual ~Observer() = default;
	/// <summary>
	/// Receive the notification form the subject
	/// </summary>
	/// <param name="value">value that the observer receive</param>
	virtual void OnNotify(const T& value) = 0;
};