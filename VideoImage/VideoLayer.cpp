#include "VideoLayer.h"
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QVideoWidget>

VideoLayer::VideoLayer(QObject *parent)
    : QObject(parent), player(new QMediaPlayer(this)), videoItem(new QGraphicsVideoItem())
{
    player->setVideoOutput(videoItem);
}

void VideoLayer::playVideo(const QString &filePath) {
    player->setSource(QUrl::fromLocalFile(filePath));
    player->play();
}

void VideoLayer::stop() {
    player->stop();
}

QMediaPlayer* VideoLayer::getPlayer() const {
    return player;
}

QGraphicsVideoItem* VideoLayer::getVideoItem() const {
    return videoItem;
}
