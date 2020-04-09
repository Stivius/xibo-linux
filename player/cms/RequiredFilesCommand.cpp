#include "RequiredFilesCommand.hpp"

RequiredFilesCommand::RequiredFilesCommand(const std::string& host,
                                           const std::string& serverKey,
                                           const std::string& hardwareKey) :
    XmdsCommand(host),
    serverKey_(serverKey),
    hardwareKey_(hardwareKey)
{
}

RequiredFilesCommand::SignalFilesReady& RequiredFilesCommand::filesReady()
{
    return filesReady_;
}

RequiredFiles::Request RequiredFilesCommand::prepareRequest()
{
    RequiredFiles::Request request;
    request.serverKey = serverKey_;
    request.hardwareKey = hardwareKey_;
    return request;
}

void RequiredFilesCommand::processResponse(const RequiredFiles::Response& response)
{
    filesReady_(response.requiredFiles(), response.requiredResources());
}
