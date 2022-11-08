#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"

#include <memory>

namespace shape_module {

class Triangle : public Polygon
{

public:

    /**
     * @brief Получить цвет формы
     * @return Цвет формы
    */
    virtual IColor::Color getColor() const { return (_color != nullptr) ? _color->getColor() : IColor::Color::NOT_COLOR; }

    /**
     * @brief Получить ширину формы
     * @return Основание
    */
    virtual const double &getWidthForm() const { return _base; }

    /**
     * @brief Получить высоту формы
     * @return Высота
    */
    virtual const double &getHeightForm() const { return _height; }

    friend class IShape;

protected:

    Triangle(const double &width_form,  const double &height_form, std::unique_ptr<IColor> color);
    ~Triangle() = default;
    Triangle(const Triangle &shape) = default;
    Triangle(Triangle && shape) = default;
    Triangle &operator=(const Triangle &shape) = default;

    /**
     * @brief Расчет площади
    */
    virtual double calcArea();

    /**
     * @brief Создание формы: получение основных параметров.
    */
    virtual void draw();

    double _base{0};
    std::unique_ptr<IColor> _color;
    double _height{0};
    double _side{0};

private:
};

}

#endif // TRIANGLE_H
