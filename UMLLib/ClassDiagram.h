#pragma once
#include "HUML.h"
#include <cmath>
#include <string>
template <class T>
class TClassDiagram: public TUML
{
public:
	virtual T Get—haract() = 0;
	~TClassDiagram();
	string GetName();
	string GetType();
	int GetTransp();
	int GetColor();
	bool GetFilling();
	string GetTitle();
	string GetSignature();
	void SetName(string val);
	void SetType(string val);
	void SetTransp(int val);
	void SetColor(int val);
	void SetFilling(bool val);
	void SetTitle(string val);
	void SetSignature(string val);
protected:
	string name;
	string type;
	string title;
	string signature;
	bool filling = 0;
	int transp = 1;
	int color = 1;
};

template<class T>
inline TClassDiagram<T>::~TClassDiagram()
{
}

template<class T>
inline string TClassDiagram<T>::GetName()
{
	return name;
}

template<class T>
inline string TClassDiagram<T>::GetType()
{
	return type;
}

template<class T>
inline int TClassDiagram<T>::GetTransp()
{
	return transp;
}

template<class T>
inline int TClassDiagram<T>::GetColor()
{
	return color;
}

template<class T>
inline bool TClassDiagram<T>::GetFilling()
{
	return filling;
}

template<class T>
inline string TClassDiagram<T>::GetTitle()
{
	return title;
}

template<class T>
inline string TClassDiagram<T>::GetSignature()
{
	return signature;
}

template<class T>
inline void TClassDiagram<T>::SetName(string val)
{
	name = val;
}

template<class T>
inline void TClassDiagram<T>::SetType(string val)
{
	type = val;
}

template<class T>
inline void TClassDiagram<T>::SetTransp(int val)
{
	if ((val >= 0) && (val <= 100))
	{
		transp = val;
	}
	else
		throw(1);
}

template<class T>
inline void TClassDiagram<T>::SetColor(int val)
{
	if ((val >= 0)&&(255 >= val))
	{
		color = val;
	}
	else
		throw(1);
}

template<class T>
inline void TClassDiagram<T>::SetFilling(bool val)
{
	filling = val;
}

template<class T>
inline void TClassDiagram<T>::SetTitle(string val)
{
	title = val;
}

template<class T>
inline void TClassDiagram<T>::SetSignature(string val)
{
	signature = val;
}
