#pragma once
#include <iostream>

using namespace std;

class Point {
public:
    int x, y;
    Point() {
        cout << "Point - Конструктор по умолчанию" << endl;
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        cout << "Point - Конструктор с параметрами (инициализирующий)" << endl;
        this->x = x;//this - указатель на текущий объект данного класса
        this->y = y;
    }
    Point(Point& p) {
        cout << "Point - Конструктор копирующий" << endl;
        this->x = p.x;
        this->y = p.y;
    }
    virtual ~Point() {
        cout << "Текущее состояние объектов х и у: " << x << " " << y << endl;
        cout << "Point - Дектруктор" << endl;
    }
    void changeplus(int kx, int ky) {//Реализация метода изменения координат сразу в определении
        x += kx;
        y += ky;
        cout << "Point - metod changeplus\n";
    }
    void changemult(int xx, int yy);
};

void Point::changemult(int xx, int yy) {//Реализация метода после определения 
    x *= xx;
    y *= yy;
    cout << "Point - metod changemult\n";
}

class Point3D : public Point {
protected:
    int z;
public:
    Point3D() :Point() {
        cout << "Point3D - Конструктор по умолчанию" << endl;
        z = 0;
    }
    Point3D(int x, int y, int z) :Point(x, y) {
        cout << "Point3D - Конструктор с параметрами (инициализирующий)" << endl;
        this->z = z;//this - указатель на текущий объект данного класса
    }
    Point3D(Point3D& p) {
        cout << "Point3D - Конструктор копирующий" << endl;
        this->x = p.x;
        this->y = p.y;
        this->z = p.z;
    }
    ~Point3D() {
        cout << "Текущее состояние объектов х, у и z: " << x << " " << y << " " << z << endl;
        cout << "Point3D - Дектруктор" << endl;
    }
    void change3D(int kx, int ky, int kz) {
        x += kx;
        y += ky;
        z += kz;
        cout << "Point3D - void change3D\n";
    }
};

class Composition {//Класс композиция, переменные других классов объявляются в этом классе
protected:
    Point3D* toch1;
    Point3D* toch2;
public:
    Composition() {
        cout << "Composition - Конструктор по умолчанию" << endl;
        toch1 = new Point3D;
        toch2 = new Point3D;
    }
    Composition(int x1, int y1, int z1, int x2, int y2, int z2) {
        cout << "Composition - Конструктор с параметрами (инициализирующий)" << endl;
        toch1 = new Point3D(x1, y1, z1);
        toch2 = new Point3D(x2, y2, z2);
    }
    Composition(Composition& p) {
        cout << "Composition - Конструктор копирующий" << endl;
        toch1 = new Point3D(*p.toch1);//Вызываем конструктор копирования Point3D, это глубокое копирование
        toch2 = new Point3D(*p.toch2);//Поверхностное копирование (toch1 = p.toch1;) здесь не подходит, так как при поверхностном
                                      //копировании указателя копируется только только адрес указателя
    }
    ~Composition() {
        cout << "Composition - Дектруктор" << endl;
    }
};