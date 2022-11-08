#include "i_shape.h"
#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

namespace shape_module {

IShape::IShape(const Form &form, const double &width_form,  const double &height_form) :
    _form{form}, _height_form{height_form}, _width_form{width_form}
{}

std::unique_ptr<IShape> IShape::factory(const std::string &&name_shape,
                                        const double &width_form,
                                        const double &height_form,
                                        std::unique_ptr<IColor> &&color)
{
    if (name_shape == "Circle")
    {
        return std::unique_ptr<IShape>(new Circle(std::min(width_form, height_form), std::move(color)));
    } else if (name_shape == "Ellipse")
    {
        return std::unique_ptr<IShape>(new Ellipse(width_form, height_form, std::move(color)));
    } else if (name_shape == "Rectangle") {
        return std::unique_ptr<IShape>(new Rectangle(width_form, height_form, std::move(color)));
    } else if (name_shape == "Square") {
        return std::unique_ptr<IShape>(new Square(std::min(width_form, height_form), std::move(color)));
    } else if (name_shape == "Triangle") {
        return std::unique_ptr<IShape>(new Triangle(width_form, height_form, std::move(color)));
    } else {
        return nullptr;
    }
}

}
