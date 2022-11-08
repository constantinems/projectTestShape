#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "i_shape.h"
#include "i_color.h"

#include <QMainWindow>
#include <QPainter>
#include <utility>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void paintEvent(QPaintEvent *event);

private slots:

    void on_pushButtonCreateShape_clicked();

private:

    constexpr static int WIDTH_PEN{5};
    constexpr static int SETTING_ALEFT{200};
    constexpr static int SETTING_ATOP{100};

    std::string defineForm() const;

    std::string defineColor() const;

    Qt::GlobalColor getColor(const shape_module::IColor::Color &color) const;

    inline QPainterPath buildTriangle(const QRectF &rect) const;

    void printPerimeterAndArea();

    Ui::MainWindow * _ui;
    QPen             _pen{};

    std::unique_ptr<shape_module::IShape> _shape;
    std::pair<shape_module::IShape::Form, shape_module::IColor::Color> _state_current{shape_module::IShape::Form::NOT_FORM,
                shape_module::IColor::Color::NOT_COLOR};
    std::pair<shape_module::IShape::Form, shape_module::IColor::Color> _state_last{shape_module::IShape::Form::NOT_FORM,
                shape_module::IColor::Color::NOT_COLOR};
};

#endif // MAINWINDOW_H
