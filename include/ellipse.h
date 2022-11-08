#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "i_shape.h"

#include <memory>

namespace shape_module {

/**
 * @brief Класс Эллипс
*/
class Ellipse : public IShape
{

public:

    /**
     * @brief Получить цвет формы
     * @return Цвет формы
    */
    virtual IColor::Color getColor() const { return (_color != nullptr) ? _color->getColor() : IColor::Color::NOT_COLOR; }

    /**
     * @brief Получить ширину формы
     * @return Ось по широте
    */
    virtual const double &getWidthForm() const { return _axis_width; }

    /**
     * @brief Получить высоту формы
     * @return Ось по высоте
    */
    virtual const double &getHeightForm() const { return _axis_height; }

    friend class IShape;

protected:

    Ellipse(const double &width_form,  const double &height_form, std::unique_ptr<IColor> color);
    Ellipse(const Form &form, const double &width_form,  const double &height_form, std::unique_ptr<IColor> color);
    virtual ~Ellipse() = default;
    Ellipse(const Ellipse &shape) = delete;
    Ellipse(Ellipse && shape) = delete;
    Ellipse &operator=(const Ellipse &shape) = delete;

    /**
     * @brief Расчет площади
    */
    virtual double calcArea();

    /**
     * @brief Расчет периметра
    */
    virtual double calcPerimeter();

    /**
     * @brief Создание формы: получение основных параметров.
    */
    virtual void draw();

    std::unique_ptr<IColor> _color;
    double _axis_width{0};
    double _axis_height{0};

private:
};

}

#endif // ELLIPSE_H
