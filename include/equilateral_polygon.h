#ifndef EQUILATERAL_POLYGON_H
#define EQUILATERAL_POLYGON_H

namespace shape_module {

/**
 * @brief Класс Равностороний многоугольник
*/
class EquilateralPolygon
{
public:

protected:

    EquilateralPolygon(const double & side) : _side{side} {}
    ~EquilateralPolygon() = default;
    EquilateralPolygon(const EquilateralPolygon &shape) = delete;
    EquilateralPolygon(EquilateralPolygon && shape) = delete;
    EquilateralPolygon &operator=(const EquilateralPolygon &shape) = delete;

    /**
     * @brief Расчет периметра
     * @param[in] number_side - количество сторон
     * return Периметр
     */
    double calcPerimeterForEquilateralPolygon(const double & number_side) { return  _side * number_side; }

    double _side{0};

private:
};

}

#endif // EQUILATERAL_POLYGON_H
