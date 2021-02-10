#ifndef CGRADIENTSELECTIONSTYLEDELEGATE_H
#define CGRADIENTSELECTIONSTYLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class CGradientSelectionStyleDelegate : public QStyledItemDelegate
{
public:
    explicit CGradientSelectionStyleDelegate(QObject *parent = 0) :
        QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        if(option.state & QStyle::State_Selected) {
            QStyleOptionViewItem opt(option);
            opt.state &= ~(QStyle::State_Selected | QStyle::State_MouseOver);
            //draw item as non selected, and without mouse-over event
            QStyledItemDelegate::paint(painter, opt, index);

            const QRectF area = opt.rect;
            QLinearGradient grad(area.left() + area.width() / 2, area.top(), area.left() + area.width() / 2, area.bottom());
            const QColor highlight = opt.palette.color(QPalette::Highlight);
            grad.setColorAt(0.0f, highlight);
            grad.setColorAt(0.3f, Qt::transparent);
            grad.setColorAt(0.7f, Qt::transparent);
            grad.setColorAt(1.0f, highlight);
            painter->fillRect(area, grad); //draw custom selection under item
        } else
            QStyledItemDelegate::paint(painter, option, index);
    }
};

#endif // CGRADIENTSELECTIONSTYLEDELEGATE_H

