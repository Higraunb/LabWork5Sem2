#pragma once
#include "ClassDiagram.h"

template<class T, int DIM>
class TLine : public TClassDiagram<T>
{
protected:
  TPoint<T, DIM> begin;
  TPoint<T, DIM> end;
  int size;
public:
  TLine();
  TLine(T* beginc_, T* endc_, int size_, int color_);
  ~TLine();
  T Get—haract() override;
  int GetDim();
  int GetSize();
  void SetSize(int size_);
  double Len();
  template<class I, int DIM>
  friend std::istream& operator>>(std::istream& inp, TLine<I, DIM>& val);

  template<class O, int DIM>
  friend std::ostream& operator<<(std::ostream& out, TLine<O, DIM>& val);
};

template<class T, int DIM>
inline TLine<T, DIM>::TLine()
{
  type = "line";
  size = 1;
}

template<class T, int DIM>
inline TLine<T, DIM>::TLine(T* beginc_, T* endc_, int size_, int color_)
{
  type = "line";
  if (size_ <= 0)
    throw("size_ <= 0");
  if (color_ <= 0)
    throw("color_ <= 0");
  try
  {
    T a = beginc_[DIM - 1];
  }
  catch (...)
  {
    throw("Indexes of begin error");
  }
  try
  {
    T a = endc_[DIM - 1];
  }
  catch (...)
  {
    throw("Indexes of end error");
  }

  color = color_;
  begin.SetColor(color);
  end.SetColor(color);

  size = size_;
  begin.SetSize(size);
  end.SetSize(size);

  for (int i = 0; i < DIM; ++i)
  {
    begin[i] = beginc_[i];
    end[i] = endc_[i];
  }
}


template<class T, int DIM>
inline TLine<T, DIM>::~TLine()
{
  size = 0;
  color = 0;
}

template<class T, int DIM>
inline T TLine<T, DIM>::Get—haract()
{
  return begin.DistTo(end);
}

template<class T, int DIM>
inline int TLine<T, DIM>::GetDim()
{
  return DIM;
}

template<class T, int DIM>
inline int TLine<T, DIM>::GetSize()
{
  return size;
}

template<class T, int DIM>
inline void TLine<T, DIM>::SetSize(int size_)
{
  if (size_ <= 0)
    throw("size_ <= 0");
  size = size_;
  begin.SetSize(size);
  end.SetSize(size);
}

template<class T, int DIM>
inline double TLine<T, DIM>::Len()
{
  return begin.DistTo(end);
}

template<class I, int DIM>
inline std::istream& operator>>(std::istream& inp, TLine<I, DIM>& val)
{
  int size_, color_, transp_;
  bool filling_;
  string name_, title_, signature_;
  cout << "Enter the size of line." << endl;
  inp >> size_;
  cout << "Enter the color of line." << endl;
  inp >> color_;
  val.SetColor(color_);
  cout << "Enter the name of line." << endl;
  inp >> name_;
  val.SetName(name_);
  cout << "Enter the signature of line." << endl;
  inp >> signature_;
  val.SetSignature(signature_);
  cout << "Enter the title of line." << endl;
  inp >> title_;
  val.SetTitle(title_);
  cout << "Enter the fillig of line." << endl;
  inp >> filling_;
  val.SetFilling(filling_);
  cout << "Enter the transp of line." << endl;
  inp >> transp_;
  val.SetTransp(transp_);
  if (color_ <= 0)
    throw("color_ <= 0");
  if (size_ <= 0)
    throw("size_ <= 0");
  val.SetColor(color_);
  val.SetSize(size_);
  cout << "Dimension of line is " << DIM << ".\n";
  for (int i = 0; i < DIM; ++i)
  {
    cout << "begin[" << i << "] = ";
    inp >> val.begin[i];
  }
  for (int i = 0; i < DIM; ++i)
  {
    cout << "end[" << i << "] = ";
    inp >> val.end[i];
  }
  return inp;
}

template<class O, int DIM>
inline std::ostream& operator<<(std::ostream& out, TLine<O, DIM>& val)
{
  out << "Type: " << val.type << "\nSize: " << val.size << "\nColor : " << val.color << "\nCoordinates of begin: (";
  for (int i = 0; i < DIM - 1; ++i)
    out << val.begin[i] << "; ";
  out << val.begin[DIM - 1] << ")\nCoordinates of end: (";
  for (int i = 0; i < DIM - 1; ++i)
    out << val.end[i] << "; ";
  out << val.end[DIM - 1] << ")\n";
  out << "\nSignature : " << val.signature << "\nTitle : " << val.title << "\nTransp : "
    << val.transp << "\nFilling : " << val.filling;
  return out;
}