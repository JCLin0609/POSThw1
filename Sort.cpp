#include "include/Sort.h"
#include <iostream>
using namespace std;

void Sort::sortByIncreasingPerimeter(std::list<Shape *> *shapeList)
{
    // for(Shape *it : *shapeList)
    //     cout << it->perimeter() << " ";
    // cout << endl;

    shapeList->sort([](const Shape *f, const Shape *s)
                    { return f->perimeter() < s->perimeter(); });
    
    // for(Shape *it : *shapeList)
    //     cout << it->perimeter() << " ";
    // cout << endl;
}

void Sort::sortByDecreasingPerimeter(std::list<Shape *> *shapeList)
{
    shapeList->sort([](const Shape *f, const Shape *s)
                    { return f->perimeter() > s->perimeter(); });
}

void Sort::sortByIncreasingArea(std::list<Shape *> *shapeList)
{
    shapeList->sort([](const Shape *f, const Shape *s)
                    { return f->area() < s->area(); });
}

void Sort::sortByDecreasingArea(std::list<Shape *> *shapeList)
{
    shapeList->sort([](const Shape *f, const Shape *s)
                    { return f->area() > s->area(); });
}

void Sort::sortByIncreasingCompactness(std::list<Shape *> *shapeList)
{
    shapeList->sort([](const Shape *f, const Shape *s)
                    { return (f->area() / f->perimeter()) < (s->area() / s->perimeter()); });
}