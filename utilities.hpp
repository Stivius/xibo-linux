#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "Parser.hpp"
#include "constants.hpp"

#include <memory>
#include <optional>
#include <iostream>
#include <wx/xml/xml.h>

namespace utilities
{
    template <typename Parser> std::shared_ptr<Parser> GetParser(wxXmlNode* node)
    {
        return std::make_shared<Parser>(node);
    }

    template <typename T> std::optional<T> GetValue(const wxString& optionName)
    {
        if(!optionName.IsEmpty())
            return std::stoi(optionName.ToStdString());
        return {};
    }

    template <> std::optional<wxString> GetValue(const wxString& optionName);
    template <> std::optional<ScaleType> GetValue(const wxString& optionName);
    template <> std::optional<Align> GetValue(const wxString& optionName);
    template <> std::optional<Valign> GetValue(const wxString& optionName);
    template <> std::optional<Render> GetValue(const wxString& optionName);

}

#endif // UTILITIES_HPP
