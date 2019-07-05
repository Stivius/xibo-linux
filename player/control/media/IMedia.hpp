#pragma once

#include "control/common/IWidget.hpp"
#include "MediaGeometry.hpp"

#include <memory>
#include <sigc++/sigc++.h>

using SignalMediaFinished = sigc::signal<void()>;

class IMedia
{
public:
    virtual ~IMedia() = default;

    virtual void attachMedia(std::unique_ptr<IMedia>&& attachedMedia) = 0;
    virtual void start() = 0;
    virtual void stop() = 0;

    virtual SignalMediaFinished mediaFinished() = 0;

    virtual MediaGeometry::Align align() const = 0;
    virtual MediaGeometry::Valign valign() const = 0;
    virtual std::shared_ptr<IWidget> view() = 0;

};