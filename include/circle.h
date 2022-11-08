#ifndef CIRCLE_H
#define CIRCLE_H

#include "ellipse.h"

#include <memory>

namespace shape_module {

/**
 * @brief Класс Круг
*/
class Circle : public Ellipse
{

public:

    /**
     * @brief Получить ширину формы
     * @return Диаметр
    */
    virtual const double &getWidthForm() const { return _diameter; }

    /**
     * @brief Получить высоту формы
     * @return Диаметр
    */
    virtual const double &getHeightForm() const { return _diameter; }

    friend class IShape;

protected:

    Circle(const double &diameter, std::unique_ptr<IColor> color);
    ~Circle() = default;
    Circle(const Circle &shape) = delete;
    Circle(Circle && shape) = delete;
    Circle &operator=(const Circle &shape) = delete;

    /**
     * @brief Расчет площади
    */
    virtual double calcArea() final;

    /**
     * @brief Расчет периметра
    */
    virtual double calcPerimeter() final;

    /**
     * @brief Создание формы: получение основных параметров.
    */
    virtual void draw();

    double _diameter{0};

private:
};

}
#endif // CIRCLE_H
