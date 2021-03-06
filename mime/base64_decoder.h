// Copyright 2014, Georg Sauthoff <mail@georg.so>

/* {{{ GPLv3

    This file is part of imapdl.

    imapdl is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    imapdl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with imapdl.  If not, see <http://www.gnu.org/licenses/>.

}}} */
#ifndef MIME_BASE64_DECODER_H
#define MIME_BASE64_DECODER_H

#include <functional>
#include <stdint.h>

#include <buffer/buffer.h>

namespace MIME {
  namespace Base64 {

    class Decoder {
      public:
      private:
        int                   cs            {0};
        uint32_t              unit_         {0};
        uint32_t              base64_value_ {0};
        Memory::Buffer::Base &conv_buffer_;
        std::string           sentinel_;
        const char           *next_         {nullptr};
      public:
        Decoder(Memory::Buffer::Base &buffer,
            const std::string &sentinel = std::string());
        void read(const char *begin, const char *end);

        bool in_start() const;
        bool in_final() const;
        bool finished() const;
        void verify_finished() const;
        const char *next() const;
    };

  }
}

#endif
