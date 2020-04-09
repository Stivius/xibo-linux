#pragma once

#include <boost/thread/future.hpp>

#include "cms/xmds/GetFile.hpp"
#include "cms/xmds/GetResource.hpp"
#include "cms/xmds/MediaInventory.hpp"
#include "cms/xmds/RequiredFiles.hpp"
#include "cms/xmds/Schedule.hpp"
#include "cms/xmds/SubmitLog.hpp"
#include "cms/xmds/SubmitScreenShot.hpp"
#include "cms/xmds/SubmitStats.hpp"
#include "networking/ResponseResult.hpp"

#include "common/types/Uri.hpp"

template <typename Result>
using FutureResponseResult = boost::future<ResponseResult<Result>>;

class XmdsRequestSender
{
public:
    XmdsRequestSender(const std::string& host, const std::string& serverKey, const std::string& hardwareKey);

    FutureResponseResult<Schedule::Result> schedule();
    FutureResponseResult<GetResource::Result> getResource(int layoutId, int regionId, int mediaId);
    FutureResponseResult<GetFile::Result> getFile(int fileId,
                                                  const std::string& fileType,
                                                  std::size_t chunkOffset,
                                                  std::size_t chunkSize);
    FutureResponseResult<MediaInventory::Result> mediaInventory(MediaInventoryItems&& items);
    FutureResponseResult<SubmitLog::Result> submitLogs(const std::string& logXml);
    FutureResponseResult<SubmitStats::Result> submitStats(const std::string& statXml);
    FutureResponseResult<SubmitScreenShot::Result> submitScreenShot(const std::string& screenShot);

    std::string getHost() const;
    std::string getServerKey() const;
    std::string getHardwareKey() const;

private:
    Uri uri_;
    std::string host_;
    std::string serverKey_;
    std::string hardwareKey_;
};
