#ifndef IMAGELAYER_H
#define IMAGELAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class ImageLayer {
public:
    ImageLayer();
    void setImage(const QString &filePath);
    void hide();
    void show();
    QGraphicsPixmapItem* getImageItem() const;

private:
    QGraphicsPixmapItem *imageItem;
};

#endif // IMAGELAYER_H
