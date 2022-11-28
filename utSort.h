#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"
using namespace std;

TEST(Sort, sortByIncreasingPerimeter)
{
    //初始設定三個Shapes
    Circle cir(0, 0, 2);                  // Perimeter = 12.5664
    Rectangle rect(0, 0, 3, 4);           // Perimeter = 14
    Triangle tri({3, 0}, {0, 4}, {0, 0}); // Perimeter = 12

    list<Shape *> shape_list, ans;
    shape_list.push_back(&cir);
    shape_list.push_back(&rect);
    shape_list.push_back(&tri);
    ans.push_back(&cir);
    ans.push_back(&rect);
    ans.push_back(&tri);

    // shape_list 丟入函式排序
    Sort::sortByIncreasingPerimeter(&shape_list);

    // ans 在本地排序
    ans.sort([](const Shape *f, const Shape *s)
             { return f->perimeter() > s->perimeter(); });

    // 3個shapes在兩個list中的排序結果必須相同
    for (int i = 0; i < 3; i++)
    {
        //各別從list取出一個並比較
        if (ans.back()->perimeter() != shape_list.back()->perimeter())
            FAIL() << "Sorting is error.";
        else
            cout << ans.back()->perimeter() << " ";
        ans.pop_back();
        shape_list.pop_back();
    }
    cout << endl;
    EXPECT_TRUE(true);
}

TEST(Sort, sortByDecreasingPerimeter)
{
    Circle cir(0, 0, 2);                  // Perimeter = 12.5664
    Rectangle rect(0, 0, 3, 4);           // Perimeter = 14
    Triangle tri({3, 0}, {0, 4}, {0, 0}); // Perimeter = 12

    list<Shape *> shape_list, ans;

    shape_list.push_back(&cir);
    shape_list.push_back(&rect);
    shape_list.push_back(&tri);
    ans.push_back(&cir);
    ans.push_back(&rect);
    ans.push_back(&tri);

    //丟入函式排序
    Sort::sortByDecreasingPerimeter(&shape_list);
    //在本地排序
    ans.sort([](const Shape *f, const Shape *s)
             { return f->perimeter() < s->perimeter(); });

    //比較函式排序和本地排序及果是否相同
    for (int i = 0; i < 3; i++)
    {
        if (ans.back()->perimeter() != shape_list.back()->perimeter())
            FAIL() << "Sorting is error.";
        else
            cout << ans.back()->perimeter() << " ";
        ans.pop_back();
        shape_list.pop_back();
    }
    cout << endl;
    EXPECT_TRUE(true);
}

TEST(Sort, sortByIncreasingArea)
{
    Circle cir(0, 0, 1.8);                // Area = 10.1788
    Rectangle rect(0, 0, 3, 4);           // Area = 12
    Triangle tri({3, 0}, {0, 4}, {0, 0}); // Area = 6

    list<Shape *> shape_list, ans;
    shape_list.push_back(&cir);
    shape_list.push_back(&rect);
    shape_list.push_back(&tri);
    ans.push_back(&cir);
    ans.push_back(&rect);
    ans.push_back(&tri);

    Sort::sortByIncreasingArea(&shape_list);
    ans.sort([](const Shape *f, const Shape *s)
             { return f->area() > s->area(); });

    for (int i = 0; i < 3; i++)
    {
        if (ans.back()->area() != shape_list.back()->area())
            FAIL() << "Sorting is error.";
        else
            cout << ans.back()->area() << " ";
        ans.pop_back();
        shape_list.pop_back();
    }
    cout << endl;
    EXPECT_TRUE(true);
}

TEST(Sort, sortByDecreasingArea)
{
    Circle cir(0, 0, 1.8);                // Area = 10.1788
    Rectangle rect(0, 0, 3, 4);           // Area = 12
    Triangle tri({3, 0}, {0, 4}, {0, 0}); // Area = 6

    list<Shape *> shape_list, ans;
    shape_list.push_back(&cir);
    shape_list.push_back(&rect);
    shape_list.push_back(&tri);
    ans.push_back(&cir);
    ans.push_back(&rect);
    ans.push_back(&tri);

    Sort::sortByDecreasingArea(&shape_list);
    ans.sort([](const Shape *f, const Shape *s)
             { return f->area() < s->area(); });

    for (int i = 0; i < 3; i++)
    {
        if (ans.back()->area() != shape_list.back()->area())
            FAIL() << "Sorting is error.";
        else
            cout << ans.back()->area() << " ";
        ans.pop_back();
        shape_list.pop_back();
    }
    cout << endl;
    EXPECT_TRUE(true);
}

TEST(Sort, sortByIncreasingCompactness) // Compactness = area/perimeter
{
    Circle cir(0, 0, 1.8);                // Area = 10.1788    perimeter = 11.304
    Rectangle rect(0, 0, 3, 4);           // Area = 12         perimeter = 14
    Triangle tri({3, 0}, {0, 4}, {0, 0}); // Area = 6          perimeter = 12

    list<Shape *> shape_list, ans;
    shape_list.push_back(&cir);
    shape_list.push_back(&rect);
    shape_list.push_back(&tri);
    ans.push_back(&cir);
    ans.push_back(&rect);
    ans.push_back(&tri);

    Sort::sortByIncreasingCompactness(&shape_list);
    ans.sort([](const Shape *f, const Shape *s)
             { return (f->area() / f->perimeter()) > (s->area() / s->perimeter()); });

    for (int i = 0; i < 3; i++)
    {
        if (ans.back()->area() != shape_list.back()->area())
            FAIL() << "Sorting is error.";
        else
            cout << ans.back()->area() / ans.back()->perimeter() << " ";
        ans.pop_back();
        shape_list.pop_back();
    }
    cout << endl;
    EXPECT_TRUE(true);
}

#endif
