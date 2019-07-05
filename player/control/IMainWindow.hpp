#pragma once

#include "control/common/IWidget.hpp"

#include <memory>
#include <sigc++/signal.h>

using SignalKeyPressed = sigc::signal<void(std::string)>;

class IMainWindow : public IWidget
{
public:
    virtual int x() const = 0;
    virtual int y() const = 0;
    virtual void move(int x, int y) = 0;

    virtual void setWidget(const std::shared_ptr<IWidget>& child) = 0;
    virtual void disableWindowResize() = 0;
    virtual void disableWindowDecoration() = 0;
    virtual void setKeepAbove(bool keepAbove) = 0;
    virtual void fullscreen() = 0;
    virtual void unfullscreen() = 0;
    virtual void setCursorVisible(bool cursorVisible) = 0;

    virtual SignalKeyPressed keyPressed() = 0;

};