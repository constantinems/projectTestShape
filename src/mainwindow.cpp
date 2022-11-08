#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <memory>
#include <cmath>
#include <QString>

#define UNUSED(value) (void)value

constexpr double WIDTH = 300.0;
constexpr double HEIGHT = 100.0;

using namespace shape_module;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
    _ui->radioButtonCircle->setChecked(false);
    _ui->radioButtonEllipse->setChecked(false);
    _ui->radioButtonRectangle->setChecked(false);
    _ui->radioButtonSquare->setChecked(false);
    _ui->radioButtonTriangle->setChecked(false);

    _pen.setWidth(WIDTH_PEN);
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    UNUSED(event);

    if (_shape != nullptr)
    {
        QPainter painter(this);
        _pen.setColor(getColor(_shape->getColor()));
        painter.setPen(_pen);

        switch (_shape->getForm())
        {
        case IShape::Form::CIRCLE:
        {
            painter.drawEllipse(QRect(SETTING_ALEFT, SETTING_ATOP,
                                      static_cast<int>(std::lround(_shape->getWidthForm())),
                                      static_cast<int>((_shape->getHeightForm()))));
            break;
        }
        case IShape::Form::ELLIPSE:
        {
            painter.drawEllipse(QRect(SETTING_ALEFT, SETTING_ATOP,
                                      static_cast<int>(std::lround(_shape->getWidthForm())),
                                      static_cast<int>((_shape->getHeightForm()))));
            break;
        }
        case IShape::Form::RECTANGLE:
        {
            painter.drawRect(QRect(SETTING_ALEFT, SETTING_ATOP,
                                   static_cast<int>(std::lround(_shape->getWidthForm())),
                                   static_cast<int>((_shape->getHeightForm()))));
            break;
        }
        case IShape::Form::SQUARE:
        {
            painter.drawRect(QRect(SETTING_ALEFT, SETTING_ATOP,
                                   static_cast<int>(std::lround(_shape->getWidthForm())),
                                   static_cast<int>((_shape->getHeightForm()))));
            break;
        }
        case IShape::Form::TRIANGLE:
        {
            painter.drawPath(buildTriangle((QRect(SETTING_ALEFT, SETTING_ATOP,
                                                  static_cast<int>(std::lround(_shape->getWidthForm())),
                                                  static_cast<int>((_shape->getHeightForm()))))));
            break;
        }

        default:
        {
            break;
        }
        }

    }
}

QPainterPath MainWindow::buildTriangle(const QRectF &rect) const
{
    QPainterPath path;

    path.moveTo(rect.left() + (rect.width() / 2.0), rect.top());
    path.lineTo(rect.bottomLeft());
    path.lineTo(rect.bottomRight());
    path.lineTo(rect.left() + (rect.width() / 2.0), rect.top());

    return path;
}

void MainWindow::on_pushButtonCreateShape_clicked()
{
    _shape = IShape::factory(defineForm(), WIDTH, HEIGHT, IColor::factory(defineColor()));
    if (_shape != nullptr)
    {
        _state_current = std::make_pair(_shape->getForm(), _shape->getColor());
        if (_state_current != _state_last)
        {
            repaint();
            printPerimeterAndArea();
            _state_last = _state_current;
        }
    }
}

std::string MainWindow::defineForm() const
{
    if (_ui->radioButtonCircle->isChecked())
    {
        return std::string("Circle");
    } else if (_ui->radioButtonEllipse->isChecked())
    {
        return std::string("Ellipse");
    } else if (_ui->radioButtonRectangle->isChecked()) {
        return std::string("Rectangle");
    } else if (_ui->radioButtonSquare->isChecked()) {
        return std::string("Square");
    } else if (_ui->radioButtonTriangle->isChecked()) {
        return std::string("Triangle");
    } else {
        return std::string("Not form");;
    }
}

std::string MainWindow::defineColor() const
{   
    if (_ui->radioButtonColorGreen->isChecked())
        return std::string("Green");
    else if (_ui->radioButtonColorRed->isChecked()) {
        return std::string("Red");
    } else {
        return std::string("Not color");
    }
}

Qt::GlobalColor MainWindow::getColor(const IColor::Color &color) const
{
    Qt::GlobalColor result = Qt::gray;

    if (color == IColor::Color::RED)
        result = Qt::red;
    else if (color == IColor::Color::GREEN)
        result = Qt::green;

    return result;
}

void MainWindow::printPerimeterAndArea()
{
    _ui->textEditShape->clear();
    _ui->textEditShape->append(QString("Perimeter = "));
    _ui->textEditShape->append(QString::number(_shape->getPerimeter()));
    _ui->textEditShape->append(QString("Area = "));
    _ui->textEditShape->append(QString::number(_shape->getArea()));
}
