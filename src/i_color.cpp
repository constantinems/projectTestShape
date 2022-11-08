#include "i_color.h"
#include "red.h"
#include "green.h"

namespace shape_module {

std::unique_ptr<IColor> IColor::factory(std::string &&name_color)
{
    if (name_color == "Red")
    {
        return std::unique_ptr<IColor>(new Red());
    } else if (name_color == "Green")
    {
        return std::unique_ptr<IColor>(new Green());
    } else {
        return nullptr;
    }
}

}
