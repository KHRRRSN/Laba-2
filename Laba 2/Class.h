#pragma once
#include <iostream>

using namespace std;

class Point {
public:
    int x, y;
    Point() {
        cout << "Point - ����������� �� ���������" << endl;
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        cout << "Point - ����������� � ����������� (����������������)" << endl;
        this->x = x;//this - ��������� �� ������� ������ ������� ������
        this->y = y;
    }
    Point(Point& p) {
        cout << "Point - ����������� ����������" << endl;
        this->x = p.x;
        this->y = p.y;
    }
    virtual ~Point() {
        cout << "������� ��������� �������� � � �: " << x << " " << y << endl;
        cout << "Point - ����������" << endl;
    }
    void changeplus(int kx, int ky) {//���������� ������ ��������� ��������� ����� � �����������
        x += kx;
        y += ky;
        cout << "Point - metod changeplus\n";
    }
    void changemult(int xx, int yy);
};

void Point::changemult(int xx, int yy) {//���������� ������ ����� ����������� 
    x *= xx;
    y *= yy;
    cout << "Point - metod changemult\n";
}

class Point3D : public Point {
protected:
    int z;
public:
    Point3D() :Point() {
        cout << "Point3D - ����������� �� ���������" << endl;
        z = 0;
    }
    Point3D(int x, int y, int z) :Point(x, y) {
        cout << "Point3D - ����������� � ����������� (����������������)" << endl;
        this->z = z;//this - ��������� �� ������� ������ ������� ������
    }
    Point3D(Point3D& p) {
        cout << "Point3D - ����������� ����������" << endl;
        this->x = p.x;
        this->y = p.y;
        this->z = p.z;
    }
    ~Point3D() {
        cout << "������� ��������� �������� �, � � z: " << x << " " << y << " " << z << endl;
        cout << "Point3D - ����������" << endl;
    }
    void change3D(int kx, int ky, int kz) {
        x += kx;
        y += ky;
        z += kz;
        cout << "Point3D - void change3D\n";
    }
};

class Composition {//����� ����������, ���������� ������ ������� ����������� � ���� ������
protected:
    Point3D* toch1;
    Point3D* toch2;
public:
    Composition() {
        cout << "Composition - ����������� �� ���������" << endl;
        toch1 = new Point3D;
        toch2 = new Point3D;
    }
    Composition(int x1, int y1, int z1, int x2, int y2, int z2) {
        cout << "Composition - ����������� � ����������� (����������������)" << endl;
        toch1 = new Point3D(x1, y1, z1);
        toch2 = new Point3D(x2, y2, z2);
    }
    Composition(Composition& p) {
        cout << "Composition - ����������� ����������" << endl;
        toch1 = new Point3D(*p.toch1);//�������� ����������� ����������� Point3D, ��� �������� �����������
        toch2 = new Point3D(*p.toch2);//������������� ����������� (toch1 = p.toch1;) ����� �� ��������, ��� ��� ��� �������������
                                      //����������� ��������� ���������� ������ ������ ����� ���������
    }
    ~Composition() {
        cout << "Composition - ����������" << endl;
    }
};