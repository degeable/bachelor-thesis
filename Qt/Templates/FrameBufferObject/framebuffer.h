#ifndef FRAMEBUFFERTRIANGLE_H
#define FRAMEBUFFERTRIANGLE_H

#include <QQuickFramebufferObject>


class FrameBuffer : public QQuickFramebufferObject
{
public:
    explicit FrameBuffer(QQuickItem* parent = nullptr);

    Renderer* createRenderer() const override;
};


#endif // FRAMEBUFFERTRIANGLE_H
