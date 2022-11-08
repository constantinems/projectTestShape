#include "square.h"

#include <cmath>

namespace shape_module {

Square::Square(const double &side_form, std::unique_ptr<IColor> color) :
    Rectangle{Form::SQUARE, side_form, side_form, std::move(color)}, EquilateralPolygon{side_form}
{
    draw();
}

double Square::calcArea()
{
    return std::pow(_side, 2.0);
}

void Square::draw()
{
    _perimeter = calcPerimeterForEquilateralPolygon(_number_side);
    _area      = calcArea();
}

}
