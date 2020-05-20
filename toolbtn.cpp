#include "toolbtn.h"

#include <QDebug>

ToolBtn::ToolBtn(QWidget* pparent) : QLabel(pparent)
{
    setPixmap(QPixmap(":/brush.png").scaledToHeight(70));
}

void ToolBtn::mouseReleaseEvent(QMouseEvent* pe)
{
    if (pe->button() == Qt::LeftButton)
        emit clicked();
}
