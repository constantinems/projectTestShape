#ifndef GREEN_H
#define GREEN_H

#include "i_color.h"

namespace shape_module {

/**
 * @brief Класс Зеленый
 */
class Green : public IColor {

public:

    ~Green() = default;

    /**
     * @brief Получить цвет
     * return Зеленый цвет
     */
    virtual Color getColor() const override { return Color::GREEN; }

    friend class IColor;

protected:

    Green() = default;
    Green(const Green &shape) = default;
    Green(Green && shape) = default;
    Green &operator=(const Green &shape) = default;

private:
};

}

#endif // GREEN_H
