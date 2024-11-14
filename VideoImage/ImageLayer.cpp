#include "ImageLayer.h"

ImageLayer::ImageLayer() {
    imageItem = new QGraphicsPixmapItem;
}

void ImageLayer::setImage(const QString &filePath) {
    QPixmap pixmap(filePath);
    imageItem->setPixmap(pixmap);
}

void ImageLayer::hide() {
    imageItem->setVisible(false);
}

void ImageLayer::show() {
    imageItem->setVisible(true);
}

QGraphicsPixmapItem* ImageLayer::getImageItem() const {
    return imageItem;
}
