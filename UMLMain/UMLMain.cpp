#include "HUML.h"
#include "C:\Users\Misha\Desktop\le\proga\LabWork5Sem2\LabWork5Sem2\build\UMLLib\Point.h"
#include "C:\Users\Misha\Desktop\le\proga\LabWork5Sem2\LabWork5Sem2\build\UMLLib\Line.h"
template <class T>
void Print(TClassDiagram<T>& var)
{
	cout << var.GetType() << endl;
}
int main()
{
	TLine<int, 2> a;
	a.SetName("erer");
	Print(a);
	cin >> a;
	cout << a;
}