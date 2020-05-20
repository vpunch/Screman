#ifndef DRAFTWGT_H
#define DRAFTWGT_H

#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

class DraftWgt : public QWidget {
public:
    DraftWgt(QWidget* parent = nullptr);

protected:
    using Points = QVector<QPointF>;

    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void paintEvent(QPaintEvent*) override;

    void drawBuffer(const Points&,
                    Qt::GlobalColor);

private:
    bool m_drawState;

    Points m_buffer;
    QVector<Points> m_oldBufs;

    Qt::GlobalColor m_color;
    QVector<Qt::GlobalColor> m_oldColors;
};

#endif // DRAFTWGT_H
