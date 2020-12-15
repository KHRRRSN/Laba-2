#include <iostream>
#include "Class.h";

using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Статические объекты:\n";//Удаляются сами в порядке 2, 3, 1
    Point tochka1;
    Point tochka2(5, 4);
    Point tochka3(tochka2);

    cout << "\n\nДинамические объекты:\n";//Удаляем мы самостоятельно в том порядке, в котором скажем
    Point* tochka4 = new Point;
    Point* tochka5 = new Point(5, 4);
    Point* tochka6 = new Point(*tochka5);

    delete tochka4;
    delete tochka5;
    delete tochka6;

    //Проверка доступа
    //tochka4

    cout << "\n\nОбъекты класса наследника:\n";
    Point3D* tochka3D1 = new Point3D;
    Point3D* tochka3D2 = new Point3D(19, 6, 1);
    Point3D* tochka3D3 = new Point3D(*tochka3D2);
    tochka3D2->change3D(2, 3, 4);//tochka3D имеет доступ к методам как класса потомка, так и предка

    delete tochka3D1;
    delete tochka3D2;
    delete tochka3D3;

    cout << "\n\nПомещение объектов в переменные рахличных типов:\n";
    Point* tochkaType1 = new Point3D;
    Point* tochkaType2 = new Point3D(11, 9, 19);//Создаем переменную указатель на адрес предка и помещаем в него объект класса потомка
                                                //Наоборот сделать нельзя 
    tochkaType2->changemult(10, 10);//tochkaType имеет доступ только к методам класса потомка

    delete tochkaType1;
    delete tochkaType2;

    cout << "\n\nКомпозиция:\n";
    Composition* segment1 = new Composition;
    Composition* segment2 = new Composition(1, 2, 3, 4, 5, 6);
    Composition* segment3 = new Composition(*segment2);

    delete segment1;
    delete segment2;
    delete segment3;

    cout << "\n\nСамовызывающиеся деструкторы:\n";


    return 0;
}

