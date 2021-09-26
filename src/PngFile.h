/*
 * steghide 0.5.1 - a steganography program
 * Copyright (C) 1999-2003 Nixy C <phoenixrising1800@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#ifndef SH_PNGFILE_H
#define SH_PNGFILE_H

#include "common.h"

#ifdef USE_LIBPNG

#include <vector>

extern "C" {
#include <stdio.h>
#include <png.h>
}

class BinaryIO;
#include "CvrStgFile.h"
class SampleValue;

/**
 * \class PngFile 
 * \brief a cover-/stego-file in the png file format
 *
 * This class uses the PNG library by the IJG for access to png files.
 **/
class PngFile : public CvrStgFile {
	public:
        PngFile (BinaryIO* io) ;
        ~PngFile (void) ;

        void read (BinaryIO* io) ;
        void write (void) ;

        std::list<CvrStgFile::Property> getProperties (void) const ;
        std::vector<MatchingAlgorithm*> getMatchingAlgorithms (Graph* g, Matching* m) const ;
        
        unsigned long getNumSamples (void) const ;
        void replaceSample (const SamplePos pos, const SampleValue* s) ;
        SampleValue* getSampleValue (const SamplePos pos) const ;
        EmbValue getEmbeddedValue (const SamplePos pos) const ;

	private:
        png_bytep* row_pointers;
        png_infop info_ptr;
        png_structp read_ptr;
        png_structp write_ptr;
} ;

#endif // def USE_LIBPNG

#endif // ndef SH_PNGFILE_H