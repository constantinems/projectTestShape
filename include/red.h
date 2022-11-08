#ifndef RED_H
#define RED_H

#include "i_color.h"

namespace shape_module {

class Red : public IColor {

public:

    ~Red() = default;

    /**
     * @brief Получить цвет
     * return Красный цвет
     */
    virtual Color getColor() const override { return Color::RED; }

    friend class IColor;

protected:

    Red() = default;
    Red(const Red &shape) = default;
    Red(Red && shape) = default;
    Red &operator=(const Red &shape) = default;

private:
};

}

#endif // RED_H
