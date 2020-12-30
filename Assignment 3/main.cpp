/*
 * Belal Hamdy Ezzat
 * 20170077
 * CS_DS_1
 */
#include <iostream>

#define PI 3.14159265358979323846
using namespace std;

struct ShapeVTable;

struct Shape {
    ShapeVTable *vtable;
};

// holds the virtual functions
struct ShapeVTable {
    double (*GetArea)(Shape *);
};

double GetArea(Shape *shape) {
    return shape->vtable->GetArea(shape);
}

// -------------------------------------

struct Circle {
    Shape parent;
    double radius;
};

double CircleArea(Circle *circle) {
    return PI * circle->radius * circle->radius;
}

ShapeVTable circle_vtable = {
        (double (*)(Shape *)) CircleArea
};

void CircleInitialize(Circle *circle, double radius) {
    circle->parent.vtable = &circle_vtable;
    circle->radius = radius;
}
// -------------------------------------

struct Rectangle {
    Shape parent;
    double width, height;
};

double RectangleArea(Rectangle *rectangle) {
    return rectangle->width * rectangle->height;
}

ShapeVTable rectangle_vtable = {
        (double (*)(Shape *)) RectangleArea
};

void RectangleInitialize(Rectangle *rectangle, double width, double height) {
    rectangle->parent.vtable = &rectangle_vtable;
    rectangle->width = width;
    rectangle->height = height;
}
// -------------------------------------

struct Square {
    Shape parent;
    double side;
};

double SquareArea(Square *square) {
    return square->side * square->side;
}

ShapeVTable square_vtable = {
        (double (*)(Shape *)) SquareArea
};

void SquareInitialize(Square *square, double side) {
    square->parent.vtable = &square_vtable;
    square->side = side;
}
int main() {
    Circle circle;
    CircleInitialize(&circle, 10); // circle with radius 10

    Rectangle rectangle;
    RectangleInitialize(&rectangle, 3, 5); // rectangle with width 3 and height 5

    Square square;
    SquareInitialize(&square, 7); // square with side length 7

    Shape *shapes[3];
    shapes[0] = (Shape *) &circle;
    shapes[1] = (Shape *) &rectangle;
    shapes[2] = (Shape *) &square;

    double total_area = 0;

    int i;
    for (i = 0; i < 3; i++) {
        double d = GetArea(shapes[i]);
        total_area += d;
    }

    cout << total_area << endl; // check if the value is correct

    return 0;
}

