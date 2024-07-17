#include <cmath>
#include <iostream>
using namespace std;

class Point {

    public:
        int x, y, z;

  Point(int x_, int y_, int z_) {
        x = x_;
        y = y_;
        z = z_;
    }
    int translate(int d, char axis) {
        switch (axis) {
            case 'x':
                x += d;
                break;
            case 'y':
                y += d;
                break;
            case 'z':
                z += d;
                break;
            default:
                return -1;  // Invalid axis
        }
        return 0;  // Successful translation
    }

   void display() const {
        cout << "Point(" << x << ", " << y << ", " << z << ")" << endl;
    }

};


class Triangle {
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

public:
     Triangle(Point* v1 = nullptr, Point* v2 = nullptr, Point* v3 = nullptr) {
        vertex_1 = v1;
        vertex_2 = v2;
        vertex_3 = v3;
    }

    ~Triangle() {
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;
    }

    int translate(int d, char axis) {
        if (vertex_1->translate(d, axis) == -1 ||
            vertex_2->translate(d, axis) == -1 ||
            vertex_3->translate(d, axis) == -1) {
            return -1;  // If any translation fails, return -1
        }
        return 0;
    }

    double calcArea() {
        // Using Heron's formula
        double a = sqrt(pow(vertex_2->x - vertex_1->x, 2) + pow(vertex_2->y - vertex_1->y, 2) + pow(vertex_2->z - vertex_1->z, 2));
        double b = sqrt(pow(vertex_3->x - vertex_2->x, 2) + pow(vertex_3->y - vertex_2->y, 2) + pow(vertex_3->z - vertex_2->z, 2));
        double c = sqrt(pow(vertex_1->x - vertex_3->x, 2) + pow(vertex_1->y - vertex_3->y, 2) + pow(vertex_1->z - vertex_3->z, 2));
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};


class Driver {
public:
    void run() {
        Point* p1 = new Point(0, 0, 0);
        Point* p2 = new Point(1, 0, 0);
        Point* p3 = new Point(0, 1, 0);
        Triangle* t = new Triangle(p1, p2, p3);

        cout << "Initial Area: " << t->calcArea() << endl;
        t->translate(1, 'x');
        cout << "Area after translation: " << t->calcArea() << endl;

        delete t;  // Cleanup
    }
};

int main() {
    Point p(1, 2, 3);
    p.display(); // Output: Point(1, 2, 3)
    Driver d;
    d.run();
    return 0;
}
