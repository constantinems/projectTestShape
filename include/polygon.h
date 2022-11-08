#ifndef POLYGON_H
#define POLYGON_H

#include "i_shape.h"

namespace shape_module {

class Polygon : public IShape
{
public:

protected:

    Polygon() = default;
    Polygon(const Form &form, const double &width_form,  const double &height_form, const uint8_t &number_side);
    virtual ~Polygon() = default;
    Polygon(const Polygon &shape) = delete;
    Polygon(Polygon && shape) = delete;
    Polygon &operator=(const Polygon &shape) = delete;


    /**
     * @brief Получение периметра по одному значению
     * @param[in] value - одиночное значение
     * @return Возврат одиночного значения
     */
    double calcPerimeter(double value) { return value; }

    /**
     * @brief Расчет периметра по любому количеству сторон
     * @param[in] value - одиночное значение
     * @param[in] args - набор сторон
     * @return Периметр
     */
    template<class... Args>
    double calcPerimeter(double value, Args... args) { return value + calcPerimeter(args...); }

    uint8_t _number_side{0};

private:
};

}

#endif // POLYGON_H
