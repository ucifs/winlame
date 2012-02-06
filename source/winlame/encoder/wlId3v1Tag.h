/*
   winLAME - a frontend for the LAME encoding engine
   Copyright (c) 2000-2007 Michael Fink

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   $Id: wlId3v1Tag.h,v 1.2 2009/11/02 20:30:52 vividos Exp $

*/
/*! \file wlId3v1Tag.h

   \brief manages id3 tag reading and writing

*/
/*! \ingroup encoder */
/*! @{ */

// prevent multiple including
#ifndef wlid3v1tag_h_
#define wlid3v1tag_h_

// needed includes

// forward references
class wlTrackInfo;

#pragma pack(push, 1)

/// id3 tag structure
struct wlId3v1Tag
{
   char tag[3];      ///< tag start, always "TAG"
   char title[30];   ///< title
   char artist[30];  ///< artist
   char album[30];   ///< album name
   char year[4];     ///< year
   char comment[29]; ///< comment
   unsigned char track; ///< track
   unsigned char genre; ///< genre id

   /// ctor
   wlId3v1Tag()
   {
      memset(this, 0, sizeof(*this));
   }

   /// ctor; constructs id3 tag from track info
   wlId3v1Tag(const wlTrackInfo& ti)
   {
      memset(this, 0, sizeof(*this));
      fromTrackInfo(ti);
   }

   /// returns pointer to data; length always 128 bytes
   unsigned int* getData()
   {
      ATLASSERT(sizeof(*this) == 128);
      return reinterpret_cast<unsigned int*>(this);
   }

   /// checks if data starts with "TAG"
   bool isValidTag() const
   {
      return strncmp(this->tag, "TAG", 3) == 0;
   }

   /// converts id3 tag to track infos
   void toTrackInfo(wlTrackInfo& ti) const;

   /// converts track infos to id3 tag
   void fromTrackInfo(const wlTrackInfo& ti);
};

#pragma pack(pop)

//@}

#endif // wlid3v1tag_h_
