/*
   winLAME - a frontend for the LAME encoding engine
   Copyright (c) 2005 Michael Fink

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

   $Id: wlCDRipTrackManager.h,v 1.2 2005/03/10 15:59:56 vividos Exp $

*/
/*! \file wlCDRipTrackManager.h

   \brief contains the cd audio extraction manager

*/
/*! \ingroup userinterface */
/*! @{ */

// prevent multiple including
#ifndef wlcdriptrackmanager_h_
#define wlcdriptrackmanager_h_

// needed includes


extern LPCTSTR g_pszCDRipPrefix;

struct wlCDRipDiscInfo
{
   wlCDRipDiscInfo():m_bVariousArtists(false), m_nYear(0), m_nDiscDrive(0){}

   CString m_cszDiscTitle;
   CString m_cszDiscArtist;
   bool m_bVariousArtists;
   unsigned int m_nYear;
   unsigned int m_nDiscDrive;
   CString m_cszGenre;

   CString m_cszCDID;
};

struct wlCDRipTrackInfo
{
   wlCDRipTrackInfo():m_nTrackOnDisc(0), m_nTrackLength(0), m_bActive(true) {}
   unsigned int m_nTrackOnDisc;
   CString m_cszTrackTitle;

   unsigned int m_nTrackLength;

   bool m_bActive;

   CString m_cszRippedFilename;
};


class wlCDRipTrackManager
{
public:
   static wlCDRipTrackManager* getCDRipTrackManager();
   ~wlCDRipTrackManager();

   wlCDRipDiscInfo& GetDiscInfo(){ return m_discInfo; }

   unsigned int GetMaxTrackInfo(){ return m_vecTrackInfo.size(); }

   wlCDRipTrackInfo& GetTrackInfo(unsigned int nIndex){ ATLASSERT(nIndex < GetMaxTrackInfo()); return m_vecTrackInfo[nIndex]; }

   void RemoveTrackInfo(unsigned int nIndex){ ATLASSERT(nIndex < GetMaxTrackInfo()); m_vecTrackInfo.erase(m_vecTrackInfo.begin() + nIndex); }

   void ResetTrackInfo(){ m_vecTrackInfo.clear(); }

   void AddTrackInfo(wlCDRipTrackInfo& info){ m_vecTrackInfo.push_back(info); }

protected:
   wlCDRipDiscInfo m_discInfo;
   std::vector<wlCDRipTrackInfo> m_vecTrackInfo;
private:
   wlCDRipTrackManager(){}
   wlCDRipTrackManager(const wlCDRipTrackManager&){}
   wlCDRipTrackManager& operator=(const wlCDRipTrackManager&){ return *this; }

   static wlCDRipTrackManager* m_pManagerInstance;
};

//@}

#endif
