#include "toolpanel.h"

#include <QDebug>

ToolPanel::ToolPanel(QWidget* pparent)
    : QWidget(pparent), size(450, 80)
{
    setFixedSize(size);
    setWindowFlags(Qt::Window);

    ToolBtn* pbrushTool = new ToolBtn(this);

    QPoint offPnt(0, size.height() - 50);
    QPoint onPnt(0, 0);
    pbrushTool->move(offPnt);

    QStateMachine* psm = new QStateMachine;

    QState* poffState = new QState(psm);
    poffState->assignProperty(pbrushTool, "pos", offPnt);
    psm->setInitialState(poffState);

    QState* ponState = new QState(psm);
    ponState->assignProperty(pbrushTool, "pos", onPnt);

    QSignalTransition* ptoOn = poffState->addTransition(
            pbrushTool, ToolBtn::clicked, ponState);
    QPropertyAnimation* onAnim = new QPropertyAnimation(pbrushTool, "pos");
    ptoOn->addAnimation(onAnim);

    QSignalTransition* ptoOff = ponState->addTransition(
            pbrushTool, ToolBtn::clicked, poffState);
    QPropertyAnimation* offAnim= new QPropertyAnimation(pbrushTool, "pos");
    ptoOff->addAnimation(offAnim);

    psm->start();

    connect(pbrushTool, ToolBtn::clicked, this, [pparent]{
        if (pparent->isHidden()) {
            pparent->showFullScreen();
        }

        else
            pparent->hide();
    });
}
