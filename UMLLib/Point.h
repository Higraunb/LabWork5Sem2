#pragma once
#include "ClassDiagram.h"
template<class T, int DIM>
class TPoint : public TClassDiagram<T>
{
protected:
  T coordinates[DIM];
  int size;
public:
  TPoint();
  TPoint(T* coordinates_, int color_, int size_);
  ~TPoint();
  T Get—haract() override;
  int GetDim();
  int GetSize();

  void SetSize(int size_);

  T& operator[](int index);

  double DistToOrigin();
  double DistTo(TPoint<T, DIM>& p);

  template<class I, int DIM>
  friend std::istream& operator>>(std::istream& inp, TPoint<I, DIM>& val);

  template<class O, int DIM>
  friend std::ostream& operator<<(std::ostream& out, TPoint<O, DIM>& val);
};

template<class T, int DIM>
inline TPoint<T, DIM>::TPoint()
{
  type = "point";
  name = "";
  size = 1;
  for (int i = 0; i < DIM; ++i)
    coordinates[i] = 0;
}

template<class T, int DIM>
inline TPoint<T, DIM>::TPoint(T* coordinates_, int color_, int size_)
{
  type = "point";
  if (size_ <= 0)
    throw("size_ <= 0");
  if (color_ <= 0)
    throw("color_ <= 0");
  try
  {
    T a = coordinates_[DIM - 1];
  }
  catch (...)
  {
    throw("Indexes error");
  }
  color = color_;
  size = size_;
  for (int i = 0; i < DIM; ++i)
    coordinates[i] = coordinates_[i];
}

template<class T, int DIM>
inline TPoint<T, DIM>::~TPoint()
{
  size = 0;
  color = 0;
}

template<class T, int DIM>
inline T TPoint<T, DIM>::Get—haract()
{
  return 0;
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetDim()
{
  return DIM;
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetSize()
{
  return size;
}

template<class T, int DIM>
inline void TPoint<T, DIM>::SetSize(int size_)
{
  if (size_ <= 0)
    throw("size_ <= 0");
  size = size_;
}

template<class T, int DIM>
inline T& TPoint<T, DIM>::operator[](int index)
{
  if (index >= DIM)
    throw("index >= DIM");
  return coordinates[index];
}

template<class T, int DIM>
inline double TPoint<T, DIM>::DistToOrigin()
{
  T res = 0;
  for (int i = 0; i < DIM; ++i)
    res += coordinates[i] * coordinates[i];
  return pow(res, 0.5);
}

template<class T, int DIM>
inline double TPoint<T, DIM>::DistTo(TPoint<T, DIM>& p)
{
  T res = 0;
  for (int i = 0; i < DIM; ++i)
    res += (coordinates[i] - p[i]) * (coordinates[i] - p[i]);
  return pow(res, 0.5);
}

template<class I, int DIM>
inline std::istream& operator>>(std::istream& inp, TPoint<I, DIM>& val)
{
  int size_, color_, transp_;
  bool filling_;
  string name_, title_, signature_;
  cout << "Enter the size of point." << endl;
  inp >> size_;
  val.SetSize(size_);
  cout << "Enter the color of point." << endl;
  inp >> color_;
  val.SetColor(color_);
  cout << "Enter the name of point." << endl;
  inp >> name_;
  val.SetName(name_);
  cout << "Enter the signature of point." << endl;
  inp >> signature_;
  val.SetSignature(signature_);
  cout << "Enter the title of point." << endl;
  inp >> title_;
  val.SetTitle(title_);
  cout << "Enter the fillig of point." << endl;
  inp >> filling_;
  val.SetFilling(filling_);
  cout << "Enter the transp of point." << endl;
  inp >> transp_;
  val.SetTransp(transp_);
  if (color_ <= 0)
    throw("color_ <= 0");
  if (size_ <= 0)
    throw("size_ <= 0");
  val.SetColor(color_);
  val.SetSize(size_);
  cout << "Dimension of point is " << DIM << ".\n";
  for (int i = 0; i < DIM; ++i)
  {
    cout << "val[" << i << "] = ";
    cin >> val.coordinates[i];
  }
  return inp;
}

template<class V, int DIM>
inline std::ostream& operator<<(std::ostream& out, TPoint<V, DIM>& val)
{
  out << "Type: " << val.type <<"\nSize: " << val.size << "\nColor : " << val.color << "\nCoordinates : (";
  for (int i = 0; i < DIM - 1; ++i)
    out << val[i] << "; ";
  out << val[DIM - 1] << ")";
  out << "\nSignature : " << val.signature << "\nTitle : " << val.title << "\nTransp : " 
    << val.transp << "\nFilling : " << val.filling;
  return out;
}
