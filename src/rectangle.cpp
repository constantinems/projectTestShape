#include "rectangle.h"

namespace shape_module {

constexpr uint8_t NUMBER_SIDE{4};

Rectangle::Rectangle(const double &width_form,  const double &height_form, std::unique_ptr<IColor> color) :
    Polygon{Form::RECTANGLE, width_form, height_form, NUMBER_SIDE},
    _color{std::move(color)},
    _lengh{_width_form},
    _width{_height_form}
{
    draw();
}

Rectangle::Rectangle(const Form &form, const double &width_form,  const double &height_form, std::unique_ptr<IColor> color) :
    Polygon{form, width_form, height_form, NUMBER_SIDE}, _color{std::move(color)}, _lengh{_width_form}, _width{_height_form}
{}

double Rectangle::calcArea()
{
    return _lengh * _width;
}

void Rectangle::draw()
{
    _perimeter = calcPerimeter(_lengh, _lengh, _width, _width);
    _area      = calcArea();
}

}
