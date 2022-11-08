#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"
#include "equilateral_polygon.h"

namespace shape_module {

class Square : public Rectangle, public EquilateralPolygon
{
public:

    /**
     * @brief Получить ширину формы
     * @return Сторона
    */
    virtual const double &getWidthForm() const { return _side; }

    /**
     * @brief Получить высоту формы
     * @return Сторона
    */
    virtual const double &getHeightForm() const { return _side; }

    friend class IShape;

protected:

    Square(const double &side_form, std::unique_ptr<IColor> color);
    ~Square() = default;
    Square(const Square &shape) = default;
    Square(Square &&shape) = default;
    Square &operator=(const Square &shape) = default;

    /**
     * @brief Расчет площади
    */
    virtual double calcArea() final;

    /**
     * @brief Создание формы: получение основных параметров.
    */
    virtual void draw() final;

private:
};

}

#endif // SQUARE_H
