#ifndef INKSCAPE_LPE_SIMPLIFY_H
#define INKSCAPE_LPE_SIMPLIFY_H

/*
 * Inkscape::LPESimplify
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */
#include "live_effects/effect.h"
#include "live_effects/parameter/togglebutton.h"
#include "live_effects/lpegroupbbox.h"

namespace Inkscape {
namespace LivePathEffect {

class LPESimplify : public Effect , GroupBBoxEffect {

public:
    LPESimplify(LivePathEffectObject *lpeobject);
    ~LPESimplify() override;

    void doEffect(SPCurve *curve) override;

    void doBeforeEffect (SPLPEItem const* lpeitem) override;

    virtual void generateHelperPathAndSmooth(Geom::PathVector &result);

    Gtk::Widget * newWidget() override;

    virtual void drawNode(Geom::Point p);

    virtual void drawHandle(Geom::Point p);

    virtual void drawHandleLine(Geom::Point p,Geom::Point p2);

protected:
    void addCanvasIndicators(SPLPEItem const */*lpeitem*/, std::vector<Geom::PathVector> &hp_vec) override;

private:
    ScalarParam steps;
    ScalarParam threshold;
    ScalarParam smooth_angles;
    ScalarParam helper_size;
    ToggleButtonParam simplify_individual_paths;
    ToggleButtonParam simplify_just_coalesce;

    double radius_helper_nodes;
    Geom::PathVector hp;
    Geom::OptRect bbox;

    LPESimplify(const LPESimplify &) = delete;
    LPESimplify &operator=(const LPESimplify &) = delete;

};

}; //namespace LivePathEffect
}; //namespace Inkscape
#endif
