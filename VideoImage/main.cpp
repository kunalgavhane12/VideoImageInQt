#include <QApplication>
#include "BaseLayer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    BaseLayer baseLayer;
    baseLayer.show();

    return app.exec();
}
