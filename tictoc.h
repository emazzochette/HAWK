#pragma once
/*
 * Copyright 2010 Andrew Leifer et al <leifer@fas.harvard.edu>
 * This file is part of MindControl.
 *
 * MindControl is free software: you can redistribute it and/or modify
 * it under the terms of the GNU  General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MindControl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MindControl. If not, see <http://www.gnu.org/licenses/>.
 *
 * For the most up to date version of this software, see:
 * http://github.com/samuellab/mindcontrol
 *
 *
 *
 * NOTE: If you use any portion of this code in your research, kindly cite:
 * Leifer, A.M., Fang-Yen, C., Gershow, M., Alkema, M., and Samuel A. D.T.,
 * 	"Optogenetic manipulation of neural activity with high spatial resolution in
 *	freely moving Caenorhabditis elegans," Nature Methods, Submitted (2010).
 */

/* 
 * File:   tictoc.h
 * Author: Marc
 *
 * Created on December 3, 2009, 12:07 PM
 */

#ifndef _TICTOC_H
#define	_TICTOC_H

/* macros to make it easy to track a function execution time
 * just put _TICTOC_TIC_FUNC at the beginning of the function call
 * and put _TICTOC_TOC_FUNC right before any return statement
 */
#define _TICTOC_TIC_FUNC TICTOC::timer().tic(__func__);
#define _TICTOC_TOC_FUNC TICTOC::timer().toc(__func__);

#include <map>
#include <cstring>
class Timing;

using namespace std;

namespace TICTOC {
    class tictoc {
    public:

        /* error return values for toc command
         * NOT_FOUND == you called toc on "name" without ever calling tic on "name" first
         * NOT_TICKED == although you called tic on "name", you called toc on "name" twice in a row
         */
        static const int NOT_FOUND = -1;
        static const int NOT_TICKED = -2;
        static const int TICKS_PER_SEC = (int)1E6;
        /* tictoc()
         * ~tictoc()
         * constructor takes no arguments
         */
        tictoc();
        virtual ~tictoc();

        /* enable(true) turns logging on
         * enable(false) turns logging off
         *
         * tic and toc will return immediately without doing anything
         * if state = false;
         *
         */
        void enable(bool state);


        /* clear()
         *
         * resets tictoc to original state, clearing all information about previously
         * called tics and tocs
         */
        void clear();

        /* void tic (const string &name, bool notick = false);
         * void tic (const char *name, bool notick = false);
         *
         * if notick is true, returns with no effect
         *
         * calling tic starts a timer running associated with "name" (case sensitive)
         * when toc("name") is called, you get the number of clock cycles (usually ms) since
         * tic("name") was last called
         *
         * if tic is called twice in a row without a toc, we reset the starting timer
         * generateReport will note the number of times this happens in the field "numblowntics"
         * 
         */
        void tic (const std::string &name, bool notock = false);
        void tic (const char *name, bool notock = false);

        /* long toc(const string &name, bool notock = false);
         * long toc(const char *name, bool notock = false);         *
         *
         * if notock is true, returns 0 immediately with no other effect
         *
         * when toc("name") is called, we stop the timer associated with "name"
         * and return the number of clock cycles (usually ms) since tic("name") was called
         * you can convert to seconds using CLOCKS_PER_SEC
         *
         * if toc("name") is called prior to tic("name"), return value will be NOT_FOUND
         * if tic("name") is called but then toc("name") is called two or more times in succession,
         * return value will be NOT_TICKED
         */

        double toc(const std::string &name, bool notock = false);
        double toc(const char *name, bool notock = false);

        std::string generateReport();
		//std::map <std::string, struct _tictoc_data> generateDataOutput();
        //static tictoc *timer = new tictoc();
	
		
    
	private:
        double clock();

        tictoc(const tictoc& orig);
        std::map <std::string, struct _tictoc_data> tt;
        Timing *tim;
        bool enabled;
    };

    /* tictoc timer
     * 
     * we declare a globally accessible static instance of tictoc
     * TICTOC::timer for convenience.  This way, you can call tic and toc from 
     * multiple libraries and have all the data retained in a single structure
     * without having to pass a pointer to a tictoc object around
     */
    tictoc& timer();
   
    
}

#endif	/* _TICTOC_H */

