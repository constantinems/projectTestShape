#include "ellipse.h"

#include <cmath>

namespace shape_module {

Ellipse::Ellipse(const double &width_form,  const double &height_form, std::unique_ptr<IColor> color) :
    IShape(Form::ELLIPSE, width_form, height_form), _color{std::move(color)}, _axis_width(width_form), _axis_height(height_form)
{
    draw();
}

Ellipse::Ellipse(const Form &form, const double &width_form,  const double &height_form, std::unique_ptr<IColor> color) :
    IShape(form, width_form, height_form), _color{std::move(color)}
{}

void Ellipse::draw()
{
    _perimeter = calcPerimeter();
    _area   = calcArea();
}

double Ellipse::calcPerimeter()
{
    return M_PI_2 * (_axis_width + _axis_height);
}

double Ellipse::calcArea()
{
    return M_PI_4 * _axis_width * _axis_height;
}

}
