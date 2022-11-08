#include "triangle.h"

#include <cmath>

namespace shape_module {

constexpr uint8_t NUMBER_SIDE{3};

Triangle::Triangle(const double &width_form,  const double &height_form, std::unique_ptr<IColor> color) :
    Polygon{Form::TRIANGLE, width_form, height_form, NUMBER_SIDE}, _base{_width_form}, _color{std::move(color)}, _height{_height_form}
{
    draw();
}

void Triangle::draw()
{
    _side      = std::hypot(_height, _base * MID);
    _perimeter = calcPerimeter(_base, _side, _side);
    _area      = calcArea();
}

double Triangle::calcArea()
{
    return MID * _height * _side;
}

}
