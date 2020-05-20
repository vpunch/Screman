#ifndef BGWGT_H
#define BGWGT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <windef.h>
#include <winuser.h>

#include "appbtn.h"

class BgWgt : public QWidget {
    Q_OBJECT

#ifdef Q_OS_WIN
    RECT m_oldWorkArea;
#endif

protected:
    void hideDecor();
    void showDecor();

public:
    BgWgt(QWidget* pparent = nullptr);
    ~BgWgt();
};

#endif // BGWGT_H
