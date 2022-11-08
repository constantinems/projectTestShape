#include "circle.h"

#include <cmath>

namespace shape_module {

Circle::Circle(const double &diameter, std::unique_ptr<IColor> color) :
    Ellipse(Form::CIRCLE, diameter, diameter, std::move(color)) , _diameter(diameter)
{
    draw();
}

void Circle::draw()
{
    _perimeter = calcPerimeter();
    _area   = calcArea();
}

double Circle::calcPerimeter()
{
    return M_PI * _diameter;
}

double Circle::calcArea()
{
    return M_PI_4 * std::pow(_diameter, 2);
}

}
