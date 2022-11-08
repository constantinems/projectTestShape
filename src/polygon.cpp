#include "polygon.h"

namespace shape_module {

Polygon::Polygon(const Form &form, const double &width_form,  const double &height_form, const uint8_t &number_side) :
    IShape{form, width_form, height_form}, _number_side{number_side}
{}

}
