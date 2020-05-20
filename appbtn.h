#ifndef APPBTN_H
#define APPBTN_H

#include <QVBoxLayout>
#include <QProcess>
#include <QLabel>
#include <QMouseEvent>

class AppBtn : public QWidget {
public:
    AppBtn(const QString& path,
           const QString& name,
           QPixmap icon = QPixmap(),
           QWidget* pparent = nullptr);

    void runApp();

protected:
    void mouseReleaseEvent(QMouseEvent*) override;

private:
    int m_iconSize;
    QString m_path;
};

#endif // APPBTN_H
