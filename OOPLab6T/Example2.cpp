#include <iostream>
#include <cmath>

using namespace std;

class Equation {
public:
    virtual double calculateRoot() const = 0;
};

class LinearEquation : public Equation {
private:
    double a, b;

public:
    LinearEquation(double coefA, double coefB) : a(coefA), b(coefB) {}

    double calculateRoot() const override {
        if (a == 0) {
            cout << "This is not a linear equation." << endl;
            return NAN;
        }
        else {
            double root = -b / a;
            cout << "X: " << root << endl;
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    QuadraticEquation(double coefA, double coefB, double coefC) : a(coefA), b(coefB), c(coefC) {}

    double calculateRoot() const override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            cout << "This equation has no real roots." << endl;
            return NAN;
        }
        else {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "X1: " << root1 << "\nX2: " << root2;
        }

    }
};

class BiquadraticEquation : public Equation {
private:
    double a, b, c;

public:
    BiquadraticEquation(double coefA, double coefB, double coefC) : a(coefA), b(coefB), c(coefC) {}

    double calculateRoot() const override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            cout << "This equation has no real roots." << endl;
            return NAN;
        }
        double t1 = (-b + sqrt(discriminant)) / (2 * a);
        double t2 = (-b - sqrt(discriminant)) / (2 * a);

        if (t1 < 0 && t2 < 0) {
            cout << "This equation has no real roots." << endl;
            return NAN;
        }
        else if (t1 > 0 && t2 < 0) {
            double root1 = sqrt(t1);
            double root2 = -sqrt(t1);
            cout << "X1: " << root1 << "\nX2: " << root2;
        }
        else if (t1 < 0 && t2 > 0) {
            double root1 = sqrt(t2);
            double root2 = -sqrt(t2);
            cout << "X1: " << root1 << "\nX2: " << root2;
        }
        else {
            double root1 = sqrt(t1);
            double root2 = -sqrt(t1);
            double root3 = sqrt(t2);
            double root4 = -sqrt(t2);
            cout << "X1: " << root1 << "\nX2: " << root2 << "X3: " << root3 << "\nX4: " << root4;
        }
    }
};

int main() {
    LinearEquation linear(2, -3);
    QuadraticEquation quadratic(1, -3, 2);
    BiquadraticEquation biquadratic(1, 0, -1);

    cout << "Quadratic equation roots: " << endl;
    quadratic.calculateRoot();
    cout << "\nLinear equation root: " << endl;
    linear.calculateRoot();
    cout << "Biquadratic equation root: " << endl;
    biquadratic.calculateRoot();
    return 0;
}
