#ifndef TOOLBTN_H
#define TOOLBTN_H

#include <QLabel>
#include <QMouseEvent>

class ToolBtn : public QLabel {
public:
    ToolBtn(QWidget* pparent = nullptr);

signals:
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent*) override;

private:
    Q_OBJECT
};

#endif // TOOLBTN_H
