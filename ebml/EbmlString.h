// Copyright © 2002-2010 Steve Lhomme.
// SPDX-License-Identifier: LGPL-2.1-or-later

/*!
  \file
  \author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBEBML_STRING_H
#define LIBEBML_STRING_H

#include <string>

#include "EbmlTypes.h"
#include "EbmlElement.h"

namespace libebml {

/*!
    \class EbmlString
    \brief Handle all operations on a printable string EBML element
*/
class EBML_DLL_API EbmlString : public EbmlElementDefaultStorage<const char *, std::string> {
  public:
    EbmlString(const EbmlCallbacksDefault<const char *> &);

    bool ValidateSize() const override {return GetSize() < 0x7FFFFFFF;} // any size is possible
    filepos_t RenderData(IOCallback & output, bool bForceRender, ShouldWrite writeFilter = WriteSkipDefault) override;
    filepos_t ReadData(IOCallback & input, ScopeMode ReadFully = SCOPE_ALL_DATA) override;
    filepos_t UpdateSize(ShouldWrite writeFilter = WriteSkipDefault, bool bForceRender = false) override;

    using EbmlElement::operator const EbmlId &;
    explicit operator const std::string &() const;

    EbmlElementDefault<const char *> &SetValue(const char * const & NewValue) override;
    EbmlElementDefault<const char *> &SetValue(std::string const &NewValue);
    std::string GetValue() const;

    bool operator==(const char * const & val) const override {
      return val == Value;
    }
};

} // namespace libebml

#endif // LIBEBML_STRING_H
