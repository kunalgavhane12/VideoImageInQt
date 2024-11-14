#ifndef VIDEOLAYER_H
#define VIDEOLAYER_H

#include <QMediaPlayer>
#include <QGraphicsVideoItem>

class VideoLayer : public QObject
{
    Q_OBJECT

public:
    explicit VideoLayer(QObject *parent = nullptr);
    void playVideo(const QString &filePath);
    void stop();

    // Getter for QMediaPlayer
    QMediaPlayer* getPlayer() const;

    // Getter for QGraphicsVideoItem
    QGraphicsVideoItem* getVideoItem() const;

private:
    QMediaPlayer* player;
    QGraphicsVideoItem* videoItem;
};

#endif // VIDEOLAYER_H
