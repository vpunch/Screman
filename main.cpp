#include <QApplication>

#include "bgwgt.h"
#include "draftwgt.h"
#include "toolpanel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BgWgt bgWgt;
    bgWgt.showFullScreen();

    DraftWgt draftWgt;
    //draftWgt.showFullScreen();

    ToolPanel toolPanel(&draftWgt);
    toolPanel.show();

    return a.exec();
}
