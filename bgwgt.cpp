#include "bgwgt.h"

#include <QDebug>

BgWgt::BgWgt(QWidget* pparent) : QWidget(pparent)
{
    setWindowFlags(Qt::WindowStaysOnBottomHint);

    hideDecor();

    QPixmap back(":/logo.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, back);
    setPalette(palette);

    AppBtn* ppBtn = new AppBtn("C:\\Program Files\\Microsoft Office\\root\\Office16\\POWERPNT.EXE",
                               "Открыть презентацию здесь");
    AppBtn* calcBtn = new AppBtn("C:\\Windows\\System32\\win32calc.exe",
                                 "Калькулятор");

    QHBoxLayout* iconLay = new QHBoxLayout;
    iconLay->addWidget(ppBtn, 0, Qt::AlignLeft | Qt::AlignTop);
    iconLay->addWidget(calcBtn, 0, Qt::AlignLeft | Qt::AlignTop);
    iconLay->addStretch(1);
    setLayout(iconLay);
}

BgWgt::~BgWgt()
{
    showDecor();
}

void BgWgt::hideDecor()
{
    QProcess::execute("taskkill /im explorer.exe /f");

    SystemParametersInfo(SPI_GETWORKAREA,
                         0,
                         (LPVOID)&m_oldWorkArea,
                         0);

    RECT workArea = {
        0,
        0,
        GetSystemMetrics(SM_CXSCREEN),
        GetSystemMetrics(SM_CYSCREEN)
    };

    SystemParametersInfo(SPI_SETWORKAREA,
                         0,
                         (LPVOID)&workArea,
                         0);
}

void BgWgt::showDecor()
{
    SystemParametersInfo(SPI_SETWORKAREA,
                         0,
                         (LPVOID)&m_oldWorkArea,
                         0);

    QProcess::startDetached("C:\\Windows\\explorer.exe");
}
