#ifndef I_COLOR_H
#define I_COLOR_H

#include <cstdint>
#include <string>
#include <memory>

namespace shape_module {

/**
 * @brief Класс Цвет
 */
class IColor {

public:

    enum class Color : uint8_t
    {
        NOT_COLOR = 0,
        GREEN     = 1,
        RED       = 2
    };

    IColor() = default;
    virtual ~IColor() = default;
    IColor(const IColor &shape) = default;
    IColor(IColor && shape) = default;
    IColor &operator=(const IColor &shape) = default;

    /**
     * @brief Виртуальный метод получения цвета
     */
    virtual Color getColor() const = 0;

    /**
     * @brief Фабричный метод создания объектов "Цвет"
     * @param[in] name_color - название цвета
     * return Созданый цвет
     */
    static std::unique_ptr<IColor> factory(std::string &&name_color);

protected:

private:
};

}

#endif // I_COLOR_H
