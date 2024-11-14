#ifndef BASELAYER_H
#define BASELAYER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QStringList>
#include "VideoLayer.h"
#include "ImageLayer.h"
#include <QResizeEvent>


class BaseLayer : public QGraphicsView
{
    Q_OBJECT

public:
    explicit BaseLayer(QWidget *parent = nullptr);
    ~BaseLayer() = default;

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void loadMediaFiles();
    void toggleDisplay();

    QGraphicsScene scene;
    VideoLayer *videoLayer;
    ImageLayer *imageLayer;
    QTimer *toggleTimer;

    QStringList videoFiles;
    QStringList imageFiles;
    int currentVideoIndex = 0;
    int currentImageIndex = 0;
    bool showingVideo = true;
};

#endif // BASELAYER_H

