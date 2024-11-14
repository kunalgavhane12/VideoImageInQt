#include "BaseLayer.h"
#include <QResizeEvent>
#include <QDir>

BaseLayer::BaseLayer(QWidget *parent)
    : QGraphicsView(parent),
    videoLayer(new VideoLayer),
    imageLayer(new ImageLayer),
    toggleTimer(new QTimer(this)),
    currentVideoIndex(0),
    currentImageIndex(0),
    showingVideo(true) {

    setScene(&scene);
    setRenderHint(QPainter::Antialiasing);

    // Disable scrolling
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Add layers to the scene
    scene.addItem(imageLayer->getImageItem());
    scene.addItem(videoLayer->getVideoItem());

    // Set Z-values to control layer order
    imageLayer->getImageItem()->setZValue(0);
    videoLayer->getVideoItem()->setZValue(1);

    setSceneRect(0, 0, 800, 600); // Adjust as needed

    // Load video and image files
    loadMediaFiles();

    // Set up toggle timer to alternate between video and image
    connect(toggleTimer, &QTimer::timeout, this, &BaseLayer::toggleDisplay);
    toggleTimer->start(5000); // Switch every 5 seconds

    // Play the first video
    if (!videoFiles.isEmpty()) {
        QString videoPath = "/home/kunal/Videos/" + videoFiles[currentVideoIndex];
        videoLayer->playVideo(videoPath);
    }
}

void BaseLayer::loadMediaFiles() {
    QDir videoDir("/home/kunal/Videos");
    QDir imageDir("/home/kunal/Pictures/Screenshots");

    videoFiles = videoDir.entryList(QStringList() << "*.mp4" << "*.avi", QDir::Files);
    imageFiles = imageDir.entryList(QStringList() << "*.png" << "*.jpg" << "*.jpeg", QDir::Files);
}

void BaseLayer::toggleDisplay() {
    if (showingVideo) {
        // Show the next image
        if (!imageFiles.isEmpty()) {
            QString imagePath = "/home/kunal/Pictures/Screenshots/" + imageFiles[currentImageIndex];
            imageLayer->setImage(imagePath);
            currentImageIndex = (currentImageIndex + 1) % imageFiles.size();
        }
        videoLayer->stop();
        imageLayer->show();
    } else {
        // Play the next video
        if (!videoFiles.isEmpty()) {
            QString videoPath = "/home/kunal/Videos/" + videoFiles[currentVideoIndex];
            videoLayer->playVideo(videoPath);
            currentVideoIndex = (currentVideoIndex + 1) % videoFiles.size();
        }
        imageLayer->hide();
    }
    showingVideo = !showingVideo;
}

void BaseLayer::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event); // Make sure base class handling is done

    QSize newSize = event->size();

    // Scale video to fit the new size while maintaining aspect ratio
    videoLayer->getVideoItem()->setSize(newSize);

    // Scale image to fit the new size while maintaining aspect ratio
    imageLayer->getImageItem()->setPixmap(imageLayer->getImageItem()->pixmap().scaled(newSize, Qt::KeepAspectRatio));
}
