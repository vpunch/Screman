#ifndef TOOLPANEL_H
#define TOOLPANEL_H

#include <QWidget>
#include <QStateMachine>
#include <QPropertyAnimation>
#include <QSignalTransition>

#include "toolbtn.h"

class ToolPanel : public QWidget {
public:
    ToolPanel(QWidget* pparent = nullptr);

private:
    Q_OBJECT

    QSize size;
};

#endif // TOOLPANEL_H
