#include "draftwgt.h"

#include <QDebug>

DraftWgt::DraftWgt(QWidget* parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    m_color = Qt::red;
}

void DraftWgt::mousePressEvent(QMouseEvent* pe)
{
    if (pe->button() == Qt::LeftButton) {
        m_drawState = true;
        m_buffer << pe->pos();
    }

    QWidget::mousePressEvent(pe);
}

void DraftWgt::mouseReleaseEvent(QMouseEvent* pe)
{
    if (m_drawState) {
        m_buffer << pe->pos();
        m_drawState = false;

        m_oldColors << m_color;
        m_oldBufs << m_buffer;
        m_buffer.clear();
    }

    QWidget::mouseReleaseEvent(pe);
}

void DraftWgt::mouseMoveEvent(QMouseEvent* pe)
{
    if (m_drawState) {
        m_buffer << pe->pos();
        repaint();
    }

    QWidget::mouseMoveEvent(pe);
}

void DraftWgt::paintEvent(QPaintEvent* pe)
{
    QPainter pntr(this);

    QColor hackColor = Qt::white;
    hackColor.setAlphaF(0.01);
    pntr.fillRect(rect(), hackColor);

    pntr.end();

    for (int i = 0; i < m_oldBufs.size(); ++i)
        drawBuffer(m_oldBufs[i], m_oldColors[i]);

    drawBuffer(m_buffer, m_color);

    QWidget::paintEvent(pe);
}

void DraftWgt::drawBuffer(const Points& buffer,
                          Qt::GlobalColor color)
{
    QPainter pntr(this);
    pntr.setRenderHint(QPainter::Antialiasing, true);
    pntr.setPen(QPen(color, 7, Qt::SolidLine));

    if (buffer.size() > 1)
        for (auto it = buffer.begin() + 1; it != buffer.end(); ++it)
            pntr.drawLine(*(it - 1), *it);

    else if (!buffer.isEmpty())
        pntr.drawPoint(buffer.front());

    pntr.end();
}
