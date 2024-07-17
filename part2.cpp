#include <cmath>
#include <iostream>
using namespace std;

class Point {

 private:

        int x, y, z; // coordinates

 public:

  Point(int x_, int y_, int z_) {
        x = x_;
        y = y_;
        z = z_;
    }
    int translate(int d, char axis) {
         if (d < 0) {
            return -2;  // Invalid value for d
        }
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
    ~Point(){}

void printCoordinates() {
        cout << "Point Coordinates: (" << getX() << ", " << getY() << ", " << getZ() << ")\n";
    }
// Getters and setters

    int getX() const { return x; }
    void setX(int val) { x = val; }

    int getY() const { return y; }
    void setY(int val) { y = val; }

 
    int getZ() const { return z; }
    void setZ(int val) { z = val; }


};


class Triangle {
    Point* vertex_1; // x, y, z
    Point* vertex_2;
    Point* vertex_3;


public:
      Triangle(Point* v1, Point* v2, Point* v3) {
        vertex_1 = v1;
        vertex_2 = v2;
        vertex_3 = v3;
    }
   
   Triangle() : vertex_1(nullptr), vertex_2(nullptr),vertex_3(nullptr){} 

    ~Triangle() {
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;
    }

    int translate(int d, char axis) { // a->getb()  is the same as a.getb(); but for pointers
        if (vertex_1->translate(d, axis) == -1 ||vertex_2->translate(d, axis) == -1 ||vertex_3->translate(d, axis) == -1) {
            return -1;  // Does translation, if any fails, return -1
        }
        return 0;
    }

      double calcArea() {
        double a = sqrt(pow(vertex_2->getX() - vertex_1->getX(), 2) +   // Euclian distance in 3D =srt[ (x2−x1)2+(y2−y1)2+(z2−z1)2 ]
                        pow(vertex_2->getY() - vertex_1->getY(), 2) +
                        pow(vertex_2->getZ() - vertex_1->getZ(), 2));

        double b = sqrt(pow(vertex_3->getX() - vertex_2->getX(), 2) + 
                        pow(vertex_3->getY() - vertex_2->getY(), 2) +
                        pow(vertex_3->getZ() - vertex_2->getZ(), 2));

        double c = sqrt(pow(vertex_1->getX() - vertex_3->getX(), 2) + 
                        pow(vertex_1->getY() - vertex_3->getY(), 2) +
                        pow(vertex_1->getZ() - vertex_3->getZ(), 2));

        // Heron's Formula to find area of triangle by knowing it's sides
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void printVertices() const { // if vertext ptr is not null
        if (vertex_1) vertex_1->printCoordinates();
        if (vertex_2) vertex_2->printCoordinates();
        if (vertex_3) vertex_3->printCoordinates();
    }
};


/*  NO USER INPUT DRIVER
class Driver {
public:
    void run() {
        // Creating points dynamically
        Point* p1 = new Point(5, 2, 3);
        Point* p2 = new Point(3, 8, 7);
        Point* p3 = new Point(9 ,6, 1);

        // Creating a triangle with these points
        Triangle* triangle = new Triangle(p1, p2, p3);

        // Displaying the initial area
        cout << "Initial Area: " << triangle->calcArea() << endl;

        // Translating the entire triangle along the x-axis
        int translationResult = triangle->translate(1, 'x');
        if (translationResult == -1) {
            cout << "Failed to translate: Invalid axis." << endl;
        } else {
            cout << "Triangle translated successfully." << endl;
            cout << "Area after translation: " << triangle->calcArea() << endl;
        }

        // Clean up
        delete triangle;  //delete the triangle and its points
    }
};
*/


class Driver {
 private:
    Triangle* triangle = nullptr;

public:
    ~Driver() {
        delete triangle;
    }
   void run() {
        char choice;
        bool exit = false;

        while (!exit) {
            cout << "\nSelect an option:" << endl;
            cout << "1. Create Triangle" << endl;
            cout << "2. Translate Triangle" << endl;
            cout << "3. Display Vertices" << endl;
            cout << "4. Calculate and Display Area" << endl;
            cout << "5. Exit\n" << endl;
            cout << ">> ";
            cin >> choice;

            switch (choice) {
                case '1':
                    createTriangle();
                    break;
                case '2':
                    translateTriangle();
                    break;
                case '3':
                    displayVertices();
                    break;
                case '4':
                    if (triangle) {
                        cout << "Area of the Triangle: " << triangle->calcArea() << endl;
                    } else {
                        cout << "Triangle not created yet." << endl;
                    }
                    break;
                case '5':
                    exit = true;
                    break;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        }
    }


   void createTriangle() {
    int x, y, z;

    // Prompt for Vertex 1
    cout << "Enter x for Vertex 1: ";
    cin >> x;
    cout << "Enter y for Vertex 1: ";
    cin >> y;
    cout << "Enter z for Vertex 1: ";
    cin >> z;

    Point* v1 = new Point(x, y, z);

    // Prompt for Vertex 2
    cout << "\nEnter x for Vertex 2: ";
    cin >> x;
    cout << "Enter y for Vertex 2: ";
    cin >> y;
    cout << "Enter z for Vertex 2: ";
    cin >> z;
  
    Point* v2 = new Point(x, y, z);


    // Prompt for Vertex 3
    cout << "\nEnter x for Vertex 3: ";
    cin >> x;
    cout << "Enter y for Vertex 3: ";
    cin >> y;
    cout << "Enter z for Vertex 3: ";
    cin >> z;
    
    Point* v3 = new Point(x, y, z);


    delete triangle;  // clean up any existing triangle if exists
    triangle = new Triangle(v1, v2, v3);

    cout << "\nTriangle created successfully." << endl;
}

    void translateTriangle() {
        if (!triangle) {
            cout << "Create a triangle first." << endl;
            return;
        }

        int d;
        char axis;
        cout << "\nEnter translation distance ";
        cin >> d ;
        cout << "Enter the axis (x, y, z): ";
        cin>> axis;

        triangle->translate(d, axis);
        cout << "\nTriangle translated along " << axis << " by " << d << " units.\n";
    }

     void displayVertices() {
        if (triangle) {
            triangle->printVertices();
        } else {
            cout << "Create a triangle first." << endl;
        }
    }
};
int main() {
    Driver d;
    d.run();
    return 0;
}
