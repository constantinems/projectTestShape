#ifndef ISHAPE_H
#define ISHAPE_H

#include "i_color.h"

#include <cstdint>

namespace shape_module {

/**
 * @brief Класс Фигура
 */
class IShape
{

public:

    enum class Form : uint8_t
    {
        NOT_FORM  = 0,
        CIRCLE    = 1,
        ELLIPSE   = 2,
        RECTANGLE = 3,
        SQUARE    = 4,
        TRIANGLE  = 5
    };

    virtual ~IShape() = default;

    /**
     * @brief Получить тип формы
     * return Тип формы
     */
    const Form &getForm() const { return _form; }

    /**
     * @brief Получить площадь
     * return Площадь
     */
    const double &getArea() const { return _area; }

    /**
     * @brief Получить периметр
     * return Периметр
     */
    const double &getPerimeter() const { return _perimeter; }

    /**
     * @brief Виртуальный метод получения ширины формы
     */
    virtual const double &getWidthForm() const  = 0;

    /**
     * @brief Виртуальный метод получения высоты формы
     */
    virtual const double &getHeightForm() const  = 0;

    /**
     * @brief Виртуальный метод получения цвета формы
     */
    virtual IColor::Color getColor() const = 0;

    /**
     * @brief Фабричный метод создания объектов "Форма"
     * @param[in] name_shape - название формы
     * @param[in] width_form - ширина
     * @param[in] height_form - высота
     * @param[in] color - цвет
     * return Форма
     */
    static std::unique_ptr<IShape> factory(const std::string &&name_shape,
                                           const double &width_form,
                                           const double &height_form,
                                           std::unique_ptr<IColor> &&color);

protected:

    constexpr static double MID{0.5};

    IShape(const Form &form, const double &width_form,  const double &height_form);
    IShape(const IShape &shape) = delete;
    IShape(IShape && shape) = delete;
    IShape &operator=(const IShape &shape) = delete;

    /**
     * @brief Виртуальный метод создания формы: получение основных параметров.
    */
    virtual void draw() = 0;

    /**
     * @brief Виртуальный метод расчета площади
    */
    virtual double calcArea() = 0;

    Form   _form{Form::NOT_FORM};
    double _height_form{0};
    double _width_form{0};
    double _area{0};
    double _perimeter{0};

private:

};

}

#endif // ISHAPE_H
