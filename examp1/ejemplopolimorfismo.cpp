#include <iostream>

class Shape
{
public:
    Shape() = default;
    Shape(std::string description) 
        : description(description){};
    virtual void draw() const
    {
        std::cout << "Dibujando " << description << "\n";
    }

protected:
    std::string description{""};
};

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(std::string description, double radius)
        : Shape(description), radius(radius){};
    virtual void draw() const
    {
        std::cout << "Dibujando " << description
                  << " con radio " << radius << "\n";
    }

protected:
    double radius{};
};

main()
{
    Shape shape("Forma");
    Circle circulo("Circulo", 4.5);

    shape.draw();
    circulo.draw();
    return 0;
}