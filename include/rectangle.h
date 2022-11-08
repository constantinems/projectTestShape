#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"

#include <memory>

namespace shape_module {

class Rectangle : public Polygon
{

public:

    virtual IColor::Color getColor() const { return (_color != nullptr) ? _color->getColor() : IColor::Color::NOT_COLOR; }

    /**
     * @brief Получить ширину формы
     * @return Длинна
    */
    virtual const double &getWidthForm() const { return _lengh; }

    /**
     * @brief Получить высоту формы
     * @return Ширина
    */
    virtual const double &getHeightForm() const { return _width; }

    friend class IShape;

protected:

    Rectangle(const double &width_form, const double &height_form, std::unique_ptr<IColor> color);
    Rectangle(const Form &form, const double &width_form,  const double &height_form, std::unique_ptr<IColor> color);
    ~Rectangle() = default;
    Rectangle(const Rectangle &shape) = default;
    Rectangle(Rectangle && shape) = default;
    Rectangle &operator=(const Rectangle &shape) = default;

    /**
     * @brief Расчет площади
    */
    virtual double calcArea();

    /**
     * @brief Создание формы: получение основных параметров.
    */
    virtual void draw();

    std::unique_ptr<IColor> _color;
    double _lengh{0};
    double _width{0};

private:
};

}

#endif // RECTANGLE_H
