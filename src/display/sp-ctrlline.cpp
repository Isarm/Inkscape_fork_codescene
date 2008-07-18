#define __INKSCAPE_CTRLLINE_C__

/*
 * Simple straight line
 *
 * Author:
 *   Lauris Kaplinski <lauris@kaplinski.com>
 *   Johan Engelen <j.b.c.engelen@ewi.utwente.nl>
 *
 * Copyright (C) 2007 Johan Engelen
 * Copyright (C) 1999-2002 Lauris Kaplinski
 *
 * Released under GNU GPL
 */

/*
 * TODO:
 * Draw it by hand - we really do not need aa stuff for it
 *
 */

#include "display-forward.h"
#include "sp-canvas-util.h"
#include "sp-ctrlline.h"

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <color.h>
#include "display/inkscape-cairo.h"


static void sp_ctrlline_class_init (SPCtrlLineClass *klass);
static void sp_ctrlline_init (SPCtrlLine *ctrlline);
static void sp_ctrlline_destroy (GtkObject *object);

static void sp_ctrlline_update (SPCanvasItem *item, NR::Matrix const &affine, unsigned int flags);
static void sp_ctrlline_render (SPCanvasItem *item, SPCanvasBuf *buf);

static SPCanvasItemClass *parent_class;

GtkType
sp_ctrlline_get_type (void)
{
    static GtkType type = 0;

    if (!type) {
        GtkTypeInfo info = {
            "SPCtrlLine",
            sizeof (SPCtrlLine),
            sizeof (SPCtrlLineClass),
            (GtkClassInitFunc) sp_ctrlline_class_init,
            (GtkObjectInitFunc) sp_ctrlline_init,
            NULL, NULL, NULL
        };
        type = gtk_type_unique (SP_TYPE_CANVAS_ITEM, &info);
    }
    return type;
}

static void
sp_ctrlline_class_init (SPCtrlLineClass *klass)
{
    GtkObjectClass *object_class = (GtkObjectClass *) klass;
    SPCanvasItemClass *item_class = (SPCanvasItemClass *) klass;

    parent_class = (SPCanvasItemClass*)gtk_type_class (SP_TYPE_CANVAS_ITEM);

    object_class->destroy = sp_ctrlline_destroy;

    item_class->update = sp_ctrlline_update;
    item_class->render = sp_ctrlline_render;
}

static void
sp_ctrlline_init (SPCtrlLine *ctrlline)
{
    ctrlline->rgba = 0x0000ff7f;
    ctrlline->s[NR::X] = ctrlline->s[NR::Y] = ctrlline->e[NR::X] = ctrlline->e[NR::Y] = 0.0;
    ctrlline->item=NULL;
}

static void
sp_ctrlline_destroy (GtkObject *object)
{
    g_return_if_fail (object != NULL);
    g_return_if_fail (SP_IS_CTRLLINE (object));

    SPCtrlLine *ctrlline = SP_CTRLLINE (object);

    ctrlline->item=NULL;

    if (GTK_OBJECT_CLASS (parent_class)->destroy)
        (* GTK_OBJECT_CLASS (parent_class)->destroy) (object);
}

static void
sp_ctrlline_render (SPCanvasItem *item, SPCanvasBuf *buf)
{
    SPCtrlLine *cl = SP_CTRLLINE (item);

    if (!buf->ct)
        return;

    sp_canvas_prepare_buffer (buf);

    guint32 rgba = cl->rgba;
    cairo_set_source_rgba(buf->ct, SP_RGBA32_B_F(rgba), SP_RGBA32_G_F(rgba), SP_RGBA32_R_F(rgba), SP_RGBA32_A_F(rgba));

    cairo_set_line_width(buf->ct, 1);
    cairo_new_path(buf->ct);

    NR::Point s = cl->s * cl->affine;
    NR::Point e = cl->e * cl->affine;

    cairo_move_to (buf->ct, s[NR::X] - buf->rect.x0, s[NR::Y] - buf->rect.y0);
    cairo_line_to (buf->ct, e[NR::X] - buf->rect.x0, e[NR::Y] - buf->rect.y0);

    cairo_stroke(buf->ct);
}

static void
sp_ctrlline_update (SPCanvasItem *item, NR::Matrix const &affine, unsigned int flags)
{
    SPCtrlLine *cl = SP_CTRLLINE (item);

    sp_canvas_request_redraw (item->canvas, (int)item->x1, (int)item->y1, (int)item->x2, (int)item->y2);

    if (parent_class->update)
        (* parent_class->update) (item, affine, flags);

    sp_canvas_item_reset_bounds (item);

    cl->affine = affine;

    NR::Point s = cl->s * affine;
    NR::Point e = cl->e * affine;

    item->x1 = round(MIN(s[NR::X], e[NR::X]) - 1);
    item->y1 = round(MIN(s[NR::Y], e[NR::Y]) - 1);
    item->x2 = round(MAX(s[NR::X], e[NR::X]) + 1);
    item->y2 = round(MAX(s[NR::Y], e[NR::Y]) + 1);

    sp_canvas_request_redraw (item->canvas, (int)item->x1, (int)item->y1, (int)item->x2, (int)item->y2);
}

void
sp_ctrlline_set_rgba32 (SPCtrlLine *cl, guint32 rgba)
{
    g_return_if_fail (cl != NULL);
    g_return_if_fail (SP_IS_CTRLLINE (cl));

    if (rgba != cl->rgba) {
        SPCanvasItem *item;
        cl->rgba = rgba;
        item = SP_CANVAS_ITEM (cl);
        sp_canvas_request_redraw (item->canvas, (int)item->x1, (int)item->y1, (int)item->x2, (int)item->y2);
    }
}

#define EPSILON 1e-6
#define DIFFER(a,b) (fabs ((a) - (b)) > EPSILON)

void
sp_ctrlline_set_coords (SPCtrlLine *cl, gdouble x0, gdouble y0, gdouble x1, gdouble y1)
{
    g_return_if_fail (cl != NULL);
    g_return_if_fail (SP_IS_CTRLLINE (cl));

    if (DIFFER (x0, cl->s[NR::X]) || DIFFER (y0, cl->s[NR::Y]) || DIFFER (x1, cl->e[NR::X]) || DIFFER (y1, cl->e[NR::Y])) {
        cl->s[NR::X] = x0;
        cl->s[NR::Y] = y0;
        cl->e[NR::X] = x1;
        cl->e[NR::Y] = y1;
        sp_canvas_item_request_update (SP_CANVAS_ITEM (cl));
    }
}

void
sp_ctrlline_set_coords (SPCtrlLine *cl, const NR::Point start, const NR::Point end)
{
    sp_ctrlline_set_coords(cl, start[0], start[1], end[0], end[1]);
}

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=99 :
