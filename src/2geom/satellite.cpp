/**
 * \file
 * \brief Satellite
 *//*
 * Authors:
 * 2015 Jabier Arraiza Cenoz<jabier.arraiza@marker.es>
 * Copyright 2015  authors
 *
 * This library is free software; you can redistribute it and/or
 * modify it either under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * (the "LGPL") or, at your option, under the terms of the Mozilla
 * Public License Version 1.1 (the "MPL"). If you do not alter this
 * notice, a recipient may use your version of this file under either
 * the MPL or the LGPL.
 *
 * You should have received a copy of the LGPL along with this library
 * in the file COPYING-LGPL-2.1; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * You should have received a copy of the MPL along with this library
 * in the file COPYING-MPL-1.1
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY
 * OF ANY KIND, either express or implied. See the LGPL or the MPL for
 * the specific language governing rights and limitations.
 */

#include <2geom/satellite.h>
#include <2geom/curve.h>
#include <2geom/nearest-point.h>
#include <2geom/sbasis-geometric.h>


namespace Geom {

Satellite::Satellite(){};

Satellite::Satellite(SatelliteType satellitetype, bool isTime, bool active, bool hasMirror, bool hidden, double size, double time)
        : _satellitetype(satellitetype), _isTime(isTime), _active(active), _hasMirror(hasMirror), _hidden(hidden), _size(size), _time(time){};

Satellite::~Satellite() {};

void
Satellite::setPosition(Geom::Point p, Geom::D2<Geom::SBasis> d2_in){
    _time =  Geom::nearest_point(p, d2_in);
    if (d2_in[0].degreesOfFreedom() != 2) {
        Geom::Piecewise<Geom::D2<Geom::SBasis> > u;
        u.push_cut(0);
        u.push(d2_in, 1);
        u = Geom::portion(u, 0.0, _time);
        _size = Geom::length(u, 0.001);
    } else {
        double lenghtPart = Geom::length(d2_in, Geom::EPSILON);
        _size = (_time * lenghtPart);
    }
}

Geom::Point 
Satellite::getPosition(Geom::D2<Geom::SBasis> d2_in){
   return d2_in.valueAt(_time);
}
    
double
Satellite::getOpositeTime(Geom::D2<Geom::SBasis> d2_in){
    double t = 0;
    if(_size == 0){
        return 1;
    }
    double lenghtPart = Geom::length(d2_in, Geom::EPSILON);
    double size = lenghtPart - _size;
    if (d2_in[0].degreesOfFreedom() != 2) {
        Geom::Piecewise<Geom::D2<Geom::SBasis> > u;
        u.push_cut(0);
        u.push(d2_in, 1);
        std::vector<double> t_roots = roots(arcLengthSb(u) - size);
        if (t_roots.size() > 0) {
            t = t_roots[0];
        }
    } else {
        if (size < lenghtPart && lenghtPart != 0) {
            t = size / lenghtPart;
        }
    }
    return t;
}

} // end namespace Geom

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:fileencoding=utf-8:textwidth=99 :
