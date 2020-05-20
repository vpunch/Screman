#include "appbtn.h"

#include <QDebug>

AppBtn::AppBtn(const QString& path,
               const QString& name,
               QPixmap icon,
               QWidget* pparent)
    : QWidget(pparent), m_path(path)
{
    m_iconSize = 60;

    if (icon.isNull()) {
        icon = QPixmap(":/appicon.png");
    }

    QLabel* piconLbl = new QLabel;
    piconLbl->setPixmap(icon.scaled(m_iconSize, m_iconSize));

    QLabel* pnameLbl = new QLabel(name);
    pnameLbl->setAlignment(Qt::AlignCenter);
    pnameLbl->setWordWrap(true);

    QVBoxLayout* play = new QVBoxLayout(this);
    play->addWidget(piconLbl, 1, Qt::AlignCenter);
    play->addWidget(pnameLbl);
    setLayout(play);

    setFocusPolicy(Qt::StrongFocus);

    setStyleSheet("\
        QWidget:focus {\
            border: 2px dashed black;\
        }\
    ");
}

void AppBtn::mouseReleaseEvent(QMouseEvent* pe)
{
    if (pe->button() == Qt::LeftButton)
        runApp();
}

void AppBtn::runApp()
{
    QProcess* papp = new QProcess(this);
    papp->start(m_path, QStringList());
}
